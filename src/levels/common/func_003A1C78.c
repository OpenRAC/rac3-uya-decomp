#include "common.h"

/* localdecomp:start func_003A1C78 */
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define L(p, o) (*(unsigned long *)((u8 *)(p) + (o)))

typedef int Q_3A1C78 __attribute__((mode(TI)));

extern s32 func_003A2258(void *);
extern void func_00439610(void *);
extern f32 func_0040C018(void *, void *);
extern void func_00444188(void *);
extern s32 func_0044FCD0(void *, void *, s32, s32, s32);
extern void func_003664D8(void *, s32, s32, void *, void *, u32);
extern void func_00436220(void *);
extern void func_004A7200(s32, s32, void *);
extern void func_00442AA8(s32, s32);
extern void func_003A2BD8(void *);
extern void func_003A2820(void *);
extern s32 func_0044F5E8(void *, void *, s32);
extern void func_004538E0(void *, s32);
extern void func_004539A8(void *, s32, f32, f32, s32, s32, s32, s32, s32, f32, s32, s32, s32);
extern s32 func_00453210(void *, s32);
extern u8 *D_001E0180;
extern u8 D_001E2AC0[];
extern u8 D_001D66B0[8];
extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern s32 D_001DFBC0;

s32 func_003A1C78(u8 *m) {
    u8 *v = P(m, 104);
    s32 i, j;
    u8 **pp;
    u8 *e;
    s32 r;
    u8 *q, *h;

    if (B(m, 32) == 0) {
        if (func_003A2258(m) != 0) {
            return 1;
        }
    }
    if (W(v, 944) != -1) {
        e = D_001E0180 + W(v, 944) * 128;
        if (F(m, 24) < F(e, 56)) {
            if (4.0f < __builtin_fabsf(F(m, 24) - F(e, 56))) {
                W(v, 944) = -1;
            }
        }
    }
    if (0.0f < F(v, 48)) {
        pp = (u8 **)(v + 1008);
        for (i = 0; i < 8; i++) {
            if (pp[i] != 0) {
                W(pp[i], 152) = W(P(pp[i], 36), 16);
                func_00439610(pp[i]);
            }
        }
    }
    if (W(v, 960) != 0 || W(v, 1068) != 0) {
        if (D_001D545C == 1) {
            H(m, 124) = 0;
        }
    }
    if (P(v, 952) != 0) {
        u8 t = B(P(v, 952), 32);
        if (t == 254) {
            P(v, 952) = 0;
        } else if (t == 253) {
            P(v, 952) = 0;
        }
    }
    if (B(m, 49) != 0) {
        if (func_0040C018(D_001E2AC0, m + 16) < 4096.0f) {
            func_00444188(m);
            B(m, 111) = 60;
        }
    }
    if (B(v, 62) != 2) {
        r = func_0044FCD0(m, v + 352, 0, 0, 0);
        if (r != 0) {
            if (r >= 2) {
                if (P(v, 752) != 0 && H(P(v, 752), 170) == 6457) {
                    func_003664D8(P(v, 752), 0, 0, D_001D66B0, D_001D66B0, 0x2F2020FF);
                    func_00436220(P(v, 752));
                    P(v, 752) = 0;
                }
                if (P(v, 756) != 0 && H(P(v, 756), 170) == 6457) {
                    func_003664D8(P(v, 756), 0, 0, D_001D66B0, D_001D66B0, 0x2F2020FF);
                    func_00436220(P(v, 756));
                    P(v, 756) = 0;
                }
            }
            func_004A7200(6, 0, m);
            pp = (u8 **)(v + 1008);
            for (j = 0; j < 8; j++) {
                if (pp[j] != 0) {
                    W(pp[j], 152) = 0;
                    func_00439610(pp[j]);
                }
            }
            if (B(m, 33) != 255) {
                func_00442AA8(B(m, 33), 0);
            }
            func_003A2BD8(m);
        }
        if (B(v, 94) == 0) {
            goto rest;
        }
    }
    func_003A2820(m);
    return 1;
rest:
    func_0044F5E8(m, v + 48, 0);
    if ((L(m, 48) & 0x104100000000L) != 0x4100000000L || W(m, 152) != 0) {
        if (0.0f < F(v, 48)) {
            if (B(v, 95) != 0) {
                func_004538E0(m, 5);
            } else if (D_001D545C != 9 || H(m, 178) == 200 || B(m, 149) == 2 || B(m, 149) == 4) {
                func_004538E0(m, 3);
            }
        }
    }
    if ((H(m, 178) + 8) % 8 == D_001DFBC0 % 8) {
        if (B(v, 95) != 0) {
            if (B(m, 149) == 0) {
                func_004539A8(m, W(v, 720), F(v, 724), 10.0f, 0, 0, 0, 0, 3, 1.0f, 0, 0, 0);
            } else {
                func_004539A8(m, W(v, 728), F(v, 732), 10.0f, 0, 0, 0, 0, 3, 1.0f, 0, 0, 0);
            }
        } else {
            if (B(m, 149) == 0) {
                func_004539A8(m, W(v, 720), F(v, 724), 10.0f, 0, 0, 0, 0, 1, 1.0f, W(v, 1060) != 0, 0, 0);
                if (H(v, 564) == 1) {
                    func_004539A8(m, W(v, 720), F(v, 724), 10.0f, 0, 0, 0, 0, 1, 1.0f, W(v, 1060) != 0, 0, 0);
                }
            } else {
                func_004539A8(m, W(v, 728), F(v, 732), 10.0f, 0, 0, 0, 0, 1, 1.0f, W(v, 1060) != 0, 0, 0);
            }
        }
    }
    if (W(v, 1040) == -1) {
        return 0;
    }
    if (W(v, 1044) != -1) {
        if ((H(v, 564) != 1 || D_001D545C == 29) && (B(m, 149) == 0 || B(m, 149) == 3 || B(m, 149) == 1 || (D_001D545C == 29 && B(m, 149) == 2))) {
            q = D_001A4C60;
            if (func_00453210(q, W(v, 1040)) != 0) {
                h = q - 0x80;
                W(v, 1048) = 1;
                W(v, 560) = W(h, 9664);
                *(Q_3A1C78 *)(v + 544) = *(Q_3A1C78 *)(h + 208);
            } else {
                W(v, 1048) = 0;
            }
        } else {
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_003A1C78 */
