#include "common.h"

typedef struct { u8 b0; s8 s[3]; u16 h4; u8 p6[0xE]; s32 f14; u8 p18[0x48]; } S_4B7678;
extern S_4B7678 D_002393F0[];
extern u8 D_001A30B0[];
extern void func_004B6500(s32);

s32 func_004B7678(u32 handle) {
    u32 idx = handle >> 16;
    S_4B7678 *s = 0;
    s32 k;
    u8 *t;

    if (idx < 12) {
        S_4B7678 *e = &D_002393F0[idx];
        if (e->b0 != 0) {
            if (e->h4 == (handle & 0xFFFF)) {
                s = e;
            }
        }
    }
    if (s == 0) {
        return 0;
    }
    s->b0 = 0;
    k = s->s[0];
    if (k != -1) {
        t = D_001A30B0 + k * 128;
        if (*(s32 *)(t + 0xDC) == s->f14 && t[0xD0] != 0) {
            func_004B6500(k);
        }
    }
    s->s[0] = -1;
    k = s->s[1];
    if (k != -1) {
        t = D_001A30B0 + k * 128;
        if (*(s32 *)(t + 0xDC) == s->f14 && t[0xD0] != 0) {
            func_004B6500(k);
        }
    }
    s->s[1] = -1;
    k = s->s[2];
    if (k != -1) {
        t = D_001A30B0 + k * 128;
        if (*(s32 *)(t + 0xDC) == s->f14 && t[0xD0] != 0) {
            func_004B6500(k);
        }
    }
    s->s[2] = -1;
    return 1;
}
