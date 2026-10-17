#include "common.h"
typedef s32 (*Fn004071B0)(s32, s32, s32, s32, s32);
extern Fn004071B0 *func_00438488(s32, s32, s32);
s32 func_004071B0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    Fn004071B0 *f = func_00438488(7721, 0, 4);
    if (f == 0) {
        return 0;
    }
    return (*f)(a0, a1, a2, a3, t0);
}
