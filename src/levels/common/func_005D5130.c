#include "common.h"

extern s32 func_005D5130(s32);

typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_005D4858(s32);
extern void func_005D5100(void);
/* The level objects' func_005D4E50 symbol starts 8 bytes before this callback. */
extern void func_005D4E50(void);
extern s32 func_0060DD48(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001E0A80;
extern s32 D_001E0AA0;
extern s32 D_001E0AC0;
extern s32 D_001E0AE0;
extern s32 D_001E0A68[2];
extern s32 D_001E0A88[2];
extern s32 D_001E0AA8[2];
extern s32 D_001E0AC8[2];
extern V16_3DF9E0 D_00243758[];
s32 func_005D5130(s32 idx) {
    V16_3DF9E0 v;
    if (D_001E0A80 == 0) {
        func_0060DD48(D_001E0A68, (s32)func_005D4858, (s32)func_005D5100, ((s32)func_005D4E50 + 8), 0, 0);
        D_001E0A80 = 1;
    }
    if (D_001E0AA0 == 0) {
        func_0060DD48(D_001E0A88, (s32)func_005D4858, (s32)func_005D5100, ((s32)func_005D4E50 + 8), 0, 0);
        D_001E0AA0 = 1;
    }
    if (D_001E0AC0 == 0) {
        func_0060DD48(D_001E0AA8, (s32)func_005D4858, (s32)func_005D5100, ((s32)func_005D4E50 + 8), 0, 0);
        D_001E0AC0 = 1;
    }
    if (D_001E0AE0 == 0) {
        func_0060DD48(D_001E0AC8, (s32)func_005D4858, (s32)func_005D5100, ((s32)func_005D4E50 + 8), 0, 0);
        D_001E0AE0 = 1;
    }
    v = D_00243758[0];
    return *(s32 *)(v.b + (idx << 2));
}
