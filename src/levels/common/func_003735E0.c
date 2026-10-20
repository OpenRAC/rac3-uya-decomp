#include "common.h"

extern s32 func_0040BA90(void *);
extern void func_00373378(void *);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern void func_004082B0(void *, s32, s32, s32, f32, f32, f32);

void func_003735E0(u8 *obj) {
    u8 *v = *(u8 **)(obj + 104);
    u8 *m;

    if (func_0040BA90(v + 84) != 0) {
        return;
    }
    func_00373378(obj);
    func_00373378(obj);
    m = v + 16;
    func_004082B0(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00440978());
    func_004082B0(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00440978());
    func_004082B0(m, 11, 0x3F204090, 1, 0.9f, 0.08f, 0.0f);
    func_004082B0(m, 65, 0x3F909090, 1, 1.0f, 0.0f, func_004408C0(30.0f, 60.0f) * 0.017453292f);
}
