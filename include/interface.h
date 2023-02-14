#include <WiFi.h>
#include <time.h>

#include "config.h"
#include "lvgl_disp_map.h"
#include "dt670.h"

IPAddress serverIP;
WiFiClient client;
int serverPort = CONFIG_PORT;

void fetch_channel_list();
void ui_resetup();
void refresh_data_task(lv_timer_t *task);
void refresh_time_task(lv_timer_t *timer);
void get_ntp_time_task(lv_timer_t *timer);
double query_channel_real(uint16_t chan);
void bitwise_swap(double &f64_val);
String double_to_SI_string(double val, String unit);
void index_changed_event_callback1(lv_event_t * event);
void index_changed_event_callback2(lv_event_t * event);
void index_changed_event_callback3(lv_event_t * event);
void index_changed_event_callback4(lv_event_t * event);

// channel indices in pulldown
uint16_t ch1_index = 0; // current
uint16_t ch2_index = 6;// amplitude
uint16_t ch3_index = 1; // temperature1
uint16_t ch4_index = 2; // temperature2
// their units
String ch1_unit = "A";
String ch2_unit = "m";
String ch3_unit = "K";
String ch4_unit = "K";

void serverConnecting()
{
    gfx->fillScreen(BLACK);
    gfx->setTextSize(2);
    gfx->setCursor(0, 0);
    gfx->setTextColor(WHITE);
    gfx->println("Quad Channel Signal Indicator");
    gfx->println("Author: CoccaGuo");
    gfx->println("Platform: ESP32-S3, LVGL, NanonisLabviewInterface");
    // wifi setup
    gfx->print("Connecting to WiFi");
    serverIP.fromString(CONFIG_IP);
    WiFi.mode(WIFI_STA);
    WiFi.setSleep(false);
    WiFi.begin(WIFI_SSID, WIFI_PW);
    int i = 0;
    while (WiFi.status() != WL_CONNECTED && i < 20)
    {
        delay(1000);
        Serial.print(".");
        i++;
    }
    // wifi failed
    if (i == 20)
    {
        gfx->println("WiFi connection failed");
        gfx->println("Please check your WiFi settings");
        // print current settings
        gfx->print("SSID: ");
        gfx->println(WIFI_SSID);
        gfx->print("Password: ");
        gfx->println(WIFI_PW);
        while (1)
            ;
    }
    gfx->println();
    gfx->println("WiFi connected");

    gfx->print("Local IP: ");
    gfx->println(WiFi.localIP());
    gfx->print("Server IP: ");
    gfx->print(serverIP);
    gfx->print(", Server Port: ");
    gfx->println(serverPort);
    // connect to server
    gfx->print("Connecting TCP Server");
    while (!client.connect(serverIP, serverPort))
    {
        delay(1000);
        Serial.print(".");
    }

    fetch_channel_list();
}

void fetch_channel_list()
{
    char query[10] = {0};
    query[0] = 0x86;
    query[1] = 0x01;
    // send query in buffer to server
    client.write(query, 10);
    // wait till server response
    while (client.available())
    {
        delay(10);
    }
    // read unsigned 64bit integer
    uint64_t channel_list_length = 0;
    client.readBytes((char *)&channel_list_length, 8);
    // change endian of current
    channel_list_length = __builtin_bswap64(channel_list_length);
    // print channel list length
    while (client.available() < channel_list_length)
    {
        delay(10);
    }
    // read channel list
    char *channel_list = new char[channel_list_length + 1];
    client.readBytes(channel_list, channel_list_length);
    channel_list[channel_list_length] = 0;
    delete[] channel_list;

    if (channel_list_length == 0)
    {
        gfx->println("No channel found, TCP Connection Error. Start over.");
        // client.stop();
        // try another port number
        if (serverPort < CONFIG_PORT_MAX)
        {
            serverPort++;
        }
        else
        {
            serverPort = CONFIG_PORT;
        }
        gfx->print("Trying port number ");
        gfx->println(serverPort);
        serverConnecting();
    }

    configTime(8 * 3600, 0, "pool.ntp.org", "time.nist.gov");

    ui_init(); // ui methods

    ui_resetup(); // setup dropdown list and refresh method

}

void ui_resetup()
{
    lv_dropdown_set_options(ui_Selector1, SIGNALS_LIST);
    lv_dropdown_set_options(ui_Selector2, SIGNALS_LIST);
    lv_dropdown_set_options(ui_Selector3, SIGNALS_LIST);
    lv_dropdown_set_options(ui_Selector4, SIGNALS_LIST);
    lv_dropdown_set_selected(ui_Selector1, ch1_index);
    lv_dropdown_set_selected(ui_Selector2, ch2_index);
    lv_dropdown_set_selected(ui_Selector3, ch3_index);
    lv_dropdown_set_selected(ui_Selector4, ch4_index);
    // events
    lv_obj_add_event_cb(ui_Selector1, index_changed_event_callback1, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_Selector2, index_changed_event_callback2, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_Selector3, index_changed_event_callback3, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_Selector4, index_changed_event_callback4, LV_EVENT_VALUE_CHANGED, NULL); 

    // add port number to label
    lv_label_set_text_fmt(ui_Label1, "CoccaGuo Works 2023.02 [%d]", serverPort);

    lv_timer_create(refresh_data_task, REFRESH_TIME, NULL);
    lv_timer_create(refresh_time_task, 10*1000, NULL);
    lv_timer_create(get_ntp_time_task, 3600*1000, NULL);

}

void get_ntp_time_task(lv_timer_t *timer)
{
    configTime(8 * 3600, 0, "pool.ntp.org", "time.nist.gov");
}


void refresh_time_task(lv_timer_t *timer)
{
    // get current time
    time_t now = time(nullptr);
    // convert to string
    char time_buffer[32];
    strftime(time_buffer, 32, "%Y-%m-%d %H:%M", localtime(&now));
    // set text
    lv_label_set_text(ui_TimeLabel, time_buffer);
}

char unit_refresh_buffer[32];

void refresh_channel_sub(lv_obj_t* selector, uint16_t &ch_index, String &ch_unit)
{
    // get the index of the selected item
    ch_index = lv_dropdown_get_selected(selector);
    // refresh the unit
    lv_dropdown_get_selected_str(selector, unit_refresh_buffer, 32);
    // the unit is in the brackets
    ch_unit = String(unit_refresh_buffer).substring(String(unit_refresh_buffer).indexOf('(') + 1, String(unit_refresh_buffer).indexOf(')'));
    // check if temperature
    if (SIGNALS_INDEX[ch_index] == TEMPERATURE_1 || SIGNALS_INDEX[ch_index] == TEMPERATURE_2)
    {
        ch_unit = "K";
    }

    if (SIGNALS_INDEX[ch_index] == PREP_GAUGE)
    {
        ch_unit = "mbar";
    }
}

void index_changed_event_callback1(lv_event_t * event)
{
    refresh_channel_sub(ui_Selector1, ch1_index, ch1_unit);
}

void index_changed_event_callback2(lv_event_t * event)
{
    refresh_channel_sub(ui_Selector2, ch2_index, ch2_unit);
}

void index_changed_event_callback3(lv_event_t * event)
{
    refresh_channel_sub(ui_Selector3, ch3_index, ch3_unit);
}

void index_changed_event_callback4(lv_event_t * event)
{
    refresh_channel_sub(ui_Selector4, ch4_index, ch4_unit);
}

void refresh_data_task(lv_timer_t *task)
{
    double data1 = query_channel_real(SIGNALS_INDEX[ch1_index]);
    lv_label_set_text(ui_Data1, double_to_SI_string(data1, ch1_unit).c_str());
    double data2 = query_channel_real(SIGNALS_INDEX[ch2_index]);
    lv_label_set_text(ui_Data2, double_to_SI_string(data2, ch2_unit).c_str());
    double data3 = query_channel_real(SIGNALS_INDEX[ch3_index]);
    lv_label_set_text(ui_Data3, double_to_SI_string(data3, ch3_unit).c_str());
    double data4 = query_channel_real(SIGNALS_INDEX[ch4_index]);
    lv_label_set_text(ui_Data4, double_to_SI_string(data4, ch4_unit).c_str());
}

void bitwise_swap(double &current)
{
    unsigned long long var = *(unsigned long long *)&current;
    var = __builtin_bswap64(var);
    current = *(double *)&var;
}

double query_channel_real(uint16_t chan)
{
    char query[10] = {0};
    query[0] = 0x26;
    query[1] = 0x04;
    double query_ch = chan;
    bitwise_swap(query_ch);
    // copy query_ch into the query buffer as a IEEE764 double
    memcpy(query + 2, &query_ch, 8);
    // send query in buffer to server
    client.write(query, 10);
    // wait till server response
    int timeout = 200;
    while (client.available() < 8 && timeout > 0)
    {
        delay(1);
        timeout--;
    }
    if (timeout == 0)
    {
        serverConnecting();
    }
    // read double
    double val = 0;
    client.readBytes((char *)&val, 8);
    bitwise_swap(val);

    // check if is temperature
    if (chan == TEMPERATURE_1 || chan == TEMPERATURE_2)
    {
        val = temperature(val);
    }

    if (chan == PREP_GAUGE)
    {
        val = exp10(val-12);
    }

    return val;
}

// take a double value and convert it to a string with SI prefix, with 3 point precision
String double_to_SI_string(double val, String unit)
{
    String str = "";
    if (abs(val) < 1e-12)
    {
        str = String(val * 1e15, 3);
        str += " f";
    }
    else if (abs(val) < 1e-9)
    {
        str = String(val * 1e12, 3);
        str += " p";
    }
    else if (abs(val) < 1e-6)
    {
        str = String(val * 1e9, 3);
        str += " n";
    }
    else if (abs(val) < 1e-3)
    {
        str = String(val * 1e6, 3);
        str += " u";
    }
    else if (abs(val) < 1)
    {
        str = String(val * 1e3, 3);
        str += " m";
    }
    else if (abs(val) < 1e3)
    {
        str = String(val, 3) + " ";
    }
    else if (abs(val) < 1e6)
    {
        str = String(val * 1e-3, 3);
        str += " k";
    }
    else
    {
        str = String(val, 3) + " ";
    }
    str += unit;

    if (unit == "mbar")
    {   
        char _numbuf[8];
        // use sprintf scientific notation
        sprintf(_numbuf, "%.2e", val);
        str = String(_numbuf) + " mbar";
    }
    return str;
}