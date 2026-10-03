#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00388440();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_00388440(void *, s32, s32);
extern s32 *func_003E03C8(s32 *);
extern s32 func_003E0FC8();
extern void func_00388440(void *, int, int);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0190);

LINKER_REMNANT("asm/remnants", func_003E0358);

/* localdecomp:start func_003E0370 */
void func_003E0370(f32 *p, f32 lo, f32 hi) {
    *p = (*p < lo) ? lo : *p;
    *p = (hi < *p) ? hi : *p;
}
/* localdecomp:end func_003E0370 */

/* localdecomp:start func_003E03A8 */
extern s32 func_003E0E28();
 
s32 func_003E03A8(void **p) {
    return func_003E0E28(p) != 0;
}
/* localdecomp:end func_003E03A8 */

/* localdecomp:start func_003E03C8 */
s32 *func_003E03C8(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003E03C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E03D8);

/* localdecomp:start func_003E0478 */
extern u8 D_00302E80_003E0478[];
extern s32 D_001DA8F8_003E0478;
extern void *func_003E1120();
extern void func_116FD0();
extern void func_003E03D8();
void *func_003E0478(s32 idx) {
    u8 *q;
    s32 *w;
    s32 n, j;
    if (D_001DA8F8_003E0478 == 0) {
        q = D_00302E80_003E0478;
        n = 4;
        do {
            w = (s32 *)(q + 0x50);
            for (j = 0x22; j != -1; j--) *w++ = 0;
            func_003E1120(q + 0x1C4);
            func_003E1120(q + 0x21CC);
            q += 0x41DC;
            n--;
        } while (n != -1);
        D_001DA8F8_003E0478 = 1;
        func_116FD0(func_003E03D8);
    }
    return D_00302E80_003E0478 + idx * 0x41DC;
}
/* localdecomp:end func_003E0478 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0550);

/* localdecomp:start func_003E0680 */
s32 func_003E0680(void **p) {
    return *(s32 *)((u8 *)*p + 0x1C0);
}
/* localdecomp:end func_003E0680 */

LINKER_REMNANT("asm/remnants", func_003E0690);

/* localdecomp:start func_003E06A0 */
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
void func_003E06A0(S_3E06A0 **p) {
    s32 i;
    for (i = 0; i < 16; i++) (*p)->a[i] = 0;
}
/* localdecomp:end func_003E06A0 */

/* localdecomp:start func_003E06D0 */
extern void func_003E1A90(void *);

void func_003E06D0(s32 *arg0) {
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s2;
    void *temp_v0;

    var_s2 = 0;
    do {
        temp_s0 = var_s2 * 4;
        temp_v1 = (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC));
        if (temp_v1 != 0) {
            func_003E1A90(temp_v1);
        }
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x11C)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x15C)) = 0;
        (*(s8 *)((u8 *)((*arg0 + var_s2)) + 0x1AC)) = 0;
        temp_v0 = *arg0 + var_s2;
        var_s2 += 1;
        (*(s8 *)((u8 *)(temp_v0) + 0x19C)) = 0;
    } while (var_s2 < 0x10);
}
/* localdecomp:end func_003E06D0 */

/* localdecomp:start func_003E0770 */
s32 func_003E0770(void **p) {
    return *(s32 *)((u8 *)*p + 0x1BC);
}
/* localdecomp:end func_003E0770 */

/* localdecomp:start func_003E0780 */
typedef struct { u8 pad[0xDC]; s32 arr[1]; } S_3E0780;
 
s32 func_003E0780(S_3E0780 **p, s32 i) {
    return (*p)->arr[i];
}
/* localdecomp:end func_003E0780 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0798);

/* localdecomp:start func_003E0870 */
extern s32 func_003E1BC8();
extern s32 func_003E0680();
extern s32 func_003E0FC8(s32);
extern s32 func_003E1950();
s32 func_003E0870(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x14;
        if (*q) func_003E1BC8(*q);
        *q = 0;
        for (i = 3; i >= 0; i--) {
            func_003E1950(func_003E0FC8(func_003E0680(p)));
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E0870 */

/* localdecomp:start func_003E0900 */
void func_003E0900(s32 **p) {
    s32 i;
    for (i = 0; i < 35; i++) (*p)[i + 20] = 0;
}
/* localdecomp:end func_003E0900 */

/* localdecomp:start func_003E0930 */
typedef struct { u8 b[16]; } B16_003E0930;
extern B16_003E0930 D_001D9680_003E0930;
extern void func_003E10E8_003E0930();
extern void func_003E06D0_003E0930();
extern void func_003E0900_003E0930();
extern void func_003E06A0_003E0930();
void func_003E0930(u8 **o) {
    B16_003E0930 tmp;
    func_003E10E8_003E0930(*o + 0x1C4);
    func_003E10E8_003E0930(*o + 0x21CC);
    func_003E06D0_003E0930(o);
    func_003E0900_003E0930(o);
    func_003E06A0_003E0930(o);
    tmp = D_001D9680_003E0930;
    *(B16_003E0930 *)*o = tmp;
    *(s32 *)(*o + 0x1BC) = -1;
}
/* localdecomp:end func_003E0930 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E09D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0B78);

/* localdecomp:start func_003E0CC0 */
typedef struct { u8 pad[0xDC]; s32 A[16]; s32 B[16]; } O_003E0CC0;
extern s32 func_003E1A98_003E0CC0();
s32 func_003E0CC0(O_003E0CC0 **pp, s32 b) {
    s32 r = -1;
    s32 i;
    if (func_003E1A98_003E0CC0(b) == 0) {
        for (i = 0; i < 16; i++) {
            if ((*pp)->A[i] == 0 && (*pp)->B[i] == 0) {
                (*pp)->B[i] = b;
                r = i;
                break;
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E0CC0 */

/* localdecomp:start func_003E0D78 */
typedef struct { u8 pad[0x11C]; s32 slots[36]; u8 used[1]; } T_3E0D78;
typedef struct { T_3E0D78 *t; } S_3E0D78;
s32 func_003E0D78(S_3E0D78 *s, s32 v) {
    s32 i = func_003E0770(s);
    T_3E0D78 *t;
    if (i < 0) return 0;
    t = s->t;
    if (t->slots[i] != 0) return 0;
    if (t->used[i] != 0) return 0;
    t->slots[i] = v;
    return 1;
}
/* localdecomp:end func_003E0D78 */

LINKER_REMNANT("asm/remnants", func_003E0DF0);

/* localdecomp:start func_003E0DF8 */
extern s32 func_003E11D0();
 
void func_003E0DF8(void **p, s32 a, s32 b) {
    func_003E11D0((u8 *)*p + 0x1C4, b, a);
}
/* localdecomp:end func_003E0DF8 */

/* localdecomp:start func_003E0E28 */
extern void *func_003E1150();
 
s32 func_003E0E28(void **p) {
    return func_003E1150((u8 *)*p + 0x1C4);
}
/* localdecomp:end func_003E0E28 */

/* localdecomp:start func_003E0E48 */
typedef struct {
    u8 pad0[0xDC];
    s32 a[16];
    s32 b[16];
    u8 pad1[0x50];
    u8 c[16];
} S_3E0E48;
s32 func_003E0E48(void *a0, s32 a1) {
    S_3E0E48 *s = *(S_3E0E48 **)a0;
    s32 r = 0;
    if (s->a[a1] != 0 && s->c[a1] == 0) {
        s->b[a1] = 0;
        (*(S_3E0E48 **)a0)->c[a1] = 1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E0E48 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0E90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0FC8);

/* localdecomp:start func_003E10E8 */
void func_003E10E8(u8 *p) {
    func_00388440((s32)(p + 8), 0, 0x2000);
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003E10E8 */

/* localdecomp:start func_003E1120 */
extern s32 *func_003ECDC8(s32 *);
void *func_003E1120(void *p) {
    func_003ECDC8((s32 *)p);
    func_003E10E8(p);
    return p;
}
/* localdecomp:end func_003E1120 */
