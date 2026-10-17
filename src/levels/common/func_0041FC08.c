#include "common.h"

extern s32 D_001D6694[];
extern u8 D_001D6808;
extern s32 D_001D6A08;
extern s32 func_0040BA90(void *);
extern void func_00433080(s32);

u8 func_0041FC08(void) {
    s32 m = D_001D6694[0];
    if (m == 0 || m == 7) {
        if (func_0040BA90(&D_001D6A08) != 0) {
            func_00433080(1);
        }
    }
    return D_001D6808;
}
