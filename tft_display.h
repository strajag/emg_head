#ifndef TFT_DISPLAY_H
#define TFT_DISPLAY_H

#include "Arduino.h"

#define TFTD_PIN_CS (10)
#define TFTD_PIN_RS (9)
#define TFTD_PIN_RES (8)
#define TFTD_PIN_SCK (13)
#define TFTD_PIN_SDA (11)

#define TFTD_SCREEN_WIDTH (160)
#define TFTD_SCREEN_HEIGHT (128)
#define TFTD_SCREEN_ROTATION (3)

#define TFTD_VALUE_RANGE_MAX (338)
#define TFTD_VALUE_RANGE_DIVISIONS (4)

#define TFTD_TEXT_SIZE (2)

extern void tftd_init(void);
extern void tftd_value_add(int32_t value);
extern void tftd_draw_text(void);
extern void tftd_draw_grid(void);

#endif /* TFT_DISPLAY_H */