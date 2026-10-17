#include "common.h"

extern void func_004C8B28(void *, s32);

typedef struct { u8 p0[0x1C4]; u32 f1C4; } S_3A9698;
extern S_3A9698 *D_001D52FC[];
extern s32 func_00440BA8(s32, s32, s32, s32, s32, s32);
extern s32 *func_004C8AE0();
extern f32 *func_004C8FB8();
extern void func_004C8B28();
void func_004CD110(u8 *base, s32 b, f32 f) {
    s32 *r;
    f32 *q;
    u8 *p;
    if ((D_001D52FC[0]->f1C4 & 0xF000) != 0) {
        func_00440BA8(0, 0, 1, 0, 1, 0);
    }
    p = base + 0x628;
    r = func_004C8AE0(p);
    *r = func_00440BA8(0x331465B7, 0x706EC8FF, 0x14, 0, 0, 0);
    q = func_004C8FB8(p);
    *q = f;
    func_004C8B28(p, b);
}
