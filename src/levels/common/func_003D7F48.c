#include "common.h"
typedef struct {
    u8 pad0[1020];
    f32 f1020;
    u8 pad1[96];
} Ent1120;
extern Ent1120 D_001E2540[];
extern void func_003D4328(f32 a, f32 b, s32 a0, s32 a1);
extern void func_003D7FD0(void);
extern void func_003DEB78(s32 a0, void (*cb)(void));
void func_003D7F48(s32 a0) {
    f32 v;
    v = (D_001E2540 + a0)->f1020;
    if (v != 0.0f) {
        func_003D4328(v * 0.35f + 0.0f, 0.005f, a0, 1);
        func_003DEB78(a0, func_003D7FD0);
    }
}
