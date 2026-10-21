#include "common.h"

/* localdecomp:start func_0044F290 */
typedef struct {
    s32 active;
    s32 f4;
    s32 timer;
    s32 idle;
} State44F290;

extern State44F290 D_002D1630;

void func_0044F290(void) {
    State44F290 *s = &D_002D1630;
    if (s->active == 0) {
        s->idle++;
        if (s->idle > 10) {
            s->idle = 10;
        }
    } else {
        s->idle = 0;
    }
    if (s->timer != 0) {
        s->timer--;
        if (s->timer == 0) {
            s->active = 0;
        }
    }
}
/* localdecomp:end func_0044F290 */
