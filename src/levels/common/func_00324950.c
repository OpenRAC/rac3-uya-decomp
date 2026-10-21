#include "common.h"

/* localdecomp:start func_00324950 */
typedef struct {
    u8 pad0[0x58];
    f32 f58;
} D_324950_t;
typedef struct M_324950 {
    u8 pad0[0x30];
    u8 b30;
    u8 pad31[0x68 - 0x31];
    D_324950_t *data;
    u8 pad6C[256 - 0x6C];
} M_324950;
typedef struct {
    u8 pad0[8];
    M_324950 *head;
    s32 xC;
    u8 pad10[0x1C - 0x10];
    s32 index;
    u8 pad20[0x30 - 0x20];
    s32 x30;
    u8 pad34[0x40 - 0x34];
    s32 x40;
    u8 pad44[0x54 - 0x44];
    s32 x54;
    s32 count;
    s32 x5C;
    u8 pad60[0x74 - 0x60];
    s32 x74;
    u8 pad78[0x84 - 0x78];
    s32 x84;
    s32 x88;
} L_324950;
extern s16 *D_0021DEA0[];
extern M_324950 *D_001E009C;
extern s32 D_001E00D8;
extern M_324950 *D_001DCA50;
extern void func_00324C10(M_324950 *, L_324950 *);
extern void func_00325070(M_324950 *, L_324950 *);
extern void func_00325208(M_324950 *, L_324950 *);
extern void func_00441FB8(M_324950 *, s32, s32);

void func_00324950(M_324950 *a0, L_324950 *l) {
    s16 *p;
    s16 *q;
    s16 *r;
    M_324950 *m;
    D_324950_t *d;
    s32 idx;
    s32 idx2;
    s32 n;
    s32 found;
    f32 f;

    func_00324C10(a0, l);
    D_001DCA50 = a0;
    if (l->x40 != 0) {
        r = D_0021DEA0[l->index];
        l->head = &D_001E009C[*r & 0x7FFF];
    } else {
        l->head = 0;
    }
    l->xC = -1;
    l->x5C = -1;
    l->x84 = -1;
    l->x30 = 0;
    l->x74 = 0;
    l->x54 = 0;
    l->x88 = 0;
    a0->b30 = 255;
    func_00325070(a0, l);
    func_00325208(a0, l);
    if (l->count != 0) {
        found = 0;
        n = 0;
        for (p = D_0021DEA0[l->index];
             (idx = l->index, (u8)idx != 255) && idx <= D_001E00D8 && p != 0 && (p[-1] >= 0 || p == D_0021DEA0[idx]);
             p++) {
            m = &D_001E009C[*p & 0x7FFF];
            if (m == 0) {
                break;
            }
            n++;
            d = m->data;
            if (d->f58 < 0.0f) {
                found = 1;
            }
        }
        if (found) {
            f = 1.0f / (f32)n;
            for (q = D_0021DEA0[l->index];
                 (idx2 = l->index, (u8)idx2 != 255) && idx2 <= D_001E00D8 && q != 0 && (q[-1] >= 0 || q == D_0021DEA0[idx2]);
                 q++) {
                m = &D_001E009C[*q & 0x7FFF];
                if (m == 0) {
                    break;
                }
                d = m->data;
                d->f58 = f;
            }
        }
    }
    func_00441FB8(a0, 1, -1);
}
/* localdecomp:end func_00324950 */
