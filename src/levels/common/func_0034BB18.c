#include "common.h"

extern f32 func_003E09C0(f32 a);
extern f32 func_003DFEF8(f32 a, f32 b);

f32 func_0034BB18(f32 *v) {
    if (v[0] == 0.0f) {
        if (v[2] > 0.0f) {
            return func_003E09C0(1.5707964f);
        }
        return func_003E09C0(-1.5707964f);
    }
    return func_003DFEF8(v[0], v[2]);
}
