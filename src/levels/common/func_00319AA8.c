#include "common.h"

/* localdecomp:start func_00319AA8 */
typedef int Q_319AA8 __attribute__((mode(TI)));
typedef union {
    Q_319AA8 q;
    struct { f32 x, y, z, w; } f;
} __attribute__((aligned(16))) V4_319AA8;
typedef struct {
    u8 pad0[0x20];
} E_319AA8;
typedef struct {
    u8 pad0[0x30];
    V4_319AA8 pos;
} M_319AA8;
typedef struct {
    s32 w0;
    f32 f4;
    f32 f8;
    f32 fC;
    union { s32 w; u8 b[4]; } w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    u8 b20[14];
    u8 pad2E[2];
    s32 w30;
    s32 w34;
    u8 pad38[8];
    f32 f40;
    f32 f44;
    f32 f48;
    u8 pad4C[0x64 - 0x4C];
    s32 w64;
    s32 w68;
    s32 w6C;
    V4_319AA8 v70;
    s32 w80;
    s32 w84;
} P_319AA8;
typedef struct {
    u8 pad0[0x10];
    u8 v10[0x10];
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 pad31[0x68 - 0x31];
    P_319AA8 *p68;
} O_319AA8;

extern s32 D_001D545C;
extern s32 D_001D6694;
extern f32 D_001DFBD0;
extern f32 D_001DFBCC;
extern s32 D_001D6768;
extern u16 **D_001D6764;
extern E_319AA8 *D_001E0F54;
extern M_319AA8 *D_001E0F5C;
extern u8 D_001E2A40[];

extern s32 func_00448E90(void *);
extern void func_00436220(O_319AA8 *);
extern f32 func_0040CF58(f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_004B4480(void *, s32, s32, s32);
extern s32 func_00440760(void *, s32, s32);
extern void func_004026A0(void (*)(O_319AA8 *), O_319AA8 *);
extern void func_0031A108(O_319AA8 *);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);

void func_00319AA8(O_319AA8 *obj) {
    P_319AA8 *p;
    u16 *e;

    p = obj->p68;
    if (D_001D545C == 7 && func_00448E90(obj->v10) == 0) {
        return;
    }
    if (p->w80 != 0) {
        return;
    }
    if (p->w84 != 0 && D_001D6694 != 0) {
        return;
    }
    if (obj->b20 != 0) {
        if (0.98f < D_001DFBD0) {
            return;
        }
        if (0.98f < D_001DFBCC) {
            return;
        }
    }
    switch (obj->b20) {
    case 0: {
        s32 n = p->w0;
        if (n >= D_001D6768 || D_001D6764[n] == 0 || n == -1) {
            func_00436220(obj);
            return;
        }
        {
            p->f8 = func_0040CF58(p->f8 * 0.017453292f);
            p->f4 = p->f4 * 0.017453292f * 0.016666668f;
            p->w14 = (p->b20[2] << 16) | (p->b20[1] << 8) | p->b20[0];
            p->w18 = (p->b20[5] << 16) | (p->b20[4] << 8) | p->b20[3];
            if (p->w68 != 0) {
                obj->b30 = *(u8 *)&p->w68;
            } else {
                obj->b30 = 255;
            }
            if (p->w1C != 0) {
                if (p->v70.f.w == 0.0f) {
                    obj->b20 = 1;
                } else {
                    obj->b20 = 2;
                }
            } else {
                p->w30 = (p->b20[9] << 24) | (p->b20[8] << 16) | (p->b20[7] << 8) | p->b20[6];
                p->w34 = (p->b20[13] << 24) | (p->b20[12] << 16) | (p->b20[11] << 8) | p->b20[10];
                if (p->f40 == 0.0f && p->f44 == 0.0f && p->f48 == 0.0f) {
                    p->w6C = 1;
                }
                func_004026A0(func_0031A108, obj);
                obj->b20 = 3;
            }
        }
        break;
    }
    case 1: {
        s32 old;
        s32 c;
        if (p->w64 != -1 && func_00440760(D_001E2A40, p->w64, 0) == 0) {
            return;
        }
        p->fC = func_0040CEC8(p->fC, p->f4);
        old = p->w10.w;
        if (p->f8 != 0.0f) {
            s32 to = p->w14;
            if (p->f8 < p->fC) {
                to = p->w18;
            }
            p->w10.w = func_0040D020(old, to, 0.1f);
        } else {
            p->w10.w = func_0040D020(p->w14, p->w18, func_0040C3E0(p->fC) * 0.5f + 0.5f);
        }
        c = p->w10.w;
        if (c != old) {
            s32 r = (c >> 16) & 0xFF;
            s32 g = (c >> 8) & 0xFF;
            s32 b = c & 0xFF;
            for (e = D_001D6764[p->w0]; e != 0; e++) {
                E_319AA8 *el;
                if ((s16)e[-1] < 0 && e != D_001D6764[p->w0]) {
                    break;
                }
                el = &D_001E0F54[*e & 0x7FFF];
                if (el == 0) {
                    break;
                }
                func_004B4480(el, b, g, r);
            }
        }
        break;
    }
    case 2: {
        V4_319AA8 v;
        E_319AA8 *el;
        M_319AA8 *m;
        if (p->w64 != -1 && func_00440760(D_001E2A40, p->w64, 0) == 0) {
            return;
        }
        v = p->v70;
        func_0040C0F0(&v, &v, 1.0f / v.f.w);
        p->fC = func_0040CEC8(p->fC, p->f4);
        for (e = D_001D6764[p->w0];
             e != 0 && !((s16)e[-1] < 0 && e != D_001D6764[p->w0]) &&
             (el = &D_001E0F54[*e & 0x7FFF]) != 0 && (m = &D_001E0F5C[*e & 0x7FFF]) != 0;
             e++) {
            f32 a;
            a = func_0040CF58(p->fC - func_0040BEF8(&m->pos, &v) * 6.2831855f);
            if (p->f8 != 0.0f) {
                f32 t = a - p->f8 + 1.0f;
                if (2.1415927f < a) {
                    t = 3.1415927f - a;
                }
                if (1.0f < t) {
                    t = 1.0f;
                } else if (t < 0.0f) {
                    t = 0.0f;
                }
                p->w10.w = func_0040D020(p->w18, p->w14, t);
            } else {
                p->w10.w = func_0040D020(p->w14, p->w18, func_0040C3E0(a) * 0.5f + 0.5f);
            }
            func_004B4480(el, p->w10.b[0], p->w10.b[1], p->w10.b[2]);
        }
        break;
    }
    case 3:
        if (p->w64 != -1 && func_00440760(D_001E2A40, p->w64, 0) == 0) {
            return;
        }
        func_004026A0(func_0031A108, obj);
        break;
    }
}
/* localdecomp:end func_00319AA8 */
