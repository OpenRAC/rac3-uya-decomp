#include "common.h"

typedef int s128_003ED620 __attribute__((mode(TI)));

typedef struct {
    u8 pad[128];
} E_003ED620;

typedef struct {
    s32 f0;
    s32 f4;
} H_003ED620;

typedef struct {
    u8 pad[8];
    H_003ED620 *h;
} Obj_003ED620;

extern s128_003ED620 D_001E2A40[];
extern u8 D_001A3190[];
extern E_003ED620 D_001A30B0[];
extern s32 D_001E2F10[];
extern s32 func_004A74A0(s32, s32, void *, s32);
extern void func_004A6E88(s32);

void func_003ED620(Obj_003ED620 *obj) {
    H_003ED620 *h = obj->h;
    u8 *e;
    s32 on;

    if (h->f4 != -1) {
        *(s128_003ED620 *)(D_001A3190 + (h->f4 << 7)) = D_001E2A40[0];
    }
    e = (u8 *)&D_001A30B0[h->f4];
    on = 0;
    if (*(void **)(e + 256) == obj) {
        on = e[208] != 0;
    }
    if (D_001E2F10[0] != 0) {
        if (!on) {
            h->f4 = func_004A74A0(h->f0, 21, obj, 1024);
        }
    } else if (on) {
        func_004A6E88(h->f4);
        h->f4 = -1;
    }
}
