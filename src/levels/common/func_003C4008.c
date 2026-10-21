#include "common.h"

/* localdecomp:start func_003C4008 */
typedef struct { u8 pad[0x25C4]; s32 w25C4; u8 pad25C8[0x283C - 0x25C8]; f32 f283C; } G_3C4008;
typedef struct { u8 pad[0x98]; s32 w98; } P_3C4008;
typedef struct { u8 pad[0x54]; P_3C4008 *p54; u8 pad58[0x100 - 0x58]; u8 b100; } B_3C4008;
typedef struct { u8 pad[0x20]; u8 b20; } M_3C4008;
extern G_3C4008 D_001A4BE0;
extern s32 func_0050DAC0(void);
extern void func_0050DB10(void);
extern s32 func_003C4FE0(M_3C4008 *);
extern s32 func_00452F60(M_3C4008 *);
void func_003C4008(M_3C4008 *m, B_3C4008 *b) {
    if (b->b100 == 0) {
        return;
    }
    if (func_0050DAC0() != 0) {
        if (b->b100 == 2) {
            return;
        }
        if (D_001A4BE0.w25C4 == 105) {
            return;
        }
        if (m->b20 == 5 && func_003C4FE0(m) != 0) {
            if (b->p54 == 0) {
                return;
            }
            if (b->p54->w98 == 0) {
                return;
            }
        }
        if (func_00452F60(m) != 0) {
            return;
        }
        if (!(0.9f < D_001A4BE0.f283C)) {
            return;
        }
        func_0050DB10();
        b->b100 = 0;
    } else {
        b->b100 = 0;
    }
}
/* localdecomp:end func_003C4008 */
