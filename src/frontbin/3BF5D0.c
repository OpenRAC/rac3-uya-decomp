#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_0037E250(f32, f32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003BFEF0(void *, s32, f32, f32);
extern void func_003886E8(f32 *, void *, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003BF5D0 */
s32 func_003BF5D0(s32 arg0) {
    return (u32)(arg0 - 500) < 41;
}
/* localdecomp:end func_003BF5D0 */

/* localdecomp:start func_003BF5E0 */
extern s32 func_003BF5D0_003BF5E0(s16);
extern u32 D_001DA51C_003BF5E0[];
extern u32 D_001DA524[];
s32 func_003BF5E0(u32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 < D_001DA51C_003BF5E0[0]) return 0;
    if (D_001DA524[0] >= arg0) {
        return func_003BF5D0_003BF5E0(*(s16 *)((u8 *)arg0 + 0xAA)) != 0;
    }
    return 0;
}
/* localdecomp:end func_003BF5E0 */

LINKER_REMNANT("asm/remnants", func_003BF630);

/* localdecomp:start func_003BF640 */
extern f32 func_00388770(s32 a);
extern void func_00388830(s32 a, s32 b, f32 x);
void func_003BF640(s32 a, f32 x) {
    if (x < func_00388770(a)) func_00388830(a, a, x);
}
/* localdecomp:end func_003BF640 */

LINKER_REMNANT("asm/remnants", func_003BF690);

/* localdecomp:start func_003BF6A8 */
extern f32 func_0037E250(f32, f32);
void func_003BF6A8(f32 *v, f32 r) {
    v[0] += func_0037E250(-r, r);
    v[1] += func_0037E250(-r, r);
    v[2] += func_0037E250(-r, r);
}
/* localdecomp:end func_003BF6A8 */

LINKER_REMNANT("asm/remnants", func_003BF728);

/* localdecomp:start func_003BF778 */
extern void func_00388830(s32 a, s32 b, f32 x);
void func_003BF778(void *a, f32 f) {
    f32 r;
    ((void (*)(void *, f32))func_00388830)(a, f);
    r = 1.0f - f * f;
    __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(r) : "f"(r));
    *(f32*)((u8*)a + 0xC) = r;
}
/* localdecomp:end func_003BF778 */

LINKER_REMNANT("asm/remnants", func_003BF7C8);

/* localdecomp:start func_003BF7E8 */
int func_003BF7E8(unsigned char *object) {
    unsigned char *link;
    int flags;

    if (object != 0)
        goto check_flags;
failure:
    return 0;
check_flags:
    flags = *(unsigned short *)(object + 0x34) & 0x20;
    __asm__ volatile(".word 0");
    if (flags == 0)
        goto failure;
    link = *(unsigned char **)(object + 0x68);
    if (link == 0)
        goto failure;
    return *(int *)(link + 8);
}
/* localdecomp:end func_003BF7E8 */

LINKER_REMNANT("asm/remnants", func_003BF820);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF838);

LINKER_REMNANT("asm/remnants", func_003BF8F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF910);

LINKER_REMNANT("asm/remnants", func_003BFA18);

/* localdecomp:start func_003BFAF8 */
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_00388E78(M_3BFAF8 *, void *);
void func_003888C8(void *, void *, M_3BFAF8 *);
void func_003BFAF8(u8 *a, void *b, void *c, M_3BFAF8 *d) {
M_3BFAF8 m; if (d == 0) { func_00388E78(&m, a + 0xC0); func_003888C8(b, c, &m); } else { func_003888C8(b, c, d); }
}
/* localdecomp:end func_003BFAF8 */

LINKER_REMNANT("asm/remnants", func_003BFB60);

/* localdecomp:start func_003BFB80 */
f32 func_003BFB80(s32 a, s32 b, s32 c) {
    f32 v[4];
    func_003BFAF8(a, v, b, c);
    return v[2];
}
/* localdecomp:end func_003BFB80 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BFBA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFC18);

/* localdecomp:start func_003BFCE8 */
extern void func_003BFC18(void *);
 
void func_003BFCE8(void *p) {
    func_003BFC18((u8 *)p + 0x10);
}
/* localdecomp:end func_003BFCE8 */

LINKER_REMNANT("asm/remnants", func_003BFD08);

/* localdecomp:start func_003BFD10 */
extern s32 D_001D5BEC[];
extern void func_003BFC18_003BFD10();
extern void func_00388830(s32, s32, f32);
void func_003BFD10(void *a0, f32 *out, f32 *in, f32 f) {
    f32 v[4];
    if (D_001D5BEC[0] == 0) {
        out[2] = in[2] - f;
    } else {
        func_003BFC18_003BFD10(a0, v, 0);
        func_00388830((s32)v, (s32)v, f);
        __asm__ __volatile__(
            "lqc2 $vf1, 0(%1)\n"
            "lqc2 $vf2, 0(%2)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "r"(in), "r"(v) : "memory");
    }
}
/* localdecomp:end func_003BFD10 */

/* localdecomp:start func_003BFD90 */
extern void func_003BFD10_003BFD90(void *);
 
void func_003BFD90(void *p) {
    func_003BFD10_003BFD90((u8 *)p + 0x10);
}
/* localdecomp:end func_003BFD90 */

LINKER_REMNANT("asm/remnants", func_003BFDB0);

/* localdecomp:start func_003BFDB8 */
extern void func_003886E8(f32 *, void *, f32);
extern void func_003BFE08(s32, f32 *, s32);
void func_003BFDB8(s32 a, s32 b, s32 c) {
    f32 buf[4];
    ((void (*)(f32 *, f32))func_003886E8)(buf, -1.0f);
    func_003BFE08(a, buf, c);
}
/* localdecomp:end func_003BFDB8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BFE08);

LINKER_REMNANT("asm/remnants", func_003BFEE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFEF0);

LINKER_REMNANT("asm/remnants", func_003C00B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0188);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318AC0);

/* localdecomp:start func_003C0B10 */
typedef struct { u8 key; u8 b1; u8 pad[2]; f32 f4, f8, fC, f10, f14, f18, f1C; } E3C;
typedef struct { u8 pad[0x14]; E3C *e; } P3C;
typedef struct { u8 pad[0xC]; u8 n; u8 pad2[0x3B]; P3C *arr[1]; } S3C;
typedef struct { u8 pad[0x24]; S3C *set; } O3C;
extern s32 func_0037E1D8();
extern f32 func_0037E250(f32, f32);
s32 func_003C0B10(O3C *obj, s32 key, s32 *idx, f32 *o1, f32 *o2, f32 *o3, f32 *o4, f32 *o5, f32 *o6, f32 *o7, u8 *o8) {
    E3C *e;
    s32 cnt = 0;
    s32 r;
    s32 i;
    s32 j;
    for (j = 0; j < obj->set->n; j++) {
        if (obj->set->arr[j]->e) {
            if (obj->set->arr[j]->e->key == key) cnt++;
        }
    }
    if (cnt == 0) return 0;
    r = func_0037E1D8(cnt);
    for (i = 0; i < obj->set->n; i++) {
        e = obj->set->arr[i]->e;
        if (e && e->key == key) {
            if (r != 0) {
                r--;
            } else {
                *o1 = e->f8 * 0.016666668f;
                *o2 = e->fC * 0.016666668f;
                *o3 = e->f10 * 0.00027777778f;
                *o4 = e->f14 * 0.00027777778f;
                *o7 = e->f4 * 0.00027777778f;
                *o5 = e->f18;
                *o6 = e->f1C;
                if (e->b1) *o8 = e->b1;
                *o1 = func_0037E250(*o1 * 0.87f, *o1 * 1.13f);
                *o2 = func_0037E250(*o2 * 0.85f, *o2 * 1.15f);
                *o3 = func_0037E250(*o3 * 0.85f, *o3 * 1.15f);
                *o7 = func_0037E250(*o7 * 0.9f, *o7 * 1.1f);
                *idx = i;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003C0B10 */

/* localdecomp:start func_003C0D70 */
typedef struct { u8 pad[0x48]; void *a[1]; } S_3C0D70;
void func_003C0D70(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg_sp0, u8 *arg_sp8) {
    u8 temp_3_2;
    void *temp_3;
    S_3C0D70 *s;

    s = *(S_3C0D70 **)((u8 *)arg0 + 0x24);
    temp_3 = (*(void **)((u8 *)s->a[arg1] + 0x14));
    if (temp_3 != 0) {
        *arg2 = (*(f32 *)((u8 *)temp_3 + 8)) * 0.016666668f;
        *arg3 = (*(f32 *)((u8 *)temp_3 + 0xC)) * 0.016666668f;
        *arg4 = (*(f32 *)((u8 *)temp_3 + 0x10)) * 0.00027777778f;
        *arg5 = (*(f32 *)((u8 *)temp_3 + 0x14)) * 0.00027777778f;
        *arg_sp0 = (*(f32 *)((u8 *)temp_3 + 4)) * 0.00027777778f;
        *arg6 = (*(f32 *)((u8 *)temp_3 + 0x18));
        *arg7 = (*(f32 *)((u8 *)temp_3 + 0x1C));
        temp_3_2 = (*(u8 *)((u8 *)temp_3 + 1));
        if (temp_3_2 != 0) {
            *arg_sp8 = temp_3_2;
        }
    }
}
/* localdecomp:end func_003C0D70 */
