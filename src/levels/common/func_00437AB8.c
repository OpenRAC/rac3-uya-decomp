#include "common.h"

/* localdecomp:start func_00437AB8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern s32 D_001A71A0[];
extern f32 D_001E00F0[];
extern void func_00438968(s32, Vec4 *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);

void func_00437AB8(void)
{
    Vec4 dir;
    f32 angle;

    func_00438968(D_001A71A0[0], &dir);
    angle = func_0040C490(dir.v[0], dir.v[1]);
    D_001E00F0[0] = func_0040C3C8(angle) * 0.14f;
    D_001E00F0[1] = func_0040C3E0(angle) * 0.14f;
    D_001E00F0[2] = -0.99f;
}
/* localdecomp:end func_00437AB8 */
