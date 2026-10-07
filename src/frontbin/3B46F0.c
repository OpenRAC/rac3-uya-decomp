#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B5BD0(void);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003B5018(void *, s32);
extern s32 *func_003B46F0(s32);
extern s32 func_003B4778(s32 *);
extern void func_003B5A70();
extern s32 func_003B5BE0(void);
extern void func_003B5BE8(void);
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

/* localdecomp:start func_003B4788 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B4788;
typedef struct { u8 f0; u8 p1[3]; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; s32 f58; u8 p5C[0x4C]; u8 fA8; u8 fA9; u8 pAA[2]; f32 fAC; s32 fB0; } O_3B4788;
extern void func_003B49E8();
extern void func_00388440();
extern void func_003B4E60();
s32 func_003B4788(O_3B4788 *o, S_3B4788 *s) {
    s32 size;
    s32 ret = 1;
    s32 i, j, k;
    o->fA8 = 0;
    o->fA9 = 0;
    { s32 t = s->fC * 0x44; size = s->f14 * t; }
    if (size >= s->f0) {
        ret = 0;
    } else {
        o->f4 = 0;
        o->f8 = 0;
        o->fC = s->fC;
        o->f10 = s->f10;
        o->f14 = s->f14;
        o->f18 = s->f8;
        o->f1C = 0;
        for (k = 0; k < 4; k++) {
            o->a20[k] = s->a24[k];
            o->a30[k] = s->a44[k];
            o->a40[k] = s->a34[k];
        }
        o->f50 = s->f1C;
        o->f54 = s->f20;
        o->fAC = s->f18;
        o->fB0 = s->f4;
        func_003B49E8(o);
        o->f0 = 1;
    }
    func_00388440(o->fB0, 0, size);
    for (i = 0; i < o->f14; i++) {
        for (j = 0; j < o->fC; j++) {
            *(s32 *)((u8 *)func_003B4950(o, i, j) + 0x40) = 0;
        }
    }
    func_003B4E60(o, 0x8066CCFF, 0x80808080, 0x666690CC, 0x80FFFFFF);
    o->f58 = 0;
    return ret;
}
/* localdecomp:end func_003B4788 */

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

/* localdecomp:start func_003B49E8 */
typedef struct { u8 p0[0x10]; s32 f10; s32 f14; s32 f18; u8 p1C[4]; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; u8 p58[4]; f32 f5C; f32 f60; u8 p64[8]; f32 f6C; f32 f70; u8 p74[0x28]; u32 f9C; f32 fA0; f32 fA4; u8 pA8[4]; f32 fAC; } S_3B49E8;
extern void func_003E3EE8();
extern s32 func_003E2C88(s32, f32, f32);
extern void func_003E38B0_003B49E8(s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E3330(s32, f32, f32);
extern s32 func_003E33F0(s32, s32);
extern s32 func_003E2560(s32, s32);
extern s32 func_003E3BD0_003B49E8(s32, u32, f32, f32, f32, f32, s32);
extern s32 func_003E3988(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E34A0(s32, s32, s32);
extern s32 func_003E24B0(s32, s32);
extern s32 func_003E2DE0(s32, s32);
void func_003B49E8(S_3B49E8 *o) {
    s32 j, i;
    u32 k;
    f32 t;
    func_003B49B0((u8 *)o);
    func_003E3EE8(0x4F00A8);
    func_003E2C88(0x4F00A8, 0.5f, 0.5f);
    func_003E38B0_003B49E8(0x4F00A8, 1);
    func_003E3EE8(0x4F00AE);
    func_003E30C8(0x4F00A8, 0x4F00AE);
    for (j = 0; j < o->f14; j++) {
        func_003E3EE8(func_003B49A0((s32)o, j));
        func_003E30C8(0x4F00A8, func_003B49A0((s32)o, j));
        for (i = 0; i < o->f10 + 2; i++) {
            func_003E3A80(func_003B4970(o, j, i), func_003B4950(o, j, i), 0x8066CCFF, o->a20[j], o->f50 + (f32)i * o->f54, o->fAC, o->fAC);
            func_003E3330(func_003B4970(o, j, i), o->a40[j], o->a30[j]);
            func_003E33F0(func_003B4970(o, j, i), 1);
            func_003E2560(func_003B4970(o, j, i), 1);
            func_003E30C8(func_003B49A0((s32)o, j), func_003B4970(o, j, i));
        }
    }
    t = o->f60 - o->fA0;
    if (t < 0.0f) t = 0.0f;
    func_003E3EE8(0x4F00AD);
    func_003E30C8(0x4F00A8, 0x4F00AD);
    o->f9C = o->f10 + 3;
    for (k = 0; k < o->f9C; k++) {
        func_003E3BD0_003B49E8(func_003B4990((s32)o, k), 0x331465B7, o->f5C, o->f50 + (f32)(k - 1) * o->f54 + o->f70, t, o->fA4, 0);
        func_003E30C8(0x4F00AD, func_003B4990((s32)o, k));
    }
    func_003E3BD0_003B49E8(0x4F00AF, 0x706EC8FF, 0.5f, 0.5f, 1.0f, 0.1f, 0);
    func_003E30C8(0x4F00AE, 0x4F00AF);
    func_003E3988(0x4F00B0, 0x80, 0x331465B7, 0.5f, 0.5f, 1.0f, 0.6f, o->f6C);
    func_003E3988(0x4F00B1, 0x80, 0x331465B7, 0.5f, 0.5f, 1.0f, -0.6f, o->f6C);
    func_003E34A0(0x4F00AE, 0x4F00B0, 0x4F00B1);
    func_003E3BD0_003B49E8(0x4F00B3, 0x70000000, 0.5f, 0.5f, 0.25f, 0.25f, 0);
    func_003E24B0(0x4F00B3, 0);
    func_003E30C8(0x4F00A8, 0x4F00B3);
    func_003E2DE0(o->f18, 0x4F00A8);
}
/* localdecomp:end func_003B49E8 */

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

/* localdecomp:start func_003B52B0 */
typedef struct {
    u8 p0[0x10]; s32 f10; s32 f14; u8 p18[8]; f32 f20[12];
    f32 f50; f32 f54; f32 f58; f32 f5C; u8 p60[0x10]; f32 f70; u8 p74[4]; f32 f78; u8 p7C[0x20]; u32 f9C;
} S_3B52B0;
void func_003B52B0(void *arg0) {
    S_3B52B0 *o = arg0;
    s32 i;
    s32 j;
    u32 k;
    f32 y;
    for (i = 0; i < o->f14; i++) {
        y = o->f50 + o->f58 - o->f54;
        for (j = 0; j < o->f10 + 2; j++) {
            func_003E1E50(func_003B4970(o, i, j), o->f20[i], y + o->f54 * j - o->f78);
        }
        if (i == 0) {
            for (k = 0; k < o->f9C; k++) {
                func_003E1E50(func_003B4990((s32)o, k), o->f5C, y + (f32)(k - 1) * o->f54 + o->f70);
            }
        }
    }
}
/* localdecomp:end func_003B52B0 */

/* localdecomp:start func_003B5440 */
extern void func_0039FF28(s32, s32, s32);
extern void func_003B60B0(s32);
typedef struct {
    u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[8]; s32 f1C; u8 p20[0x30];
    f32 f50; f32 f54; u8 p58[4]; f32 f5C; u8 p60[8]; f32 f68; u8 p6C[0xC]; f32 f78;
} S_3B5440;
typedef struct { u8 p[0x40]; s32 f40; } E_3B5440;
void func_003B5440(void *arg0, s32 b) {
    S_3B5440 *o = arg0;
    f32 base = o->f50;
    f32 step = o->f54;
    f32 y;
    if (b & 0x1000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n - 1;
        if (n > 0) {
            while (j > 0 && ((E_3B5440 *)func_003B4950(o, 0, j))->f40 == 4) j--;
            if (((E_3B5440 *)func_003B4950(o, 0, j))->f40 != 4) {
                d = n - j;
                if (d <= o->f8 + 1) {
                    o->f8 = j - o->f4;
                } else {
                    s32 t;
                    t = o->f4 + 1;
                    o->f4 = t - (d - o->f8);
                    o->f8 = -1;
                }
            }
        }
        ((s32 (*)(s32, s32, s32))func_0039FF28)(3, 0, 0);
        if (o->f8 < 0) {
            o->f8 = 0;
            if (o->f4 - 1 >= 0) o->f1C = 2;
        }
    } else if (b & 0x4000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n + 1;
        if (n < o->fC - 1) {
            while (j < o->fC - 1 && ((E_3B5440 *)func_003B4950(o, 0, j))->f40 == 4) j++;
            if (((E_3B5440 *)func_003B4950(o, 0, j))->f40 != 4) {
                d = j - n;
                if (d <= o->f10 - o->f8) {
                    o->f8 = j - o->f4;
                } else {
                    o->f8 = o->f10;
                    o->f4 = j - o->f10;
                }
            }
        }
        ((s32 (*)(s32, s32, s32))func_0039FF28)(3, 0, 0);
        if (o->f10 - 1 < o->f8) {
            o->f8 = o->f10 - 1;
            {
                s32 t = o->f4 + 1;
                if (!(o->fC - o->f10 < t)) o->f1C = 1;
            }
        }
    }
    y = base + (f32)o->f8 * step;
    func_003E1E50(0x4F00B0, o->f5C, y - o->f68);
    func_003E1E50(0x4F00AF, o->f5C, y - o->f78);
    func_003E1E50(0x4F00B1, o->f5C, y + o->f68);
    func_003B60B0(0x4F00AF);
}
/* localdecomp:end func_003B5440 */

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
/* localdecomp:start func_003B57F8 */
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; s32 f10; s32 f14; } O_3B57F8;
extern s32 func_003E22D0();
extern s32 func_003E2728();
extern void func_003B5290(s32 *);
void func_003B57F8(void *op) {
    O_3B57F8 *o = (O_3B57F8 *)op;
    s32 i;
    s32 a;
    s32 n;
    s32 j;
    s32 t;
    func_003B5290((s32 *)o);
    for (i = 0; i < o->f14; i++) {
        {
            a = o->f4;
            t = a - 1;
            n = o->f10;
            if (t <= -1) t = 0;
            j = func_003B4970(o, i, 0);
            func_003E2728(j, func_003B4950(o, i, t));
            func_003B5708(o, i, 0, t);
            if (a != 0) {
                func_003E22D0(func_003B4970(o, i, 0), 1, 1);
            } else {
                func_003E22D0(func_003B4970(o, i, 0), 1, 0);
            }
            j = 1;
            if (n > 0) {
                do {
                    if (a >= 0 && a < o->fC) {
                        func_003E22D0(func_003B4970(o, i, j), 1, 1);
                        t = func_003B4970(o, i, j);
                        func_003E2728(t, func_003B4950(o, i, a));
                        func_003B5708(o, i, j, a);
                    } else {
                        func_003E22D0(func_003B4970(o, i, j), 1, 0);
                    }
                    j++;
                    n--;
                    a++;
                } while (n > 0);
            }
            if (a != o->fC) {
                func_003E22D0(func_003B4970(o, i, j), 1, 1);
                if (a >= o->fC) a--;
                t = func_003B4970(o, i, j);
                func_003E2728(t, func_003B4950(o, i, a));
                func_003B5708(o, i, j, a);
            } else {
                func_003E22D0(func_003B4970(o, i, j), 1, 0);
            }
        }
    }
}
/* localdecomp:end func_003B57F8 */

/* localdecomp:start func_003B5A70 */
extern s32 func_0037DF98(s32);
extern void func_003B5AB0(s32, s32, s32);
void func_003B5A70(s32 a, s32 b, s32 c) {
    func_003B5AB0(func_0037DF98(a), b, c);
}
/* localdecomp:end func_003B5A70 */

/* localdecomp:start func_003B5AB0 */
extern s32 func_00389D18(f32, s32, s32);
extern f32 func_003BEB48(f32, f32, f32);
extern f32 D_001D96D8;
void func_003B5AB0(s32 a, s32 pp, s32 qq) {
    f32 *p = (f32 *)pp;
    f32 *q = (f32 *)qq;
    f32 r;
    f32 t;
    f32 k;
    f32 c;
    f32 lo;
    f32 hi;
    if (a != 0) {
        c = 0.49f;
        t = (f32)func_00389D18(1.2f, a, -1) / D_001D96D8;
        k = 1.2f;
        lo = 6.0f;
        hi = 11.0f;
        if (c < t) {
            k = 0.588000059f / t;
            t = c;
        }
        r = func_003BEB48(lo, hi, (t - 0.0f) / c);
        *q = r;
        if (hi < r) {
            *q = hi;
        } else if (r < lo) {
            *q = lo;
        }
        *p = k;
    }
}
/* localdecomp:end func_003B5AB0 */

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
