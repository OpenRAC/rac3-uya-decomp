#include "common.h"

extern void func_0045CB08();

s32 func_0011F0A0(s32);                       /* extern */
s32 func_0013CEF8();                                  /* extern */
typedef struct { s32 x0; s16 h4; u8 b6; u8 b7; u8 pad[0x10]; void *f18; s32 f1C; } S_39D770;
extern S_39D770 D_001CCFD0_0039D770[];

void func_0045CB08(s32 arg0) {
    s32 (*temp_v1)(s32, s32);
    s32 temp_a0;
    s32 temp_a1;

    if (arg0 == 1) {
        if (D_001CCFD0_0039D770->h4 == 0) {
            D_001CCFD0_0039D770->f18 = 0;
            D_001CCFD0_0039D770->f1C = 0;
            return;
        }
        if (func_0013CEF8() != 0) {
            D_001CCFD0_0039D770->h4 = 2;
            return;
        }
        func_0011F0A0(0);
        temp_v1 = (s32 (*)(s32, s32))D_001CCFD0_0039D770->f18;
        D_001CCFD0_0039D770->h4 = 0;
        temp_a1 = D_001CCFD0_0039D770->b6 == 0;
        D_001CCFD0_0039D770->b6 = 0U;
        if (temp_v1 != 0) {
            temp_a0 = D_001CCFD0_0039D770->f1C;
            D_001CCFD0_0039D770->f18 = 0;
            D_001CCFD0_0039D770->f1C = 0;
            temp_v1(temp_a0, temp_a1);
        }
    }
}
