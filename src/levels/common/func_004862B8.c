#include "common.h"

extern u8 *D_001D52FC[];
extern s32 D_001D886C;
extern s32 D_001D8868;
extern s32 D_001D8878;
extern s32 func_004A7368(s32, s32, s32);
extern void func_005130C8(s32, s32);

void func_004862B8(void) {
    s32 t;
    u32 v = *(u32 *)(D_001D52FC[0] + 452);

    if (v & 0x1000) {
        func_004A7368(3, 0, 0);
        t = D_001D886C - 1; D_001D886C = t; if (t < 0) {
            D_001D886C = 1;
        }
    } else if (v & 0x4000) {
        func_004A7368(3, 0, 0);
        t = D_001D886C + 1; D_001D886C = t; if (t >= 2) {
            D_001D886C = 0;
        }
    } else if (v & 0x8000) {
        func_004A7368(3, 0, 0);
        t = D_001D8868 - 1; D_001D8868 = t; if (t < 0) {
            D_001D8868 = 4;
            D_001D8878 = 0;
            D_001D886C += 2;
        }
    } else {
        goto other;
    }
    func_005130C8(0x19000E, 0x402299DE);
    return;
other:
    if (v & 0x2000) {
        func_004A7368(3, 0, 0);
        t = D_001D8868 + 1; D_001D8868 = t; if (t >= 4) {
            D_001D8868 = 0;
            D_001D8878 = 0;
            D_001D886C += 2;
        }
        func_005130C8(0x19000E, 0x402299DE);
    }
}
