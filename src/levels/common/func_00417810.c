#include "common.h"

/* localdecomp:start func_00417810 */
typedef int s128_417810 __attribute__((mode(TI)));

typedef struct {
    union {
        s128_417810 q[15];
        struct {
            u8 b0;
            u8 depth;
            u8 pad2[68];
            s16 child;
            s16 parent;
        } f;
    } u;
} S_417810;

extern S_417810 D_002C5640[];

s32 func_00417810(S_417810 *out, s32 idx, s32 depth) {
    s32 ok = 0;
    s32 i;

    if (depth < 255) {
        while (D_002C5640[idx].u.f.parent != 0) {
            idx = D_002C5640[idx].u.f.parent;
        }
        for (i = 0; i < depth && D_002C5640[idx].u.f.child != 0; i++) {
            idx = D_002C5640[idx].u.f.child;
        }
        if (D_002C5640[idx].u.f.depth == depth) {
            ok = 1;
            *out = D_002C5640[idx];
        }
    }
    return ok;
}
/* localdecomp:end func_00417810 */
