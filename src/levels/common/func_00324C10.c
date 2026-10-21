#include "common.h"

/* localdecomp:start func_00324C10 */
typedef struct M_324C10 M_324C10;
typedef struct {
    s32 key;
    u8 pad4[83 - 4];
    u8 b83;
    u8 pad84[104 - 84];
    M_324C10 *prev;
    M_324C10 *next;
} D_324C10_t;
struct M_324C10 {
    u8 pad0[104];
    D_324C10_t *data;
    u8 pad108[256 - 108];
};
typedef struct {
    s32 i0;
    M_324C10 *head;
    u8 pad8[28 - 8];
    s32 index;
    s32 count;
} L_324C10;
extern s16 *D_0021DEA0[];
extern M_324C10 *D_001E009C;
extern s32 D_001E00D8;
extern u8 func_00324BA8(D_324C10_t *);

void func_00324C10(s32 a0, L_324C10 *l) {
    s16 *p;
    s16 *q;
    void *t;
    M_324C10 *m;
    M_324C10 *cur;
    D_324C10_t *d;
    D_324C10_t *c;
    s32 n;
    s32 idx;

    l->count = 0;
    l->head = 0;
    for (q = D_0021DEA0[l->index];
         (idx = l->index, (u8)idx != 255) && idx <= D_001E00D8 && q != 0 && (q[-1] >= 0 || q == D_0021DEA0[idx]);
         q++) {
        m = &D_001E009C[*q & 0x7FFF];
        if (m == 0) {
            break;
        }
        d = m->data;
        d->b83 = 255;
        d->prev = 0;
        d->next = 0;
        l->count++;
    }
    n = 0;
    cur = 0;
    c = 0;
    for (p = D_0021DEA0[l->index];
         (idx = l->index, (u8)idx != 255) && idx <= D_001E00D8 && p != 0 && (p[-1] >= 0 || p == D_0021DEA0[idx]);
         p++) {
        m = &D_001E009C[*p & 0x7FFF];
        if (m == 0) {
            break;
        }
        d = m->data;
        d->b83 = func_00324BA8(d);
        if (n == 0) {
            cur = m;
            l->head = cur;
            n = 1;
            c = cur->data;
        } else {
            while (d->key < c->key && c->prev != 0) {
                cur = c->prev;
                c = cur->data;
            }
            if (c->prev == 0 && d->key < c->key) {
                c->prev = m;
                d->next = cur;
                l->head = m;
            } else {
                while (c->key < d->key && c->next != 0) {
                    cur = c->next;
                    c = cur->data;
                }
                if (c->next == 0 && c->key < d->key) {
                    c->next = m;
                    d->prev = cur;
                } else if (d->key < c->key) {
                    d->prev = c->prev;
                    d->next = cur;
                    if (c->prev != 0) {
                        c->prev->data->next = m;
                    }
                    c->prev = m;
                } else {
                    d->prev = cur;
                    d->next = c->next;
                    if (c->next != 0) {
                        t = c->prev;
                        t = ((M_324C10 *)t)->data;
                        ((D_324C10_t *)t)->prev = m;
                    }
                    c->next = m;
                }
            }
            n++;
        }
    }
}
/* localdecomp:end func_00324C10 */
