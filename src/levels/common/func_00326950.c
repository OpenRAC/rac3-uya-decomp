#include "common.h"

typedef struct {
    s32 f0;
    u8 pad4[8];
    s32 f12;
    u8 pad10[4];
    s32 f20;
    u8 pad18[16];
    s32 f40;
    s32 f44;
    u8 pad30[8];
} E00326950;

typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[68 - 12];
    s32 f68;
    u8 pad48[83 - 72];
    u8 b83;
} V00326950;

typedef struct {
    u8 pad0[40];
    s32 f40;
} W00326950;

typedef struct O00326950 {
    u8 pad0[104];
    void *p104;
} O00326950;

extern E00326950 D_002AEA90[];
extern u8 D_001426E0[];
typedef struct { u8 pad0[48]; u8 a[64]; u8 b[16]; } R00326950;
extern R00326950 *D_001E0180;
extern O00326950 *func_003252E8(O00326950 *);
extern void func_00438430(s32);
extern void func_00329048(O00326950 *, W00326950 *, s32);
extern s32 func_004344A0(void);
extern void func_0049FDB0(u8 *, u8 *);

void func_00326950(O00326950 *a) {
    V00326950 *v = a->p104;
    O00326950 *o = func_003252E8(a);
    W00326950 *w = o->p104;
    E00326950 *e;
    u8 *q;
    s32 i;
    s32 k;

    if (v->f68 != 0) {
        return;
    }
    if (v->f8 != -1) {
        func_00438430(v->f8);
    }
    if (v->b83 == 255) {
        return;
    }
    e = &D_002AEA90[v->b83];
    if (e->f12 == 0) {
        return;
    }
    q = &D_001426E0[e->f12];
    if ((u8)++*q > 100) {
        *q = 100;
    }
    if (D_001426E0[e->f12] == 1) {
        switch (e->f40) {
        case 1:
            D_001426E0[113] = 255;
            D_001426E0[114] = 255;
            break;
        case 2:
            func_00329048(o, w, e->f44);
            break;
        }
    }
    if (e->f20 != 0) {
        D_001426E0[e->f20] = 1;
    }
    i = 0;
    if (D_002AEA90[0].f0 >= 0) {
        do {
            k = D_002AEA90[i].f12;
            if (k != 0 && k != 47 && k != 192) {
                if (D_001426E0[k] == 0) {
                    break;
                }
            }
            i++;
        } while (D_002AEA90[i].f0 >= 0);
    }
    if (D_002AEA90[i].f0 == -1) {
        D_001426E0[189] = 1;
        func_004344A0();
    }
    func_004344A0();
    func_0049FDB0(&D_001E0180[w->f40].a[0], &D_001E0180[w->f40].b[0]);
}
