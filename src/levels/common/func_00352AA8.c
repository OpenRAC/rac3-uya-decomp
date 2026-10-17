#include "common.h"

extern void func_0040BA90(void *);
extern void func_0040BAC0(void *);
extern void func_00439610(u8 *);
extern void func_0044EB78(u8 *, void *, s32, s32, f32);

void func_00352AA8(u8 *self) {
    u8 *v = *(u8 **)(self + 104);
    u8 **list;
    s32 i;

    func_0040BA90(v + 736);
    list = (u8 **)(v + 1008);
    func_0040BAC0(v + 740);
    for (i = 0; i < 8; i++) {
        if (list[i] != 0) {
            *(s32 *)(list[i] + 152) = 0;
            func_00439610(list[i]);
        }
    }
    if (*(u16 *)(self + 150) < 0xFFFF) {
        *(u16 *)(self + 150) += 1;
    }
    func_0044EB78(self, v + 592, 2, 1, 2.5f);
}
