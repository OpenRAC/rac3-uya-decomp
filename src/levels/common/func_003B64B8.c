#include "common.h"

/* localdecomp:start func_003B64B8 */
typedef int Q_3B64B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B64B8;

typedef struct {
    V4_3B64B8 v0;
    u8 pad10[4];
    f32 f20;
} V_3B64B8;

typedef struct M_3B64B8 {
    u8 pad0[16];
    union {
        Q_3B64B8 q;
        V4_3B64B8 v;
    } pos;
    u8 state;
    u8 pad21[104 - 33];
    V_3B64B8 *vars;
    u8 pad6C[170 - 108];
    s16 h170;
    u8 padAC[184 - 172];
    struct M_3B64B8 *target;
    u8 padBC[192 - 188];
    V4_3B64B8 v192;
    u8 padD0[240 - 208];
    f32 f240;
} M_3B64B8;

extern f32 D_001DFBCC;
extern f32 D_001DFBD0;
extern s32 D_001DFBC0;
extern M_3B64B8 *D_001EAA98[];
extern u8 D_001D66B0;

extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040BF38(void *);
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BE90(void *, void *, f32);
extern void func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_00440978(void);
extern void func_0040CCA0(void *, void *, void *, f32);
extern s32 func_0013D3E0(void);
extern void func_00462FD0(void *, void *, s32, s32, s32, s32, f32);
extern void func_00443628(void *, void *, s32, void *, f32);
extern s32 func_003F8448(void *, void *, s32, void *, void *);
extern s32 func_003F9498(f32, void *, s32, void *);
extern s32 func_0040BA90(void *);
extern s32 func_003FB1D0(void *, s32, void *, void *, f32);
extern void func_00447D00(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern void func_00436220(void *);

void func_003B64B8(M_3B64B8 *m) {
    V_3B64B8 *vars = m->vars;
    V4_3B64B8 np;
    V4_3B64B8 la;
    V4_3B64B8 lb;
    V4_3B64B8 lc;
    f32 len;
    s32 flag;

    if (m->state != 1) {
        return;
    }
    m->f240 = func_0040CEC8(m->f240, 0.1047197655f);
    {
        Q_3B64B8 x, y, d;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(vars->v0));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m->pos.v));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(np) : "j"(d));
    }
    flag = 0.9f < D_001DFBCC || 0.9f < D_001DFBD0;
    if (!flag || !(D_001DFBC0 & 1)) {
        len = func_0040BF38(vars);
        *(Q_3B64B8 *)&lc = 0;
        lc.x = func_004408C0(-1.0f, 1.0f);
        lc.y = func_004408C0(-1.0f, 1.0f);
        lc.z = func_004408C0(-1.0f, 1.0f);
        *(Q_3B64B8 *)&lb = *(Q_3B64B8 *)&lc;
        func_0040C0F0(&lb, &lb, func_004408C0(0.04f, 0.08f) * 0.016666668f);
        func_0040BE90(&la, vars, func_004408C0(0.2f, 0.99f));
        {
            Q_3B64B8 x, y, d;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(la));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(lb));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(lb) : "j"(d));
        }
        func_0040C0F0(&la, vars, func_004408C0(0.0f, 1.0f) * len);
        {
            Q_3B64B8 x, y, d;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(la));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m->pos.v));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(la) : "j"(d));
        }
        func_00466F98(&m->pos, &lb, 7, 127, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.0004f, 0.0f);
        *(Q_3B64B8 *)&lc = 0;
        lc.z = 0.01f;
        func_0040C2D0(&lc, &lc, &m->v192);
        func_0040CCA0(&lc, &lc, &m->v192, func_00440978());
        if (func_0013D3E0() & 1) {
            func_00462FD0(&la, &lc, 0x4F007FFF, 0x1FFFFFFF, 13, 1, 25000.0f);
        }
    }
    func_00443628(&la, m->target, 0x10001, vars, vars->f20);
    *(u16 *)((u8 *)&la + 0x1A) = m->h170;
    {
        Q_3B64B8 x, y, d;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m->pos.v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m->target->pos.v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(la) : "j"(d));
    }
    la.z = 0.0f;
    func_0040C0F0(&la, &la, 1.6666667f);
    la.w = 5627.9248f;
    *((u8 *)&la + 0x18) = 4;
    *(s32 *)&lc |= 1;
    if (func_003F8448(&m->pos, &np, 0, m->target, &la) != 0 ||
        func_003F9498(0.3f, &m->pos, 1, m->target) != 0 ||
        func_0040BA90(&vars->f20 - 1) != 0) {
        if (D_001EAA98[0] != 0) {
            if (D_001EAA98[0] == m->target) {
                goto setpos;
            }
            if (D_001EAA98[0]->h170 != 78) {
                func_003FB1D0(&m->pos, 0, m->target, &la, 0.5f);
            }
            func_00447D00(m, &D_001D66B0, 0, 0.0f, 0.0f, 0, 2, 10, 0.0f, 0.0f, 9.0f, 0.666000009f, -1, 0.0f, 0, 1, -1, 0, 0x01010001);
            func_00436220(m);
            return;
        }
        func_00447D00(m, &D_001D66B0, 0, 0.0f, 0.0f, 0, 2, 8, 0.0f, 0.0f, 9.0f, 0.5f, -1, 0.0f, 0, 1, -1, 0, 0x01010001);
        func_00436220(m);
        return;
    }
setpos:
    m->pos.v = np;
}
/* localdecomp:end func_003B64B8 */
