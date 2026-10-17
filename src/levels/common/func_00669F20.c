#include "common.h"

typedef struct {
    s32 pad;
    s32 (*fn)(u32);
} VT00669F20;

extern VT00669F20 *func_005BF058(void);
extern s32 func_00669F78(u32);
extern u32 D_0024C060;

s32 func_00669F20(u32 a) {
    if (a < D_0024C060) {
        return func_00669F78(a);
    }
    return func_005BF058()->fn(a);
}
