#include "common.h"

/* localdecomp:start func_003B7330 */
typedef struct { u8 pad[36]; f32 f36; } C_3B7330;
typedef struct { u8 pad[12]; s32 i12; u8 pad16[156]; s16 h172; } V_3B7330;
typedef struct M_3B7330 {
    u8 pad0[32];
    u8 b32;
    u8 b33;
    u8 pad34[2];
    C_3B7330 *p36;
    u8 pad40[4];
    f32 f44;
    u8 pad48[1];
    u8 b49;
    u8 pad50[2];
    u16 h52;
    u8 pad54[50];
    V_3B7330 *vars;
    u8 pad108[62];
    s16 h170;
    u8 pad172[84];
} M_3B7330;
extern s32 D_001D545C;
extern volatile u8 D_001D5476;
extern s32 D_001F3FC0[];
extern s32 D_001E00D8;
extern M_3B7330 *D_001E009C;
extern s16 *D_0021DEA0[];
extern u8 D_001E2A40[];
extern f32 D_001A4C68[];
extern void func_00442E08(M_3B7330 *, s32);
extern void func_00441C78(M_3B7330 *, s32, s32, s32);
extern void func_00439610(M_3B7330 *);
extern void func_003B72B8(M_3B7330 *, s32, s32);
extern void func_003B7640(M_3B7330 *, s32);
extern s32 func_00453210(void *, s32);
extern void func_00441FB8(M_3B7330 *, s32, s32);
extern void func_003B8370(M_3B7330 *);
extern void func_003B9A98(void);
extern void func_00402498(void *, M_3B7330 *);
void func_003B7330(M_3B7330 *m) {
    V_3B7330 *v;
    s16 *p;
    M_3B7330 *o;
    M_3B7330 *o2;

    v = m->vars;
    if (m->h52 & 2) {
        return;
    }
    if (m->h170 != 7486 && D_001D5476 != 0) {
        func_00442E08(m, 7486);
        m->f44 = m->p36->f36 * 1.5f;
        func_00441C78(m, 5, 0, 0);
        func_00439610(m);
    }
    if (D_001D545C == 9) {
        if (D_001F3FC0[0] != 2) {
            return;
        }
    } else if (D_001F3FC0[0] != 0) {
        return;
    }
    func_003B72B8(m, 9, 1);
    func_003B72B8(m, 22, 0);
    switch (m->b32) {
    case 0:
        func_003B7640(m, m->b33);
        v->h172 = 0;
        break;
    case 1:
        if (v->i12 != -1 && func_00453210(D_001E2A40, v->i12) != 0) {
            for (p = D_0021DEA0[m->b33];
                 m->b33 != 255 && m->b33 <= D_001E00D8 && p != 0 &&
                 (p[-1] >= 0 || p == D_0021DEA0[m->b33]) &&
                 (o = &D_001E009C[*p & 0x7fff]) != 0;
                 p++) {
                o->b49 = 0;
                o->h52 |= 1;
            }
            func_00441FB8(m, 2, -1);
        }
        func_003B8370(m);
        if (D_001D545C == 13 && D_001A4C68[0] > 89.0f) {
            break;
        }
        func_00402498(func_003B9A98, m);
        break;
    case 2:
        if (func_00453210(D_001E2A40, v->i12) == 0) {
            for (p = D_0021DEA0[m->b33];
                 m->b33 != 255 && m->b33 <= D_001E00D8 && p != 0 &&
                 (p[-1] >= 0 || p == D_0021DEA0[m->b33]) &&
                 (o2 = &D_001E009C[*p & 0x7fff]) != 0;
                 p++) {
                o2->b49 = 1;
                o2->h52 &= ~1;
            }
            func_00441FB8(m, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_003B7330 */
