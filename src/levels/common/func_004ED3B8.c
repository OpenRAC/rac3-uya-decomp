#include "common.h"

/* localdecomp:start func_004ED3B8 */
typedef struct {
    f32 v[4];
} Vec4ED3B8;

typedef struct {
    u8 pad0[0x1B4];
    f32 f1B4;
} Cam4ED3B8;

extern Vec4ED3B8 D_001A4CF0[];
extern void func_0040BE90(Vec4ED3B8 *, Vec4ED3B8 *, f32);

void func_004ED3B8(f32 s) {
    Vec4ED3B8 *p = D_001A4CF0;
    func_0040BE90(p, p, s);
    func_0040BE90(p + 1, p + 1, s);
    func_0040BE90(p + 2, p + 2, s);
    func_0040BE90(p - 2, p - 2, s);
    func_0040BE90(p + 5, p + 5, s);
    {
        Cam4ED3B8 *c = (Cam4ED3B8 *)(p - 17);
        c->f1B4 *= s;
    }
}
/* localdecomp:end func_004ED3B8 */
