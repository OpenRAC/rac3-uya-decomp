#include "common.h"

extern s32 D_001D545C;
extern s32 D_001EAA98[];
extern void func_004493C0(void *, s32, void *, void *, void *, void *);
extern void func_00443140(void *, s32, s32, f32);

void func_0032EC40(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    func_004493C0(m, *(s32 *)(v + 0x70), m + 0x10, m + 0xF0, m + 0x10, m + 0xF0);
    if (D_001D545C == 7) {
        func_00443140(m + 0x10, 0, 0, 0.5f);
        if (D_001EAA98[0] == 0) {
            *(s32 *)(v + 0x70) = 0;
        }
    }
}
