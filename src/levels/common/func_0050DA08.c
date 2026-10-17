#include "common.h"

typedef struct {
    u8 pad0[0x8A];
    u16 h8A;
    u8 pad8C[0xF0 - 0x8C];
} S_50DA08;

typedef struct {
    u8 arr[0x40];
} S_50DA08a;

typedef struct {
    s32 arr[0x40];
} S_50DA08b;

extern s32 D_001A5E08[];
extern S_50DA08a D_001425C0;
extern S_50DA08 D_002C5640[];
extern S_50DA08b D_001427F0;

s32 func_0050DA08(s32 i) {
    if (i == -1) {
        i = D_001A5E08[0];
    }
    if ((D_001425C0.arr[i] + D_002C5640)->h8A == 0) {
        return 1;
    }
    return D_001427F0.arr[i];
}
