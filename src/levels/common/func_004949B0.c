#include "common.h"

extern s32 func_004949B0(void);
extern void func_004A7368(s32, s32, s32);
extern void func_003EFFC8(void);
extern s32 D_001D92E0;
extern s32 D_001D92F4;
extern s32 D_001D92F8;
extern s32 D_001D92DC;
extern s32 D_001D92D8;

extern void func_003EFFC8(void);
extern void func_004A7368(s32, s32, s32);
extern s32 D_001D92DC;
extern s32 D_001D92D8;
extern void * D_001D52FC;
extern void *D_001D52FC_003B42D0[];
extern s32 D_001D92F4;
extern s32 D_001D92E0;
extern s32 D_001D92F8;
s32 func_004949B0(void) {
    s32 t;
    s32 m;
    if (D_001D92DC == 1) {
        return 0;
    }
    func_003EFFC8();
    t = D_001D92D8;
    switch (t) {
    case 0:
        m = *(s32 *)((u8 *)D_001D52FC + 0x1C4);
        if (m & D_001D92F4) {
            D_001D92E0 = 1;
            D_001D92DC = 1;
            func_004A7368(4, 0, 0);
        } else if (m & D_001D92F8) {
            D_001D92DC = 1;
            D_001D92E0 = 2;
            func_004A7368(4, 0, 0);
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)D_001D52FC_003B42D0[0] + 0x1C4) & D_001D92F4) {
            D_001D92E0 = t;
            func_004A7368(0x12, 0, 0);
            D_001D92DC = t;
        }
        break;
    }
    return 1;
}
