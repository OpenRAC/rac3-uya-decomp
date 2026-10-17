#include "common.h"
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    s32 w24;
    u8 b28;
    u8 pad[3];
} S_00674CF0;
extern void func_0058F1B0(void *, void *, s32);
extern void func_0053B738(void *);
extern void func_0066B7F8(s32, s32, s32, s32, s32, s32, s32, void *);
s32 func_00674CF0(s32 a0, s32 a1, s32 a2, void *a3) {
    S_00674CF0 buf;
    func_0058F1B0(&buf, a3, 32);
    if (buf.b28 == 13) {
        func_0053B738(&buf);
    } else {
        func_0066B7F8(buf.w16, buf.w20, buf.b28, 0, buf.w24, buf.w12, 0, &buf);
    }
    return 32;
}
