#include "common.h"

/* localdecomp:start func_0061ADC8 */
typedef struct O_61ADC8 {
    u32 id;
    s32 owner;
    s32 active;
    struct O_61ADC8 *next;
    struct O_61ADC8 *prev;
} O_61ADC8;

extern O_61ADC8 *D_0024CF40[8];
extern O_61ADC8 *D_0024CF60[8];
extern s32 D_0024D85C;
extern void func_0061BB00(O_61ADC8 *);

O_61ADC8 *func_0061ADC8(O_61ADC8 *o) {
    O_61ADC8 *nx = o->next;
    u32 k;
    O_61ADC8 **used;
    O_61ADC8 **freel;

    k = ((u8 *)o)[3] & 0xF;
    freel = &D_0024CF60[k];
    used = &D_0024CF40[k];
    o->active = 2;
    if (D_0024D85C != -1 && o->owner == D_0024D85C) {
        func_0061BB00(o);
    }
    if (o->prev != 0) {
        o->prev->next = o->next;
    }
    if (o->next != 0) {
        o->next->prev = o->prev;
    }
    if (*used == o) {
        *used = o->next;
    }
    o->prev = 0;
    o->next = *freel;
    if (*freel != 0) {
        (*freel)->prev = o;
    }
    *freel = o;
    return nx;
}
/* localdecomp:end func_0061ADC8 */
