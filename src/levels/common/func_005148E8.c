#include "common.h"
extern s32 func_00476988_005148E8(s32);
extern s32 func_00512FE8_005148E8(s32, s32);
extern s32 func_005130C8_005148E8(s32, s32);
extern s32 func_00513548_005148E8(s32, f32, f32);
extern s32 func_00512480_005148E8(s32, f32, f32);
s32 func_005148E8(s32 identifier, s32 mode, s32 subtype, f32 first, f32 second, f32 third, f32 fourth) {
    s32 found = func_00476988_005148E8(identifier);
    s32 all_ok = func_00512FE8_005148E8(identifier, mode) != 0;
    s32 result;
    if (!found) all_ok = 0;
    result = func_005130C8_005148E8(identifier, subtype) != 0;
    all_ok = all_ok & result;
    result = func_00513548_005148E8(identifier, third, fourth) != 0;
    all_ok = all_ok & result;
    result = func_00512480_005148E8(identifier, first, second) != 0;
    return all_ok & result;
}
