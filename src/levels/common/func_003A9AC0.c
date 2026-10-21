#include "common.h"

/* localdecomp:start func_003A9AC0 */
typedef struct {
    u8 pad[0x30];
    u8 b30;
    u8 pad2[3];
    u16 h34;
    u8 pad3[0x98 - 0x36];
    int x98;
} S_3A9AC0m;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x10];
} S_3A9AC0a;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x28];
} S_3A9AC0b;
typedef struct {
    u8 pad[0x24];
    int n;
    S_3A9AC0b *p;
    u8 pad2[4];
} S_3A9AC0c;
typedef struct {
    u8 pad[8];
    int n8;
    S_3A9AC0a *pC;
    u8 pad2[0x34 - 0x10];
    int n34;
    S_3A9AC0c *p38;
} S_3A9AC0d;
typedef struct {
    u8 pad[0xD0];
    u8 bD0;
    u8 pad2[0xDC - 0xD1];
    S_3A9AC0m *mDC;
} S_3A9AC0e;
typedef struct {
    u8 pad[0x64];
    S_3A9AC0m *m;
    S_3A9AC0d *d;
    u8 pad2[0xBA0 - 0x6C];
    u8 xBA0[0xC48 - 0xBA0];
    int xC48;
    u8 pad3[0xD1C - 0xC4C];
    int xD1C;
} S_3A9AC0o;

extern u8 D_001A30B0[];
extern void func_004A6E88(int);
extern void func_0044B7F0(S_3A9AC0m *, void *);
extern void func_004A6DF8(S_3A9AC0m *, int);
extern void func_00441FB8(S_3A9AC0m *, int, int);

void func_003A9AC0(int unused, S_3A9AC0o *o, int flag) {
    S_3A9AC0d *d = o->d;
    S_3A9AC0a *a;
    S_3A9AC0b *b;
    S_3A9AC0c *c;
    int i, j;
    int k = o->xD1C;

    if (k != -1) {
        S_3A9AC0e *e = (S_3A9AC0e *)(D_001A30B0 + k * 128);
        if (e->mDC == o->m && e->bD0 != 0) {
            func_004A6E88(k);
        }
    }
    o->xD1C = -1;
    func_0044B7F0(o->m, o->xBA0);
    if (d->n8 != 0) {
        a = d->pC;
        for (i = 0; i < d->n8; i++) {
            func_0044B7F0(o->m, (u8 *)o + (a->x4 * 128 + 160));
            a++;
        }
    }
    if (d->n34 != 0) {
        c = d->p38;
        for (j = 0; j < d->n34; j++) {
            if (c->n != 0) {
                b = c->p;
                for (i = 0; i < c->n; i++) {
                    func_0044B7F0(o->m, (u8 *)o + (b->x4 * 128 + 160));
                    b++;
                }
            }
            c++;
        }
    }
    o->m->h34 |= 0x41;
    o->m->h34 &= 0xEFFF;
    o->m->x98 = 0;
    func_004A6DF8(o->m, 1);
    if (flag) {
        func_00441FB8(o->m, 1, -1);
        o->m->h34 |= 2;
    } else {
        o->m->b30 = 255;
        func_00441FB8(o->m, 3, -1);
    }
    o->d = 0;
    o->m = 0;
    o->xC48 = 0;
}
/* localdecomp:end func_003A9AC0 */
