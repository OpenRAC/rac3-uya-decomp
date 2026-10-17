#include "common.h"
typedef struct {
    char pad[1916];
    s32 v;
} Unk244740;
extern s32 D_001426A8[];
extern Unk244740 D_00244740;
extern s32 D_001DAE1C;
s32 func_004BBD58(void) {
    if (D_001426A8[0] & 1) {
        D_00244740.v = 1;
    }
    if (D_001DAE1C != D_00244740.v) {
        D_001DAE1C = D_00244740.v;
        return 1;
    }
    return 0;
}
