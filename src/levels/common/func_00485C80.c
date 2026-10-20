#include "common.h"
extern s32 D_001D8868;
extern s32 D_001D8878;
extern s32 D_001D886C;
extern s32 D_001D87C0;
extern s32 D_001D87D0[2];
extern s32 D_001D87F0[2];
extern s32 D_001D8874;
extern u8 D_00142CA0[];
extern s32 func_00484718(s32, s32, s32);
void func_00485C80(void) {
    s32 r;
    s32 i;
    r = func_00484718(D_001D8878, D_001D8868, D_001D886C);
    switch (D_001D87C0) {
    case 0:
        if (r == 0 || D_00142CA0[r] == 0) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (D_001D87D0[i] == r) {
                D_001D87D0[i] = 0;
            }
        }
        D_001D87D0[D_001D8874] = r;
        D_001D8874++;
        break;
    case 1:
        if (r == 0 || D_00142CA0[r] == 0) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (D_001D87F0[i] == r) {
                D_001D87F0[i] = 0;
            }
        }
        D_001D87F0[D_001D8874] = r;
        D_001D8874++;
        break;
    }
}
