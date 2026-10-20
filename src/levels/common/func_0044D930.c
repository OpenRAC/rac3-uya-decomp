#include "common.h"

typedef struct {
    u8 pad0[32];
    u8 state;
} Veldin44D930Obj;

typedef struct {
    u8 pad0[5168];
    Veldin44D930Obj *obj;
    u8 pad1[5808 - 5172];
    s32 mode;
} Veldin1A4BE0;

typedef struct {
    u8 b[16];
} Veldin1D7C30;

extern Veldin1A4BE0 D_001A4BE0;
extern Veldin1D7C30 D_001D7C30;
extern float *func_00440728(Veldin44D930Obj *);
extern s32 func_0044CF68(s32, s32, float, float, float, float, float, void *, s32, s32, s32, s32, Veldin1D7C30 *, s32, s32, s32);
s32 func_0044D930(s32 a0, s32 a1, float f0, float f1, float f2, float f3, float f4, s32 a2) {
    Veldin44D930Obj *obj;
    float *v;
    Veldin1D7C30 tmp;
    u8 buf[16];

    obj = D_001A4BE0.obj;
    if (obj != 0 && obj->state != 254 && obj->state != 253) {
        v = func_00440728(obj);
        if (v != 0 && *v > 0.0f) {
            return (s32)D_001A4BE0.obj;
        }
    }
    tmp = D_001D7C30;
    if (D_001A4BE0.mode == 1) {
        return 0;
    }
    return func_0044CF68(a0, a1, f0, f1, f2, f3, f4, buf, 0, 0, 0, a2, &tmp, 1, -1, 0);
}
