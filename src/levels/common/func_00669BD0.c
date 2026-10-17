#include "common.h"

typedef struct {
    s32 a;
    s32 b;
    s32 cur;
} S_669BD0;

extern S_669BD0 D_001A5E50;
extern s32 func_0061A800(s32);

s32 func_00669BD0(s32 start) {
    s32 i;

    if (func_0061A800(start) != 0) {
        return 0;
    }
    for (i = start + 1; i != start; i++) {
        if (i >= 8) {
            i = 0;
        }
        if (i == D_001A5E50.cur) {
            return 1;
        }
        if (func_0061A800(i) != 0) {
            break;
        }
    }
    func_0061A800(i);
    return 0;
}
