#include "emgh_sensor.h"
#include "Arduino.h"

void emghs_init()
{
    pinMode(EMGHS_PIN_SENSOR, INPUT);
    pinMode(EMGHS_PIN_ELECTRODE_1, INPUT);
    pinMode(EMGHS_PIN_ELECTRODE_2, INPUT);
}

int32_t emghs_read()
{
    return map(analogRead(EMGHS_PIN_SENSOR), 0, 675, -338, 338);
}

uint8_t emghs_ready(void)
{
    return (digitalRead(EMGHS_PIN_ELECTRODE_1) == LOW && digitalRead(EMGHS_PIN_ELECTRODE_2) == LOW);
}