#include "common.h"
extern s32 D_001DC598[2];
extern s32 D_001DC5B8[2];
s32 *func_00313A98(s32 a0, s32 a1, s32 *a2) {
    s32 *r = 0;
    switch (a1) {
    case 1:
        *a2 = 28;
        return D_001DC598;
    case 6:
        *a2 = 4;
        return D_001DC5B8;
    }
    return r;
}
