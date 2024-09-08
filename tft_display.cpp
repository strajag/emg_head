#include "tft_display.h"
#include "Arduino.h"
#include "Adafruit_ST7735.h"

Adafruit_ST7735 tftd = Adafruit_ST7735(TFTD_PIN_CS, TFTD_PIN_RS, TFTD_PIN_RES);

static uint8_t y_pixels[TFTD_SCREEN_WIDTH];
static uint32_t x_counter = 0;
static int32_t value_max = 0;
static int32_t value_max_last = 0;

void tftd_init()
{
    tftd.initR(INITR_BLACKTAB);
    tftd.setRotation(TFTD_SCREEN_ROTATION);
    tftd.fillScreen(ST7735_BLACK);
    tftd.setTextSize(TFTD_TEXT_SIZE);

    for(x_counter = 0; x_counter < TFTD_SCREEN_WIDTH - 1; x_counter++)
        tftd_draw_grid();

    x_counter = 0;
    tftd_draw_text();
}

void tftd_draw_text()
{
    tftd.setCursor(0, 0);
    tftd.setTextColor(ST7735_BLACK);
    tftd.print(value_max_last);
    tftd.setCursor(0, 0);
    tftd.setTextColor(ST7735_GREEN);
    tftd.print(value_max);
}

void tftd_draw_grid()
{
    uint8_t i;
    uint8_t division = TFTD_SCREEN_HEIGHT / TFTD_VALUE_RANGE_DIVISIONS;
    
    for(i = 0; i < TFTD_VALUE_RANGE_DIVISIONS - 1; i++)
        tftd.drawPixel(x_counter, division * (i + 1), ST7735_YELLOW);
}

void tftd_value_add(int32_t value)
{
    value = constrain(value, TFTD_VALUE_RANGE_MAX * -1, TFTD_VALUE_RANGE_MAX);

    if(abs(value) > abs(value_max))
        value_max = value;

    value = map(value, TFTD_VALUE_RANGE_MAX * -1, TFTD_VALUE_RANGE_MAX, TFTD_SCREEN_HEIGHT - 1, 0);

    if(x_counter < TFTD_SCREEN_WIDTH - 2)
        tftd.drawLine(x_counter + 1, y_pixels[x_counter + 1], x_counter + 2, y_pixels[x_counter + 2], ST7735_BLACK);

    y_pixels[x_counter + 1] = value;
    tftd.drawLine(x_counter, y_pixels[x_counter], x_counter + 1, y_pixels[x_counter + 1], ST7735_WHITE);
  
    x_counter++;
    tftd_draw_grid();
    
    if(x_counter > TFTD_SCREEN_WIDTH - 2)
    {
        tftd_draw_text();
        value_max_last = value_max;
        x_counter = value_max = 0;

        tftd_draw_grid();
        tftd.drawLine(x_counter, y_pixels[x_counter], x_counter + 1, y_pixels[x_counter + 1], ST7735_BLACK);
        y_pixels[x_counter] = y_pixels[TFTD_SCREEN_WIDTH - 1];
    }
}