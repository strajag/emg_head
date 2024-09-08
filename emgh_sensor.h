#ifndef EMGH_SENSOR_H
#define EMGH_SENSOR_H

#include "Arduino.h"

#define EMGHS_PIN_SENSOR A0
#define EMGHS_PIN_ELECTRODE_1 (6)
#define EMGHS_PIN_ELECTRODE_2 (7)

extern void emghs_init(void);
extern int32_t emghs_read(void);
extern uint8_t emghs_ready(void);

#endif /* EMGH_SENSOR_H */