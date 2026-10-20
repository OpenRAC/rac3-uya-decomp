#include "common.h"

typedef int s128_2FB638 __attribute__((mode(TI)));

typedef struct {
    s128_2FB638 q0;
    f32 f10;
    f32 f14;
    s16 h18;
    s16 h1A;
    f32 f1C;
    int f20;
    int f24;
} V_2FB638;

extern u8 *func_00435E70(int, int);
extern void func_00438908(void *, int, int, int);
extern f32 func_004408C0(f32, f32);
extern void func_00439610(void *);

u8 *func_002FB638(s128_2FB638 *pos, s128_2FB638 *q, int h, int mode, int bit, int x) {
    u8 *m = func_00435E70(0x7A, 0x80);
    V_2FB638 *pv;

    if (m != 0) {
        pv = *(V_2FB638 **)(m + 0x68);
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x23] = 0x80;
        pv->f24 = x;
        func_00438908(m, 0x7F, 0x7F, 0x7F);
        *(s128_2FB638 *)(m + 0x10) = *pos;
        pv->q0 = *q;
        pv->f10 = func_004408C0(0.104719765f, 0.20943953f);
        pv->f14 = func_004408C0(0.104719765f, 0.20943953f);
        pv->h18 = h;
        pv->h1A = h;
        if (mode == 2) {
            mode = 1;
            pv->f20 = 1;
        }
        if (mode == 0) {
            *(f32 *)(m + 0x2C) *= func_004408C0(0.5f, 0.75f);
        }
        pv->f1C = *(f32 *)(m + 0x2C);
        m[0xBC] = mode | (bit << 1);
        func_00439610(m);
    }
    return m;
}
