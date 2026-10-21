#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003ADAC0);

/* localdecomp:start func_003AECC8 */
typedef struct { s32 (*fn)(u8 *); } Vt003AECC8;

extern s32 D_001D6694_3AECC8;
extern s16 D_001A4DBC_3AECC8[];
extern u8 D_001E2AC0_3AECC8[];
extern u8 *D_001E009C_3AECC8;
extern s32 D_001E00D8_3AECC8;
extern u32 D_00142BA0_3AECC8[];
extern u8 *D_0021F740_3AECC8[];
extern s16 *D_0021DEA0_3AECC8[];

extern s32 func_003AF0D0_3AECC8(u8 *m);
extern f32 func_0040C018_3AECC8(void *a, void *b);
extern void func_00444188_3AECC8(u8 *m);
extern Vt003AECC8 *func_00438488_3AECC8(s32 a0, s32 a1, s32 a2);
extern s32 func_004B6C68_3AECC8(void);
extern s32 func_0044FCD0_3AECC8(u8 *m, u8 *a1, s32 a2, s32 a3, s32 t0);
extern void func_003AF958_3AECC8(u8 *m);
extern void func_0044CB08_3AECC8(u8 *m, u8 *o, s32 a2, s32 a3);
extern void func_004538E0_3AECC8(u8 *m, s32 a);
extern void func_004539A8_3AECC8(u8 *m, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 s0, s32 s1, f32 f12, f32 f13, f32 f14);

s32 func_003AECC8(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    s32 ok;
    u8 *p;
    s16 *q;
    s32 i;

    if (m[0x20] == 0) {
        if (func_003AF0D0_3AECC8(m) != 0) {
            return 1;
        }
    }
    if (D_001D6694_3AECC8 == 2) {
        D_001A4DBC_3AECC8[0] = 60;
    }
    if (m[0x31] != 0) {
        if (func_0040C018_3AECC8(D_001E2AC0_3AECC8, m + 0x10) < 576.0f) {
            func_00444188_3AECC8(m);
            m[0x6F] = 0x16;
        }
    }
    ok = 1;
    if (*(s32 *)(v + 0x354) != -1) {
        Vt003AECC8 *vt = func_00438488_3AECC8(0xF6E, 0, 4);
        if (vt == 0) {
            ok = 0;
        } else {
            u32 r = vt->fn(D_001E009C_3AECC8 + (*(s32 *)(v + 0x354) << 8));
            if ((D_00142BA0_3AECC8[r >> 2] & (1 << (r & 0x1F))) == 0) {
                ok = 0;
            } else if (func_004B6C68_3AECC8() == 0) {
                *(s32 *)(v + 0x354) = -1;
                *(s32 *)(v + 0x2F8) = 0;
            } else {
                ok = 0;
            }
        }
    }
    if (ok) {
        if (func_0044FCD0_3AECC8(m, v + 0x160, 0, 0, 0) != 0) {
            if (*(s16 *)(v + 0x66) < 5) {
                *(s16 *)(v + 0x66) += 1;
            }
        }
        if (v[0x3E] == 2) {
            func_003AF958_3AECC8(m);
        }
    } else {
        m[0xA8] = 0xFF;
        *(s16 *)(v + 0x198) = 0;
    }
    if (*(s32 *)(v + 0x348) != -1) {
        *(f32 *)(m + 0x18) = *(f32 *)(D_0021F740_3AECC8[*(s32 *)(v + 0x348)] + 0x18);
    }
    if (*(s32 *)(v + 0x2E0) != -1) {
        p = D_001E009C_3AECC8;
        p += *(s32 *)(v + 0x2E0) << 8;
        func_0044CB08_3AECC8(m, p, 1, 0);
        *(s32 *)(p + 0x98) = 0;
    }
    if (*(s32 *)(v + 0x2E4) != -1) {
        i = 0;
        for (q = D_0021DEA0_3AECC8[*(s32 *)(v + 0x2E4)];
             (*(s32 *)(v + 0x2E4) & 0xFF) != 0xFF && D_001E00D8_3AECC8 >= *(s32 *)(v + 0x2E4) && q != 0 &&
             (q[-1] >= 0 || q == D_0021DEA0_3AECC8[*(s32 *)(v + 0x2E4)]);
             q++) {
            p = D_001E009C_3AECC8 + ((*q & 0x7FFF) << 8);
            if (p == 0) {
                break;
            }
            if (*(s16 *)(p + 0xAA) == 0x16BD || *(s16 *)(p + 0xAA) == 0x16E4) {
                func_0044CB08_3AECC8(m, p, i + 2, 0);
                i++;
                *(s32 *)(p + 0x98) = 0;
            }
        }
    }
    if (v[0x5F] != 0) {
        func_004538E0_3AECC8(m, 5);
    } else {
        func_004538E0_3AECC8(m, 3);
    }
    if (v[0x5F] != 0) {
        if (m[0x95] == 0) {
            func_004539A8_3AECC8(m, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_004539A8_3AECC8(m, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        if (m[0x95] == 0) {
            func_004539A8_3AECC8(m, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_004539A8_3AECC8(m, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_003AECC8 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF0D0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF408);

/* localdecomp:start func_003AF490 */
/* This file's small data (.sdata, targets/veldin/data_split.txt): retail reads
   these through $gp, so they are defined here, not in another file. */
f32 D_001DE57C = 10.0f;
f32 D_001DE580 = 50.0f;
f32 D_001DE584 = 9.0f;
extern void func_0044B5C8(void *, void *, s32, f32, f32);
extern void func_0044B920(void *, void *, void *, f32, f32, f32);
extern void func_00402498(void *, void *);
extern void func_003AF748();
extern s32 D_001D6694;
void func_003AF490(u8 *o) {
    u8 *pv = *(u8 **)(o + 0x68);

    func_0044B5C8(o, pv + 0x240, 0, 0.03f, 0.3f);
    if (*(u16 *)(o + 0x96) < 0xFFFF) {
        *(u16 *)(o + 0x96) += 1;
    }
    func_0044B920(o, pv + 0x2D8, pv + 0x2DC, D_001DE584 * 0.017453292f,
                  D_001DE57C * 0.017453292f * 0.016666668f, D_001DE580 * 0.017453292f * 0.016666668f);
    if (D_001D6694 == 0 && o[0x31] != 0 && o[0x95] != 0) {
        func_00402498(func_003AF748, o);
    }
}
/* localdecomp:end func_003AF490 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF578);

/* localdecomp:start func_003AF630 */
typedef int Q __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 pad0[0x44]; u8 x44; u8 pad45[0x354 - 0x45]; s32 x354; } B_3AF630;
typedef struct { u8 pad0[0x68]; B_3AF630 *x68; } O_3AF630;
extern V4 D_001E2A40_3AF630;
extern void func_00437698_3AF630(void *, s32, void *);
extern void func_0040C0F0_3AF630(void *, void *, f32);
extern void func_003CB388_3AF630(void *, void *, void *, s32, f32);
void func_003AF630(O_3AF630 *o, s32 k) {
    V4 a, b, c, d;
    B_3AF630 *p = o->x68;
    Q qa, qb;
    func_00437698_3AF630(o, 12, &a);
    func_00437698_3AF630(o, 11, &b);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(b));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(D_001E2A40_3AF630));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qb) : "0"(qb), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(qb));
    func_0040C0F0_3AF630(&c, &c, 0.5f);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(b));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(c));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "0"(qb), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(qb));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qb) : "0"(qb), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qb));
    func_0040C0F0_3AF630(&d, &d, 0.58333337f);
    func_003CB388_3AF630(o, &c, &d, k, p->x354 == -1 ? (f32)p->x44 : 0.0f);
}
/* localdecomp:end func_003AF630 */

LINKER_REMNANT("asm/veldin/remnants", func_003AF740);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF748);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF778);

/* localdecomp:start func_003AF870 */
typedef int Q_3AF870 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3AF870;
typedef struct { V4_3AF870 r[4]; } M4_3AF870;
typedef struct { f32 a, b; } P_3AF870;
extern P_3AF870 D_001DE610_3AF870[1];
extern s32 D_001DE640_3AF870[2];
extern f32 D_001DE600_3AF870[2];
extern f32 D_001DE5F0_3AF870[2];
extern void func_00437698_3AF870(void *, s32, void *);
extern void func_00437600_3AF870(void *, s32, void *);
extern void func_0040C2F8_3AF870(void *, void *, void *);
extern void func_0044E620_3AF870(void *, s32, f32, f32);
void func_003AF870(void *o) {
    V4_3AF870 v;
    M4_3AF870 m;
    V4_3AF870 w;
    s32 i;
    for (i = 0; i < 3; i++) {
        Q_3AF870 qa, qb, qr;
        func_00437698_3AF870(o, 8, &v);
        func_00437600_3AF870(o, 8, &m);
        func_0040C2F8_3AF870(&w, &D_001DE610_3AF870[i * 2], &m);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(w));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
        func_0044E620_3AF870(&v, D_001DE640_3AF870[i], D_001DE600_3AF870[i], D_001DE5F0_3AF870[i]);
    }
}
/* localdecomp:end func_003AF870 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF958);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AFB80);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AFB88);

