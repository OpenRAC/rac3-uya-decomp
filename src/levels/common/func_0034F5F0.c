#include "common.h"

/* localdecomp:start func_0034F5F0 */
typedef struct {
    u8 pad0[16];
    u32 w16;
    u8 pad1[68 - 20];
    u16 h68;
} R_34F5F0;

typedef struct {
    u8 pad0[16];
    f32 pos[4];
    u8 pad1[35 - 32];
    u8 b35;
    R_34F5F0 *r36;
    u8 pad2[49 - 40];
    u8 b49;
    u8 pad3[52 - 50];
    u16 h52;
    u8 pad4[152 - 54];
    u32 w152;
    u8 pad5[192 - 156];
    f32 v192[4];
    f32 v208[4];
    u8 pad6[240 - 224];
    f32 v240[4];
} O_34F5F0;

typedef struct {
    f32 f0;
    s32 w4;
    O_34F5F0 *obj;
    u8 b12;
    u8 b13;
    s8 c14;
    u8 b15;
} V_34F5F0;

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad1[104 - 33];
    V_34F5F0 *vars;
} M_34F5F0;

typedef struct { u8 b[16]; } A0_34F5F0;
typedef struct { u8 b[8]; } A1_34F5F0;
typedef struct { u8 b[16]; } A3_34F5F0;
typedef int Q_34F5F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_34F5F0;

extern A0_34F5F0 D_001DD490[];
extern A1_34F5F0 D_001DD4A0[];
extern A1_34F5F0 D_001DD4A8[];
extern A3_34F5F0 D_001DD4B0[];

extern s32 func_00440848(s32);
extern s32 func_004A7200(s32, s32, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00440A88(void *, f32, f32);
extern f32 func_004408C0(f32, f32);
extern s32 func_0040D020(s32, s32, f32);
extern void *func_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_00441FB8(void *, s32, s32);
extern void func_0044B598(void *, s32);
extern void func_0040C638(void *, void *);
extern f32 func_004450C0(f32 *, f32, f32);
extern void func_00436220(void *);

void func_0034F5F0(M_34F5F0 *m) {
    V_34F5F0 *vars = m->vars;
    s32 a0[4];
    f32 a1[2];
    f32 a2[2];
    f32 a3[4];
    V4_34F5F0 pos;
    V4_34F5F0 vel;
    s32 i;
    s32 k;
    s32 col;
    f32 s;

    switch (m->state) {
    case 0:
        func_004A7200(func_00440848(2), 0, m);
        vars->obj->h52 &= 0xFFBE;
        vars->obj->h52 |= vars->obj->r36->h68 & 0x1000;
        vars->obj->w152 = vars->obj->r36->w16;
        vars->obj->h52 |= 0x100;
        func_0040C0F0(vars->obj->v192, vars->obj->v192, 0.1f);
        func_0040C0F0(vars->obj->v208, vars->obj->v208, 0.1f);
        *(A0_34F5F0 *)a0 = D_001DD490[0];
        *(A1_34F5F0 *)a1 = D_001DD4A0[0];
        *(A1_34F5F0 *)a2 = D_001DD4A8[0];
        *(A3_34F5F0 *)a3 = D_001DD4B0[0];
        if (vars->b13) {
            vars->f0 = 1.0f;
        } else {
            vars->f0 = 0.0f;
        }
        if (vars->b12 == 0) {
            for (i = 0; i < 30; i++) {
                k = i & 1;
                func_00440A88(&pos, 0.0f, a2[k] * (f32)vars->c14);
                {
                    Q_34F5F0 qa, qb, qr;
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
                    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(V4_34F5F0 *)vars->obj->pos));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                    __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qr));
                }
                pos.z += func_004408C0(0.0f, (f32)vars->c14 + (f32)vars->c14);
                col = func_0040D020(a0[k * 2], a0[k * 2 + 1], func_004408C0(0.0f, 1.0f));
                s = a1[k] * (f32)vars->c14;
                __asm__("sq $0,%0" : "=m"(vel));
                vel.z = func_004408C0(a3[k * 2], a3[k * 2 + 1]) * (f32)vars->c14 * (1.0f / 60.0f);
                func_00468DC0(&pos, &vel, col, s, 60, (u8)func_00440848(255), 0, vars->b15, 0);
            }
        }
        func_00441FB8(m, 1, -1);
        break;
    case 1:
        vars->obj->b35 = vars->f0 * 127.0f;
        func_0044B598(vars->obj, func_0040D020(0xF0FF2000, vars->w4, vars->f0));
        func_0040C638(vars->obj->v192, vars->obj->v240);
        func_0040C0F0(vars->obj->v192, vars->obj->v192, vars->f0);
        func_0040C0F0(vars->obj->v208, vars->obj->v208, vars->f0);
        if (vars->b13 == 0) {
            func_004450C0(&vars->f0, 1.0f, 1.0f / 30.0f);
            if (vars->f0 == 1.0f) {
                vars->obj->h52 &= 0xFEFF;
                vars->obj->h52 &= 0xFFFD;
                func_0044B598(vars->obj, vars->w4);
                func_00436220(m);
            }
        } else {
            func_004450C0(&vars->f0, 0.0f, 1.0f / 12.0f);
            if (vars->f0 == 0.0f) {
                vars->obj->h52 &= 0xFEFF;
                vars->obj->h52 &= 0xFFFD;
                func_0044B598(vars->obj, vars->w4);
                vars->obj->h52 |= 1;
                vars->obj->b49 = 0;
                func_00436220(m);
            }
        }
        break;
    }
}
/* localdecomp:end func_0034F5F0 */
