#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct S_3A2A38q { u8 pad0[0x20]; s128 x20; } S_3A2A38q;
typedef struct S_3A2A38m {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x68 - 0x21];
    void *x68;
    u8 pad6c[0x96 - 0x6C];
    u16 x96;
    s32 x98;
    u8 pad9c[0xAA - 0x9C];
    s16 xAA;
    u8 padac[0xB8 - 0xAC];
    struct S_3A2A38m *xB8;
} S_3A2A38m;
typedef struct S_3A2A38v {
    u8 pad0[0x250];
    u8 x250[0x2E0 - 0x250];
    u8 x2E0[4];
    u8 x2E4[0xC];
    S_3A2A38m *x2F0[2];
    u8 pad2f8[8];
    u8 x300[0xF0];
    S_3A2A38m *x3F0[8];
} S_3A2A38v;

extern void func_00437698(S_3A2A38m *, s32, s128 *);
extern void func_00439610(S_3A2A38m *);
extern void func_0044B5C8(S_3A2A38m *, void *, s32, f32, f32);
extern void func_0040BA90(void *);
extern void func_0040BAC0(void *);
extern void func_0044EB78(S_3A2A38m *, void *, s32, s32, f32);

void func_003A2A38(S_3A2A38m *m) {
    S_3A2A38v *v = m->x68;
    S_3A2A38m *o;
    S_3A2A38q *q;
    s128 buf;
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        o = v->x2F0[i];
        if (o != 0 && o->xAA == 6457 && o->xB8 == m && o->x20 != 254 && o->x20 != 253) {
            q = o->x68;
            if (i != 0) {
                func_00437698(m, 3, &buf);
            } else {
                func_00437698(m, 2, &buf);
            }
            q->x20 = buf;
        } else {
            v->x2F0[i] = 0;
        }
    }
    for (j = 0; j < 8; j++) {
        if (v->x3F0[j] != 0) {
            v->x3F0[j]->x98 = 0;
            func_00439610(v->x3F0[j]);
        }
    }
    func_0044B5C8(m, v->x300, 4, 0.03f, 0.3f);
    func_0040BA90(v->x2E0);
    func_0040BAC0(v->x2E4);
    if (m->x96 < 0xFFFF) {
        m->x96++;
    }
    func_0044EB78(m, v->x250, 5, 1, 2.5f);
}
