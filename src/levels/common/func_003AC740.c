#include "common.h"

extern void func_003AC840(void);
extern void func_003AC950(u8 *);
extern s32 func_00452EC8(u8 *);
extern void func_004A72A8(s32, s32, u8 *, s32);
extern s32 func_003ACDE8(u8 *);
extern s32 func_0040BA90(void *);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_00436220(u8 *);

void func_003AC740(u8 *o) {
    u8 *s = *(u8 **)(o + 104);
    u8 *p;
    u8 *q;
    s32 st = o[32];

    if (st != 2) {
        if (st < 3) {
            if (st == 1) {
                func_003AC840();
                func_003AC950(o);
            }
        }
    } else {
        if (func_00452EC8(o) != 0) {
            func_004A72A8(1, 0, o, 6496);
        }
        if (func_003ACDE8(o) != 0) {
            p = *(u8 **)(o + 184);
            if (p != 0 && s[36] == 0) {
                p[188] = 1;
                s[36] = 1;
            }
        }
        if (func_0040BA90(s + 20) != 0) {
            func_00441FB8(o, 3, -1);
            func_00436220(o);
            q = *(u8 **)(o + 184);
            if (q != 0 && s[36] == 0) {
                q[188] = 2;
            }
        }
    }
}
