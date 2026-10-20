#include "common.h"

extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[238];
} S_2C5640;

extern S_2C5640 D_002C5640[];

extern void func_00438938(void *obj, s32 *a, s32 *b, s32 *c);
extern void func_00438908(void *obj, s32 a, s32 b, s32 c);
extern void func_004DE980(void);
extern void func_004DEA00(s32 a, void *obj);

void func_004DEE80(void) {
    s32 v0;
    s32 v1;
    s32 v2;
    s32 c;
    s32 i;

    {
        u8 *base = D_001A4BE0;
        s32 mode = *(s32 *)(base + 9668);
        c = 0;
        if (mode == 130 || mode == 177 || mode == 132) {
            u8 *b2 = D_001A4BE0;
            c = *(s32 *)(b2 + 440) < 30;
        }
    }
    if (c) {
        u8 *base = D_001A4BE0;
        if (*(s32 *)(base + 10272) == 0) {
            long t = *(long *)(*(u8 **)(base + 9664) + 56);
            *(s32 *)(base + 10272) = 1;
            *(long *)(base + 10264) = t;
        }
        func_00438938(*(void **)(base + 9664), &v0, &v1, &v2);
        if (*(s32 *)(base + 440) % 4 < 3) {
            v0 = 0;
            v1 = 0;
            v2 = 0;
        } else {
            v0 = 144;
            v1 = 144;
            v2 = 240;
        }
        {
            u8 *b2 = D_001A4BE0;
            func_00438908(*(void **)(b2 + 9664), v0, v1, v2);
        }
        func_004DE980();
    } else {
        u8 *base = D_001A4BE0;
        if (*(s32 *)(base + 10272) != 0) {
            *(long *)(*(u8 **)(base + 9664) + 56) = *(long *)(base + 10264);
            *(s32 *)(base + 10272) = 0;
        }
    }
    {
        u8 *base = D_001A4BE0;
        i = *(s32 *)(base + 4648);
        if (i >= 0 && ((S_2C5640 *)((u8 *)D_002C5640 + D_001425C0[i] * 240))->b1 != 0) {
            if (*(s32 *)(base + 4608) != 0) {
                func_004DEA00(*(s32 *)(base + 4608), *(void **)(base + 9664));
            }
        }
    }
}
