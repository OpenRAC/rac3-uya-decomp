#include "common.h"

typedef struct {
    u8 pad[288];
    void *items[10];
    s32 count;
    s32 active;
} S_44B4B8;

extern void func_00436220(void *);

void func_0044B4B8(S_44B4B8 *p) {
    s32 i;

    if (p->active != 0) {
        for (i = 0; i < p->count; i++) {
            if (p->items[i] != 0) {
                func_00436220(p->items[i]);
                p->items[i] = 0;
            }
        }
        p->active = 0;
    }
}
