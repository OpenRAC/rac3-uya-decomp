#include "common.h"
typedef struct {
    s32 a;
    s32 pad4;
    s32 timer;
    s32 count;
    s32 pad[3];
} S_5BB350;
extern S_5BB350 D_00484160[];
void func_005BB350(void) {
    S_5BB350 *p;
    s32 i;
    for (i = 0; i < 8; i++) {
        p = &D_00484160[i];
        if (p->a == 0) {
            p->count++;
            if (p->count > 10) {
                p->count = 10;
            }
        } else {
            p->count = 0;
        }
        if (p->timer != 0) {
            p->timer--;
            if (p->timer == 0) {
                p->a = 0;
            }
        }
    }
}
