#include "common.h"

/* localdecomp:start func_004EB0E8 */
typedef struct {
    u8 pad0[1007];
    u8 unk3EF;
    u8 pad3F0[8697];
    u8 unk25E9;
    u8 pad25EA[590];
    f32 unk2838;
} S_001A4BE0;

extern S_001A4BE0 D_001A4BE0;
extern s32 func_004E5470(s32);
extern void func_004EAFF8(s32, f32, f32, f32);

void func_004EB0E8(void) {
    f32 t = D_001A4BE0.unk2838;
    f32 a;
    f32 b;
    f32 c;

    if (t == 1.0f) {
        a = 0.022f;
    } else {
        a = t * 0.02f;
        if (0.022f < a) {
            a = 0.022f;
        }
        if (a < 0.01f) {
            a = 0.01f;
        }
    }
    if (D_001A4BE0.unk2838 == 1.0f) {
        b = 0.09308423101902008f;
    } else {
        b = t * 0.06399540603160858f;
        if (0.09308423101902008f < b) {
            b = 0.09308423101902008f;
        }
        if (b < 0.03199770301580429f) {
            b = 0.03199770301580429f;
        }
    }
    c = 0.27f;
    if (D_001A4BE0.unk3EF != 0) {
        a = 0.035f;
        b = 0.19489510357379913f;
    }
    switch (func_004E5470(0)) {
    case 16:
    case 17:
    case 39:
    case 47:
        if (D_001A4BE0.unk25E9 != 0 && D_001A4BE0.unk3EF == 0) {
            if (0.95f < t) {
                a = 0.017f;
                c = 0.18f;
                b = 0.1454441100358963f;
            } else {
                a = t * 0.009f;
                c = 0.15f;
                b = t * 0.07853981852531433f;
            }
        }
        break;
    }
    func_004EAFF8(0, a, c, b);
}
/* localdecomp:end func_004EB0E8 */
