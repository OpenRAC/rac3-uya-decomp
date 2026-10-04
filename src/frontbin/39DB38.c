#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039DB38 */
typedef struct {
    u8 pad0[0x100];
    f32 cur[16];
    f32 prev[16];
    u8 pad180[0xE];
    s16 head;
    s32 cnt;
    u8 pad194[0xC];
    s32 x1A0;
    s32 x1A4;
    s32 x1A8;
    s32 x1AC;
    s32 x1B0;
    s32 x1B4;
    s32 x1B8;
    s32 x1BC;
    s32 x1C0;
    s32 x1C4;
    s32 x1C8;
    s32 x1CC;
    s32 x1D0;
    s32 x1D4;
    s32 x1D8;
    u8 pad1DC[4];
    s32 hist[30];
    f32 ang[30];
    f32 mag[30];
    s32 x348;
    s32 idx;
    s32 count;
    s32 btn[7];
    s32 btn2[7];
    f32 an[7][16];
    u8 pad54C;
    u8 x54D;
    u8 x54E;
    u8 x54F;
    u8 pad550[0x18];
    s32 delay;
} Pad_39DB38;

extern s32 D_001D5B94;
extern u8 D_001D5477[];
extern f32 func_003887A0(f32 *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);

#define SWAP_LR(x) \
    if ((x) & 0x8000) { (x) = ((x) & ~0x8000) | 0x2000; } \
    else if ((x) & 0x2000) { (x) = ((x) & ~0x2000) | 0x8000; }

void func_0039DB38(Pad_39DB38 *o, u8 *raw, s32 len) {
    f32 v2[2];
    s32 i, n, j, v, b;
    f32 m, a;
    u8 c, r;
    s32 q;
    s32 b2;

    o->btn[o->idx] = ((raw[2] << 8) | raw[3]) ^ 0xFFFF;
    o->btn2[o->idx] = o->btn[o->idx];
    for (i = 0; i < 16; i++) {
        o->an[o->idx][i] = 0.0f;
    }
    if (len >= 8) {
        for (i = 0; i < 4; i++) {
            v = raw[i + 4] - 0x7F;
            if (v < 0) {
                v = -v;
            }
            if (v >= 0x30) {
                o->an[o->idx][i] = (f32)(v - 0x30) / 76.0f;
                if (o->an[o->idx][i] > 1.0f) {
                    o->an[o->idx][i] = 1.0f;
                }
                if (raw[i + 4] < 0x7F) {
                    o->an[o->idx][i] = -o->an[o->idx][i];
                }
            }
        }
    }
    if (len >= 0x14) {
        for (i = 4; i < 16; i++) {
            o->an[o->idx][i] = raw[i + 4] * 0.003921569f;
        }
    }
    if (*(u8 *)0x1D5477) {
        o->an[o->idx][2] = -o->an[o->idx][2];
        o->an[o->idx][0] = -o->an[o->idx][0];
        if (o->btn[o->idx] & 0x8000) {
            o->btn[o->idx] &= ~0x8000;
            o->btn[o->idx] |= 0x2000;
        } else if (o->btn[o->idx] & 0x2000) {
            o->btn[o->idx] &= ~0x2000;
            o->btn[o->idx] |= 0x8000;
        }
        o->btn2[o->idx] = o->btn[o->idx];
    }
    if (D_001D5B94 == 7) {
        if (o->an[o->idx][2] < 0.0f) {
            o->btn[o->idx] |= 0x8000;
        }
        if (o->an[o->idx][2] > 0.0f) {
            o->btn[o->idx] |= 0x2000;
        }
        if (o->an[o->idx][3] < 0.0f) {
            o->btn[o->idx] |= 0x1000;
        }
        if (o->an[o->idx][3] > 0.0f) {
            o->btn[o->idx] |= 0x4000;
        }
    }
    if (o->count >= o->delay) {
        j = (o->idx - o->delay + 7) % 7;
        o->x1A0 = o->btn[j];
        o->x1B0 = o->btn2[j];
        for (i = 0; i < 16; i++) {
            o->cur[i] = o->an[(o->idx - o->delay + 7) % 7][i];
        }
    } else {
        o->x1A0 = o->x1AC;
        o->x1B0 = o->x1BC;
    }
    o->idx = (o->idx + 1) % 7;
    if (++o->count > o->delay) {
        o->count = o->delay;
    }
    for (i = 0; i < 16; i++) {
        o->prev[i] = o->cur[i];
    }
    if (o->cur[2] != 0.0f || o->cur[3] != 0.0f) {
        o->x1D8 = 1;
    } else {
        o->x1D8 = 0;
    }
    if (o->cur[2] < 0.0f) {
        o->x1A0 |= 0x8000;
    }
    if (o->cur[2] > 0.0f) {
        o->x1A0 |= 0x2000;
    }
    if (o->cur[3] < 0.0f) {
        o->x1A0 |= 0x1000;
    }
    if (o->cur[3] > 0.0f) {
        o->x1A0 |= 0x4000;
    }
    b = o->x1A0;
    o->x1A4 = ~o->x1AC & b;
    o->x1D4 = (b & 0xF000) == 0;
    o->x1D0 = b == 0;
    o->x1A8 = ~b & o->x1AC;
    o->x1B4 = ~o->x1AC & o->x1B0;
    o->x1B8 = ~b & o->x1BC;
    o->x1C4 = ~o->x1AC & b;
    o->x1C8 = ~b & o->x1AC;
    o->x1C0 = b;
    o->x348 = b;
    if (*(u8 *)0x1D5477) {
        o->prev[2] = -o->prev[2];
        o->prev[0] = -o->prev[0];
        SWAP_LR(o->x1C0);
        SWAP_LR(o->x1C4);
        SWAP_LR(o->x1C8);
    }
    if (o->x1CC == 1) {
        o->x1A0 &= ~0x5030;
        o->x1A4 &= ~0x5030;
        o->x1A8 &= ~0x5030;
        o->cur[0] = 0.0f;
        o->cur[1] = 0.0f;
        o->x1CC = 0;
    }
    if (o->x1CC == 2) {
        o->x1A0 &= 0x900;
        o->x1A4 &= 0x900;
        o->x1A8 &= 0x900;
        o->x1B0 &= 0x900;
        o->x1D4 = 1;
        o->cur[2] = 0.0f;
        o->cur[3] = 0.0f;
        o->x1CC = 0;
    }
    v2[0] = o->cur[2];
    v2[1] = o->cur[3];
    m = func_003887A0(v2);
    a = func_00388A28(v2[0], v2[1]);
    o->mag[o->head] = m;
    o->ang[o->head] = a;
    if (m > 0.9f) {
        for (q = 1; q < 4; q++) {
            j = (o->head - q + 30) % 30;
            if (o->mag[j] > 0.9f) {
                break;
            }
            if (o->mag[j] < 0.25f) {
                o->x1A4 |= 0x10000;
                break;
            }
        }
        if (!(o->x1A4 & 0x10000)) {
            for (n = 1; n < 5; n++) {
                if (func_00389468(o->ang[(o->head - n + 30) % 30], a) > 0.959931076f) {
                    o->x1A4 |= 0x10000;
                    break;
                }
            }
        }
    }
    if (D_001D5B94 != -1) {
        o->hist[o->head] = o->x1A4;
        o->head = (o->head + 1) % 30;
        if (++o->cnt > 30) {
            o->cnt = 30;
        }
    }
    r = o->x54E;
    if (r) {
        b2 = o->x1A0;
        if (b2 != 0 && b2 == o->x1AC) {
            c = --o->x54F;
            if (c == 0 || c == 0xFF) {
                o->x54F = r;
                o->x1A4 = b2;
            }
        } else {
            o->x54F = o->x54D;
        }
    }
}
/* localdecomp:end func_0039DB38 */

LINKER_REMNANT("asm/remnants", func_0039E4A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E4B0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318530);

/* localdecomp:start func_0039E8E0 */
typedef struct { u8 pad[0x5C0]; } S_39E8E0;
extern S_39E8E0 D_001CD0C0[];
void func_0039E4B0(S_39E8E0 *);
void func_0039E8E0(void) {
    s32 i;
    for (i = 0; i < 8; i++) func_0039E4B0(&D_001CD0C0[i]);
}
/* localdecomp:end func_0039E8E0 */

/* localdecomp:start func_0039E928 */
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_143950;
extern u8 D_001A71C4[];
s32 func_0039E928(s32 a, s32 i) {
    if (D_143950.arr[i] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
/* localdecomp:end func_0039E928 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039E9A0);

LINKER_REMNANT("asm/remnants", func_0039EA58);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EA60);

/* localdecomp:start func_0039EB38 */
extern s32 D_00222480[];
extern f32 func_003887C8(void *, void *);
extern void func_0039EA60(f32 *, void *, f32, f32, f32);
typedef struct { s32 pad; f32 *q; } S_39EB38;
void func_0039EB38(S_39EB38 *p, void *a, void *b, void *c) {
    f32 f;
    if (b == 0) b = D_00222480;
    f = func_003887C8(a, b);
    func_0039EA60(p->q, c, f, p->q[0], p->q[1]);
}
/* localdecomp:end func_0039EB38 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039EB98);

INCLUDE_ASM("asm/nonmatchings/text", func_0039ED50);

/* localdecomp:start func_0039EE40 */
extern s32 D_001685EC[];
extern void func_0013CFC0(s32, s32);
void func_0039EE40(void) {
    func_0013CFC0(2, D_001685EC[0]);
}
/* localdecomp:end func_0039EE40 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039EE68);

LINKER_REMNANT("asm/remnants", func_0039FAF8);

/* localdecomp:start func_0039FB08 */
extern u8 D_1A30B0[];
void func_0039FB08(u32 i) {
    if (i < 52) {
        u8 *e = D_1A30B0 + i * 128;
        u8 s = e[0xD0];
        if (s == 7) {
            *(s32 *)(e + 0xDC) = 0;
            *(s32 *)(e + 0x100) = 0;
            e[0xD0] = 0;
            return;
        }
        if (s != 0 && s != 6) e[0xD0] = 4;
    }
}
/* localdecomp:end func_0039FB08 */

/* localdecomp:start func_0039FB60 */
typedef struct { u8 pad[0x1200]; s32 x1200; u8 pad2[0x25C0 - 0x1204]; s32 x25C0; } S_39FB60;
typedef struct { u8 pad[0x50]; u8 b50; u8 pad2[0x2F]; } S2_39FB60;
extern S_39FB60 D_001A4BE0[];
extern S2_39FB60 D_001A30B0[];
s32 func_0039FB60(s32 id) {
    s32 n = 0x34;
    s32 i;
    if (id == 0 || (D_001A4BE0[0].x25C0 != id && D_001A4BE0[0].x1200 != id)) n = 0x2A;
    for (i = 0; i < n; i++) {
        if (D_001A30B0[i + 1].b50 == 0) break;
    }
    if (i == n) return -1;
    return i;
}
/* localdecomp:end func_0039FB60 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039FBD8);

/* localdecomp:start func_0039FE80 */
typedef struct { u8 pad[0xD]; u8 bD; u8 pad2[0x1A]; s32 f28; } O_39FE80;
typedef struct { u8 pad[0x24]; O_39FE80 *o; } P_39FE80;
extern u8 D_1A30B0[];
extern s32 func_0039FBD8();
s32 func_0039FE80(s32 a, s32 b, P_39FE80 *p) {
    O_39FE80 *o;
    s32 r;
    u8 *e;
    if (p == 0) return -1;
    o = p->o;
    if (o == 0) return -1;
    if (o->f28 == 0) return -1;
    if (a >= o->bD) return -1;
    r = func_0039FBD8(o->f28 + a * 32, b, p, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = (s32)p;
        *(s16 *)(e + 0xCA) = a;
        *(s32 *)(e + 0x108) = -1;
    }
    return r;
}
/* localdecomp:end func_0039FE80 */

/* localdecomp:start func_0039FF28 */
extern s32 D_001D9DAC;
extern s32 D_001D5B9C;
extern u8 D_1A30B0[];
extern s32 func_0039FBD8();
s32 func_0039FF28(s32 a, s32 b, s32 c) {
    s32 r;
    u8 *e;
    if (D_001D9DAC == 0) return -1;
    if (a >= D_001D5B9C) return -1;
    r = func_0039FBD8(D_001D9DAC + a * 32, b, c, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = c;
        *(s16 *)(e + 0xCA) = a;
    }
    return r;
}
/* localdecomp:end func_0039FF28 */

LINKER_REMNANT("asm/remnants", func_0039FFB8);
