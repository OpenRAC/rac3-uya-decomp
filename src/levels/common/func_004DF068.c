#include "common.h"

/* localdecomp:start func_004DF068 */
typedef struct {
    u8 pad0[1536];
    s32 x600;
    u8 pad604[76];
    f32 x650;
    u8 pad654[8];
    s16 x65C;
    u8 pad65E[226];
    s32 x740;
    s32 x744;
    u8 pad748[7800];
    u8 *x25C0;
    s32 x25C4;
} S_4DF068;

extern void func_0044B920(u8 *, s32 *, s32 *, f32, f32, f32);
extern S_4DF068 D_001A4BE0;

void func_004DF068(void) {
    if (D_001A4BE0.x25C4 == 129 || D_001A4BE0.x25C4 == 80) {
        func_0044B920(D_001A4BE0.x25C0, &D_001A4BE0.x740, &D_001A4BE0.x744, 0.17453292f, 0.026179941f, 0.03490659f);
    }
    if (D_001A4BE0.x65C != 0 && D_001A4BE0.x600 == 0) {
        *(f32 *)(D_001A4BE0.x25C0 + 244) = D_001A4BE0.x650;
    }
}
/* localdecomp:end func_004DF068 */
