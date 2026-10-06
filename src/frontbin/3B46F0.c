#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B5BD0(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 *func_003B46F0(s32);
extern s32 func_003B4778(s32 *);
extern void func_003B5A70();
extern void func_003B56D0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003B56F0(void *, f32, f32, f32, f32);
extern void func_003B5000(void *, s32, f32, f32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B46F0 */
typedef struct { u8 b[0xB4]; } E_3B46F0;
extern E_3B46F0 D_0027CD70[];
extern s32 D_001DA228;
extern void func_003B45B0(E_3B46F0 *);
s32 *func_003B46F0(s32 idx) {
    s32 i;
    E_3B46F0 *p;
    if (D_001DA228 == 0) {
        p = D_0027CD70;
        i = 3;
        do { func_003B45B0(p); i--; __asm__ volatile("nop"); p++; } while (i != -1);
        D_001DA228 = 1;
    }
    return (s32 *)&D_0027CD70[idx];
}
/* localdecomp:end func_003B46F0 */

/* localdecomp:start func_003B4778 */
s32 func_003B4778(s32 *p) {
    return p[1] + p[2];
}
/* localdecomp:end func_003B4778 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B4788);

/* localdecomp:start func_003B4950 */
s32 func_003B4950(void *p, s32 x, s32 y) {
    return *(s32 *)((u8 *)p + 0xB0) + (*(s32 *)((u8 *)p + 0x14) * y + x) * 0x44;
}
/* localdecomp:end func_003B4950 */

/* localdecomp:start func_003B4970 */
s32 func_003B4970(void *p, s32 x, s32 y) {
    y += 0x4F0000;
    return x * (*(s32 *)((u8 *)p + 0x14) * *(s32 *)((u8 *)p + 0x10)) + y;
}
/* localdecomp:end func_003B4970 */

/* localdecomp:start func_003B4990 */
s32 func_003B4990(s32 a0, s32 a1) {
    return a1 + 0x4F0048;
}
/* localdecomp:end func_003B4990 */

/* localdecomp:start func_003B49A0 */
s32 func_003B49A0(s32 a0, s32 a1) {
    return a1 + 0x4F00A9;
}
/* localdecomp:end func_003B49A0 */

/* localdecomp:start func_003B49B0 */
extern s32 func_003E3040();
 
s32 func_003B49B0(u8 *p) {
    s32 r = 0;
    if (p[0] != 0) {
        p[0] = 0;
        func_003E3040(*(s32 *)(p + 0x18));
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003B49B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B49E8);

/* localdecomp:start func_003B4E60 */
void func_003B4E60(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x8c) = a1;
    *(s32 *)((u8 *)a0 + 0x90) = a2;
    *(s32 *)((u8 *)a0 + 0x94) = a3;
    *(s32 *)((u8 *)a0 + 0x98) = a4;
}
/* localdecomp:end func_003B4E60 */

/* localdecomp:start func_003B4E78 */
extern s32 func_003B4970(void *, s32, s32);
extern s32 func_003E23C0(s32, s32, s32);
typedef struct { u8 p[0x10]; s32 n; } S_B4E78;
void func_003B4E78(S_B4E78 *s) {
    s32 i, t;
    for (i = 0; ; ) {
        t = s->n + 2;
        if (i >= t) break;
        func_003E23C0(func_003B4970(s, 0, i), 1, 3);
        func_003E23C0(func_003B4970(s, 1, i), 2, 3);
        i++;
    }
}
/* localdecomp:end func_003B4E78 */

LINKER_REMNANT("asm/remnants", func_003B4F08);

/* localdecomp:start func_003B4F10 */
extern s32 func_003E24B0(s32 arg0, s32 arg1);
void func_003B4F10(u8 *p) {
    func_003E24B0(0x4F00B0, p[0xA8]);
    func_003E24B0(0x4F00B1, p[0xA8]);
}
/* localdecomp:end func_003B4F10 */

/* localdecomp:start func_003B4F50 */
extern s32 func_003B4990(s32, s32);
extern s32 func_003E2C88(s32, f32, f32);
extern s32 func_003E24B0(s32, s32);
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x4C]; f32 x60; u8 p64[0x10]; u8 x74; u8 p75[0x2B]; f32 xA0; f32 xA4; } S_4F;
void func_003B4F50(S_4F *a0) {
    f32 t = a0->x60 - a0->xA0;
    s32 i;
    if (t < 0.0f) t = 0.0f;
    for (i = 0; i < a0->x10 + 2; i++) {
        func_003E2C88(func_003B4990((s32)a0, i), t, a0->xA4);
        func_003E24B0(func_003B4990((s32)a0, i), a0->x74);
    }
}
/* localdecomp:end func_003B4F50 */

/* localdecomp:start func_003B5000 */
void func_003B5000(void *a0, s32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "sb $5, 0x74($4)\n"
        "swc1 $12, 0x70($4)\n"
        "swc1 $13, 0xa4($4)\n"
        :: "r"(a0), "r"(a1)
    );
    *(f32 *)((u8 *)a0 + 0xa0) = a4;
}
/* localdecomp:end func_003B5000 */

/* localdecomp:start func_003B5018 */
extern void func_003B4F50();
extern void func_003B51F0(void *);
extern void func_003B52B0(void *);
extern void func_003B5440(void *, s32);
extern void func_003B57F8(void *);
extern void func_003B60F0();
extern s32 func_003E1E50(s32, f32, f32);
extern s32 func_003E21F8(s32, f32);
extern s32 func_003E24B0(s32 arg0, s32 arg1);
extern s32 func_003E2C88(s32, f32, f32);

void func_003B5018(void *arg0, s32 arg1) {
    func_003B4F10(arg0);
    func_003B5128(arg0);
    func_003B51F0(arg0);
    func_003B52B0(arg0);
    func_003B57F8(arg0);
    func_003B4F50(arg0);
    func_003B60F0();
    if ((*(s32 *)((u8 *)(arg0) + 0x1C)) == 0) {
        func_003B5440(arg0, arg1);
    }
    func_003E1E50(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_003E2C88(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_003E1E50(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_003E2C88(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_003E24B0(0x4F00B3, (*(u8 *)((u8 *)(arg0) + 0xA9)));
    func_003E21F8(0x4F00B0, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_003E21F8(0x4F00B1, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_003E2C88(0x4F00AF, (*(f32 *)((u8 *)(arg0) + 0x60)), (*(f32 *)((u8 *)(arg0) + 0x64)));
}
/* localdecomp:end func_003B5018 */

/* localdecomp:start func_003B5128 */
void func_003B5128(void *arg0) {
    f32 var_f0;
    f32 var_f1;
    s32 temp_v1;

    temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1C));
    var_f0 = 0.0048076925f;
    switch (temp_v1) {                              /* irregular */
    case 1:
        var_f1 = -1.0f;
        break;
    case 3:
        var_f1 = -1.0f;
        var_f0 = 0.01923077f;
        break;
    case 2:
        var_f1 = 1.0f;
        break;
    case 4:
        var_f1 = 1.0f;
        var_f0 = 0.01923077f;
        break;
    default:
        var_f1 = 0.0f;
        break;
    }
    (*(f32 *)((u8 *)(arg0) + 0x58)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x58)) + (var_f1 * var_f0));
}
/* localdecomp:end func_003B5128 */

/* localdecomp:start func_003B51F0 */
void func_003B51F0(void *arg0)
{
  f32 temp_f0;
  f32 temp_f1;
  s32 temp_2_2;
  s32 temp_2;
  s32 temp_3;
  s32 temp_4;
  s32 temp_5;
  s32 var_3;
  temp_f1 = *((f32 *) (((u8 *) arg0) + 0x58));
  temp_f0 = *((f32 *) (((u8 *) arg0) + 0x54));
  if ((temp_f0 < temp_f1) || (temp_f1 < (-temp_f0)))
  {
    temp_3 = *((s32 *) (((u8 *) arg0) + 0x1C));
    switch (temp_3)
    {
      case 3:

      case 1:
        temp_2 = (*((s32 *) (((u8 *) arg0) + 4))) + 1;
        *((s32 *) (((u8 *) arg0) + 4)) = temp_2;
        var_3 = temp_2;
        break;

      default:
        temp_2_2 = (*((s32 *) (((u8 *) arg0) + 4))) - 1;
        *((s32 *) (((u8 *) arg0) + 4)) = temp_2_2;
        var_3 = temp_2_2;
        break;

    }

    temp_4 = *((s32 *) (((u8 *) arg0) + 0xC));
    temp_5 = (var_3 > (-1)) ? (var_3) : (0);
    *((f32 *) (((u8 *) arg0) + 0x58)) = 0.0f;
    *((s32 *) (((u8 *) arg0) + 0x1C)) = 0;
    *((s32 *) (((u8 *) arg0) + 4)) = (s32) ((temp_5 < temp_4) ? (temp_5) : (temp_4 - 1));
  }
}
/* localdecomp:end func_003B51F0 */

/* localdecomp:start func_003B5290 */
void func_003B5290(s32 *p) {
    s32 c = p[3];
    if (p[1] >= c) {
        p[1] = c - 1;
    }
}
/* localdecomp:end func_003B5290 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B52B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5440);

LINKER_REMNANT("asm/remnants", func_003B56C8);

/* localdecomp:start func_003B56D0 */
void func_003B56D0(s32 *arg0, float float1, float float2, float float3, float float4, float float5) {
    float *floatPtr = (float *)arg0;
    
    floatPtr[24] = float2; // $f13 -> 0x60
    floatPtr[25] = float3; // $f14 -> 0x64
    floatPtr[26] = float4; // $f15 -> 0x68
    floatPtr[27] = float5; // $f16 -> 0x6c
    floatPtr[23] = float1; // $f12 -> 0x5c
    
    arg0[30] = 0;          // $zero -> 0x78
}
/* localdecomp:end func_003B56D0 */

/* localdecomp:start func_003B56F0 */
void func_003B56F0(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "swc1 $15, 0x88($4)\n"
        "swc1 $12, 0x7c($4)\n"
        "swc1 $13, 0x80($4)\n"
        :: "r"(a0)
    );
    *(f32 *)((u8 *)a0 + 0x84) = a3;
}
/* localdecomp:end func_003B56F0 */

/* localdecomp:start func_003B5708 */
typedef struct { u8 p0[0x40]; s32 f40; } Q_3B5708;
typedef struct { u8 p0[0x8C]; s32 f8C; s32 f90; s32 f94; s32 f98; } R_3B5708;
extern Q_3B5708 *func_003B4950();
extern s32 func_003B4970();
extern s32 func_003E2808();
void func_003B5708(R_3B5708 *a, s32 b, s32 c, s32 d) {
    s32 r;
    switch (func_003B4950(a, b, d)->f40) {
    case 0:
        r = func_003B4970(a, b, c);
        func_003E2808(r, a->f8C);
        break;
    case 1:
        r = func_003B4970(a, b, c);
        func_003E2808(r, a->f90);
        break;
    case 2:
        r = func_003B4970(a, b, c);
        func_003E2808(r, a->f94);
        break;
    case 3:
        r = func_003B4970(a, b, c);
        func_003E2808(r, a->f98);
        break;
    case 4:
        r = func_003B4970(a, b, c);
        func_003E2808(r, a->f90);
        break;
    }
}
/* localdecomp:end func_003B5708 */
INCLUDE_ASM("asm/nonmatchings/text", func_003B57F8);

/* localdecomp:start func_003B5A70 */
extern s32 func_0037DF98(s32);
extern void func_003B5AB0(s32, s32, s32);
void func_003B5A70(s32 a, s32 b, s32 c) {
    func_003B5AB0(func_0037DF98(a), b, c);
}
/* localdecomp:end func_003B5A70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5AB0);

extern s32 D_001D8C18[];
/* localdecomp:start func_003B5BD0 */
extern s32 D_001D8C18_003B5BD0;
void func_003B5BD0(void) {
    *(u8 *)&D_001D8C18_003B5BD0 = 1;
}
/* localdecomp:end func_003B5BD0 */

/* localdecomp:start func_003B5BE0 */
extern u8 D_001D8C18_003B5BE0;
s32 func_003B5BE0(void) {
    return D_001D8C18_003B5BE0;
}
/* localdecomp:end func_003B5BE0 */

/* localdecomp:start func_003B5BE8 */
extern u8 D_001D8C18_003B5BE8;
void func_003B5BE8(void) {
    D_001D8C18_003B5BE8 = 0;
}
/* localdecomp:end func_003B5BE8 */

LINKER_REMNANT("asm/remnants", func_003B5BF0);
