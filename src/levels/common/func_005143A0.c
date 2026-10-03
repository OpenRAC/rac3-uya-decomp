#include "common.h"

extern s32 func_005139B0_005143A0(s32, s32);
s32 func_005143A0(s32 identifier, s32 first, s32 second, s32 third, s32 fourth, s32 fifth, s32 sixth, s32 seventh) {
    s32 all_ok;
    s32 result;
    all_ok = func_005139B0_005143A0(identifier, first) != 0;
    result = func_005139B0_005143A0(identifier, second) != 0; all_ok = all_ok & result;
    result = func_005139B0_005143A0(identifier, third) != 0; all_ok = all_ok & result;
    result = func_005139B0_005143A0(identifier, fourth) != 0; all_ok = all_ok & result;
    result = func_005139B0_005143A0(identifier, fifth) != 0; all_ok = all_ok & result;
    result = func_005139B0_005143A0(identifier, sixth) != 0; all_ok = all_ok & result;
    result = func_005139B0_005143A0(identifier, seventh) != 0; all_ok = all_ok & result;
    return all_ok;
}
