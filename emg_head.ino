#include "Arduino.h"
#include "tft_display.h"
#include "emgh_sensor.h"

#define DISPLAY_VALUE_SPEED (20)

uint32_t display_value_last_time;
int32_t sensor_value_sum = 0;
int32_t sensor_value_counter = 0;

void setup()
{
    Serial.begin(9600);
    while(!Serial)
    delay(1);

    tftd_init();
    emghs_init();

    delay(2000);

    display_value_last_time = millis();
}

void loop()
{
    if(emghs_ready())
    {
        sensor_value_sum += emghs_read();
        sensor_value_counter++;
        if(millis() - display_value_last_time >= DISPLAY_VALUE_SPEED)

        display_value_last_time = millis();
        tftd_value_add(sensor_value_sum / sensor_value_counter);
        sensor_value_sum = sensor_value_counter = 0;
    }
}