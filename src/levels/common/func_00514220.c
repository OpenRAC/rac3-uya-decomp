#include "common.h"
extern s32 func_005139B0_00514220(s32, s32);
s32 func_00514220(s32 identifier, s32 first, s32 second, s32 third, s32 fourth, s32 fifth) {
    s32 all_ok;
    s32 result;
    all_ok = func_005139B0_00514220(identifier, first) != 0;
    result = func_005139B0_00514220(identifier, second) != 0;
    all_ok = all_ok & result;
    result = func_005139B0_00514220(identifier, third) != 0;
    all_ok = all_ok & result;
    result = func_005139B0_00514220(identifier, fourth) != 0;
    all_ok = all_ok & result;
    result = func_005139B0_00514220(identifier, fifth) != 0;
    return all_ok & result;
}
