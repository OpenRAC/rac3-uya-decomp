#include "common.h"

typedef int Q_37BB28 __attribute__((mode(TI)));

typedef struct {
    char pad0[16];
    Q_37BB28 v16;
} Tgt_37BB28;

typedef struct {
    float m0[4];
    float m1[4];
    Q_37BB28 q32;
    Q_37BB28 v48;
    char pad64[16];
    float a[3];
    float b[3];
    float c[3];
    float d[3];
    float e[3];
    float g[3];
    char sub[8];
    void *owner;
    Tgt_37BB28 *tgt;
    char pad168[8];
} Ent_37BB28;

typedef struct {
    char pad0[80];
    int count;
    char pad84[60];
    Ent_37BB28 ent[12];
} Cont_37BB28;

typedef struct {
    char pad0[16];
    float pos[4];
    char pad32[72];
    Cont_37BB28 *cont;
} Obj_37BB28;

typedef struct {
    char pad0[128];
    Q_37BB28 v;
    char pad144[9520];
    Tgt_37BB28 *tgt;
} Glob_37BB28;

typedef struct {
    char pad0[16];
    float scale;
} Fac_37BB28;

extern int D_001EEB00[];
extern Glob_37BB28 D_001A4BE0;
extern void func_00437698(Obj_37BB28 *, int, Q_37BB28 *);
extern int func_003FB1D0(float *, int, Obj_37BB28 *, int, float);
extern void func_0037B870(Obj_37BB28 *, int, int);
extern float func_0040CEC8(float, float);
extern float func_0040C3C8(float);
extern float func_0040C3E0(float);
extern void func_004C41E8(float *, float *);
extern void func_0040BE90(float *, float *, float);
extern Fac_37BB28 *func_00440728(Tgt_37BB28 *);
extern int func_0040BA90(void *);

/* localdecomp:start func_0037BB28 */
void func_0037BB28(Obj_37BB28 *obj) {
    Cont_37BB28 *cont = obj->cont;
    Q_37BB28 vq;
    Q_37BB28 q;
    int n;
    int i;
    int j;
    Ent_37BB28 *e;
    Fac_37BB28 *f;

    func_00437698(obj, 0, &q);
    n = func_003FB1D0(obj->pos, 1, obj, 0, 6.0f);
    for (j = 0; j < n; j++) {
        func_0037B870(obj, D_001EEB00[j], 3000);
    }
    for (i = 0; i < 12; i++) {
        if (cont->ent[i].owner != obj) {
            continue;
        }
        if (cont->ent[i].tgt == 0) {
            continue;
        }
        e = &cont->ent[i];
        e->a[0] = func_0040CEC8(e->a[0], e->b[0]);
        e->a[1] = func_0040CEC8(e->a[1], e->b[1]);
        e->a[2] = func_0040CEC8(e->a[2], e->b[2]);
        e->d[0] = func_0040CEC8(e->d[0], e->e[0]);
        e->d[1] = func_0040CEC8(e->d[1], e->e[1]);
        e->d[2] = func_0040CEC8(e->d[2], e->e[2]);
        e->m0[0] = func_0040C3C8(e->a[0]) * e->c[0];
        e->m0[1] = func_0040C3E0(e->a[1]) * e->c[1];
        e->m0[2] = -func_0040C3E0(e->a[2]) * e->c[2];
        e->m1[0] = func_0040C3C8(e->d[0]) * e->g[0];
        e->m1[1] = func_0040C3E0(e->d[1]) * e->g[1];
        e->m1[2] = -func_0040C3E0(e->d[2]) * e->g[2];
        e->q32 = q;
        if (cont->ent[i].tgt == D_001A4BE0.tgt) {
            func_004C41E8(obj->pos, (float *)&vq);
            func_0040BE90((float *)&vq, (float *)&vq, 0.8f);
            __asm__ __volatile__(
                "lqc2 vf1, %0\n"
                "lqc2 vf2, %1\n"
                : : "m"(D_001A4BE0.v), "m"(vq));
        } else {
            f = func_00440728(cont->ent[i].tgt);
            if (f == 0) {
                goto skip;
            }
            func_004C41E8(obj->pos, (float *)&vq);
            func_0040BE90((float *)&vq, (float *)&vq, f->scale);
            __asm__ __volatile__(
                "lqc2 vf2, %0\n"
                "lqc2 vf1, %1\n"
                : : "m"(vq), "m"(cont->ent[i].tgt->v16));
        }
        __asm__ __volatile__(
            "vadd.xyz vf1, vf1, vf2\n"
            "sqc2 vf1, %0\n"
            : "=m"(e->v48));
    skip:
        if (func_0040BA90(e->sub) != 0) {
            e->owner = 0;
            e->tgt = 0;
            cont->count--;
        }
    }
}
/* localdecomp:end func_0037BB28 */
