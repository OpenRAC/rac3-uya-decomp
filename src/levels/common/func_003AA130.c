#include "common.h"

extern s32 D_001DE738;
extern s32 D_001DE758;

s32 *func_003AA130(s32 unused, s32 kind, s32 *count) {
    switch (kind) {
    case 1:
        *count = 28;
        return &D_001DE738;
    case 2:
        *count = 12;
        return &D_001DE758;
    }
    return 0;
}
