#include "common.h"

/* localdecomp:start func_00486138 */
extern u8 *D_001D52FC[];
extern s32 D_001D886C;
extern s32 D_001D8868;
extern s32 D_001D8878;

extern s32 func_004A7368(s32 a, s32 b, s32 c);
extern void func_005130C8(s32 a, s32 b);

void func_00486138(void) {
    u32 pad = *(u32 *)(D_001D52FC[0] + 452);

    if (pad & 0x1000) {
        func_004A7368(3, 0, 0);
        D_001D886C--;
        if (D_001D886C < 0) {
            D_001D886C = 3;
        }
        func_005130C8(0x19000E, 0x402299DE);
        func_005130C8(0x19000F, 0x402299DE);
    } else if (pad & 0x4000) {
        func_004A7368(3, 0, 0);
        D_001D886C++;
        if (D_001D886C >= 4) {
            D_001D886C = 0;
        }
        func_005130C8(0x19000E, 0x402299DE);
        func_005130C8(0x19000F, 0x402299DE);
    } else if (pad & 0x8000) {
        func_004A7368(3, 0, 0);
        D_001D8868--;
        if (D_001D8868 < 0) {
            if (D_001D886C < 2) {
                D_001D8868 = 4;
            } else {
                D_001D886C -= 2;
                D_001D8868 = 3;
                D_001D8878 = 1;
            }
        }
        func_005130C8(0x19000E, 0x402299DE);
        func_005130C8(0x19000F, 0x402299DE);
    } else if (pad & 0x2000) {
        func_004A7368(3, 0, 0);
        D_001D8868++;
        if (D_001D8868 >= 5) {
            D_001D8868 = 0;
            if (D_001D886C >= 2) {
                D_001D886C -= 2;
                D_001D8878 = 1;
            }
        }
        func_005130C8(0x19000E, 0x402299DE);
        func_005130C8(0x19000F, 0x402299DE);
    }
}
/* localdecomp:end func_00486138 */
