#include "common.h"

extern s32 func_00457288(s32, s32, s32, s32, u8 *);
extern s32 D_001D81F4;
extern void func_004799C0(void);
extern void func_00479218();

extern s32 D_001D81F4;
extern void func_0042FF20();
extern void func_00479218();
extern s32 func_00457288(s32, s32, s32, s32, u8 *);
extern void func_004799C0(void);
void func_004793F8(void) {
    switch (D_001D81F4) {
    case 0:
        func_0042FF20(func_00479218, 0, 0);
    case 1:
        func_00457288(4, 1, 1, 0, 0);
        D_001D81F4++;
        break;
    case 2:
        func_004799C0();
        break;
    }
}
