#include "common.h"

/* localdecomp:start func_004176F8 */
typedef struct {
    u8 b0;
    u8 pad1[71];
    s16 h72;
    u8 pad2[58];
    u16 h132;
    u8 pad3[4];
    u16 h138;
    u8 pad4[100];
} S_004176F8;
extern u8 D_001425C0[];
extern S_004176F8 D_002C5640[];
extern s32 D_001427F0[];
extern s32 D_00142DE0[];
extern s32 func_00416790(s32, s32);
extern s32 func_00449AE8(s32);
s32 func_004176F8(s32 a0) {
    s32 r = 0;
    S_004176F8 *t;
    if ((D_002C5640 + D_001425C0[a0])->b0 != 0) {
        while ((D_002C5640 + a0)->h72 != 0) {
            a0 = (D_002C5640 + a0)->h72;
        }
        r = func_00416790(a0, 5);
        if (r != 0) {
            t = D_002C5640 + D_001425C0[a0];
            if (t->h132 != 0) {
                D_001427F0[a0] = t->h138;
            }
            func_00449AE8(a0);
            D_00142DE0[a0] = 0;
        }
    }
    return r;
}
/* localdecomp:end func_004176F8 */
