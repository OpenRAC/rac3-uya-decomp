#include "common.h"
typedef int u128_003E94A0 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E94A0;
extern Slot_003E94A0 D_001E2AC0[];
extern u8 *func_003F1368(s32, s32);
void func_003E94A0(s32 a0, u128_003E94A0 *a1) {
    u8 *o = (&D_001E2AC0[a0])->o;
    u8 *r;
    if (*(s16 *)(o + 134) != 5) {
        r = func_003F1368(a0, 5);
    } else {
        r = o;
    }
    *(u128_003E94A0 *)(*(u8 **)(r + 112) + 128) = *a1;
}
