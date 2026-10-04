#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388440();
extern void func_003A3EF0(s32, unsigned long);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_00388440(void *, s32, s32);
extern void func_11F0A0();
extern s32 D_001D9DB0;
extern s32 D_001D9DB8;
extern void func_003885F0(u32 *, s32, s32);
extern void func_00388440(void *, int, int);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003BDAC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDAC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDBA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDC90);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDD68);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDEA8);

/* localdecomp:start func_003BE0D0 */
extern u8 D_0037C2A0[];
extern s32 D_001D9DB0;
extern s32 D_001D9DB8;
extern void func_11F0A0(s32);
extern void func_003885F0(u32 *, s32, s32);
extern void func_003C5D90();
void func_003BE0D0(void) {
    func_11F0A0(0);
    func_003885F0((u32 *)0x70003800, (s32)D_0037C2A0, 0x800);
    func_003C5D90(D_001D9DB0, D_001D9DB8);
}
/* localdecomp:end func_003BE0D0 */

/* localdecomp:start func_003BE118 */
extern void func_00388440();
 
void func_003BE118(void) {
    func_00388440(0x70003A00, 0x40000000, 0x3C0);
}
/* localdecomp:end func_003BE118 */

/* localdecomp:start func_003BE140 */
extern void func_003885F0();
extern u8 D_002D6400[];
 
void func_003BE140(void) {
    func_003885F0((s32)D_002D6400, 0x70003A00, 0x3C0);
}
/* localdecomp:end func_003BE140 */

/* localdecomp:start func_003BE170 */
extern void func_003885F0();
 extern u8 D_002D6400[];

void func_003BE170(void) {
    func_003885F0(0x70003A00, (s32)D_002D6400, 0x3C0);
}
/* localdecomp:end func_003BE170 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BE1A0);

/* localdecomp:start func_003BE260 */
extern void *D_001DA518_003BE260;
extern void func_003A3EF0(s32, unsigned long);
extern void func_11F0A0(s32);
extern void func_003BE170(void);
extern void *func_003C5E70(s32, void *, s32, s32);
extern void func_003BE140(void);
void func_003BE260(s32 a0, s32 a1) {
    func_003A3EF0(0x47, 0x5360B);
    func_11F0A0(0);
    func_003BE170();
    D_001DA518_003BE260 = func_003C5E70(a0, D_001DA518_003BE260, a1, 0);
    func_003BE140();
    D_001DA518_003BE260 = (u8 *)D_001DA518_003BE260 - 0x10;
}
/* localdecomp:end func_003BE260 */

/* localdecomp:start func_003BE2E0 */
extern void func_003BDBA0(void);
extern void func_003BE0D0(void);
extern void func_003BDD68(void);
extern void func_003BDEA8(void);
extern s32 D_001DA564[];
extern u8 *D_001DA5B0;
extern u8 D_002F8220[];
void func_003BE2E0(void) {
    func_003BDBA0();
    func_003BE0D0();
    if (D_001DA564[0] != 0) {
        func_003BDD68();
    }
    if (D_001DA5B0 > D_002F8220) {
        func_003BDEA8();
    }
}
/* localdecomp:end func_003BE2E0 */

/* localdecomp:start func_003BE340 */
extern void func_003BE118();
extern void func_003BE1A0();
extern void func_003BE2E0();
s32 func_003C5E70_003BE340(s32, s32, s32, s32);      /* extern */
extern s32 D_001DA518;
extern s32 D_001DA51C;
extern s32 D_001DA554;

void func_003BE340(void) {
    s32 var_a3;

    func_003BE1A0();
    func_003BE118();
    var_a3 = 1;
    if (D_001DA554 != 0) {
        D_001DA554 = 0;
        var_a3 = 3;
    }
    D_001DA518 = func_003C5E70_003BE340(D_001DA51C, D_001DA518, -1, var_a3);
    func_003BE2E0();
}
/* localdecomp:end func_003BE340 */

LINKER_REMNANT("asm/remnants", func_003BE3A0);

/* localdecomp:start func_003BE3C0 */
extern int D_001DA51C;
extern int D_001DA524_003BE3C0;
int func_003BE3C0(void) {
    unsigned char *current = (unsigned char *)(*(volatile int *)&D_001DA51C);
    unsigned char *end = (unsigned char *)(*(volatile int *)&D_001DA524_003BE3C0);
    int result = (int)end;

    if (current != end) {
        do {
            result = *(int *)(current + 0x24);
            current += 0x100;
        } while (current != end);
    }
    return result;
}
/* localdecomp:end func_003BE3C0 */

LINKER_REMNANT("asm/remnants", func_003BE400);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE418);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE4F0);
TEXT_PADDING(4);

LINKER_REMNANT("asm/remnants", func_003BE688);

/* localdecomp:start func_003BE6A8 */
extern f32 func_00388960(f32);
f32 func_003BE6A8(f32 a, f32 b, f32 t) {
    if (t == 0.0f) return a;
    if (t == 1.0f) return b;
    return a + (b - a) * ((1.0f - func_00388960(t * 3.14159274f)) * 0.5f);
}
/* localdecomp:end func_003BE6A8 */

LINKER_REMNANT("asm/remnants", func_003BE740);

/* localdecomp:start func_003BE7F0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_002276E0;
s32 func_003CE740(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
f32 func_003BE7F0(V_3BE7F0 *p, s32 flags, s32 c, f32 dz) {
    V_3BE7F0 a = *p;
    V_3BE7F0 b = *p;
    a.z = 0.01f;
    b.z += dz;
    if (func_003CE740(&b, &a, flags | 2, c, 0)) return D_002276E0.z;
    return 0.0f;
}
/* localdecomp:end func_003BE7F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BE860);

LINKER_REMNANT("asm/remnants", func_003BE948);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE988);

/* localdecomp:start func_003BEA80 */
extern s32 func_00388F50();
extern void func_00389018(void *, s32, f32);
void func_003BEA80(s32 *arg0, void *arg1) {
    s32 spv[12];

    func_00389018(&spv[8], 0, (*(f32 *)((u8 *)arg1 + 0)));
    func_00389018(&spv[4], 1, (*(f32 *)((u8 *)arg1 + 4)));
    func_00389018(spv, 2, (*(f32 *)((u8 *)arg1 + 8)));
    ((s32 (*)())func_00388F50)(arg0, &spv[8], &spv[4]);
    ((s32 (*)())func_00388F50)(arg0, arg0, spv);
}
/* localdecomp:end func_003BEA80 */

LINKER_REMNANT("asm/remnants", func_003BEB18);

/* localdecomp:start func_003BEB48 */
f32 func_003BEB48(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}
/* localdecomp:end func_003BEB48 */

/* localdecomp:start func_003BEB58 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) Vector_003BEB58;
extern f32 func_003BEB48(f32, f32, f32);
void func_003BEB58(Vector_003BEB58 *output, Vector_003BEB58 first, Vector_003BEB58 second, f32 fraction) {
    output->x = func_003BEB48(first.x, second.x, fraction);
    output->y = func_003BEB48(first.y, second.y, fraction);
    output->z = func_003BEB48(first.z, second.z, fraction);
    output->w = func_003BEB48(first.w, second.w, fraction);
}
/* localdecomp:end func_003BEB58 */

LINKER_REMNANT("asm/remnants", func_003BEBF0);

/* localdecomp:start func_003BEBF8 */
f32 func_003BEBF8(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f13;

    var_f13 = fparg1;
    var_f0 = fparg0 - *arg0;
    if ((var_f13 < var_f0) || (var_f13 = -var_f13, (var_f0 < var_f13))) {
        var_f0 = var_f13;
    }
    temp_f1 = *arg0 + var_f0;
    *arg0 = temp_f1;
    { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(fparg0 - temp_f1)); return r; }
}
/* localdecomp:end func_003BEBF8 */

LINKER_REMNANT("asm/remnants", func_003BEC48);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEC60);

LINKER_REMNANT("asm/remnants", func_003BEE08);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEE20);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003BEFF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF058);

/* localdecomp:start func_003BF2A0 */
extern void func_00388E38(void *, void *);
extern void func_003BF058(void *, void *);
extern void func_00388E58(void *, void *);
void func_003BF2A0(void *a, void *b) {
    u8 m[0x40];
    func_00388E38(m, b);
    func_003BF058(a, m);
    func_00388E58(b, m);
}
/* localdecomp:end func_003BF2A0 */

LINKER_REMNANT("asm/remnants", func_003BF2F0);

/* localdecomp:start func_003BF2F8 */
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern void func_003886E8(f32 *, void *, f32);
void func_003BF2F8(f32 *q, void *axis, f32 angle) {
    f32 h = angle * 0.5f;
    func_003886E8(q, axis, func_00388978(h));
    q[3] = func_00388960(h);
}
/* localdecomp:end func_003BF2F8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BF360);

/* localdecomp:start func_003BF4F8 */
extern void func_003C1A60(s32, s32 *, s32 *, s32 *);
typedef struct { s16 x0; s16 x2; u8 x4, x5, x6; u8 p7[5]; u16 xC; s16 xE; } S_BF;
void func_003BF4F8(s32 a0, S_BF *a1) {
    s32 r, g, b;
    s32 v = a1->x0;
    if (v != 0 && a1->x2 == 0) {
        return;
    }
    a1->x2 = 0;
    a1->x0 = a1->xC;
    if (v != 0) {
        a1->x0 = (f32)(s16)a1->xC * ((f32)v / (f32)a1->xE);
        if (a1->x0 <= 0) {
            a1->x0 = 1;
        }
    } else {
        func_003C1A60(a0, &r, &g, &b);
        a1->x4 = r;
        a1->x5 = g;
        a1->x6 = b;
    }
}
/* localdecomp:end func_003BF4F8 */

LINKER_REMNANT("asm/remnants", func_003BF5C0);
