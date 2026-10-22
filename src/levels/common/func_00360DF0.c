#include "common.h"

/* localdecomp:start func_00360DF0 */
typedef int Q_00360DF0 __attribute__((mode(TI)));

extern s32 func_00360DB0(void *, void *);
extern void func_00361560(void *);
extern void func_003617C0(void *);
extern f32 func_0041C8C0(void *, void *);
extern f32 func_0041C8F0(void *, void *);
extern void func_00448A30(void *);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004513D8(void *, s32, s32);
extern void func_00451EC8(s32, s32);
extern void func_004536F0(void *);
extern void func_0045BFA8(void *, s32, s32, s32);
extern void func_0045ED70(void *, void *, s32);
extern s32 func_0045F458(void *, void *, s32, s32, s32);
extern s32 func_00462998(void *, s32);
extern void func_00463068(void *, s32);
extern void func_00463130(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_004660E8(s32);
extern void func_004B6878(s32, s32, void *);
extern u8 D_00142637[];
extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern s32 D_001D67C4;
extern s32 D_001DF9C0;
extern u8 *D_001E0EF8;
extern u8 D_001E28C0[];
extern u8 D_002C5F80[];

s32 func_00360DF0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    u8 **p;
    s32 i;
    s32 hp;
    s32 r;
    u8 *g;
    u8 *t;
    s32 x;
    s32 y;
    s32 z;
    s32 one;

    if (*(f32 *)(v + 0x30) > 0.0f) {
        p = (u8 **)(v + 0x4B0);
        for (i = 0; i < 8; i++, p++) {
            u8 *e = *p;
            if (e != 0) {
                *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
                func_00448A30(*p);
            }
        }
    }
    if (o[0x31] != 0 && func_0041C8F0(D_001E28C0, o + 0x10) < 576.0f) {
        func_004536F0(o);
        o[0x6F] = 0x16;
    }
    if (v[0x3E] == 2) {
        func_00361560(o);
        return 1;
    }
    if (v[0x61] == 0x3F && func_00360DB0(o, v) != 0) {
        func_004513D8(o, 0x1D, -1);
        if (o[0x43] != 0x14) {
            func_00451098(o, 0x14, 1, 3);
        }
    }
    if (D_001E0EF8 != 0 && func_00360DB0(o, v) != 0 &&
        func_0041C8C0(o + 0x10, D_001E0EF8 + 0x10) < 6.0f &&
        *(f32 *)(v + 0x30) <= (t = D_002C5F80 + D_00142637[0] * 0xF0, *(f32 *)(t + 0x6C))) {
        func_004513D8(o, 0x1D, -1);
        if (o[0x43] != 0x14) {
            func_00451098(o, 0x14, 1, 3);
        }
    }
    if (*(s32 *)(v + 0x2FC) != 0) {
        func_0045BFA8(o, *(s32 *)(v + 0x2FC), 0, 0);
    }
    hp = *(f32 *)(v + 0x30);
    if (*(s32 *)(v + 0x4E4) != 0) {
        r = func_0045F458(o, v + 0x160, 0, 0, 1);
        if (r != 0) {
            if (r >= 2) {
                func_004B6878(5, 0, o);
            }
            p = (u8 **)(v + 0x4B0);
            for (i = 0; i < 8; i++, p++) {
                u8 *e = *p;
                if (e != 0) {
                    *(s32 *)(e + 0x98) = 0;
                    func_00448A30(*p);
                }
            }
            if (o[0x21] != 0xFF) {
                func_00451EC8(o[0x21], 0);
            }
            func_003617C0(o);
        }
    } else {
        if (func_0045F458(o, v + 0x160, 0, 0, 0) != 0) {
            func_004B6878(5, 0, o);
            p = (u8 **)(v + 0x4B0);
            for (i = 0; i < 8; i++, p++) {
                u8 *e = *p;
                if (e != 0) {
                    *(s32 *)(e + 0x98) = 0;
                    func_00448A30(*p);
                }
            }
            if (o[0x21] != 0xFF) {
                func_00451EC8(o[0x21], 0);
            }
            func_003617C0(o);
        }
    }
    if (*(f32 *)(v + 0x30) < hp) {
        *(s32 *)(v + 0x2F8) = 1;
        func_003617C0(o);
    }
    func_0045ED70(o, v + 0x30, 0);
    if ((y = v[0x5F]) != 0 && (y = D_001D545C) == 0x16 && *(s32 *)(v + 0x50C) == 0) {
        z = D_001D67C4 + 1;
        *(s32 *)(v + 0x50C) = 1;
        D_001D67C4 = z;
        if (z >= 15) {
            func_004660E8(0x17);
        }
    }
    if (v[0x5E] != 0) {
        func_00361560(o);
        return 1;
    }
    if (((*(unsigned long *)(o + 0x30) & 0x104100000000UL) != 0x4100000000UL || *(s32 *)(o + 0x98) != 0) &&
        *(f32 *)(v + 0x30) > 0.0f) {
        if (v[0x5F] != 0) {
            func_00463068(o, 5);
        } else if (D_001D545C != 9 || *(s16 *)(o + 0xB2) == 0xCA || o[0x95] == 3 || o[0x95] == 5) {
            func_00463068(o, 3);
        }
    }
    if ((*(s16 *)(o + 0xB2) + 8) % 8 == D_001DF9C0 % 8) {
        if (v[0x5F] != 0) {
            if (o[0x95] == 1) {
                func_00463130(o, *(s32 *)(v + 0x2E0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2E4), 10.0f, 1.0f);
            } else {
                func_00463130(o, *(s32 *)(v + 0x2E8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2EC), 10.0f, 1.0f);
            }
        } else if (o[0x95] == 1 || o[0x95] == 8) {
            func_00463130(o, *(s32 *)(v + 0x2E0), 0, 0, 0, 0, 1, *(s32 *)(v + 0x500) != 0, 0, *(s32 *)(v + 0x510) != 0, *(f32 *)(v + 0x2E4), 10.0f, 1.0f);
        } else {
            func_00463130(o, *(s32 *)(v + 0x2E8), 0, 0, 0, 0, 1, *(s32 *)(v + 0x500) != 0, 0, *(s32 *)(v + 0x510) != 0, *(f32 *)(v + 0x2EC), 10.0f, 1.0f);
        }
    }
    if (*(s32 *)(v + 0x4D0) == -1) {
        return 0;
    }
    if (*(s32 *)(v + 0x4D4) == -1) {
        return 0;
    }
    one = 1;
    if (*(s16 *)(v + 0x234) == one && D_001D545C != 0x1D) {
        return 0;
    }
    x = o[0x95];
    if (x == one || x == 4 || x == 2 || (D_001D545C == 0x1D && x == 3)) {
        g = D_001A4C60;
        if (func_00462998(g, *(s32 *)(v + 0x4D0)) != 0) {
            u8 *h = g - 0x80;
            *(s32 *)(v + 0x4D8) = 1;
            *(s32 *)(v + 0x230) = *(s32 *)(h + 0x25C0);
            *(Q_00360DF0 *)(v + 0x220) = *(Q_00360DF0 *)(h + 0xD0);
        } else {
            *(s32 *)(v + 0x4D8) = 0;
        }
    }
    return 0;
}
/* localdecomp:end func_00360DF0 */
