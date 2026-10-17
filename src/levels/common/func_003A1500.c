#include "common.h"
typedef struct { u8 pad[0x30]; u8 x30[0x20]; s32 x50; u8 pad54[0x6C - 0x54]; f32 x6C; u8 pad70[8]; f32 x78; } V_3A1500;
typedef struct { u8 pad[0x68]; V_3A1500 *x68; u8 pad6C[0xF0 - 0x6C]; f32 xF0; } O_3A1500;
extern s32 D_001DE984;
extern s32 D_001DE988;
extern f32 D_001DEA50;
extern u8 D_001D66B0[];
extern u8 D_001E1220[];
extern s32 func_00423180(O_3A1500 *);
extern s32 func_00412A30(s32, s32);
extern void func_0034C308(O_3A1500 *, void *, void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern f32 func_003E0930(f32, f32);
extern int func_003DF4F8(void *);
extern void func_003A1210(O_3A1500 *, s32);
void func_003A1500(O_3A1500 *a0) {
    V_3A1500 *v = a0->x68;
    if (func_00423180(a0)) {
        v->x50 = func_00412A30(D_001DE988, D_001DE984);
    }
    func_0034C308(a0, v->x30, v, D_001D66B0, 1, 0, 0, 1, v->x6C, 0.0f, v->x78, v->x78, 0.0f, 0.0f);
    a0->xF0 = func_003E0930(a0->xF0, D_001DEA50);
    if (D_001E1220[0] != 0 || func_003DF4F8(&v->x50)) {
        func_003A1210(a0, 66);
    }
}
