
#define WIFI_SSID "B217"
#define WIFI_PW "stmb217666"

#define CONFIG_IP "192.168.50.101"

#define CONFIG_PORT 6341
#define CONFIG_PORT_MAX 6343

#define TEMPERATURE_1 2
#define TEMPERATURE_2 3
#define PREP_GAUGE 4

#define REFRESH_TIME 1000 

// SIGNALS CHART
char SIGNALS_LIST[] = "Current (A)\nTemperature 1 (V)\nTemperature 2 (V)\nBias (V)\nGauge (V)\nZ (m)\nAmplitude (m)\nFreq. Shift (Hz)\n";
int SIGNALS_INDEX[] = {0, 2, 3, 8, 4, 14, 17, 18};
