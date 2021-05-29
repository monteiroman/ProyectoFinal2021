#include "../include/main.h"
extern int conns;

static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                            int32_t event_id, void* event_data){
    if (event_id == WIFI_EVENT_AP_STACONNECTED) {
        wifi_event_ap_staconnected_t* event = 
                                    (wifi_event_ap_staconnected_t*) event_data;
        ESP_LOGI(TAG, "--------> New connected device <--------");
        ESP_LOGI(TAG, "station "MACSTR" join, AID=%d",
                                            MAC2STR(event->mac), event->aid);
        conns++;
    } else if (event_id == WIFI_EVENT_AP_STADISCONNECTED) {
        wifi_event_ap_stadisconnected_t* event = 
                                (wifi_event_ap_stadisconnected_t*) event_data;
        ESP_LOGI(TAG, "--------> Device disconnected <--------");
        ESP_LOGI(TAG, "station "MACSTR" leave, AID=%d",
                                            MAC2STR(event->mac), event->aid);
        conns=(conns==0)?0:conns-1;
    }
}

// void wifi_init_softap(){
//     esp_netif_init();
//     ESP_ERROR_CHECK(esp_event_loop_create_default());

//     wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
//     ESP_ERROR_CHECK(esp_wifi_init(&cfg));

//     ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, 
//                                                     &wifi_event_handler, NULL));

//     wifi_config_t wifi_config = {
//         .ap = {
//             .ssid = EXAMPLE_ESP_WIFI_SSID,
//             .ssid_len = strlen(EXAMPLE_ESP_WIFI_SSID),
//             .password = EXAMPLE_ESP_WIFI_PASS,
//             .max_connection = EXAMPLE_MAX_STA_CONN,
//             .authmode = WIFI_AUTH_WPA_WPA2_PSK
//         },
//     };
//     if (strlen(EXAMPLE_ESP_WIFI_PASS) == 0){
//         wifi_config.ap.authmode = WIFI_AUTH_OPEN;
//     }

//     ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
//     ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &wifi_config));
//     ESP_ERROR_CHECK(esp_wifi_start());

//     ESP_LOGI(TAG, "wifi_init_softap finished. SSID:%s password:%s",
//                                 EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
// }

void init_GPIO(){
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_INPUT_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    gpio_set_level(GPIO_OUTPUT_IO_2, 0);
}

void init_Thread(){
    pthread_t t1;

    esp_pthread_cfg_t cfg = esp_pthread_get_default_config();
    cfg.stack_size = (4 * 1024);
    esp_pthread_set_cfg(&cfg);

    pthread_create(&t1, NULL, thread_blink, NULL);
}
