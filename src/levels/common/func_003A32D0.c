#include "common.h"

/* localdecomp:start func_003A32D0 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
} V_3A32D0;

typedef struct {
    u8 pad0[0x1A4];
    s32 w1A4;
} G_3A32D0;

extern void func_003C3A40(s32 id);
extern s32 func_004181C8(void *t, s32 id, s32 c);
extern s32 func_004264D8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern void func_00419970(u8 *m, s32 a, s32 b);
extern void func_003C39E0(s32 id);
extern void func_004DDC98(u8 *p, s32 a, f32 b);
extern void func_003F0508(s32 id, s32 a);
extern f32 func_0041C818(f32 *p, f32 target, f32 rate);
extern void func_00400138(s32 id, s32 a);
extern void func_004C5F00(u8 *a, u8 *b, s32 c, s32 d);
extern void func_00476038(u8 *a, u8 *b);
extern void func_00425D78(s32 a, s32 b, s32 c);
extern s32 func_003C3A10(s32 id);
extern void func_004CF3B8(s32 a, s32 b);
extern s32 D_001D545C;
extern G_3A32D0 *D_001D52FC;
extern s32 D_002CF1F0[];
extern u8 D_001426F7[];
extern u8 *D_001DEB00;
extern u8 D_001A4C60[];
extern f32 D_001DE350;

void func_003A32D0(u8 *m) {
    V_3A32D0 *v;
    u8 *e;

    v = *(V_3A32D0 **)(m + 0x68);
    if (v->w10 != -1 && m[0xBC] == 0) {
        m[0xBC] = 1;
        func_003C3A40(v->w10);
    }
    if (m[0x20] == 0) {
        m[0x30] = 0xFF;
        if (D_001D545C == 4) {
            if (func_004181C8(D_001A4C60, v->w0, 0) != 0) {
                func_004264D8(0, 9, 0xA48, 1, 0, 0, 0);
                if (D_001D52FC->w1A4 == 16 && D_002CF1F0[0] == 9) {
                    func_00419970(m, 1, -1);
                }
            }
        } else if (D_001D545C == 8 || D_001D545C == 0x1B || D_001D545C == 0x1C) {
            if (D_001D545C == 8 && v->w8 == 0x1B && D_001426F7[0] == 1) {
            } else if (func_004181C8(D_001A4C60, v->w0, 0) != 0) {
                switch (v->wC) {
                case 1:
                    break;
                case 0:
                    func_004264D8(0, 9, 0xC53, 1, 0, 0, 0);
                    break;
                case 2:
                    func_004264D8(0, 9, 0x850, 1, 0, 0, 0);
                    break;
                case 3:
                    func_004264D8(0, 9, 0xC54, 1, 0, 0, 0);
                    break;
                default:
                    func_004264D8(0, 9, 0x850, 1, 0, 0, 0);
                    break;
                }
                if ((D_001D545C == 0x1B && v->wC == 1) || (D_001D52FC->w1A4 == 16 && D_002CF1F0[0] == 9)) {
                    if (v->w4 == -1) {
                        if (D_001D545C == 0x1C && v->w8 == 8) {
                            D_001426F7[0] = 1;
                        }
                        if (v->w8 == 0x1B) {
                            D_001426F7[0] = 1;
                        }
                        if (v->w10 != -1) {
                            func_00419970(m, 3, -1);
                            func_003C39E0(v->w10);
                        } else if (v->w14 != -1) {
                            func_00419970(m, 4, -1);
                            func_004DDC98(D_001DEB00 + v->w14 * 0x80 + 0x30, 0, *(f32 *)(D_001DEB00 + v->w14 * 0x80 + 0x78));
                        } else {
                            func_003F0508(v->w8, 1);
                        }
                    } else {
                        func_00419970(m, 1, -1);
                    }
                }
            }
        } else {
            if (func_004181C8(D_001A4C60, v->w0, 0) != 0) {
                func_00419970(m, 1, -1);
            }
        }
    }
    if (m[0x20] == 1) {
        func_0041C818(&D_001DE350, 1.0f, 0.033333335f);
        if (D_001DE350 == 1.0f) {
            D_001DE350 = 1.5f;
        }
        if (D_001DE350 >= 1.0f) {
            func_00400138(v->w8, 0);
            e = D_001DEB00 + v->w4 * 0x80;
            func_004C5F00(e + 0x30, e + 0x70, 0, 1);
            func_00476038(e + 0x30, e + 0x70);
            if (D_001D545C == 2 && *(f32 *)(e + 0x38) < 50.0f) {
                func_00425D78(0xC7A, -1, 0);
            }
            func_00419970(m, 2, -1);
        }
    }
    if (m[0x20] == 2) {
        func_0041C818(&D_001DE350, 0.0f, 0.033333335f);
        if (D_001DE350 <= 0.0f) {
            D_001DE350 = 0.0f;
            func_00419970(m, 0, -1);
        }
    }
    if (m[0x20] == 3) {
        if (func_003C3A10(v->w10) != 0) {
            func_003F0508(v->w8, 1);
        }
    }
    if (m[0x20] == 4) {
        if (++*(u16 *)(m + 0x96) == 0x55) {
            func_004CF3B8(0x69, 1);
        }
        if (*(u16 *)(m + 0x96) > 100) {
            func_0041C818(&D_001DE350, 1.0f, 0.050000004f);
        }
        if (*(u16 *)(m + 0x96) == 0x82) {
            func_003F0508(v->w8, 1);
        }
    }
}
/* localdecomp:end func_003A32D0 */
