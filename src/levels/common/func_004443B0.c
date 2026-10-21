#include "common.h"

/* localdecomp:start func_004443B0 */
typedef struct {
    u8 pad0[0x20];
    u8 b20;
} P_4443B0;
typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x11];
    u8 b17;
    P_4443B0 *p18;
    s16 h1C;
} A_4443B0;
typedef struct {
    u8 pad0[0x20];
    P_4443B0 *p20;
    u32 w24;
    u8 b28;
    u8 pad29[3];
    f32 f2C;
} B_4443B0;
typedef struct {
    u8 pad0[0x18];
    u8 b18;
} R_4443B0;
extern A_4443B0 *func_00440728(void *);
extern u8 func_00449C10(void *);
extern R_4443B0 *func_00445EB8(void *);
f32 func_004443B0(void *x, B_4443B0 *b) {
    A_4443B0 *a;
    f32 f;
    f = 0.0f;
    a = func_00440728(x);
    if (a != 0) {
        if (a->p18 != 0) {
            s32 v = a->p18->b20;
            if (v == 0xFE) {
                a->h1C = 0;
                a->p18 = 0;
            } else if (v == 0xFD) {
                a->h1C = 0;
                a->p18 = 0;
            }
        }
        if (a->h1C != 0) {
            if (a->h1C++ >= 0x79) {
                a->p18 = 0;
                a->h1C = 0;
            }
        }
        if (b != 0) {
            P_4443B0 *q = b->p20;
            f = b->f2C;
            if (q != 0) {
                if (a->p18 != q) {
                    a->p18 = q;
                    a->b17 = func_00449C10(b->p20);
                    a->h1C = 1;
                } else if (b->b28 == 9) {
                    if (a->h1C < 0x3C) {
                        f = 0.0f;
                    } else {
                        a->h1C = 1;
                    }
                } else {
                    if (a->h1C < 10) {
                        f = 0.0f;
                    }
                    a->h1C = 1;
                }
            }
            if ((f32)a->h4 <= 1.0f) {
                if (0.0f < f) {
                    if (f < 1.0f) {
                        f = 1.0f;
                    }
                }
            }
            if (b->w24 & 0x100000) {
                R_4443B0 *r = func_00445EB8(x);
                if (r != 0) {
                    r->b18 = 1;
                }
                return f;
            }
            if (b->w24 & 0x200000) {
                R_4443B0 *r = func_00445EB8(x);
                if (r != 0) {
                    r->b18 = 2;
                }
                return f;
            }
            if (b->w24 & 0x400000) {
                R_4443B0 *r = func_00445EB8(x);
                if (r != 0) {
                    r->b18 = 3;
                }
                return f;
            }
            if (b->w24 & 0x10000000) {
                R_4443B0 *r = func_00445EB8(x);
                if (r != 0) {
                    r->b18 = 4;
                }
                return f;
            }
            {
            R_4443B0 *r = func_00445EB8(x);
            if (r != 0) {
                r->b18 = 0;
            }
            }
        }
    }
    return f;
}
/* localdecomp:end func_004443B0 */
