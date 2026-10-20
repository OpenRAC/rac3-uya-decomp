#include "common.h"

typedef struct {
    s32 a[4];
} Blob_00475D20;

extern s32 D_001E0370;
extern s32 D_001E0388;
extern s32 D_001E0390;
extern s32 D_001E03A8;
extern s32 D_001E03B0;
extern s32 D_001E03C8;
extern s32 D_001E03D0;
extern s32 D_001E03E8;
extern Blob_00475D20 D_001D8090;
/* 0x00475378 lies 8 bytes into the target's func_00475370 symbol. */
extern void func_00475370();
#define CB_00475378 ((void (*)())((u8 *)func_00475370 + 8))
extern void func_00475D00();
extern void func_00475B38();
extern s32 func_00511FE0(void *, void (*)(), void (*)(), void (*)(), s32, s32);

s32 func_00475D20(s32 idx) {
    Blob_00475D20 tmp;

    if (D_001E0388 == 0) {
        func_00511FE0(&D_001E0370, CB_00475378, func_00475D00, func_00475B38, 0, 0);
        D_001E0388 = 1;
    }
    if (D_001E03A8 == 0) {
        func_00511FE0(&D_001E0390, CB_00475378, func_00475D00, func_00475B38, 0, 0);
        D_001E03A8 = 1;
    }
    if (D_001E03C8 == 0) {
        func_00511FE0(&D_001E03B0, CB_00475378, func_00475D00, func_00475B38, 0, 0);
        D_001E03C8 = 1;
    }
    if (D_001E03E8 == 0) {
        func_00511FE0(&D_001E03D0, CB_00475378, func_00475D00, func_00475B38, 0, 0);
        D_001E03E8 = 1;
    }
    tmp = D_001D8090;
    return tmp.a[idx];
}
