#include "common.h"

extern s32 func_004344A0();

typedef struct { u8 pad[0x410]; s32 f410; } S_399F90;
extern S_399F90 D_001F4020;
extern s32 func_00434680();
extern s32 func_00434640();
s32 func_004344A0(void) {
    s32 i = 5;
    s32 j;
    s32 k;
    s32 r;
    for (;;) {
        j = i - 1;
        func_00434488();
        r = func_00434680(D_001F4020.f410);
        for (k = 0; k < 60; k++) {
            if (k != D_001F4020.f410) func_00434680(k);
        }
        i = j;
        if (i < 0) break;
        if (func_00434480() == 0) break;
    }
    func_00434640(D_001F4020.f410);
    return r;
}
