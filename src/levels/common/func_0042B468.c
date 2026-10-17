#include "common.h"

typedef struct {
    u8 pad[1128];
    s32 a[5];
    s32 b[6];
    s32 c[1];
} S_42B468;

extern void func_0040BD58(s32, s32, s32);
extern S_42B468 D_001F4020;

void func_0042B468(s32 i, s32 j) {
    func_0040BD58(D_001F4020.a[i], D_001F4020.a[j], D_001F4020.c[j] << 4);
    D_001F4020.b[i] = D_001F4020.b[j];
    D_001F4020.c[i] = D_001F4020.c[j];
    D_001F4020.b[j] = -1;
}
