#include "common.h"

typedef struct {
    u8 p0[0x10];
    f32 f10;
    s32 w14;
    f32 f18;
} V_3BAF88;
typedef struct {
    u8 p0[0x68]; V_3BAF88 *w68; u8 p6C[0x84]; f32 fF0;
} M_3BAF88;
extern f32 D_001DE9EC;
extern f32 D_001DE9F4;
extern f32 D_001DEA04;
extern f32 D_001DEA08;
extern void func_00436220(void);
extern s32 func_003BB0D8(M_3BAF88 *, V_3BAF88 *);
extern f32 func_0040CEC8(f32, f32);
extern void func_003BB130(void);
extern void func_004026A0(void *, M_3BAF88 *);

void func_003BAF88(M_3BAF88 *m) {
    V_3BAF88 *p = m->w68;
    if (p->w14 != 0) {
        p->f10 -= D_001DE9EC;
        if (p->f10 < D_001DE9EC) {
            func_00436220();
            return;
        }
    } else if (p->f10 < 1.0f) {
        p->f10 += D_001DE9EC;
        if (p->f10 > 1.0f) {
            p->f10 = 1.0f;
        }
    }
    if (func_003BB0D8(m, p) != 0) {
        p->f18 += (1.0f - p->f18) * D_001DEA04 + D_001DEA08;
    } else {
        p->f18 -= p->f18 * D_001DEA04 + D_001DEA08;
    }
    if (p->f18 > 1.0f) {
        p->f18 = 1.0f;
    } else if (p->f18 < 0.0f) {
        p->f18 = 0.0f;
    }
    m->fF0 = func_0040CEC8(m->fF0, D_001DE9F4);
    func_004026A0(func_003BB130, m);
}
