#define CONN_SLEEP  200
#define DISC_SLEEP  1000

// GPIO must be configured for input (or input and output).
#define TOGGLE_GPIO(gpio) (gpio_set_level(gpio, (gpio_get_level(gpio)==0?1:0)))

extern int conns;
