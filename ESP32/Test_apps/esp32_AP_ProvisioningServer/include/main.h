#include <stdio.h>
#include <string.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <driver/gpio.h>

#include <esp_log.h>
#include <esp_wifi.h>
#include <esp_event.h>
#include <nvs_flash.h>

#include <wifi_provisioning/manager.h>

#include <esp_system.h>
#include <esp_pthread.h>
#include <pthread.h>

#include <lwip/err.h>
#include <lwip/sys.h>

#include <wifi_provisioning/scheme_softap.h>

#define GPIO_OUTPUT_IO_2            2
#define GPIO_OUTPUT_PIN_SEL         1ULL<<GPIO_OUTPUT_IO_2

void * thread_blink(void *);
void init_GPIO();
void init_Thread();
esp_err_t custom_prov_data_handler(uint32_t, const uint8_t *, ssize_t,
                                          uint8_t **, ssize_t *, void *);
void event_handler(void *, esp_event_base_t, int, void *);
