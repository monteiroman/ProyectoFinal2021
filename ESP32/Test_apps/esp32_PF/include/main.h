#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_pthread.h"
#include "pthread.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#define GPIO_OUTPUT_IO_2     2
#define GPIO_OUTPUT_PIN_SEL  1ULL<<GPIO_OUTPUT_IO_2

#define EXAMPLE_ESP_WIFI_SSID      "mywifissid"
#define EXAMPLE_ESP_WIFI_PASS      "mywifipass"
#define EXAMPLE_MAX_STA_CONN       (3)

void * thread_blink(void *);
void wifi_init_softap();
void init_GPIO();
void init_Thread();

static const char *TAG = "wifi softAP";
