#include "common.h"

extern s32 func_004C46A8(void *, u8 *);
extern u8 *func_004C4758(void *, u8 **, s32, s32);

u8 *func_004C4820(void *a, u8 **list, s32 n, s32 *out, s32 type) {
    s32 i;
    u8 *r;

    *out = 1;
    for (i = 0; i < n; i++) {
        if (type > 0 && (*(u8 **)(list[i] + 36))[70] != type) {
            continue;
        }
        if (func_004C46A8(a, list[i]) == 1) {
            return list[i];
        }
    }
    if (n < 2) {
        return 0;
    }
    r = func_004C4758(a, list, n, type);
    if (r != 0) {
        *out = 0;
    }
    return r;
}
