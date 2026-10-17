#include "common.h"
typedef struct {
    u8 pad0[128];
    u8 f128[9700 - 128];
    u8 f9700;
} S_001A4BE0;
extern S_001A4BE0 D_001A4BE0;
extern f32 func_00400C50(void *, void *);
extern void func_004DD3A8(s32, s32, void *);
void func_0032E840(u8 *a0) {
    if (D_001A4BE0.f9700 == 0) {
        if (func_00400C50(D_001A4BE0.f128, a0 + 16) < 1.7f) {
            func_004DD3A8(1, 63, a0);
        }
    }
}
