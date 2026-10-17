#include "common.h"

typedef struct { u8 b[16]; } V16_48DCD8;
extern void func_0048DE38(void);
extern void func_0048E238(void);
extern void func_0048E140(void);
extern void func_0048E2B8(void);
extern void func_0048E2D8(void);
extern s32 func_00511FE0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001E0A98;
extern s32 D_001E0AB8;
extern s32 D_001E0AD8;
extern s32 D_001E0AF8;
extern s32 D_001E0A80[2];
extern s32 D_001E0AA0[2];
extern s32 D_001E0AC0[2];
extern s32 D_001E0AE0[2];
extern V16_48DCD8 D_001D8E58[];
s32 func_0048DCD8(s32 idx) {
    V16_48DCD8 v;
    if (D_001E0A98 == 0) {
        func_00511FE0(D_001E0A80, (s32)func_0048DE38, (s32)func_0048E238, (s32)func_0048E140, (s32)func_0048E2B8, (s32)func_0048E2D8);
        D_001E0A98 = 1;
    }
    if (D_001E0AB8 == 0) {
        func_00511FE0(D_001E0AA0, (s32)func_0048DE38, (s32)func_0048E238, (s32)func_0048E140, (s32)func_0048E2B8, (s32)func_0048E2D8);
        D_001E0AB8 = 1;
    }
    if (D_001E0AD8 == 0) {
        func_00511FE0(D_001E0AC0, (s32)func_0048DE38, (s32)func_0048E238, (s32)func_0048E140, (s32)func_0048E2B8, (s32)func_0048E2D8);
        D_001E0AD8 = 1;
    }
    if (D_001E0AF8 == 0) {
        func_00511FE0(D_001E0AE0, (s32)func_0048DE38, (s32)func_0048E238, (s32)func_0048E140, (s32)func_0048E2B8, (s32)func_0048E2D8);
        D_001E0AF8 = 1;
    }
    v = D_001D8E58[0];
    return *(s32 *)(v.b + (idx << 2));
}
