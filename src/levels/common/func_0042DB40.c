#include "common.h"

extern void func_0040BBA8(void *, s32, s32);
extern void func_0042DB40();
extern u32 D_001D545C;

typedef struct { u8 p0[0xC]; s32 fC; s32 f10; s32 f14; u8 p1[0x10]; s32 f28; } S_39AAF0;
extern S_39AAF0 D_001F4020_0039AAF0;
extern u32 D_001D545C;
extern s32 D_00143140[];
extern s32 func_0040D1F8();
extern void func_0042E070();
void func_0042DB40(void *arg0) {
    S_39AAF0 *p = &D_001F4020_0039AAF0;
    s32 r;
    if (p->f10 != 0) {
        if (p->f28 == 0) {
            func_0040BBA8(arg0, 0, 0x800);
            return;
        }
        func_0042AC78(D_001D545C);
        r = func_0040D1F8(arg0, 0x800, p->f14, p->fC);
        if (r == -1) func_0042E070(arg0);
        if (D_00143140[D_001D545C] < r) D_00143140[D_001D545C] = r;
    }
}
