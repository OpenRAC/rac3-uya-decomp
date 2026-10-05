#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003CBE40();
extern void func_003CB890();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003CB890 */
extern void func_003CB498(s32, s32, s32);
extern s32 func_003D94A8(s32, s32, s32);
extern s32 func_003DBCE8(s32, s32, s32);
extern u8 D_002FB780[];
void func_003CB890(s32 arg0) {
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    void *temp_16;

    temp_16 = (arg0 * 0x30) + D_002FB780;
    temp_2 = (*(s32 *)((u8 *)temp_16 + 0xC));
    if (temp_2 != 0) {
        temp_4 = temp_2 + ((*(s16 *)((u8 *)temp_16 + 0)) * 2);
        func_003D94A8(temp_4, temp_4 + ((*(s16 *)((u8 *)temp_16 + 2)) * 2), arg0);
        temp_4_2 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 4)) * 2);
        (*(s16 *)((u8 *)temp_16 + 0)) = 0;
        (*(s16 *)((u8 *)temp_16 + 2)) = 0;
        func_003DBCE8(temp_4_2, temp_4_2 + ((*(s16 *)((u8 *)temp_16 + 6)) * 2), arg0);
        temp_4_3 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 8)) * 2);
        (*(s16 *)((u8 *)temp_16 + 4)) = 0;
        (*(s16 *)((u8 *)temp_16 + 6)) = 0;
        func_003CB498(temp_4_3, temp_4_3 + ((*(s16 *)((u8 *)temp_16 + 0xA)) * 2), arg0);
        (*(s16 *)((u8 *)temp_16 + 8)) = 0;
        (*(s16 *)((u8 *)temp_16 + 0xA)) = 0;
    }
}
/* localdecomp:end func_003CB890 */

/* localdecomp:start func_003CB958 */
typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001DA730[8];
extern f32 D_001DA740;
extern f32 D_001DA744;
extern volatile f32 D_001DA748;
extern u8 D_001DA750[];
extern void func_003886B0(void *, void *);
extern void func_003886E8(f32 *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(s32, s32, f32);
void func_003CB958(void *a, f32 t) {
    f32 v[4];
    f32 x, y, z;
    *(u128_3CB958 *)D_001DA730 = *(u128_3CB958 *)a;
    func_003886B0(v, a);
    func_003886E8((f32 *)D_001DA750, D_001DA730, t);
    x = v[0]; y = v[1]; z = v[2];
    if (x < y) {
        if (x < z) {
            D_001DA740 = x;
            D_001DA744 = z;
            D_001DA748 = y;
        } else {
            goto A;
        }
    } else if (y < z) {
        D_001DA740 = z;
        D_001DA744 = y;
        D_001DA748 = x;
    } else {
A:
        D_001DA740 = y;
        D_001DA744 = x;
        D_001DA748 = z;
    }
    func_00388758(&D_001DA740, &D_001DA740, D_001DA730);
    func_00388830((s32)&D_001DA740, (s32)&D_001DA740, 1.0f);
}
/* localdecomp:end func_003CB958 */

/* localdecomp:start func_003CBA68 */
void func_003CC4B0(s16 *);
void func_003CC5F8(s16 *);
char *func_003CBA68(s16 *p) {
    char *q = (char *)p;
    if (*p == 0) { func_003CC4B0(p); q += 0x20; }
    else if (*p == 1) { func_003CC5F8(p); q += 0x30; }
    return q;
}
/* localdecomp:end func_003CBA68 */

INCLUDE_ASM("asm/nonmatchings/text", func_003CBAC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBC70);

/* localdecomp:start func_003CBE40 */
__asm__(".extern D_001DA770, 4");
__asm__(".extern D_001D9380, 4");

typedef struct { s32 x0; void *x4; s32 x8; s32 xC; } Q_003CBE40;
typedef struct {
    s32 x0;
    s32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 pad1C[4];
    u8 x20[0x10];
} R_003CBE40;
typedef struct { u8 pad[0x150]; s16 x150; s16 x152; } V_003CBE40;

extern Q_003CBE40 *D_001DA0D0[1];
extern s32 D_001DA770;
extern s32 D_001D9380;
extern volatile s32 D_001D9384;
extern f32 D_001DA760;
extern f32 D_001DA764;
extern u8 D_001D5477;
extern u8 D_1420B0[];
extern u8 D_0037C240[];
extern V_003CBE40 D_1CFEC0;
extern s32 D_1A1ED0[];

extern void func_003CBAC0();
extern void func_003CBC70();
extern void func_003CB958(void *, f32);
extern void func_003CC8B8(f32 *, f32 *);
extern s32 func_003CCB40(s32, s32);
extern void func_003CC950(s32, s32);
extern void func_003CCFB0(s32, s32);
extern void func_003CCE10(s32, s32);
extern void func_003CD250(s32);
extern void func_003A3EF0(s32, unsigned long);

void func_003CBE40(R_003CBE40 *q) {
    R_003CBE40 *r;
    Q_003CBE40 *start;
    s32 a, b, k, res, n;
    f32 v0[4];
    f32 v1[4];

    func_003CBAC0();
    r = q;
    D_001DA0D0[0]->x0 = 0x30000007;
    D_001DA0D0[0]->x4 = D_1420B0;
    D_001DA0D0[0]->x8 = 0x13000000;
    D_001DA0D0[0]->xC = 0x50000007;
    (++D_001DA0D0[0])->x0 = 0x30000003;
    D_001DA0D0[0]->x4 = D_0037C240;
    D_001DA0D0[0]->x8 = 0x13000000;
    D_001DA0D0[0]->xC = 0x50000003;
    start = D_001DA0D0[0] + 1;
    D_001DA760 = (D_1CFEC0.x150 >> 1) - 0x800;
    D_001DA764 = (D_1CFEC0.x152 >> 1) - 0x800;
    D_001DA0D0[0] = D_001DA0D0[0] + 2;
    if (D_001D5477) {
        b = 1;
        a = 2;
    } else {
        b = 2;
        a = 1;
    }
    while (r->x0 != 0) {
        q++;
        func_003CB958(r->x20, 1000.0f);
        v1[0] = v0[0] = r->x10;
        v1[1] = v0[1] = r->x14;
        v1[2] = v0[2] = r->x18;
        v0[3] = -r->x8 - r->xC;
        v1[3] = -r->x8 + r->xC;
        for (k = 0; k < r->x0; k++) {
            q = (R_003CBE40 *)func_003CBA68((s16 *)q);
            func_003CC8B8(v0, v1);
            if (r->x4 != 0) {
                res = func_003CCB40(0x70000000, D_001DA770);
            } else {
                func_003CC950(0x70000000, D_001DA770);
                res = 0;
            }
            if (res != 0) {
                func_003CCFB0(a, D_001D9384);
                func_003CCFB0(b, D_001D9380);
                if (res & 0x20) {
                    func_003CD250(D_001D9380);
                }
            } else {
                func_003CCE10(a, D_001D9384);
                func_003CCE10(b, D_001D9380);
            }
        }
        r = q;
    }
    n = D_001DA0D0[0] - start - 1;
    if (n > 0) {
        start->x0 = n | 0x10000000;
        start->x4 = 0;
        start->x8 = 0;
        start->xC = n | 0x50000000;
    } else {
        D_001DA0D0[0]--;
    }
    func_003A3EF0(0x4C, 0x80000 | (D_1A1ED0[1] >> 13));
    func_003A3EF0(0x42, (0x8000L << 22) | 0x64);
    func_003CBC70(0);
    func_003A3EF0(0x47, 0x5360B);
    func_003A3EF0(0x42, (0x8000L << 24) | 0x44);
}
/* localdecomp:end func_003CBE40 */
