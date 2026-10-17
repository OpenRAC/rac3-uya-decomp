#include "common.h"

extern void func_0056FB18(u8 *);
extern void func_0057AA58(s32, u8 *, f32);

void func_0056FF88(u8 *o) {
    u8 *s = (u8 *)*(s32 *)(o + 112) + 224;
    func_0056FB18(o);
    if (*(s32 *)(s + 64)) {
        o[137] = 0;
        func_0057AA58(*(s32 *)(o + 148), o + 48, 0.5f);
    }
}
