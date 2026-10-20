#include "common.h"

typedef struct {
    s32 a[38];
} T_44C9C8;

extern T_44C9C8 D_002BC290;
extern void func_0044ECE0(s32 a, s32 b, s32 c);
extern void func_0044F2E8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);

void func_0044C9C8(s32 i, u8 flag) {
    T_44C9C8 t = D_002BC290;

    if (flag) {
        func_0044ECE0(t.a[i], -1, 0);
    } else if (t.a[i] != 0) {
        func_0044F2E8(0, 15, t.a[i], 180, 0, 0, 0);
    }
}
