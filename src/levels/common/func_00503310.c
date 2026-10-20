#include "common.h"
typedef struct {
    u8 pad[36];
    s32 w36;
    u8 pad2[200];
} T_00503310;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern T_00503310 D_002C5640[];
extern s32 func_004E5470(s32);
extern void func_004E6CB0(void);
extern s32 func_004FC518(s32, s32);
extern void func_00448B80(void *, f32);
extern void func_0050BB98(s32, s32, f32);
s32 func_00503310(void) {
    u8 *g = D_001A4BE0;
    s32 i;
    s32 id;
    if (g[9705] == 0) {
        return 0;
    }
    if (g[9707] == 0) {
        return 0;
    }
    if (*(s16 *)(g + 10356) != 0) {
        return 0;
    }
    i = func_004E5470(0);
    if (i != *(s32 *)(g + 10292)) {
        func_004E6CB0();
        return 0;
    }
    id = (D_002C5640 + D_001425C0[i])->w36;
    if (func_004FC518(0, 0) != 0) {
    func_00448B80(g + 352, 0.0250000022f);
    if (0.0250000022f < *(f32 *)(g + 436)) {
        *(f32 *)(g + 436) = 0.0250000022f;
    }
    func_0050BB98(id, 0, 11.0f);
    if (*(s32 *)(g + 3704) != 0) {
        *(s32 *)(g + 3716) = 1;
    }
    *(s32 *)(g + 10288) = id;
    return 1;
    }
    return 0;
}
