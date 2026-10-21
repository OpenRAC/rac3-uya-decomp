#include "common.h"

/* localdecomp:start func_004CF890 */
extern s32 func_004CFA08();
s32 func_004CF890(void *ctx, s32 p, s32 a, s32 q, s32 d, s32 r, s32 b, s32 s, s32 c) {
    s32 over;
    s32 len;
    if (a + d < b + c) {
        over = b + c - (a + d);
        if (c <= over) {
            b -= over - c;
            c = 0;
        } else {
            c -= over;
        }
    }
    if (a <= b) {
        func_004CFA08(ctx, p, r, a);
        func_004CFA08(ctx, q, r + a, b - a);
        func_004CFA08(ctx, q + b - a, s, c);
    } else if ((len = a - b) <= c) {
        func_004CFA08(ctx, p, r, b);
        func_004CFA08(ctx, p + b, s, len);
        func_004CFA08(ctx, q, s + a - b, c - len);
    } else {
        func_004CFA08(ctx, p, r, b);
        func_004CFA08(ctx, p + b, s, c);
    }
    return b + c;
}
/* localdecomp:end func_004CF890 */
