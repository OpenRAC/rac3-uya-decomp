#include "common.h"

/* localdecomp:start func_003A2820 */
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
} T_3A2820;
typedef struct {
    u8 pad0[0x3C0];
    s32 i3C0;
    u8 pad3C4[0x68];
    s32 i42C;
} M_3A2820;
typedef struct {
    u8 pad0[0x47];
    u8 b47;
    T_3A2820 *t48;
    u8 pad4C[0x12];
    u8 b5E;
} N_3A2820;
typedef struct {
    u8 pad0[0x68];
    N_3A2820 *m;
    u8 pad6C[0x3E];
    s16 hAA;
} O_3A2820;
extern s32 D_001D545C;
extern s32 D_001D67AC;
extern s32 D_001D67B4;
extern s32 D_001D67C0;
extern u8 D_00142758[];
extern s32 D_001D66B0;
extern s32 func_004344A0();
extern void func_00456960(s32);
extern void func_004A7200(s32, s32, O_3A2820 *);
extern void func_0044F090(O_3A2820 *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern void func_004412D0(O_3A2820 *, s32, s32);

void func_003A2820(O_3A2820 *obj) {
    N_3A2820 *m = obj->m;
    s16 h;

    if (D_001D545C == 4 && m->t48 != 0 && (m->t48->hAA == 0x185E || m->t48->hAA == 0x11C1)) {
        D_00142758[0] = 1;
        func_004344A0();
        if ((D_001D67AC += 1) >= 25) {
            func_00456960(6);
        }
    } else if (D_001D545C == 12 && m->t48 != 0 && m->b47 == 9) {
        if (++D_001D67B4 >= 20) {
            func_00456960(15);
        }
    } else if (D_001D545C == 18 && m->t48 != 0 && (m->t48->hAA == 0x185E || m->t48->hAA == 0x11C1)) {
        if (++D_001D67C0 >= 20) {
            func_00456960(21);
        }
    }
    if (m->b5E == 0) {
        func_004A7200(11, 0, obj);
        h = obj->hAA;
        if (D_001D545C == 1 && ((M_3A2820 *)m)->i42C != 0 && ((M_3A2820 *)m)->i3C0 != 0) {
            obj->hAA = 0x1F02;
        }
        func_0044F090(obj, 0x7FFF, &D_001D66B0, 1, 20, 0.75f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
        if (D_001D545C == 1 && ((M_3A2820 *)m)->i42C != 0 && ((M_3A2820 *)m)->i3C0 != 0) {
            obj->hAA = h;
        }
    }
    func_004412D0(obj, 0, 3);
}
/* localdecomp:end func_003A2820 */
