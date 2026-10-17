#include "common.h"

extern s32 func_0051DC38();
extern void func_005197F0();
extern s32 *func_00511BF8();
extern s32 func_005121D8();
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
extern u8 D_001DC198[8];

typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
extern u8 D_001DC198[8];
extern u8 D_001DC100_003E8AD0[8];
extern S_3E8AD0 D_001E1660_003E8AD0[];
extern s32 *func_00511BF8();
extern s32 **func_00511CE8_003E8AD0();
extern s32 func_005121D8();
extern void func_005197F0();
void func_00519950(T_3E8AD0 *p, s32 flags) {
    O_3E8AD0 *a, *b;
    s32 *q;
    s32 **t;
    s32 **w;
    p->f8 = &D_001DC198;
    func_005197F0(p);
    a = p->x2C;
    if (a->x44 != 0) func_005121D8(a->x44);
    a->x44 = 0;
    b = p->x2C;
    if (b->x44 != 0) func_005121D8(b->x44);
    b->x44 = 0;
    if (b->arr != 0) {
        w = b->arr + 16;
        if (b->arr != w) {
            do {
                w--;
                if (*w) func_005121D8(*w);
                *w = 0;
            } while (b->arr != w);
        }
    }
    if (D_001E1660_003E8AD0->f4 != 0) {
        q = (s32 *)D_001E1660_003E8AD0;
    } else {
        q = func_00511BF8(D_001E1660_003E8AD0);
    }
    t = func_00511CE8_003E8AD0(q, 1);
    if (t != 0) {
        ((VT_3E8AD0 *)*t)->fC(t, p->x2C);
        p->x2C = 0;
    }
    p->f8 = &D_001DC100_003E8AD0;
    if (flags & 1) func_0051DC38(p);
}
