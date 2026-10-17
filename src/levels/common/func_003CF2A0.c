#include "common.h"

typedef void (*Fn_003CF2A0)(u8 *);

extern u8 D_001A30B0[];
extern void func_00445660(s32);
extern void func_004B6500(s32);
extern Fn_003CF2A0 *func_004478A8(s32, s32);

void func_003CF2A0(u8 *self) {
    u8 *v = *(u8 **)(self + 104);
    s32 idx;
    u8 *e;

    if (*(s32 *)(v + 156) != 0) {
        func_00445660(*(s32 *)(v + 156));
        *(s32 *)(v + 156) = 0;
    }
    if (*(s32 *)(v + 160) != 0) {
        func_00445660(*(s32 *)(v + 160));
        *(s32 *)(v + 160) = 0;
    }
    idx = *(s32 *)(v + 164);
    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 220) == self && e[208] != 0) {
            func_004B6500(idx);
        }
    }
    *(s32 *)(v + 164) = -1;
    (*func_004478A8(6625, 108))(self);
}
