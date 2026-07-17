#include "types.h"
#include "button.h"
#include "timer.h"


void Led_init(Led_t *);
void Led_toggle(Led_t *);
void Led_off(Led_t *);
void Led_setMode(Led_t *, LedMode_t);
void Led_update(Led_t *);
