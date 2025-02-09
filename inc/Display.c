#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/font.h"

#include "inc/Display.h"


void display_init(ssd1306_t *ssd){
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init(ssd,WIDTH, HEIGHT, false, endereco, I2C_PORT);
    ssd1306_config(ssd);
    ssd1306_send_data(ssd);
    ssd1306_fill(ssd, false);
    ssd1306_send_data(ssd);
}

void display_draw(ssd1306_t *ssd, const char *x, const *y){
    ssd1306_fill(ssd, false);
    ssd1306_draw_string(ssd, x, 0, 0);  
    ssd1306_draw_string(ssd, y, 0, 20); 
    ssd1306_send_data(ssd);
}
