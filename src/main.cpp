#include <Arduino.h>
#include <ui.h>
#include <ui_helpers.h>
#include <interface.h>


void setup()
{   
    lv_init(); // lv methods

    lvgl_ui_setup(); // setup lcd and link lvgl to lcd

    serverConnecting(); // setup wifi and connect to server, all methods are followed below

    
}



void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}