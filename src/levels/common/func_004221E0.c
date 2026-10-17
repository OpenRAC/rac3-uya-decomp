#include "common.h"
typedef int u128_3CB5B0 __attribute__((mode(TI)));

typedef struct { u8 p0[0x10]; u128_3CB5B0 q10; } B_3CB5B0;
typedef struct { u8 p0[0x10]; s32 state; u8 p1[0xC]; u128_3CB5B0 q20; } E_3CB5B0;
extern B_3CB5B0 D_001F1BC0[];
extern E_3CB5B0 D_001F1CC0[];
extern void func_004221E0(void *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3CB748;
typedef struct { s16 h0, h2, h4, h6, h8, hA; u32 w; u8 pad[0x20]; } S_3CB748;
extern u32 func_004B4578(u32, u32, s32, void *);
extern u32 func_004A4330(u32, u32, s32, void *);
extern u32 func_004AF350(u32, u32, s32, void *);
void func_004221E0(void *arg) {
    s32 idx = (s32)arg;
    S_3CB748 *s = (S_3CB748 *)&D_001F1CC0[idx];
    u8 *b = (u8 *)&D_001F1BC0[idx];
    u8 *q = b + 0x10;
    u32 cur = s->w;
    u32 end = cur + 0x400;
    s32 x;
    V_3CB748 v = *(V_3CB748 *)(b + 0x10);
    if (cur < end) {
        s->h0 = 0;
        cur = func_004B4578(cur, end, idx, q);
        x = (s32)(cur - s->w) >> 1;
        s->h2 = x;
        if (cur < end) {
            s->h4 = x;
            cur = func_004A4330(cur, end, idx, q);
            x = (s32)(cur - s->w) >> 1;
            s->h6 = x - (u16)s->h4;
            if (cur < end) {
                s->h8 = x;
                s->hA = ((s32)(func_004AF350(cur, end, idx, q) - s->w) >> 1) - (u16)s->h8;
            }
        }
    }
}
