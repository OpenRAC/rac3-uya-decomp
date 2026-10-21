#include "common.h"

/* localdecomp:start func_003A5210 */
typedef struct {
    u8 p0[0xAA];
    s16 h170;
} T_3A5210;

typedef struct {
    u8 p0[0x47];
    u8 b71;
    T_3A5210 *target;
    u8 p4C[0x12];
    u8 b94;
} V_3A5210;

typedef struct {
    u8 p0[0x68];
    V_3A5210 *pVar;
} M_3A5210;

extern s32 D_001D545C;
extern s32 D_001D67B4;
extern s32 D_001D67C0;
extern u8 D_001D66B0[];
extern void func_00456960(s32 id);
extern void func_0044F090(M_3A5210 *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                          f32 x3, f32 x4, s32 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_004412D0(M_3A5210 *m, s32 a, s32 b);

void func_003A5210(M_3A5210 *m) {
    V_3A5210 *v = m->pVar;

    if (D_001D545C == 12 && v->target != 0 && v->b71 == 9) {
        if (++D_001D67B4 >= 20) {
            func_00456960(15);
        }
    } else if (D_001D545C == 18 && v->target != 0 && v->target->h170 == 6238) {
        if (++D_001D67C0 >= 20) {
            func_00456960(21);
        }
    }
    if (v->b94 == 0) {
        func_0044F090(m, 0x3FFF, D_001D66B0, 2, 20, -1.0f, 3.0f, 6.0f,
                      3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
    }
    func_004412D0(m, 0, 3);
}
/* localdecomp:end func_003A5210 */
