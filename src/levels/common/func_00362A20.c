#include "common.h"
typedef struct { u8 pad[0x300]; s32 x300; } V_362A20;
typedef struct { u8 pad[0x43]; u8 x43; u8 pad44[0x68 - 0x44]; V_362A20 *x68; } O_362A20;
extern s32 func_00462650(O_362A20 *);
extern void func_00468218(O_362A20 *, f32, f32, f32, f32);
extern void func_00451098(O_362A20 *, s32, s32, s32);
extern s32 func_00468288(O_362A20 *, s32);
extern void func_004513D8(O_362A20 *, s32, s32);
s32 func_00362A20(O_362A20 *a0) {
    V_362A20 *v = a0->x68;
    if (func_00462650(a0)) {
        func_00468218(a0, 0.00166666671f, 0.0333333351f, 0.00698131742f, 0.209439531f);
        if (a0->x43 != 2) {
            func_00451098(a0, 2, 0, 10);
        }
    }
    if (func_00468288(a0, v->x300)) {
        func_004513D8(a0, 3, -1);
        return 1;
    }
    return 0;
}
