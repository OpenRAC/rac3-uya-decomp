#include "common.h"

/* localdecomp:start func_004AB800 */
typedef int Q_4AB800 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    Q_4AB800 v10;
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 x34;
    u8 pad36[0x40 - 0x36];
    u8 b40;
    u8 b41;
    u8 pad42[2];
    f32 f44;
    u8 pad48[0x61 - 0x48];
    u8 b61;
    u8 pad62;
    u8 b63;
    u8 pad64[4];
    u8 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 xAA;
} M_4AB800;
typedef struct {
    u8 pad0[0x34];
    s32 x34;
    s32 x38;
    s32 x3C;
    s16 x40;
    s16 pad42;
    s16 x44;
    s16 pad46;
    s16 x48;
    u8 pad4A[0x60 - 0x4A];
    s8 b60;
    u8 pad61[0x1A0 - 0x61];
    M_4AB800 *list[1];
} G_4AB800;
typedef struct {
    u8 pad0[0x1A0];
    union {
        unsigned long d;
        struct {
            u32 lo;
            u32 hi;
        } w;
    } x1A0;
} P_4AB800;
typedef struct {
    u8 pad0[0x25C0];
    M_4AB800 *x25C0;
} S_4AB800;

extern G_4AB800 D_001E6E00;
extern s32 D_001D6690;
extern f32 D_001DF9D0;
extern u32 D_00142690[];
extern s32 D_001D4D40;
extern s32 D_001D545C;
extern P_4AB800 *D_001D52FC;
extern s32 D_00143950[];
extern s16 D_001CCFD4[];
extern S_4AB800 D_001A4BE0;
extern M_4AB800 *D_001E0EE8;
extern s32 D_001D4B60;
extern u8 *D_001E009C;
extern u8 *D_001E00A4;
extern void func_004B51C0(void);
extern void func_004ACFE0(void);
extern void func_0045B9C8(void);
extern void func_0045CA60(s32);
extern void func_004ABC38(void);
extern void func_004AB778(s32);
extern s32 func_004B6518(void);
extern void func_00436350(M_4AB800 *);
extern void func_0040BE90(void *, void *, f32);
extern void func_004A7F50(M_4AB800 *, s32);
extern void func_004ACA98();
extern void func_004026A0(void *, M_4AB800 *);
extern void func_00439610(M_4AB800 *);
extern void func_0050EA58(M_4AB800 *, s32);
extern void func_004DEBC0(M_4AB800 *);
extern s32 func_00510800(void);
extern void func_004A57D8(void);
extern void func_00422048(void);
extern void func_004B5258(void);

s32 func_004AB800(void) {
    Q_4AB800 a, b;
    Q_4AB800 x, y;
    s32 r;
    s32 done;
    s32 n;
    s32 i;
    s32 lim;
    M_4AB800 *e;
    u8 *o;

    if (D_001E6E00.b60 != 0) {
        return 0;
    }
    if (D_001E6E00.x34 + 1 >= D_001E6E00.x40) {
        D_001D6690 = 0;
        D_001E6E00.b60 = 1;
        return 0;
    }
    func_004B51C0();
    func_004ACFE0();
    D_001E6E00.x38++;
    D_001E6E00.x34++;
    D_001DF9D0 -= 0.34f;
    if (D_001DF9D0 < 0.0f) {
        D_001DF9D0 = 0.0f;
    }
    if (*(volatile s32 *)&D_001E6E00.x34 >= D_001E6E00.x48) {
        func_0045B9C8();
    }
    r = 0;
    done = D_001E6E00.x34 >= D_001E6E00.x40;
    if (D_001E6E00.x34 >= 18 && D_001DF9D0 == 0.0f) {
        if (((D_00142690[0] & 0xFFFF0000) || D_001D4D40 != 0 || D_001D545C <= 0) && (D_001D52FC->x1A0.w.hi & 0x800)) {
            r = 1;
        } else if ((D_001D52FC->x1A0.d & 0x8000000000FUL) == 0x8000000000FUL) {
            r = 1;
        }
    }
    if (r || done) {
        D_001E6E00.b60 = 1;
        D_001D6690 = 0;
    } else {
        lim = 0x60;
        if (D_00143950[0]) {
            lim = 0x50;
        }
        if (D_001E6E00.x38 >= lim) {
            D_001E6E00.x3C++;
            if (D_001CCFD4[0]) {
                func_0045CA60(1);
            }
            func_004ABC38();
            func_004AB778(D_001E6E00.x3C + 1);
        }
        n = func_004B6518();
        for (i = 0; i < D_001E6E00.x44; i++) {
            s32 h;
            u8 *q;
            e = D_001E6E00.list[i];
            h = D_001E6E00.x38 >> 1;
            e->b41 = h + 1;
            e->b40 = h;
            func_00436350(e);
            e->f44 = (f32)(D_001E6E00.x38 & 1) * 0.5f;
            if (n && (D_001E6E00.x38 & 1)) {
                e->f44 = 1.0f;
            }
            q = e->p68;
            func_0040BE90(&a, q + e->b40 * 16, 1.0f - e->f44);
            func_0040BE90(&b, q + e->b41 * 16, e->f44);
            __asm__("lqc2 %0, %2\n\tlqc2 %1, %3\n\tvadd.xyz %0, %0, %1" : "=&j"(x), "=&j"(y) : "m"(a), "m"(b));
            __asm__("sqc2 %1, %0" : "=m"(e->v10) : "j"(x) : "memory");
            if (e->xAA == 0xD54) {
                e->b63 = 8;
                func_004A7F50(e, 0);
                if (D_001E0EE8 == 0 || D_001E0EE8->xAA == 0xD54) {
                    func_004026A0(func_004ACA98, e);
                }
            }
            e->b61 = 0xFF;
            func_00439610(e);
            if (e->xAA == 0) {
                D_001A4BE0.x25C0 = e;
                func_0050EA58(e, 1);
            }
            if (e->xAA == 10) {
                func_004DEBC0(e);
            }
        }
        if (D_001D4B60 == 4 || func_00510800() > 0) {
            for (o = D_001E009C; o < D_001E00A4; o += 0x100) {
                if (o[0x20] < 0xFE && ((M_4AB800 *)o)->xAA == 0x50A) {
                    ((M_4AB800 *)o)->x34 |= 1;
                }
            }
        }
    }
    func_004A57D8();
    func_00422048();
    func_004B5258();
    return r;
}
/* localdecomp:end func_004AB800 */
