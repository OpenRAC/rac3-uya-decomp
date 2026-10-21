#include "common.h"

/* localdecomp:start func_004E3570 */
typedef struct {
    u8 pad0[36];
    f32 f36;
} Q_4E3570;

typedef struct O_4E3570 {
    u8 pad0[36];
    Q_4E3570 *p36;
    u8 pad28[44 - 40];
    f32 f44;
    u8 pad30[170 - 48];
    s16 h170;
} O_4E3570;

typedef struct {
    u8 pad0[800];
    f32 f800;
    f32 f804;
    f32 f808;
    f32 f812;
    f32 f816;
    f32 f820;
    u8 pad338[872 - 824];
    s16 h872;
    u8 pad36A[1132 - 874];
    u8 b1132;
    u8 pad46D[4688 - 1133];
    O_4E3570 *p4688;
    O_4E3570 *p4692;
    u8 pad1258[5136 - 4696];
    f32 f5136;
    f32 f5140;
    s32 w5144;
    s16 h5148;
    u16 h5150;
    u8 pad1420[9664 - 5152];
    s32 w9664;
    s32 w9668;
    u8 pad25C8[9676 - 9672];
    s32 w9676;
} G_4E3570;

typedef struct {
    u8 pad0[800];
    f32 f800;
    f32 f804;
    u8 pad328[876 - 808];
    f32 f876;
    u8 pad370[976 - 880];
    f32 f976;
    f32 f980;
    u8 pad3D8[1052 - 984];
    f32 f1052;
    u8 pad420[1152 - 1056];
    f32 f1152;
    u8 pad484[1328 - 1156];
    f32 f1328;
} H_4E3570;

extern G_4E3570 D_001A4BE0;
extern H_4E3570 D_002F4580;

extern s32 func_004E5540(void);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CF10(f32, f32);
extern void func_0050CCC8(f32, f32, s32, s32, s32, s32);
extern void func_00437698(s32, s32, f32 *);
extern f32 func_004408C0(f32, f32);
extern void func_00464068(f32 *, s32, f32);

void func_004E3570(void) {
    f32 buf[4];
    O_4E3570 *o;
    f32 a;
    f32 b;
    s32 i;
    s32 p;

    if (D_001A4BE0.p4688 != 0) {
        D_002F4580.f876 = 0.01f;
        D_002F4580.f1052 = 0.01f;
    }
    o = D_001A4BE0.p4688;
    if (o != 0 && o->h170 == 173) {
        o->f44 = o->p36->f36 * 0.9f;
    }
    o = D_001A4BE0.p4692;
    if (o != 0 && o->h170 == 173) {
        o->f44 = o->p36->f36 * 0.9f;
    }
    if (func_004E5540() != 0) {
        return;
    }
    if (0.015f < __builtin_fabsf(D_001A4BE0.f800) || 0.015f < __builtin_fabsf(D_001A4BE0.f804) ||
        0.0174532924f < __builtin_fabsf(D_001A4BE0.f808) || 0.0174532924f < __builtin_fabsf(D_001A4BE0.f812) ||
        0.0174532924f < __builtin_fabsf(D_001A4BE0.f816) || 0.0174532924f < __builtin_fabsf(D_001A4BE0.f820)) {
        if (D_001A4BE0.h872 != 1) {
            D_002F4580.f804 = -D_001A4BE0.f808;
            D_002F4580.f980 = -D_001A4BE0.f812;
            a = func_0040C490(0.2f, D_001A4BE0.f800) * 1.2f;
            b = -func_0040C490(0.2f, D_001A4BE0.f804) * 1.2f;
            if (0.785398185f < a) {
                a = 0.785398185f;
            }
            if (a < -0.17453292f) {
                a = -0.17453292f;
            }
            if (0.17453292f < b) {
                b = 0.17453292f;
            }
            if (b < -0.785398185f) {
                b = -0.785398185f;
            }
            D_002F4580.f1152 = a;
            D_002F4580.f1328 = b;
            D_002F4580.f800 = -func_0040CF10(D_001A4BE0.f816, -a);
            D_002F4580.f976 = -func_0040CF10(D_001A4BE0.f820, -b);
        }
    }
    if (!(D_001A4BE0.h5150 & 0x80)) {
        if (D_001A4BE0.w9668 == 3) {
            func_0050CCC8(0.0209999997f, 0.00200000009f, 1, 2, 1, 0);
        }
        if (D_001A4BE0.w9676 == 4 && D_001A4BE0.b1132 != 0 && D_001A4BE0.b1132 < 12) {
            func_0050CCC8(0.0160000008f, 0.00200000009f, 1, 2, 0, 1);
        }
        if (D_001A4BE0.w5144 > 0 && D_001A4BE0.h5148 != 0) {
            p = 0;
            if (D_001A4BE0.h5150 & 1) {
                p = D_001A4BE0.w9664 + 192;
            }
            D_001A4BE0.w5144--;
            func_00437698(D_001A4BE0.w9664, 22, buf);
            for (i = 0; i < D_001A4BE0.h5148; i++) {
                func_00464068(buf, p, D_001A4BE0.f5136 + func_004408C0(-D_001A4BE0.f5140, D_001A4BE0.f5140));
            }
            func_00437698(D_001A4BE0.w9664, 23, buf);
            for (i = 0; i < D_001A4BE0.h5148; i++) {
                func_00464068(buf, p, D_001A4BE0.f5136 + func_004408C0(-D_001A4BE0.f5140, D_001A4BE0.f5140));
            }
        }
    } else {
        D_001A4BE0.w5144 = 0;
    }
}
/* localdecomp:end func_004E3570 */
