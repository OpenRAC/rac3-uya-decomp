#include "common.h"

extern s32 D_001D6694;
extern s32 D_001D9870;

void func_004AC3F0(s32);
void func_004AC588(s32);
extern s32 D_001D6694;
extern s32 D_001D9870;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B8C70_003B8C70;
extern S_001CCFD0_003B8C70_003B8C70 D_001CCFD0_003B8C70[];

void func_004D4AB8(void) {
    if (D_001D9870 != 0) {
        D_001CCFD0_003B8C70->f7 = 0;
        switch (D_001D9870) {                       /* irregular */
        case 17:
            func_004AC3F0(0x11);
            break;
        case 18:
            func_004AC588(0x12);
            break;
        }
        D_001CCFD0_003B8C70->f7 = 1;
        D_001D6694 = 6;
        D_001D9870 = 0;
    }
}
