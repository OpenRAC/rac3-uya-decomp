#include "common.h"

/* localdecomp:start func_004CFA08 */
typedef struct { s32 a; s32 b; s32 c; s32 d; } Req_004CFA08;
extern void func_0011F0A0(s32);
extern s32 func_0011F1E0(Req_004CFA08 *, s32);
s32 func_004CFA08(s32 unused, s32 b, s32 a, s32 n) {
    Req_004CFA08 r;
    if (n <= 0) {
        return 0;
    }
    func_0011F0A0(0);
    r.a = a;
    r.b = b;
    r.c = n;
    r.d = 0;
    while (func_0011F1E0(&r, 1) == 0) {
    }
    return n;
}
/* localdecomp:end func_004CFA08 */
