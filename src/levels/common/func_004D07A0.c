#include "common.h"

/* localdecomp:start func_004D07A0 */
extern s32 func_004D07A0();
extern s32 D_001DB840;
extern void func_0013CDF0(s32);

extern s32 D_001DB840;
typedef struct { u8 p0[8]; s32 f8; } P_3ABE98;
extern char D_001DB848[];
extern char D_001DB860[];
extern void func_0011F0A0();
extern s32 func_0012BC00();
extern void func_0011AF48();
extern s32 func_0013CD28();
s32 func_004D07A0(P_3ABE98 *p, s32 b, s32 c) {
    s32 r;
    u8 buf[3];
    r = 0;
    if (D_001DB840 != 0) {
        func_0011F0A0(2);
        if (((s32 (*)(s32))func_0013CDF0)(1) == 0) {
            D_001DB840 = 0;
            if (func_0012BC00() == 0) {
                r = (c >> 11) << 11;
                p->f8 = p->f8 + (c >> 11);
            } else {
                func_0011AF48(D_001DB848);
            }
        }
    } else {
        buf[0] = 100;
        buf[1] = 0;
        buf[2] = 0;
        func_0013CDF0(0);
        if (func_0013CD28(p->f8, c >> 11, b, buf) != 0) {
            D_001DB840 = 1;
        } else {
            func_0011AF48(D_001DB860);
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_004D07A0 */
