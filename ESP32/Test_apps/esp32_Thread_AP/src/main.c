/* WiFi softAP Example

    This example code is in the Public Domain (or CC0 licensed, at your option.)

    Unless required by applicable law or agreed to in writing, this
    software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
    CONDITIONS OF ANY KIND, either express or implied.
*/
#include "../include/main.h"

int conns=0;

void app_main(){
    init_GPIO();
    init_Thread();
     
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || 
                                        ret == ESP_ERR_NVS_NEW_VERSION_FOUND){
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_LOGI(TAG, "ESP_WIFI_MODE_AP");
    wifi_init_softap();
}
