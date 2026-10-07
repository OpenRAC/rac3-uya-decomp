#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003D1600();
extern void func_003D1050();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D1050 */
extern void func_003D0C58(s32, s32, s32);
extern s32 func_003DEC68(s32, s32, s32);
extern s32 func_003E14A8(s32, s32, s32);
extern u8 D_002FF780[];
void func_003D1050(s32 arg0) {
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    void *temp_16;

    temp_16 = (arg0 * 0x30) + D_002FF780;
    temp_2 = (*(s32 *)((u8 *)temp_16 + 0xC));
    if (temp_2 != 0) {
        temp_4 = temp_2 + ((*(s16 *)((u8 *)temp_16 + 0)) * 2);
        func_003DEC68(temp_4, temp_4 + ((*(s16 *)((u8 *)temp_16 + 2)) * 2), arg0);
        temp_4_2 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 4)) * 2);
        (*(s16 *)((u8 *)temp_16 + 0)) = 0;
        (*(s16 *)((u8 *)temp_16 + 2)) = 0;
        func_003E14A8(temp_4_2, temp_4_2 + ((*(s16 *)((u8 *)temp_16 + 6)) * 2), arg0);
        temp_4_3 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 8)) * 2);
        (*(s16 *)((u8 *)temp_16 + 4)) = 0;
        (*(s16 *)((u8 *)temp_16 + 6)) = 0;
        func_003D0C58(temp_4_3, temp_4_3 + ((*(s16 *)((u8 *)temp_16 + 0xA)) * 2), arg0);
        (*(s16 *)((u8 *)temp_16 + 8)) = 0;
        (*(s16 *)((u8 *)temp_16 + 0xA)) = 0;
    }
}
/* localdecomp:end func_003D1050 */

/* localdecomp:start func_003D1118 */
typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001DA730[8];
extern f32 D_001DA740;
extern f32 D_001DA744;
extern volatile f32 D_001DA748;
extern u8 D_001DA750[];
extern void func_0038D110(void *, void *);
extern void func_0038D148(f32 *, void *, f32);
extern void func_0038D1B8(void *, void *, void *);
extern void func_0038D290(s32, s32, f32);
void func_003D1118(void *a, f32 t) {
    f32 v[4];
    f32 x, y, z;
    *(u128_3CB958 *)D_001DA730 = *(u128_3CB958 *)a;
    func_0038D110(v, a);
    func_0038D148((f32 *)D_001DA750, D_001DA730, t);
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
    func_0038D1B8(&D_001DA740, &D_001DA740, D_001DA730);
    func_0038D290((s32)&D_001DA740, (s32)&D_001DA740, 1.0f);
}
/* localdecomp:end func_003D1118 */

/* localdecomp:start func_003D1228 */
void func_003D1C70(s16 *);
void func_003D1DB8(s16 *);
char *func_003D1228(s16 *p) {
    char *q = (char *)p;
    if (*p == 0) { func_003D1C70(p); q += 0x20; }
    else if (*p == 1) { func_003D1DB8(p); q += 0x30; }
    return q;
}
/* localdecomp:end func_003D1228 */

/* localdecomp:start func_003D1280 */
typedef struct { u8 pad0[0x150]; s16 x; s16 y; } S_3CBAC0;
extern S_3CBAC0 D_001CFEC0;
extern u32 *D_001DA0D0_003D1280;
extern void func_003A96B0(s32, unsigned long);
void func_003D1280(void) {
    S_3CBAC0 *s = &D_001CFEC0;
    s32 x = s->x;
    s32 y = s->y;
    s32 n = x / 32;
    s32 i;
    unsigned long *q;
    s32 k;
    func_003A96B0(0x42, 0x64);
    D_001DA0D0_003D1280[0] = (n + 5) | 0x10000000;
    D_001DA0D0_003D1280[1] = 0;
    D_001DA0D0_003D1280[2] = 0;
    D_001DA0D0_003D1280[3] = (n + 5) | 0x50000000;
    D_001DA0D0_003D1280 += 4;
    q = (unsigned long *)D_001DA0D0_003D1280;
    q[0] = 0x1000000000000001UL;
    q[1] = 0xE;
    q[2] = 0x35001;
    q[3] = 0x47;
    q[4] = 0x2400000000008001UL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = 0x80808080;
    q[8] = (n | 0x8000) | 0x2400000000000000UL;
    q[9] = 0x44;
    i = 0;
    if (i < n) {
        k = 10;
        do {
            q[k++] = (0x8000 - x * 8 + i * 0x200) | ((unsigned long)(0x8000 - y * 8) << 16);
            q[k++] = (0x8200 - x * 8 + i * 0x200) | ((unsigned long)(y * 8 + 0x7FF0) << 16);
            i++;
        } while (i < n);
    }
    D_001DA0D0_003D1280 += n * 4 + 20;
}
/* localdecomp:end func_003D1280 */

/* localdecomp:start func_003D1430 */
typedef struct { u8 pad0[0x150]; s16 x; s16 y; } S_3CBC70;
extern S_3CBC70 D_001CFEC0_003D1430;
extern u32 *D_001DA0D0_003D1430;
void func_003D1430(s32 rgba) {
    S_3CBC70 *s = &D_001CFEC0_003D1430;
    s32 x = s->x;
    s32 y = s->y;
    s32 n = x / 32;
    s32 i;
    unsigned long *q;
    s32 k;
    D_001DA0D0_003D1430[0] = (n + 5) | 0x10000000;
    D_001DA0D0_003D1430[1] = 0;
    D_001DA0D0_003D1430[2] = 0;
    D_001DA0D0_003D1430[3] = (n + 5) | 0x50000000;
    D_001DA0D0_003D1430 += 4;
    q = (unsigned long *)D_001DA0D0_003D1430;
    q[0] = 0x1000000000000001UL;
    q[1] = 0xE;
    q[2] = 0x35801;
    q[3] = 0x47;
    q[4] = 0x2400000000000001UL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = rgba;
    q[8] = (n | 0x8000) | 0x2400000000000000UL;
    q[9] = 0x44;
    i = 0;
    if (i < n) {
        k = 10;
        do {
            q[k++] = (0x8000 - x * 8 + i * 0x200) | ((unsigned long)(0x8000 - y * 8) << 16);
            q[k++] = (0x8200 - x * 8 + i * 0x200) | ((unsigned long)(y * 8 + 0x7FF0) << 16);
            i++;
        } while (i < n);
    }
    D_001DA0D0_003D1430 += n * 4 + 20;
    D_001DA0D0_003D1430[0] = 0x10000000;
    D_001DA0D0_003D1430[1] = 0;
    D_001DA0D0_003D1430[2] = 0x13000000;
    D_001DA0D0_003D1430[3] = 0;
    D_001DA0D0_003D1430 += 4;
}
/* localdecomp:end func_003D1430 */

/* localdecomp:start func_003D1600 */
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
extern u8 D_00380280[];
extern V_003CBE40 D_1CFEC0;
extern s32 D_1A1ED0[];

extern void func_003D1280();
extern void func_003D1430();
extern void func_003D1118(void *, f32);
extern void func_003D2078(f32 *, f32 *);
extern s32 func_003D2300(s32, s32);
extern void func_003D2110(s32, s32);
extern void func_003D2770(s32, s32);
extern void func_003D25D0(s32, s32);
extern void func_003D2A10(s32);
extern void func_003A96B0(s32, unsigned long);

void func_003D1600(R_003CBE40 *q) {
    R_003CBE40 *r;
    Q_003CBE40 *start;
    s32 a, b, k, res, n;
    f32 v0[4];
    f32 v1[4];

    func_003D1280();
    r = q;
    D_001DA0D0[0]->x0 = 0x30000007;
    D_001DA0D0[0]->x4 = D_1420B0;
    D_001DA0D0[0]->x8 = 0x13000000;
    D_001DA0D0[0]->xC = 0x50000007;
    (++D_001DA0D0[0])->x0 = 0x30000003;
    D_001DA0D0[0]->x4 = D_00380280;
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
        func_003D1118(r->x20, 1000.0f);
        v1[0] = v0[0] = r->x10;
        v1[1] = v0[1] = r->x14;
        v1[2] = v0[2] = r->x18;
        v0[3] = -r->x8 - r->xC;
        v1[3] = -r->x8 + r->xC;
        for (k = 0; k < r->x0; k++) {
            q = (R_003CBE40 *)func_003D1228((s16 *)q);
            func_003D2078(v0, v1);
            if (r->x4 != 0) {
                res = func_003D2300(0x70000000, D_001DA770);
            } else {
                func_003D2110(0x70000000, D_001DA770);
                res = 0;
            }
            if (res != 0) {
                func_003D2770(a, D_001D9384);
                func_003D2770(b, D_001D9380);
                if (res & 0x20) {
                    func_003D2A10(D_001D9380);
                }
            } else {
                func_003D25D0(a, D_001D9384);
                func_003D25D0(b, D_001D9380);
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
    func_003A96B0(0x4C, 0x80000 | (D_1A1ED0[1] >> 13));
    func_003A96B0(0x42, (0x8000L << 22) | 0x64);
    func_003D1430(0);
    func_003A96B0(0x47, 0x5360B);
    func_003A96B0(0x42, (0x8000L << 24) | 0x44);
}
/* localdecomp:end func_003D1600 */
