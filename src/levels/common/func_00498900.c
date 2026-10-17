#include "common.h"
extern s32 D_001D943C;
extern u8 *D_001D52FC[];
extern void func_00498660(void);
extern s32 func_0048F078(void);
extern void func_00513758(s32);
extern void func_005120B8(s32);
void func_00498900(s32 a0) {
    if (D_001D943C >= 0) {
        if (*(s32 *)(D_001D52FC[0] + 452) & 0x40) {
            func_00498660();
        }
    }
    if (*(s32 *)(D_001D52FC[0] + 452) & 0x910) {
        func_00513758(func_0048F078());
        func_005120B8(a0);
    }
}
