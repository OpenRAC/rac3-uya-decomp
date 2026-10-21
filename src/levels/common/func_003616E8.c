#include "common.h"

/* localdecomp:start func_003616E8 */
extern void func_0041C368(void *);
extern void func_0041C398(void *);
extern void func_00448A30(void *);
extern void func_0045E078(void *, void *, s32, s32, f32);
extern void func_0045AAE8(void *, void *, s32, f32, f32);

void func_003616E8(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    u8 **p;
    s32 i;
    func_0041C368(v + 0x2F0);
    func_0041C398(v + 0x2F4);
    p = (u8 **)(v + 0x4B0);
    for (i = 0; i < 8; i++, p++) {
        u8 *e = *p;
        if (e != 0) {
            *(s32 *)(e + 0x98) = 0;
            func_00448A30(*p);
        }
    }
    if (*(u16 *)(o + 0x96) < 0xFFFF) {
        *(u16 *)(o + 0x96) += 1;
    }
    func_0045E078(o, v + 0x260, 2, 1, 2.5f);
    func_0045AAE8(o, v + 0x390, 1, 0.03f, 0.3f);
}
/* localdecomp:end func_003616E8 */
