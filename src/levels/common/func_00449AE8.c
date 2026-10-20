#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[4];
    s32 w10;
    u8 pad14[0xF0 - 0x14];
} S_449AE8;

extern u8 D_001425C0[];
extern S_449AE8 D_002C5640[];
extern s16 D_001CCFD4[];
extern s32 D_001A71D8[];
extern s32 D_001A71DC[];
extern s32 D_001A71E0[];
extern s32 D_001A71E4[];
extern s32 func_00429FC8(s32);
extern void func_00429DB0(s32);
extern void func_00503930(s32);

s32 func_00449AE8(s32 id) {
    s32 ret;
    s32 st;
    u8 *ip;
    S_449AE8 *tbl;
    S_449AE8 *e;

    ip = D_001425C0 + id;
    tbl = D_002C5640;
    ret = 0;
    e = tbl + *ip;
    st = e->w8;
    if (st == 0) {
        if (func_00429FC8(e->w10) != 0 || D_001CCFD4[0] == 0) {
            D_001A71D8[0] = id;
            func_00503930(id);
            if (func_00429FC8((tbl + *ip)->w10) == 0) {
                func_00429DB0((tbl + *ip)->w10);
            }
            ret = 1;
        }
    } else if (st == 3) {
        D_001A71E4[0] = id;
        ret = 1;
    } else if (st == 2) {
        D_001A71E0[0] = id;
        ret = 1;
    } else if (st == 1) {
        D_001A71DC[0] = id;
        ret = 1;
    }
    return ret;
}
