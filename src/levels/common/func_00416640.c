#include "common.h"
typedef struct {
    u8 b0;
    u8 pad1[70 - 1];
    s16 h46;
    u8 pad48[104 - 72];
    s32 w68;
    u8 pad6C[138 - 108];
    u16 h8A;
    u8 pad8C[240 - 140];
} S_416640;
extern u8 D_001425C0[];
extern S_416640 D_002C5640[];
extern s32 D_00142DE0[];
extern s32 D_001427F0[];
void func_00416640(s32 a0) {
    S_416640 *p = &D_002C5640[D_001425C0[a0]];
    s32 n = p->h46;
    s32 r;
    if (n == 0) {
        return;
    }
    r = p->w68;
    if (r >= 0) {
        r <<= 5;
        if (D_00142DE0[a0] < r) {
            D_00142DE0[a0] = r;
        }
    }
    D_001425C0[a0] = n;
    p = &D_002C5640[D_001425C0[a0]];
    if (p->b0 != 0) {
        D_001427F0[a0] = p->h8A;
    }
}
