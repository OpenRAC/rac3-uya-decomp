#include "common.h"

typedef int s128_3A7C18 __attribute__((mode(TI)));

typedef struct {
    s128_3A7C18 q0;
    u8 *parent;
    f32 f14;
    int f18;
    f32 f1C;
    f32 f20;
} V_3A7C18;

extern u8 *func_00435E70(int, int);
extern f32 func_00440978(void);
extern void func_0040C638(void *, void *);

u8 *func_003A7C18(u8 *parent, s128_3A7C18 *a, s128_3A7C18 *pos, int n, f32 f) {
    u8 *m = func_00435E70(6390, 128);
    V_3A7C18 *pv;

    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        pv = *(V_3A7C18 **)(m + 0x68);
        *(long *)(m + 0x38) = *(long *)(parent + 0x38);
        *(s128_3A7C18 *)(m + 0x10) = *pos;
        pv->q0 = *a;
        pv->f14 = f;
        pv->parent = parent;
        pv->f20 = func_00440978();
        *(u16 *)(m + 0x34) |= 0x208;
        *(f32 *)((u8 *)pv + 0xC) = (f32)n;
        *(s128_3A7C18 *)(m + 0xF0) = *(s128_3A7C18 *)(parent + 0xF0);
        func_0040C638(m + 0xC0, m + 0xF0);
        m[0x23] = 0x80;
        *(u16 *)(m + 0x34) |= 0x100;
        pv->f18 = 0;
    }
    return m;
}
