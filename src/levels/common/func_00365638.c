#include "common.h"

extern s32 func_00462650(u8 *);
extern void func_00451098(u8 *, s32, s32, s32);

s32 func_00365638(u8 *obj) {
    if (func_00462650(obj) != 0 && obj[67] != 0) {
        func_00451098(obj, 0, 0, 10);
    }
    return 0;
}
