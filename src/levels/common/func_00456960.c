#include "common.h"

/* localdecomp:start func_00456960 */
typedef struct {
    u8 pad[186];
    u8 b186;
} St_00456960;

extern u8 D_001D54B0[1];
extern s32 D_001D6790;
extern St_00456960 D_001426E0;
extern void func_004A7368(s32, s32, s32);
extern void func_0044ECE0(s32, s32, s32);
extern void func_004344A0(void);

void func_00456960(s32 idx) {
    s32 i;

    if (D_001D54B0[idx] == 0) {
        D_001D54B0[idx] = 1;
        func_004A7368(1, 0, 0);
        func_0044ECE0(1734, -1, 0);
        D_001D6790 = 1;
        if (D_001426E0.b186 == 0) {
            for (i = 0; i < 30; i++) {
                if (D_001D54B0[i] == 0) {
                    return;
                }
            }
            func_0044ECE0(4785, -1, 0);
            D_001426E0.b186 = 1;
            func_004344A0();
        }
    }
}
/* localdecomp:end func_00456960 */
