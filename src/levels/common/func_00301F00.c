#include "common.h"

/* localdecomp:start func_00301F00 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern void func_0044E088(Vec4 *, Vec4 *, Vec4 *, f32);
extern s32 func_003F8448(Vec4 *, s32 *, s32, s32, s32);
extern s32 D_001A4CC0[];

s32 func_00301F00(u8 *obj) {
    Vec4 v;
    v = *(Vec4 *)(obj + 16);
    func_0044E088((Vec4 *)(obj + 16), &v, &v, -0.5f);
    return func_003F8448(&v, D_001A4CC0, 18, 0, 0) == 0;
}
/* localdecomp:end func_00301F00 */
