#include "common.h"

extern void func_004CFB28(s32 *);

typedef struct { s32 x0; u8 p4[0x30]; s32 x34; s32 x38; s32 x3C; s32 x40; s32 x44; s32 x48; s32 x4C; s32 x50; s32 x54; s32 x58; } S_3AB220;
extern u32 func_0013D158();
void func_004CFB28(s32 *arg0) {
    S_3AB220 *o = (S_3AB220 *)arg0;
    s32 s0, s1, s2, s3;
    s32 n = 0;
    s32 base, pos;
    s32 v, sz, mod, len, rest;
    s32 t;
    switch (o->x0) {
    case 1:
        s0 = o->x48 + o->x50 % o->x4C;
        s1 = o->x4C - o->x50;
        s2 = 0;
        s3 = 0;
        break;
    case 2:
        t = func_0013D158() & 0xFFFFFF;
        func_004CF7D0(&s0, &s1, &s2, &s3, o, t - o->x48);
        break;
    case 3:
        return;
    }
    v = o->x3C;
    sz = v / 1024 * 1024;
    mod = (o->x38 - v + o->x40) % o->x40;
    len = o->x40 - mod;
    if (sz < len) len = sz;
    rest = sz - len;
    base = o->x34;
    pos = base + mod;
    if (s1 + s3 >= 0x400 && len + rest >= 0x400) {
        n = func_004CF890(o, s0, s1, s2, s3, pos, len, base, rest);
    }
    o->x3C -= n;
    o->x50 += n;
    o->x58 = (o->x58 + n) % o->x4C;
}
