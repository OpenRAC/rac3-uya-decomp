#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_003D9F60(void);
extern void func_003D8890(void);
extern void func_003D9EA0(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern void func_003D9760(E_3A3028 *, s32, s32, s32, f32, f32, f32);
extern void func_003DA018();
extern void func_003D8890();
extern void func_003D96A0();
extern void func_003D99A0(void *, s32, s32, s32, s32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D6C70 */
void func_003D6C70(s32 *p, s32 n) { s32 t = *p; t = (t + 0x1FFF) & -0x2000; *p = t + n; }
/* localdecomp:end func_003D6C70 */

/* localdecomp:start func_003D6C90 */
void func_003D6C90(long **pp, s32 x0, s32 y0, s32 x1, s32 y1, s32 z) {
    s32 n, step, i, d;
    unsigned long *p, *q;
    s32 x;
    d = x1 - x0;
    x = x0;
    n = d >> 9;
    step = d / n;
    p = (unsigned long *)*pp;
    *p = (unsigned long)(n | 0x8000) | 0x2400000000000000UL;
    p += 1;
    *pp = (long *)p;
    *p = 0x55;
    *pp = (long *)(p + 1);
    for (i = 0; i < n; i++) {
        q = (unsigned long *)*pp;
        *q = (unsigned long)x | ((long)y0 << 16) | ((long)z << 32);
        q += 1;
        *pp = (long *)q;
        x += step;
        *q = (unsigned long)x | ((long)y1 << 16) | ((long)z << 32);
        *pp = (long *)(q + 1);
    }
}
/* localdecomp:end func_003D6C90 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D6D30);

/* localdecomp:start func_003D6E10 */
extern void func_003D6D30(long **, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D4BD0_003D6E10;
extern s32 D_001D4BD4_003D6E10;
void func_003D6E10(u8 **pp8, s32 a1, s32 w, s32 h, s32 a4, s32 a5, s32 a6) {
    long **pp = (long **)pp8;
    s32 lw, lh, x, y, z;
    s32 ow, oh;
    ow = (w << 4) + 8;
    oh = (h << 4) + 8;
    w = (w > 0x3F) ? w : 0x40;
    h = (h > 0x3F) ? h : 0x40;
    if (w & (w - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1E - t; }
    }
    if (h & (h - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1E - t; }
    }
    if (a4 != 0) {
        x = 2; y = 2; z = 1;
    } else if (a5 != 0) {
        x = 1; y = 1; z = 1;
    } else {
        x = 2; y = 2; z = 2;
    }
    *(*pp)++ = 0x4000000000000001UL;
    *(*pp)++ = 0xEEEE;
    *(*pp)++ = ((long)x << 2) | ((long)y << 4) | ((long)z << 6) | ((long)a6 << 32);
    *(*pp)++ = 0x42;
    *(*pp)++ = 5;
    *(*pp)++ = 8;
    *(*pp)++ = (a1 >> 8) | ((long)(w >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *(*pp)++ = 6;
    *(*pp)++ = 0x31001;
    *(*pp)++ = 0x47;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x156;
    func_003D6D30(pp, D_001D4BD0_003D6E10 - 8, D_001D4BD4_003D6E10 - 8, 8, 8,
                  (D_001D5600 << 4) + D_001D4BD0_003D6E10 - 8, (D_001D5604 << 4) + D_001D4BD4_003D6E10 - 8, ow, oh);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x1400000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0x60;
    *(*pp)++ = 0x14;
}
/* localdecomp:end func_003D6E10 */

/* localdecomp:start func_003D7138 */
void func_003D7138(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12) {
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(a2 - 1) << 16) | ((long)(a3 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 13) | ((long)a4 << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x4400000000008001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x306;
    *(*pp)++ = a9 | ((long)a10 << 8) | ((long)a11 << 16) | ((long)a12 << 24);
    *(*pp)++ = a5 | ((long)a6 << 16);
    *(*pp)++ = a7 | ((long)a8 << 16);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D7138 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D72C8);

/* localdecomp:start func_003D72D0 */
extern void func_003D6D30(long **, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D72D0(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17, s32 a18) {
    *(*pp)++ = 0x4000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(a8 - 1) << 16) | ((long)(a9 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 8) | ((long)a4 << 14) | ((long)a5 << 26) | ((long)a6 << 30) | 0x400000000UL;
    *(*pp)++ = 7;
    *(*pp)++ = (a7 >> 13) | ((long)a10 << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x30802;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_003D6D30(pp, a11, a12, a15, a16, a13, a14, a17, a18);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D72D0 */

/* localdecomp:start func_003D7500 */
void func_003D7500(u8 **pp, s32 a1, s32 w, s32 h, s32 a4, s32 w2, s32 h2) {
    s32 lw, lh;
    s32 sw, sh, ow, oh;
    s32 k1, k2;
    sw = w << 4;
    sh = h << 4;
    ow = (w2 << 4) + 0x98;
    oh = (h2 << 4) + 0x98;
    k1 = 0x98;
    k2 = 0x98;
    w = (w > 0x3F) ? w : 0x40;
    h = (h > 0x3F) ? h : 0x40;
    w2 = (w2 > 0x3F) ? w2 : 0x40;
    h2 = (h2 > 0x3F) ? h2 : 0x40;
    if (w & (w - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1E - t; }
    }
    if (h & (h - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1E - t; }
    }
    func_003D72D0((long **)pp, a1, w, h, w >> 6, lw, lh, a4, w2, h2, w2 >> 6, k1, k2,
                  ow, oh, 0, 0, sw, sh);
}
/* localdecomp:end func_003D7500 */

/* localdecomp:start func_003D7628 */
void func_003D7628(s32 p0, s32 a1, s32 w, s32 h, s32 a4) {
    long **pp = (long **)p0;
    s32 lw, lh;
    s32 ow, oh, sw, sh, ow1, oh1;
    sw = w << 4;
    ow = sw + 0xA0;
    sh = h << 4;
    ow1 = (w + 1) << 4;
    oh = sh + 0xA0;
    oh1 = (h + 1) << 4;
    w = (w > 0x3F) ? w : 0x40;
    h = (h > 0x3F) ? h : 0x40;
    if (w & (w - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1E - t; }
    }
    if (h & (h - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1E - t; }
    }
    *(*pp)++ = 0x5000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(w - 1) << 16) | ((long)(h - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 8) | ((long)(w >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *(*pp)++ = 7;
    *(*pp)++ = (a4 >> 13) | ((long)(w >> 6) << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x60;
    *(*pp)++ = 0x15;
    *(*pp)++ = 5;
    *(*pp)++ = 9;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_003D6D30(pp, 0xA0, 0xA0, 0, 0, ow, oh, sw, sh);
    *(*pp)++ = 0x1000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = (a4 >> 8) | ((long)(w >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *(*pp)++ = 7;
    *(*pp)++ = (a1 >> 13) | ((long)(w >> 6) << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_003D6D30(pp, 0xA0, 0xA0, 0x10, 0x10, ow, oh, ow1, oh1);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D7628 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D7A98);

/* localdecomp:start func_003D7AA0 */
extern void func_003D7628(s32, s32, s32, s32, s32);
 
void func_003D7AA0(s32 a0, s32 a1, s32 a2) {
    func_003D7628(a0, a1, 0x100, 0x100, a2);
}
/* localdecomp:end func_003D7AA0 */

/* localdecomp:start func_003D7AC8 */
extern void func_003D7628(s32, s32, s32, s32, s32);
 
void func_003D7AC8(s32 a0, s32 a1, s32 a2) {
    func_003D7628(a0, a1, 0x80, 0x80, a2);
}
/* localdecomp:end func_003D7AC8 */

/* localdecomp:start func_003D7AF0 */
extern void func_003D7628(s32, s32, s32, s32, s32);
 
void func_003D7AF0(s32 a0, s32 a1, s32 a2) {
    func_003D7628(a0, a1, 0x40, 0x40, a2);
}
/* localdecomp:end func_003D7AF0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D7B18);

/* localdecomp:start func_003D7B30 */
void func_003D7B30(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17, s32 a18, s32 a19, s32 a20, s32 a21, s32 a22, s32 a23, s32 a24, s32 a25, s32 a26, s32 a27, s32 a28, s32 a29, s32 a30) {
    *(*pp)++ = 0x3000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(a8 - 1) << 16) | ((long)(a9 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 8) | ((long)a4 << 14) | ((long)a5 << 26) | ((long)a6 << 30) | 0x400000000UL;
    *(*pp)++ = 7;
    *(*pp)++ = (a7 >> 13) | ((long)a10 << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0x32000000A8UL;
    *(*pp)++ = 0x43;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x356;
    func_003D6D30(pp, a11, a12, a15, a16, a13, a14, a17, a18);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0x3200000068UL;
    *(*pp)++ = 0x43;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x356;
    func_003D6D30(pp, a11, a12, a19, a20, a13, a14, a21, a22);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x356;
    func_003D6D30(pp, a11, a12, a23, a24, a13, a14, a25, a26);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x356;
    func_003D6D30(pp, a11, a12, a27, a28, a13, a14, a29, a30);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D7B30 */

/* localdecomp:start func_003D7F80 */
extern s32 func_003D6C70(s32 *, s32);
extern void func_003D8038(void);
extern void func_003D8750(void);
__asm__(".extern D_001D5608, 4");
__asm__(".extern D_001D5610, 4");
__asm__(".extern D_001D5614, 4");
__asm__(".extern D_001D561C, 4");
extern s32 D_001D5608, D_001D5610, D_001D5614, D_001D561C;
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];
void func_003D7F80(void) {
    s32 p, r1, r2, r3;
    D_001D5608 = 0x3FA000;
    D_001D560C = 0x3FE000;
    D_001D5624 = 0x400000;
    p = 0x379000;
    r1 = func_003D6C70(&p, 0x40000);
    p = 0x379000;
    D_001D5614 = r1;
    r2 = func_003D6C70(&p, 0x40000);
    D_001D561C = r2;
    r3 = func_003D6C70(&p, 0x40000);
    D_001D5620 = r3;
    D_001D5610 = D_001A1ED4[0];
    func_003D8038();
    func_003D8750();
    D_001D55EC = D_001D55EC | 1;
}
/* localdecomp:end func_003D7F80 */

/* localdecomp:start func_003D8038 */
__asm__(".extern D_001D93AC, 1");
__asm__(".extern D_001D9390, 4");
__asm__(".extern D_001D9394, 4");
__asm__(".extern D_001D9398, 4");
__asm__(".extern D_001D939C, 4");
extern s32 D_001D0A50[];
extern s32 D_001D5600, D_001D5604, D_001D5608_003D8038, D_001D5610_003D8038, D_001D5614_003D8038, D_001D561C_003D8038, D_001D5620, D_001D55F0;
extern u8 D_001D93AC;
extern s32 D_001D9390, D_001D9394, D_001D9398, D_001D939C;
extern void func_003D6C90(long **, s32, s32, s32, s32, s32);
extern void func_003D7500(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7138(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D7AA0(s32, s32, s32);
extern void func_003D7AC8(s32, s32, s32);
extern void func_003D7AF0(s32, s32, s32);
extern void func_003D7B30(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D8038(void) {
    long *d = (long *)D_001D0A50;
    long *p;
    s32 lw, lh, v;
    d[0] = 0x5000000000000001UL;
    d[1] = 0xEEEEEEEEEEEEEEEEUL;
    d[2] = 0;
    d[3] = 0x3F;
    d[4] = 0xA0000000A0UL;
    d[5] = 0x19;
    d[6] = 0x100000000UL;
    d[7] = 0x4F;
    d[8] = 0x60;
    d[9] = 0x15;
    d[10] = 5;
    d[11] = 9;
    d[12] = 0x3000000000000001UL;
    d[13] = 0xEEEEEEEEEEEEEEEEUL;
    d[14] = (D_001D5614_003D8038 >> 13) | 0x40000;
    d[15] = 0x4D;
    d[16] = 0xFF000000FF0000UL;
    d[17] = 0x41;
    d[18] = 0x3040C;
    d[19] = 0x48;
    d[20] = 0x2400000000000001UL;
    d[21] = 1;
    d[22] = 0;
    d[23] = 0x306;
    p = d + 24;
    func_003D6C90(&p, 0xA0, 0xA0, 0x10A0, 0x10A0, 0);
    *p++ = 0x5000000000000001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    v = D_001D5600;
    if (v & (v - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lw = 0x1E - t; }
    }
    v = D_001D5604;
    if (v & (v - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lh = 0x1E - t; }
    }
    *p++ = ((long)D_001D5610_003D8038 >> 8) | (((long)D_001D5600 >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *p++ = 7;
    *p++ = (D_001D5614_003D8038 >> 13) | 0x40000;
    *p++ = 0x4D;
    *p++ = 0xFF000000FF0000UL;
    *p++ = 0x41;
    *p++ = 0x3040D;
    *p++ = 0x48;
    *p++ = 0x8000000088UL;
    *p++ = 0x43;
    *p++ = 0x2400000000000001UL;
    *p++ = 1;
    *p++ = D_001D9390 | ((long)D_001D9394 << 8) | ((long)D_001D9398 << 16) | ((long)D_001D939C << 24);
    *p++ = 0x316;
    func_003D6D30(&p, 0x98, 0x98, 0, 0, 0x1098, 0x1098, D_001D5600 << 4, D_001D5604 << 4);
    *p++ = 0x1000000000008001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    *p++ = 0;
    *p++ = 0x3F;
    *p++ = 0x1000000000000001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    *p++ = 0x30802;
    *p++ = 0x48;
    if (D_001D93AC == 1) {
        func_003D7AA0((s32)&p, D_001D5614_003D8038, D_001D5620);
        func_003D7AA0((s32)&p, D_001D5614_003D8038, D_001D5620);
    }
    func_003D7500((u8 **)&p, D_001D5614_003D8038, 0x100, 0x100, D_001D5620, 0x80, 0x80);
    func_003D7AC8((s32)&p, D_001D5620, D_001D561C_003D8038);
    if (D_001D93AC == 1) {
        func_003D7AC8((s32)&p, D_001D5620, D_001D561C_003D8038);
    }
    func_003D7500((u8 **)&p, D_001D561C_003D8038, 0x80, 0x80, D_001D5620, 0x40, 0x40);
    func_003D7AF0((s32)&p, D_001D5620, D_001D561C_003D8038);
    func_003D7AF0((s32)&p, D_001D5620, D_001D561C_003D8038);
    func_003D7AF0((s32)&p, D_001D5620, D_001D561C_003D8038);
    func_003D7138(&p, D_001D561C_003D8038, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0, 0, 0);
    func_003D7138(&p, D_001D5608_003D8038, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0, 0, 0);
    func_003D7B30(&p, D_001D5620, 0x40, 0x40, 1, 6, 6, D_001D561C_003D8038, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0,
                  0x400, 0x400, 0x10, 0, 0x410, 0x400, 0, 0x10, 0x400, 0x410, 0x10, 0x10, 0x410, 0x410);
    func_003D7B30(&p, D_001D561C_003D8038, 0x40, 0x40, 1, 6, 6, D_001D5608_003D8038, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0,
                  0x400, 0x400, 0x10, 0, 0x410, 0x400, 0, 0x10, 0x400, 0x410, 0x10, 0x10, 0x410, 0x410);
    D_001D55F0 = (u8 *)p - (u8 *)d;
}
/* localdecomp:end func_003D8038 */

/* localdecomp:start func_003D8750 */
__asm__(".extern D_001D93A0, 4");
extern s32 D_001D5608_003D8750, D_001D5620, D_001D561C_003D8750, D_001D93A0, D_001D55F4;
extern u8 D_001D2A50[];
extern void func_003D7500(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7AA0();
extern void func_003D6E10(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D8750(void) {
    u8 *p = D_001D2A50;
    func_003D7500(&p, D_001D5608_003D8750, 0x40, 0x40, D_001D5620, 0x80, 0x80);
    func_003D7500(&p, D_001D5620, 0x80, 0x80, D_001D561C_003D8750, 0x100, 0x100);
    func_003D7AA0(&p, D_001D561C_003D8750, D_001D5620);
    func_003D6E10(&p, D_001D561C_003D8750, 0x100, 0x100, 1, 0, D_001D93A0);
    D_001D55F4 = p - D_001D2A50;
}
/* localdecomp:end func_003D8750 */

/* localdecomp:start func_003D8810 */
extern s32 D_001D55F0;
extern u32 *D_001DA0D0;
__asm__(".extern D_001D938C, 4");
extern s32 D_001D938C;
extern s32 D_001D0A50[];
void func_003D8810(void) {
    D_001D938C = 0x6000;
    D_001DA0D0[0] = (D_001D55F0 >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D0A50;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55F0 >> 4) | 0x50000000;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003D8810 */

/* localdecomp:start func_003D8890 */
__asm__(".extern D_001D938C, 4");
extern u32 *D_001DA0D0;
extern s32 D_001D55F4;
extern u8 D_001D2A50[];
extern s32 D_001D938C;
void func_003D8890(void) {
    D_001DA0D0[0] = (D_001D55F4 >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D2A50;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55F4 >> 4) | 0x50000000;
    D_001D938C = 0;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003D8890 */

/* localdecomp:start func_003D8908 */
extern s32 D_001A1ED0[];
void func_003D8908(unsigned long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    *(*pp)++ = 0x7000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = ((long)(a1 - 1) << 16) | ((long)(a2 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = ((long)D_001A1ED0[2] >> 13) | ((long)a3 << 16) | 0xFF00000001000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x30802;
    *(*pp)++ = 0x48;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000 | 0x100000000UL;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x80000000A4UL;
    *(*pp)++ = 0x43;
    *(*pp)++ = 0x4400000000000001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x346;
    *(*pp)++ = 0xFFFFFFFFUL;
    *(*pp)++ = (long)a4 | ((long)a5 << 16);
    *(*pp)++ = (long)a6 | ((long)a7 << 16);
    *(*pp)++ = 0x3000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D8908 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D8BE8);

/* localdecomp:start func_003D8F40 */
typedef struct { s32 f0; s32 f4; s32 f8; } T_3D3780;
extern T_3D3780 D_001A1ED0_003D8F40;
s32 func_003D8F40(long **pp, s32 w, s32 h, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 c) {
    T_3D3780 *t = &D_001A1ED0_003D8F40;
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = (t->f8 >> 13) | 0x31000000;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x4000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = ((long)(w - 1) << 16) | ((long)(h - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = ((long)t->f4 >> 13) | ((long)a3 << 16) | 0xFFFFFF00000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x70802;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0x4400000000000001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x306;
    *(*pp)++ = 0xFFFFFF;
    *(*pp)++ = a4 | ((long)a5 << 16) | ((long)c << 32);
    *(*pp)++ = a6 | ((long)a7 << 16) | ((long)c << 32);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D8F40 */

/* localdecomp:start func_003D9210 */
__asm__(".extern D_001D5634_003D9210, 4");
extern s32 D_001D5600_003D9210;
extern s32 D_001D5604_003D9210;
extern s32 D_001D5628_003D9210;
extern s32 D_001D5630_003D9210;
extern s32 D_001D5634_003D9210;
extern s32 D_001D55F8_003D9210;
extern u8 D_001D3650_003D9210[];
extern void func_003D7500(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7AA0();
void func_003D9210(void) {
    u8 *p;
    unsigned long *q = (unsigned long *)D_001D3650_003D9210;
    q[0] = 0x5000000000000001UL;
    q[1] = 0xEEEEEEEEEEEEEEEEUL;
    q[2] = 0;
    q[3] = 0x3F;
    q[4] = 0xA0000000A0UL;
    q[5] = 0x19;
    q[6] = 0x100000000UL;
    q[7] = 0x4F;
    q[8] = 0x60;
    q[9] = 0x15;
    q[10] = 5;
    q[11] = 9;
    p = D_001D3650_003D9210 + 0x60;
    func_003D7500(&p, D_001D5630_003D9210, D_001D5600_003D9210, D_001D5604_003D9210, D_001D5628_003D9210, 0x100, 0x100);
    func_003D7AA0(&p, D_001D5628_003D9210, D_001D5634_003D9210);
    func_003D7AA0(&p, D_001D5628_003D9210, D_001D5634_003D9210);
    D_001D55F8_003D9210 = p - D_001D3650_003D9210;
}
/* localdecomp:end func_003D9210 */

/* localdecomp:start func_003D9350 */
extern s32 D_001D5600_003D9350;
__asm__(".extern D_001D5600_003D9350, 16");
extern s32 D_001D5604_003D9350;
__asm__(".extern D_001D5604_003D9350, 16");
extern s32 D_001D5628_003D9350;
__asm__(".extern D_001D5628_003D9350, 16");
extern s32 D_001D55FC_003D9350;
__asm__(".extern D_001D55FC_003D9350, 16");
extern u8 D_001D3EF0[];
extern s32 func_003D8908();
extern s32 func_003D8BE8();
extern s32 func_003D8F40();
extern void func_003D6E10(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D9350(void) {
    u8 *p;
    p = D_001D3EF0;
    func_003D8908(&p, D_001D5600_003D9350, D_001D5604_003D9350, D_001D5600_003D9350 >> 6, 0, 0, (D_001D5600_003D9350 + 1) << 4, (D_001D5604_003D9350 + 1) << 4);
    func_003D8BE8(&p, 1);
    func_003D8F40(&p, D_001D5600_003D9350, D_001D5604_003D9350, D_001D5600_003D9350 >> 6, 0, 0, (D_001D5600_003D9350 + 1) << 4, (D_001D5604_003D9350 + 1) << 4, 0xFF82FF);
    func_003D6E10(&p, D_001D5628_003D9350, 0x100, 0x100, 0, 1, 0x80);
    D_001D55FC_003D9350 = (s32)p - (s32)D_001D3EF0;
}
/* localdecomp:end func_003D9350 */

/* localdecomp:start func_003D9440 */
__asm__(".extern D_001D5634, 4");
__asm__(".extern D_001D5630, 4");
extern s32 func_003D6C70();
extern void func_003D9210(void);
extern void func_003D9350(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628;
extern s32 D_001A1ED4[];
extern s32 D_001D55EC;
void func_003D9440(void) {
    s32 spv[4];
    spv[0] = 0x37C000;
    D_001D5634 = func_003D6C70(spv, 0x40000);
    D_001D5628 = func_003D6C70(spv, 0x40000);
    D_001D5630 = D_001A1ED4[0];
    func_003D9210();
    func_003D9350();
    D_001D55EC |= 2;
}
/* localdecomp:end func_003D9440 */

/* localdecomp:start func_003D94B0 */
extern u32 *D_001DA0D0;
extern s32 D_001D55F8;
extern s32 D_001D55FC;
extern u8 D_001D3650[];
extern u8 D_001D3EF0[];
void func_003D94B0(void) {
    D_001DA0D0[0] = (D_001D55F8 >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D3650;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55F8 >> 4) | 0x50000000;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = (D_001D55FC >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D3EF0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55FC >> 4) | 0x50000000;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003D94B0 */

/* localdecomp:start func_003D9588 */
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0;
extern S_1CFEC0 D_1CFEC0;
extern s32 D_001D5604;
extern s32 D_001D5600;
extern void func_003D7F80();
extern void func_003D9440();
void func_003D9588(void) {
    S_1CFEC0 *p = &D_1CFEC0;
    D_001D5600 = p->h150;
    D_001D5604 = p->h152;
    func_003D7F80();
    func_003D9440();
}
/* localdecomp:end func_003D9588 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D95C8);

/* localdecomp:start func_003D9600 */
extern long func_00389920(s32);
extern u8 D_00380EF0[];

void func_003D9600(void *arg0, s32 arg1, s32 arg2, long arg3) {
    void *temp_s0;

    (*(long *)((u8 *)(arg0) + 0x78)) = func_00389920(arg1);
    (*(long *)((u8 *)(arg0) + 0x80)) = (long) (0xFF9000000000 | 0x260);
    (*(long *)((u8 *)(arg0) + 0x70)) = 0;
    temp_s0 = (arg2 * 0x14) + D_00380EF0;
    (*(long *)((u8 *)(arg0) + 0x88)) = (long) ((*(s32 *)((u8 *)(temp_s0) + 0)) | ((long) (*(s32 *)((u8 *)(temp_s0) + 4)) * 4) | ((long) (*(s32 *)((u8 *)(temp_s0) + 8)) * 0x10) | ((long) (*(s32 *)((u8 *)(temp_s0) + 0xC)) << 6) | (arg3 << 0x20));
}
/* localdecomp:end func_003D9600 */

/* localdecomp:start func_003D96A0 */
typedef int u128_3D3EE0 __attribute__((mode(TI)));
extern void func_003D9600(void *, s32, s32, long);
void func_003D96A0(u8 *p, s32 a1, s32 a2, f32 *src, u128_3D3EE0 *q, s32 a5) {
    s32 i;
    f32 *fp;
    s32 *ip;
    func_003D9600(p, a1, a5, 0x80);
    ip = (s32 *)(p + 0x40);
    fp = (f32 *)(p + 0x54);
    for (i = 0; i < 4; i++) {
        fp[i * 2 - 1] = src[i * 2];
        fp[i * 2] = src[i * 2 + 1];
        ip[i] = a2;
        ((u128_3D3EE0 *)p)[i] = q[i];
    }
}
/* localdecomp:end func_003D96A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D9738);

/* localdecomp:start func_003D9760 */
typedef int Q_3D3FA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D3FA0;
typedef struct { V_3D3FA0 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } B_3D3FA0;
extern V_3D3FA0 D_00222480_003D9760[];
extern V_3D3FA0 D_001D91B0[];
typedef struct { u8 pad[0x80]; f32 f80[4]; u8 pad2[0x3D0]; } G_3D3FA0;
extern G_3D3FA0 D_00222650_003D9760[];
extern u8 D_00222650[];
extern s32 D_001D52F0;
extern void func_0038D290(void *, void *, f32);
extern void func_0038D1B8(void *, void *, void *);
extern void func_0038D630(void *, void *);
extern void func_0038D918(void *, void *, void *);
extern void func_0038D148(void *, void *, f32);
extern void func_0038D350(void *, void *, void *);
extern void func_003D2FF0(void *, s32, s32);
void func_003D9760(E_3A3028 *e, s32 tex, s32 col, s32 blend, f32 size, f32 dist, f32 ang) {
    B_3D3FA0 buf;
    V_3D3FA0 m[4];
    V_3D3FA0 q;
    f32 rot[12];
    Q_3D3FA0 a, b, r;
    s32 k;
    G_3D3FA0 *p;
    func_003D9600(&buf, tex, blend, 0x80);
    *(Q_3D3FA0 *)&m[3] = *(Q_3D3FA0 *)e;
    buf.c[3] = col;
    buf.c[2] = col;
    buf.c[1] = col;
    buf.c[0] = col;
    buf.uv[0] = 0;
    buf.uv[1] = 0;
    buf.uv[2] = 0;
    buf.uv[3] = 1.0f;
    buf.uv[4] = 1.0f;
    buf.uv[5] = 0;
    buf.uv[6] = 1.0f;
    buf.uv[7] = 1.0f;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_00222480_003D9760[0]));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(m[3]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(m[0]) : "j"(a));
    func_0038D290(&m[0], &m[0], 1.0f);
    p = &D_00222650_003D9760[D_001D52F0];
    func_0038D1B8(&m[1], &m[0], (u8 *)p + 0x80);
    func_0038D290(&m[1], &m[1], 1.0f);
    func_0038D1B8(&m[2], &m[1], &m[0]);
    if (ang != 0) {
        *(Q_3D3FA0 *)&q = 0;
        q.x = ang;
        func_0038D630(rot, &q);
        func_0038D918(&m[0], &m[0], rot);
    }
    func_0038D148(&q, &m[0], dist);
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(m[3]));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(q));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(m[3]) : "j"(b));
    for (k = 0; k < 4; k++) {
        func_0038D148(&buf.v[k], &D_001D91B0[k], size);
        func_0038D350(&buf.v[k], &buf.v[k], m);
    }
    func_003D2FF0(&buf, 0, 0);
}
/* localdecomp:end func_003D9760 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D9958);

/* localdecomp:start func_003D99A0 */
typedef struct { f32 x, y, z; } P_3D41E0;
typedef struct { f32 a, b; } T_3D41E0;
__asm__(".extern D_001D93D0, 4");
__asm__(".extern D_001D9400, 4");
extern f32 D_001D93D0;
extern f32 D_001D9400;
extern s32 D_001D9388;
extern P_3D41E0 D_002FF900[];
extern s32 D_002FFA08[];
extern T_3D41E0 D_002FFA60[];
extern void func_003A96B0(s32, unsigned long);
extern long func_00389920(s32);
extern void func_0038CA78(void);
extern void func_0038D350();
extern f32 func_0038D3C0(f32);
extern f32 func_0038D3D8(f32);
extern s32 func_0038DF00(s32, s32, f32);
extern void func_003D3C74(s32, void *, void *, void *, s32);
void func_003D99A0(void *m, s32 tex, s32 rgba, s32 cnt, s32 mode, f32 t) {
    f32 v[4];
    f32 o[4];
    s32 i, n, r, col, mask;
    f32 da, ang, acc, step, c;
    s32 k;
    func_003A96B0(8, 0);
    da = 0.31415927f;
    func_003A96B0(0x14, 0xFF9000000260UL);
    func_003A96B0(6, func_00389920(tex));
    if (mode != 0) {
        if (mode == 2) {
            func_003A96B0(0x47, 0x513F1);
            D_001D9388 |= 1;
        } else {
            func_003A96B0(0x47, 0x53001);
        }
        func_003A96B0(0x42, 0x8000000048UL);
        mask = 0xFF000000;
        col = rgba & mask;
    } else {
        func_003A96B0(0x47, 0x513F1);
        func_003A96B0(0x42, 0x8000000044UL);
        col = rgba & 0xFFFFFF;
    }
    func_0038CA78();
    t = t - (f32)(s32)t + 7.0f;
    v[0] = 0;
    v[1] = 0;
    v[2] = 1.0f;
    v[3] = 1.0f;
    func_0038D350(o, v, m);
    for (i = 0; i < 22; i++) {
        D_002FFA60[i].a = (f32)((i / 2) & 1);
        if ((i ^ 1) & 1) {
            D_002FF900[i].x = o[0];
            D_002FF900[i].y = o[1];
            D_002FF900[i].z = o[2];
            D_002FFA08[i] = rgba;
            D_002FFA60[i].b = t;
        }
    }
    if (cnt < 0) {
        step = 0;
        cnt = -cnt;
    } else {
        step = 1.0f / (f32)cnt;
    }
    acc = 0;
    if (cnt > 10) cnt = 10;
    n = cnt;
    ang = acc;
    while (n != 0) {
        ang += da;
        acc += step;
        t -= 1.0f;
        c = func_0038D3D8(ang);
        v[2] = func_0038D3C0(ang);
        r = func_0038DF00(rgba, col, acc);
        for (i = 1, k = 0; i < 22; i += 2, k++) {
            v[0] = c * (&D_001D93D0)[k];
            v[1] = c * (&D_001D9400)[k];
            func_0038D350(o, v, m);
            D_002FF900[i].x = o[0];
            D_002FF900[i].y = o[1];
            D_002FF900[i].z = o[2];
            D_002FFA08[i] = r;
            D_002FFA60[i].b = t;
        }
        func_003D3C74(0x16, D_002FF900, D_002FFA08, D_002FFA60, 1);
        n--;
        if (n == 0) break;
        ang += da;
        acc += step;
        t -= 1.0f;
        c = func_0038D3D8(ang);
        v[2] = func_0038D3C0(ang);
        r = func_0038DF00(rgba, col, acc);
        for (i = 0, k = 0; i < 22; i += 2, k++) {
            v[0] = c * (&D_001D93D0)[k];
            v[1] = c * (&D_001D9400)[k];
            func_0038D350(o, v, m);
            D_002FF900[i].x = o[0];
            D_002FF900[i].y = o[1];
            D_002FF900[i].z = o[2];
            D_002FFA08[i] = r;
            D_002FFA60[i].b = t;
        }
        func_003D3C74(0x16, D_002FF900, D_002FFA08, D_002FFA60, 1);
        n--;
    }
}
/* localdecomp:end func_003D99A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D9E40);

/* localdecomp:start func_003D9E70 */
extern s32 D_001D4BB0[];
extern void func_003DCE60(s32);
extern void func_003A9888(void);
void func_003D9E70(void) {
    func_003DCE60(D_001D4BB0[0]);
    func_003A9888();
}
/* localdecomp:end func_003D9E70 */

/* localdecomp:start func_003D9EA0 */
typedef struct { s16 a; s16 b; } T_D46E0;
typedef struct { u8 p0[0x33]; u8 f33; } E_D46E0;
typedef struct { u8 p0[0xF]; u8 cnt; u8 q[0xC]; E_D46E0 *ent; } O_D46E0;
extern s32 D_00304F40[];
extern O_D46E0 *D_002FFB40[];
extern T_D46E0 D_00304940[];
void func_003D9EA0(void) {
    s32 *p;
    s32 i;
    O_D46E0 *o;
    u8 *e;
    for (p = D_00304F40; *p >= 0; p++) {
        o = D_002FFB40[*p];
        e = (u8 *)o->ent;
        for (i = 0; i < o->cnt; i++) {
            T_D46E0 *t = &D_00304940[e[0x33]];
            if (t->a != 0) { *(u32 *)e = (*(u32 *)e & 0xFFFFC000) | t->a; }
            if (t->b != 0) { *(u32 *)(e + 0x20) = (*(u32 *)(e + 0x20) & 0xFFFFC000) | t->b; }
            e += 0x50;
        }
    }
}
/* localdecomp:end func_003D9EA0 */

/* localdecomp:start func_003D9F60 */
extern s32 D_001D4BB4;
void func_0038D050(s32, s32 *, s32);
void func_003A9200(s32 *);
extern void func_003A96B0(s32, unsigned long);
void func_003DA098();
void func_003DB000();
void func_003DC3D0();
void func_003DD110();
void func_11F0A0(s32);
extern s32 D_001D4BB0_003D9F60;
extern u8 D_001D7960[];
extern s32 D_001DA0D0_003D9F60;
extern u8 D_100AE0[];
extern u8 D_1159B0[];

void func_003D9F60(void) {
    func_003A96B0(0x47, 0x5340B);
    D_001D4BB0_003D9F60 = D_001D4BB4;
    func_11F0A0(0);
    func_003DA098();
    func_003D9E70();
    func_11F0A0(0);
    func_003DD110();
    func_003A9200(D_1159B0);
    func_003DB000();
    func_003DC3D0();
    func_003A9200(D_100AE0);
    func_0038D050(D_001DA0D0_003D9F60, D_001D7960, 0x20);
    D_001DA0D0_003D9F60 += 0x20;
}
/* localdecomp:end func_003D9F60 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003DA010);

/* localdecomp:start func_003DA018 */
typedef struct {
    u8 pad[0x7614];
    s32 value;
} SourceBlock_003DA018;
extern u8 *D_001DA784;
extern u8 *D_001DA788;
extern s32 D_001DA790;
extern s32 D_001DA7A8;
extern s32 D_001DA7AC;
extern s32 D_001DA7B0;
extern u8 *D_001DA7B4;
__asm__(".extern D_001DA784, 16");
__asm__(".extern D_001DA788, 16");
__asm__(".extern D_001DA790, 16");
__asm__(".extern D_001DA7A8, 16");
__asm__(".extern D_001DA7AC, 16");
__asm__(".extern D_001DA7B4, 16");
void func_003DA018(void) {
    register SourceBlock_003DA018 *source_block __asm__("$3") = (SourceBlock_003DA018 *)0x220000;
    register u8 *buffer __asm__("$2") = (u8 *)0x300000;
    s32 source;
    register u8 *entry __asm__("$5");
    register u8 *end __asm__("$3");
    __asm__ volatile("" : "+r"(source_block), "+r"(buffer));
    source = source_block->value;
    buffer -= 0x2C0;
    entry = D_001DA784;
    end = D_001DA788;
    D_001DA790 = source;
    D_001DA7B4 = buffer;
    D_001DA7A8 = 0;
    D_001DA7AC = 0;
    D_001DA7B0 = 0;
    if (entry != end) {
        register u16 empty __asm__("$4") = 0xFFFF;
        register u8 marker __asm__("$3") = 0xFF;
        do {
            entry[0x1F] = marker;
            *(s16 *)(entry + 0x16) = 0;
            *(u16 *)(entry + 0x14) = empty;
            buffer = D_001DA788;
            __asm__ volatile("" : "+r"(buffer));
            entry += 0x20;
        } while (entry != buffer);
    }
}
/* localdecomp:end func_003DA018 */
