#include "../include/main.h"
#include "../include/thread_blink.h"

void * thread_blink(void * p){
    int delay=DISC_SLEEP;

    while(1){
        TOGGLE_GPIO(GPIO_OUTPUT_IO_2);
       
        delay=(conns>0)?CONN_SLEEP:DISC_SLEEP;
        vTaskDelay(delay / portTICK_RATE_MS);
    }
    return NULL;
}