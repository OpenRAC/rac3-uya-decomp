#include "common.h"

typedef struct {
    u8 pad0[0x38];
    float f38;
    int i3C;
    u8 pad40[0x88 - 0x40];
    int i88;
    int i8C;
    u8 pad90[0xBC - 0x90];
    int iBC;
    int iC0;
    int iC4;
} Data;

/* localdecomp:start func_003B4480 */
float func_003B4480(u8 *obj, int unused, int flag, float *cur, float *max)
{
    Data *d = *(Data **)(obj + 0x68);
    float r;

    if (d->i3C != 0) {
        if (cur != 0) {
            *max = d->i3C;
            if (d->iC4 >= d->i3C) {
                *cur = d->i3C;
            } else {
                *cur = d->iC4;
            }
        }
        r = (float)d->iC4 / (float)d->i3C;
        if (1.0f < r) {
            r = 1.0f;
        }
        return r;
    }
    if (d->iBC < 0) {
        if (d->i88 != 0) {
            if (d->i8C < d->i88) {
                if (cur != 0) {
                    *cur = d->i8C;
                    *max = d->i88;
                }
                return (float)d->i8C / (float)d->i88;
            }
            if (cur != 0) {
                *cur = d->iC4;
                *max = d->iC0;
            }
            r = (float)d->iC4 / (float)d->iC0;
            if (0.0f < d->f38) {
                if (cur != 0) {
                    *cur *= d->f38;
                    *max *= d->f38;
                    if (*max < *cur) {
                        *cur = *max;
                    }
                }
                return r / d->f38;
            }
            return r;
        }
        if (!flag) {
            return -1.0f;
        }
    }
    if (flag) {
        if (cur != 0) {
            *cur = d->iC4;
            *max = d->iC0;
        }
        r = (float)d->iC4 / (float)d->iC0;
    } else {
        if (cur != 0) {
            *cur = d->iC4;
            *max = d->iBC;
        }
        r = (float)d->iC4 / (float)d->iBC;
    }
    if (0.0f < d->f38) {
        if (cur != 0) {
            *cur *= d->f38;
            *max *= d->f38;
            if (*max < *cur) {
                *cur = *max;
            }
        }
        return r / d->f38;
    }
    return r;
}
/* localdecomp:end func_003B4480 */
