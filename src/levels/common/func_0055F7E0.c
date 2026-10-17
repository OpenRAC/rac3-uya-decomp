#include "common.h"
extern void *func_0066B3C0(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_006601C8(void *a0, void *a1, s32 a2);
void func_0055F7E0(u8 *a0) {
    u16 buf;
    void *h = func_0066B3C0(a0, 1, 0, 250);
    u8 *s = *(u8 **)(a0 + 104);
    buf = *(u16 *)(s + 8);
    func_006601C8(h, &buf, 2);
    buf = *(u16 *)(s + 10);
    func_006601C8(h, &buf, 2);
}
