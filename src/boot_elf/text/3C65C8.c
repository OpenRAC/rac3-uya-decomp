#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003A5560();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C65C8);

/* localdecomp:start func_003C65D0 */
typedef int Q_3C0E10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C0E10;
typedef struct { u8 p0[0x10]; V_3C0E10 pos; } O_3C0E10;
typedef struct { u8 p0[0x46]; u8 b46; } P_3C0E10;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[0xC]; P_3C0E10 *f24; } E_3C0E10;
extern E_3C0E10 *D_0022B740[];
extern s32 func_003D4F50(void *, s32, void *, s32, f32);
extern s32 func_003C4DA0();
extern f32 func_0038DEC8(f32, f32);
extern f32 func_0038D488(f32, f32);
extern f32 func_0038D200(f32 *);
extern f32 func_0038D3C0(f32);
extern f32 func_0038D3D8(f32);
extern void func_0038D290(void *, void *, f32);
s32 func_003C65D0(void *, f32 *, f32 *, f32, f32, f32);
s32 func_003C65D0(void *o, f32 *out, f32 *v, f32 a, f32 lim, f32 unused) {
    O_3C0E10 *obj = (O_3C0E10 *)o;
    f32 t[4] __attribute__((aligned(16)));
    f32 u[4] __attribute__((aligned(16)));
    f32 arr[16];
    f32 ang, d;
    s32 n, i, cnt;
    *(Q_3C0E10 *)out = *(Q_3C0E10 *)v;
    *(Q_3C0E10 *)t = *(Q_3C0E10 *)v;
    t[2] = 0.0f;
    func_0038D290(t, t, a);
    __asm__(
        "lqc2 $vf2, %1\n"
        "lqc2 $vf1, %2\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(*(V_3C0E10 *)u) : "m"(*(V_3C0E10 *)t), "m"(obj->pos));
    ang = func_0038D488(t[0], t[1]);
    n = func_003D4F50(u, 0, obj, 0, a);
    if (n != 0) {
    cnt = 0;
    for (i = 0; i < n && i < 16; i++) {
        if (func_003C4DA0(D_0022B740[i]) != 0 || (D_0022B740[i]->f24 != 0 && D_0022B740[i]->f24->b46 == 0x16)) {
            d = func_0038D488(D_0022B740[i]->f10 - obj->pos.x, D_0022B740[i]->f14 - obj->pos.y);
            if (func_0038DEC8(ang, d) < lim) {
                arr[cnt++] = d;
            }
        }
    }
    if (cnt != 0) {
        s32 j, k;
        for (j = 0; j < cnt - 1; j++) {
            s32 jj = j + 1;
            for (k = 0; k < cnt - jj; k++) {
                if (arr[k + 1] < arr[k]) {
                    f32 tmp = arr[k];
                    arr[k] = arr[k + 1];
                    arr[k + 1] = tmp;
                }
            }
        }
        d = arr[cnt >> 1];
        ang = func_0038D200(out);
        out[0] = func_0038D3C0(d) * ang;
        out[1] = func_0038D3D8(d) * ang;
    }
    return 1;
    }
    return 0;
}
/* localdecomp:end func_003C65D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C6830);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C68F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C6C00);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C70B8);

/* localdecomp:start func_003C7110 */
typedef struct { u16 id; u16 t; } E_C1950;
typedef struct { u8 p0[0x10]; u8 k; u8 p11; u8 n; u8 p13[9]; E_C1950 e[1]; } Y_C1950;
typedef struct { u8 p0[0xC]; u8 cnt; u8 pD[0x3B]; Y_C1950 *y[1]; } X_C1950;
typedef struct { u8 p0[0x24]; X_C1950 *x; } O_C1950;
void func_003C7110(O_C1950 *o, s32 idx, u16 t) {
    X_C1950 *x = o->x;
    Y_C1950 *y;
    E_C1950 *e;
    s32 i;
    if (x != 0 && idx < x->cnt) {
        y = x->y[idx];
        if (y->n != 0) {
            e = (E_C1950 *)((u8 *)y + (y->k * 4 + 0x1C));
            for (i = 0; i < y->n && (t << 4) >= e[i].t; i++) {
                func_003A5560(e[i].id, 0, o);
            }
        }
    }
}
/* localdecomp:end func_003C7110 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C71E8);

/* localdecomp:start func_003C7200 */
unsigned long func_003C7200(u8 *p, unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    register unsigned long shifted __asm__("$5") = a << 32;
    __asm__ volatile("" : "+r"(shifted));
    c <<= 8;
    d <<= 16;
    __asm__ volatile("" : "+r"(d));
    return *(unsigned long *)(p + 0x38) = shifted | b | c | d;
}
/* localdecomp:end func_003C7200 */
