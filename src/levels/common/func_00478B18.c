#include "common.h"

extern s32 func_00478B18(s32);
extern void func_00478A28();

typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_00478390(s32);
extern void func_00478AF8(void);
extern void func_00478A28(void);
extern s32 func_00511FE0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001E0518;
extern s32 D_001E0538;
extern s32 D_001E0558;
extern s32 D_001E0578;
extern s32 D_001E0500[2];
extern s32 D_001E0520[2];
extern s32 D_001E0540[2];
extern s32 D_001E0560[2];
extern V16_3DF9E0 D_001D8178[];
s32 func_00478B18(s32 idx) {
    V16_3DF9E0 v;
    if (D_001E0518 == 0) {
        func_00511FE0(D_001E0500, (s32)func_00478390, (s32)func_00478AF8, (s32)func_00478A28, 0, 0);
        D_001E0518 = 1;
    }
    if (D_001E0538 == 0) {
        func_00511FE0(D_001E0520, (s32)func_00478390, (s32)func_00478AF8, (s32)func_00478A28, 0, 0);
        D_001E0538 = 1;
    }
    if (D_001E0558 == 0) {
        func_00511FE0(D_001E0540, (s32)func_00478390, (s32)func_00478AF8, (s32)func_00478A28, 0, 0);
        D_001E0558 = 1;
    }
    if (D_001E0578 == 0) {
        func_00511FE0(D_001E0560, (s32)func_00478390, (s32)func_00478AF8, (s32)func_00478A28, 0, 0);
        D_001E0578 = 1;
    }
    v = D_001D8178[0];
    return *(s32 *)(v.b + (idx << 2));
}
