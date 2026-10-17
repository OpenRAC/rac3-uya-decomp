#include "common.h"
extern u8 *func_0053B150(s32 a0);
extern u8 *func_0053B188(u8 *a0, s32 *a1);
void func_003F12B0(u8 *a0) {
    s32 i;
    u8 *it;
    u8 *v;
    u8 *e;
    it = func_0053B150(*(s32 *)(*(u8 **)(a0 + 104) + 684));
    for (i = 0; (v = func_0053B188(it, &i)) != 0 && (e = *(u8 **)(v + 28)) != 0; i++) {
        if (e != a0) {
            *(s32 *)(e + 152) = *(s32 *)(*(u8 **)(e + 36) + 16);
        }
    }
}
