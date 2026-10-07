#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003B05C0();
extern void func_003B0F78();
extern void func_003B1168();
extern s32 func_003B0320();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B0260 */
extern void func_003B0620(s32 *);
extern s32 D_001DA138[];

void func_003B0260(void) {
    func_003B0620((s32 *)D_001DA138[0]);
}
/* localdecomp:end func_003B0260 */

/* localdecomp:start func_003B0288 */
extern s32 func_0013D080();
typedef struct { s32 f0; s32 f4; u8 pad8[0x28]; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C; s32 f50; u8 pad54[4]; s32 f58; s32 f5C; } S_3AAAC8;
s32 func_003B0288(S_3AAAC8 *p, s32 a, s32 b, s32 c) {
    s32 r;
    p->f34 = a;
    p->f40 = b;
    p->f0 = 0;
    p->f4 = c;
    p->f30 = 0;
    p->f38 = 0;
    p->f3C = 0;
    p->f44 = 0;
    p->f50 = 0;
    p->f58 = 0;
    p->f5C = 0;
    if (c == 2) p->f4C = 0x6000;
    else if (c == 3) p->f4C = 0x400;
    else p->f4C = 0xC000;
    r = func_0013D080(p->f4C, 0x1000, 0x400, 0, 2, p->f4);
    p->f48 = r;
    if (r < 0) return 0;
    return 1;
}
/* localdecomp:end func_003B0288 */

/* localdecomp:start func_003B0320 */
extern void func_13D0F8();
 
s32 func_003B0320(void) {
    func_13D0F8();
    return 1;
}
/* localdecomp:end func_003B0320 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B0340);

/* localdecomp:start func_003B0348 */
extern void func_0013D120(s32, s32, s32, s32, s32);
typedef struct { s32 f0, f4; s32 f8, fC, f10; s32 f14, f18; u8 p1C[0x2C]; s32 f48, f4C; u8 p50[0xC]; s32 f5C; } T;
void func_003B0348(T *a) {
    if (a->f4 != 3) {
        func_0013D120(a->f48, (a->f4C / 1024) * 1024, a->f48 + a->f5C, 0, 0);
    } else {
        func_0013D120(a->f48, (a->f4C / 1024) * 1024, a->f5C, a->f14, a->f18);
    }
    a->f0 = 2;
}
/* localdecomp:end func_003B0348 */

/* localdecomp:start func_003B03E8 */
extern void func_0013D0C0(s32 *);
void func_003B03E8(s32 *p) {
    func_0013D0C0(p);
    p[0] = 0;
    p[0x30 / 4] = 0;
    p[0x38 / 4] = 0;
    p[0x3C / 4] = 0;
    p[0x44 / 4] = 0;
    p[0x50 / 4] = 0;
    p[0x58 / 4] = 0;
    p[0x5C / 4] = 0;
}
/* localdecomp:end func_003B03E8 */

/* localdecomp:start func_003B0430 */
typedef struct { s32 f0; s32 f4; u8 pad8[0x28]; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } B_3AAC70;
void func_003B0430(B_3AAC70 *b, s32 *o1, s32 *o2, s32 *o3, s32 *o4) {
    s32 lo, hi, v, r;
    if (b->f0 == 0) {
        if (b->f4 != 4) {
            *o1 = (s32)((u8 *)b + 8 + b->f30);
            *o2 = 0x28 - b->f30;
            *o3 = b->f34;
            *o4 = b->f40;
        } else {
            *o1 = b->f34;
            *o2 = b->f40;
            *o3 = 0;
            *o4 = 0;
        }
    } else {
        v = b->f40;
        lo = b->f3C;
        hi = b->f38;
        r = v - lo;
        if (v - hi >= r) {
            *o1 = b->f34 + hi;
            *o2 = r;
            *o3 = 0;
            *o4 = 0;
        } else {
            *o1 = b->f34 + hi;
            *o2 = b->f40 - b->f38;
            *o3 = b->f34;
            *o4 = r - (b->f40 - b->f38);
        }
    }
}
/* localdecomp:end func_003B0430 */

/* localdecomp:start func_003B0500 */
void func_003B0500(void *arg0, s32 arg1) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_8;

    var_8 = arg1;
    if ((*(s32 *)((u8 *)arg0 + 0)) == 0) {
        if ((*(s32 *)((u8 *)arg0 + 4)) != 4) {
            temp_4 = (*(s32 *)((u8 *)arg0 + 0x30));
            temp_2 = 0x28 - temp_4;
            temp_2_2 = (temp_2 >= var_8) ? var_8 : temp_2;
            temp_4_2 = temp_4 + temp_2_2;
            (*(s32 *)((u8 *)arg0 + 0x30)) = temp_4_2;
            if (temp_4_2 >= 0x28) {
                (*(s32 *)((u8 *)arg0 + 0)) = 1;
            }
            var_8 -= temp_2_2;
        } else {
            (*(s32 *)((u8 *)arg0 + 0)) = 1;
        }
    }
    if ((*(s32 *)((u8 *)arg0 + 4)) == 3) {
        (*(s32 *)((u8 *)arg0 + 0x40)) = ((*(s32 *)((u8 *)arg0 + 0x40)) / 256) * 256;
    }
    (*(s32 *)((u8 *)arg0 + 0x3C)) = (*(s32 *)((u8 *)arg0 + 0x3C)) + var_8;
    (*(s32 *)((u8 *)arg0 + 0x44)) = (*(s32 *)((u8 *)arg0 + 0x44)) + var_8;
    (*(s32 *)((u8 *)arg0 + 0x38)) = ((*(s32 *)((u8 *)arg0 + 0x38)) + var_8) % (*(s32 *)((u8 *)arg0 + 0x40));
}
/* localdecomp:end func_003B0500 */

/* localdecomp:start func_003B05C0 */
s32 func_003B05C0(u8 *p) {
    switch (*(s32 *)(p + 4)) {
    case 4:
    case 2:
        return *(s32 *)(p + 0x50) >= *(s32 *)(p + 0x4C);
    case 3:
        return *(s32 *)(p + 0x50) >= 0x1000;
    default:
        return 1;
    }
}
/* localdecomp:end func_003B05C0 */

/* localdecomp:start func_003B0620 */
extern s32 func_003B0DC8(void);
extern void func_003B09E0(s32 *);
extern void func_003B0B68(s32 *);
void func_003B0620(s32 *p) {
    if (p[0] != 0) {
        s32 t = p[1];
        if (t == 4) func_003B0DC8();
        else if (t == 2) func_003B09E0(p);
        else if (t == 3) func_003B0B68(p);
    }
}
/* localdecomp:end func_003B0620 */

/* localdecomp:start func_003B0688 */
void func_003B0688(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, void *arg4, s32 arg5) {
    s32 temp_11;
    s32 temp_12;
    s32 temp_hi;

    temp_11 = (*(s32 *)((u8 *)arg4 + 0x4C));
    temp_12 = (*(s32 *)((u8 *)arg4 + 0x58));
    temp_hi = (((arg5 + temp_11) - temp_12) - 0x400) % temp_11;
    if ((u32)(arg5 - temp_12) < 0x400U) {
        *arg0 = (*(s32 *)((u8 *)arg4 + 0x48));
        *arg1 = 0;
        *arg2 = (*(s32 *)((u8 *)arg4 + 0x48));
        *arg3 = 0;
        return;
    }
    temp_hi = ((temp_hi / 1024) * 1024);
    if ((temp_11 - temp_12) >= temp_hi) {
        *arg0 = (*(s32 *)((u8 *)arg4 + 0x48)) + temp_12;
        *arg1 = temp_hi;
        *arg2 = 0;
        *arg3 = 0;
        return;
    }
    *arg0 = (*(s32 *)((u8 *)arg4 + 0x48)) + temp_12;
    *arg1 = (*(s32 *)((u8 *)arg4 + 0x4C)) - (*(s32 *)((u8 *)arg4 + 0x58));
    *arg2 = (*(s32 *)((u8 *)arg4 + 0x48));
    *arg3 = temp_hi - ((*(s32 *)((u8 *)arg4 + 0x4C)) - (*(s32 *)((u8 *)arg4 + 0x58)));
}
/* localdecomp:end func_003B0688 */

/* localdecomp:start func_003B0748 */
extern s32 func_003B08C0();
s32 func_003B0748(void *ctx, s32 p, s32 a, s32 q, s32 d, s32 r, s32 b, s32 s, s32 c) {
    s32 over;
    s32 len;
    if (a + d < b + c) {
        over = b + c - (a + d);
        if (c <= over) {
            b -= over - c;
            c = 0;
        } else {
            c -= over;
        }
    }
    if (a <= b) {
        func_003B08C0(ctx, p, r, a);
        func_003B08C0(ctx, q, r + a, b - a);
        func_003B08C0(ctx, q + b - a, s, c);
    } else if ((len = a - b) <= c) {
        func_003B08C0(ctx, p, r, b);
        func_003B08C0(ctx, p + b, s, len);
        func_003B08C0(ctx, q, s + a - b, c - len);
    } else {
        func_003B08C0(ctx, p, r, b);
        func_003B08C0(ctx, p + b, s, c);
    }
    return b + c;
}
/* localdecomp:end func_003B0748 */

/* localdecomp:start func_003B08C0 */
extern void func_0011F0A0(s32);
extern s32 func_0011F1E0(s32 *, s32);
s32 func_003B08C0(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s[4];
    s32 r;
    if (a3 <= 0) return 0;
    func_0011F0A0(0);
    s[0] = a2; s[1] = a1; s[2] = a3; s[3] = 0;
    do { r = func_0011F1E0(s, 1); __asm__ volatile("nop
	nop"); } while (r == 0);
    return a3;
}
/* localdecomp:end func_003B08C0 */

/* localdecomp:start func_003B0940 */
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern void func_13D180();
void func_003B0940(u8 *o, s32 a, s32 b, s32 c) {
    s32 s[4];
    s32 h;
    func_11F0A0(0);
    s[0] = a;
    s[1] = *(s32 *)(o + 0x48);
    s[2] = b;
    s[3] = 0;
    do {
        h = func_11F1E0(s, 1);
    } while (h == 0);
    do {
    } while (func_11F1C0(h) >= 0);
    func_13D180(b, c);
}
/* localdecomp:end func_003B0940 */

/* localdecomp:start func_003B09E0 */
typedef struct { s32 x0; u8 p4[0x30]; s32 x34; s32 x38; s32 x3C; s32 x40; s32 x44; s32 x48; s32 x4C; s32 x50; s32 x54; s32 x58; } S_3AB220;
extern u32 func_13D158();
void func_003B09E0(s32 *arg0) {
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
        t = func_13D158() & 0xFFFFFF;
        func_003B0688(&s0, &s1, &s2, &s3, o, t - o->x48);
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
        n = func_003B0748(o, s0, s1, s2, s3, pos, len, base, rest);
    }
    o->x3C -= n;
    o->x50 += n;
    o->x58 = (o->x58 + n) % o->x4C;
}
/* localdecomp:end func_003B09E0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B0B68);

/* localdecomp:start func_003B0DC8 */
s32 func_003B0DC8(void) {
}
/* localdecomp:end func_003B0DC8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B0DD0);

ASM_FUNC("asm/boot_elf/handwritten", func_003B0F78);

ASM_FUNC("asm/boot_elf/handwritten", func_003B1168);

/* localdecomp:start func_003B11A8 */
extern s32 func_12C908(s32);
extern s32 D_001D5520;
extern volatile s32 D_001DA150_003B11A8[];
extern volatile s32 D_001DA154[];
void func_003B11A8(s32 a) {
    while (func_12C908(0) == a && D_001D5520 == 0) {
    }
    D_001DA150_003B11A8[0] = 1;
    D_001DA154[0] = 0;
}
/* localdecomp:end func_003B11A8 */

/* localdecomp:start func_003B11F8 */
extern s32 D_001DA150[];

void func_003B11F8(void) {
    D_001DA150[0] = 0;
}
/* localdecomp:end func_003B11F8 */
