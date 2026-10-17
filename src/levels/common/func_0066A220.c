#include "common.h"
typedef struct {
    u8 p0[0x18]; s32 w18; s16 h1C; u8 p1e[2]; s32 w20; s32 w24; s32 w28; u8 b2C; u8 p2d[3];
    s32 w30; s32 w34; s32 w38; s32 w3C; s32 w40; s32 w44; s32 w48; s32 w4C; u8 b50; u8 b51;
} S_66A220;
void func_0066A220(S_66A220 *s) {
    s->b51 = 1;
    s->w18 = 0;
    s->w20 = 0;
    s->h1C = 0;
    s->w24 = -1;
    s->w28 = -1;
    s->b2C = 0;
    s->w30 = 0;
    s->w34 = -1;
    s->w48 = -1;
    s->w38 = -1;
    s->w44 = -1;
    s->w3C = -1;
    s->w40 = -1;
    s->b50 = 0;
    s->w4C = -1;
}
