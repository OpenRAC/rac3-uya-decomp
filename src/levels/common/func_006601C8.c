#include "common.h"
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;
extern void func_0058F1B0(void *dst, void *src, s32 n);
void func_006601C8(u8 *a0, void *a1, s32 a2) {
    func_0058F1B0(a0 + 12 + a0[84], a1, a2);
    a0[84] += a2;
    if (((S_6601C8 *)a0)->cap < (u32)a0[84]) {
        ((S_6601C8 *)a0)->cap = a0[84];
    }
}
