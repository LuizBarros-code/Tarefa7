
#ifndef DISPLAY_H
#define DISPLAY_H


#include "ssd1306.h"
#include <stdbool.h>

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C


#define WIDTH 128
#define HEIGHT 64

void display_init(ssd1306_t *ssd);
void display_draw(ssd1306_t *ssd, const char *x, const *y);

#endif // DISPLAY_OLED_H