#include "common.h"

typedef void (*F_66B4A0)(s32, s32);

typedef struct {
    u8 pad0[0xC];
    F_66B4A0 fnC;
} S_66B4A0c;

typedef struct {
    u8 pad0[0x18];
    s32 w18;
} S_66B4A0b;

typedef struct {
    s32 w0;
    u8 pad4[0x10 - 0x4];
    s32 w10;
    F_66B4A0 fn14;
    s32 w18;
} S_66B4A0;

extern S_66B4A0b *func_0061AA60(s32 a0);
extern S_66B4A0c *func_005BF058(s32 a0);

void func_0066B4A0(S_66B4A0 *a0) {
    S_66B4A0c *r;
    a0->w10 = func_0061AA60(a0->w0)->w18;
    r = func_005BF058(a0->w10);
    if (r != 0) {
        a0->fn14 = r->fnC;
        a0->fn14(a0->w10, 1);
    } else {
        a0->fn14 = 0;
    }
    a0->w18 = 0;
}
