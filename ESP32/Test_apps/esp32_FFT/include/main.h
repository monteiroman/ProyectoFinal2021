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






#include <math.h>

#include <sdkconfig.h>

#include <soc/timer_group_struct.h>
#include <driver/periph_ctrl.h>
#include <driver/timer.h>


#include "fft.h"

