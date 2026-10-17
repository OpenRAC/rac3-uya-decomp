#include "common.h"
extern float D_001DF750[];
extern float D_001DF74C[];
s32 func_00355038(float f) {
    s32 r = 0;
    if (D_001DF750[0] < f) {
        if (D_001DF74C[0] < f) r = 1;
    }
    return r;
}
