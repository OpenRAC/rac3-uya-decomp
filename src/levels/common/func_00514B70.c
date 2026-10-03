#include "common.h"

extern s32 func_00515F28_00514B70(s32);
extern s32 func_00512480_00514B70(s32, f32, f32);
extern s32 func_005130C8_00514B70(s32, s32);
extern s32 func_00513548_00514B70(s32, f32, f32);
extern s32 func_00512650_00514B70(s32, f32, f32);
s32 func_00514B70(s32 identifier, s32 mode, f32 first, f32 second, f32 third, f32 fourth, f32 fifth, f32 sixth) {
    s32 found = func_00515F28_00514B70(identifier);
    s32 all_ok = func_00512480_00514B70(identifier, first, second) != 0;
    s32 result;
    if (!found) all_ok = 0;
    result = func_005130C8_00514B70(identifier, mode) != 0;
    all_ok = all_ok & result;
    result = func_00513548_00514B70(identifier, third, fourth) != 0;
    all_ok = all_ok & result;
    result = func_00512650_00514B70(identifier, fifth, sixth) != 0;
    return all_ok & result;
}
