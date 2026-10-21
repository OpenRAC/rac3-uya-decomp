#include "common.h"

/* localdecomp:start func_00352978 */
typedef struct {
    u8 p0[0xAA];
    s16 h170;
} T_352978;

typedef struct {
    u8 p0[0x47];
    u8 b71;
    T_352978 *target;
    u8 p4C[0x430];
    s32 w1148;
} V_352978;

typedef struct {
    u8 p0[0x68];
    V_352978 *pVar;
} M_352978;

extern s32 D_001D545C;
extern s32 D_001D67AC;
extern s32 D_001D67B4;
extern s32 D_001D67C0;
extern void func_00456960(s32 id);
extern void func_004412D0(M_352978 *m, s32 a, s32 b);

void func_00352978(M_352978 *m) {
    V_352978 *v = m->pVar;

    if (v->w1148 == 0) {
        func_004412D0(m, 0, 3);
    }
    if (D_001D545C == 4 && v->target != 0 &&
        (v->target->h170 == 6238 || v->target->h170 == 4545)) {
        if (++D_001D67AC >= 25) {
            func_00456960(6);
        }
    } else if (D_001D545C == 12 && v->target != 0 && v->b71 == 9) {
        if (++D_001D67B4 >= 20) {
            func_00456960(15);
        }
    } else if (D_001D545C == 18 && v->target != 0 &&
               (v->target->h170 == 6238 || v->target->h170 == 4545)) {
        if (++D_001D67C0 >= 20) {
            func_00456960(21);
        }
    }
}
/* localdecomp:end func_00352978 */
