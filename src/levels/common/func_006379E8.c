#include "common.h"

typedef struct {
    s16 active;
    s16 type;
    s16 timer;
    s16 arg;
} Slot_6379E8;

typedef struct {
    u8 pad0[891];
    u8 b891;
    u8 pad1[9200 - 892];
    Slot_6379E8 slots[2];
} Self_6379E8;

extern s32 func_0058EFB8(s16 *timer);
extern void func_00637C98(Self_6379E8 *self, s32 a, s32 b, s32 c, s32 d);
extern void func_006377E8(Self_6379E8 *self, s32 type, s32 arg);

void func_006379E8(Self_6379E8 *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (func_0058EFB8(&self->slots[i].timer) == 2) {
            self->slots[i].active = 0;
            if (self->slots[i].type == 28) {
                func_00637C98(self, self->b891, 1, 1, 50);
            } else {
                func_006377E8(self, self->slots[i].type, self->slots[i].arg);
            }
        }
    }
}
