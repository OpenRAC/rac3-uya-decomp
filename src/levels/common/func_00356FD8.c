#include "common.h"

extern s32 func_00436340(void *);
extern void func_003502D8(void *, void *, void *);
extern s32 func_003F0638(void *);
extern void func_00425278(void *, s32, s32);
extern void func_003518E8(void *, void *);

s32 func_00356FD8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    if (func_00436340(m) != 0) {
        *(s32 *)(v + 0x330) = 30;
    }
    func_003502D8(m, v, v + 0x220);
    if (func_003F0638(v + 0x330) != 0) {
        func_00425278(m, 26, -1);
        func_003518E8(m, v);
        return 1;
    }
    return 0;
}
