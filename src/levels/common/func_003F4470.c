#include "common.h"
typedef s32 (*Fn003F4470)(s32, s32, s32, s32, s32);
extern Fn003F4470 *func_00425B08(s32, s32, s32);
s32 func_003F4470(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    Fn003F4470 *f = func_00425B08(2491, 0, 4);
    if (f == 0) {
        return 0;
    }
    return (*f)(a0, a1, a2, a3, t0);
}
