#include "common.h"
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 f10[16];
} Src_0034C508;
typedef struct {
    u8 pad0[24];
    Src_0034C508 *src;
    u8 pad1C[20];
} Ent_0034C508;
extern Ent_0034C508 D_0027F600[];
extern void func_0044DF40(void *, f32 *, s32);
extern void func_0040BE90(f32 *, f32 *, f32);
extern void func_0034CC80(s32);
void func_0034C508(s32 a) {
    f32 v[4];
    Ent_0034C508 *p;
    s32 i;
    f32 k1;
    f32 k2;
    p = D_0027F600;
    k1 = 0.000976499985f;
    k2 = 0.850000024f;
    for (i = 0; i < 30; i++, p++) {
        if (p->src != 0) {
            func_0044DF40(p->src->f10, v, 1);
            func_0040BE90(v, v, p->src->fC * k1 * k2);
            v[0] += p->src->f0 * k1;
            v[1] += p->src->f4 * k1;
            v[2] += p->src->f8 * k1;
        }
    }
    func_0034CC80(a);
}
