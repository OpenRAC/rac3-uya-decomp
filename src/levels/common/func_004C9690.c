#include "common.h"

extern s32 D_002EF420[];
extern void func_004C8C60();
typedef struct { u8 pad[4]; f32 *v; u8 p2[0x28-8]; void *p28; u8 p3[4]; long l30; s32 w38; s32 w3C; } S_3A6450;
void func_004C9690(S_3A6450 *p) {
    func_004C8C60(p);
    p->p28 = D_002EF420;
    p->l30 = 1;
    p->w38 = 0;
    p->v[0] = 1.0f;
    p->v[1] = 1.0f;
    p->w3C = 1;
}
