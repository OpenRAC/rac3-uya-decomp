#include "common.h"

extern s32 func_00476820_005147F0(s32);
extern s32 func_004179C8_005147F0(void);
extern s32 func_00513458_005147F0(s32, s32, s32);
extern s32 func_005130C8_005147F0(s32, s32);
extern s32 func_00513548_005147F0(s32, f32, f32);
extern s32 func_00512480_005147F0(s32, f32, f32);
extern s32 func_005129D8_005147F0(s32, f32);

s32 func_005147F0(s32 identifier, s32 mode, s32 subtype, f32 first, f32 second, f32 third, f32 fourth, f32 fifth) {
    s32 found = func_00476820_005147F0(identifier);
    s32 all_ok = func_00513458_005147F0(identifier, func_004179C8_005147F0(), mode) != 0;
    s32 result;
    if (!found) all_ok = 0;
    result = func_005130C8_005147F0(identifier, subtype) != 0;
    all_ok = all_ok & result;
    result = func_00513548_005147F0(identifier, third, fourth) != 0;
    all_ok = all_ok & result;
    result = func_00512480_005147F0(identifier, first, second) != 0;
    all_ok = all_ok & result;
    result = func_005129D8_005147F0(identifier, fifth) != 0;
    return all_ok & result;
}
