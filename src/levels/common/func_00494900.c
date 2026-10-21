#include "common.h"

/* localdecomp:start func_00494900 */
extern s32 func_00494900();
extern void func_004948D8();

extern void func_004948C8(void);
extern void func_004948D8(s32, s32);
extern void func_004949A0(s32, s32);
extern s32 D_001D92DC;
extern s32 D_001D92D8;
extern s32 D_001D92E4;
extern s32 D_001D92E8;
extern s32 D_001D92EC;
extern s8 D_001D92F0;
s32 func_00494900(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (D_001D92DC != 1) {
        return 0;
    }
        D_001D92DC = 0;
        func_004948C8();
        D_001D92D8 = arg0;
        D_001D92E4 = arg1;
        D_001D92E8 = arg2;
        D_001D92EC = arg3;
        D_001D92F0 = arg4;
        func_004949A0(0x60, 0x1A0);
        func_004948D8(0xFFFF, 0xFFFF);
    return 1;
}
/* localdecomp:end func_00494900 */
