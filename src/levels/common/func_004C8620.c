#include "common.h"

typedef struct K_3A54A0 { struct K_3A54A0 *next; u8 p4[4]; f32 t; f32 v[4]; } K_3A54A0;
typedef struct { u8 p0[0xC]; K_3A54A0 *k; u32 n; s32 mode; } H_3A54A0;
typedef struct { u8 p0[8]; H_3A54A0 *h; } O_3A54A0;
void func_004C8620(O_3A54A0 *o, f32 *out, f32 t) {
    H_3A54A0 *h = o->h;
    u32 n = h->n;
    K_3A54A0 *cur; K_3A54A0 *prev; K_3A54A0 *nx;
    u32 i; f32 r; f32 inv;
    if (n == 0) return;
    if (n == 1) {
        out[0] = o->h->k->v[0];
        out[1] = o->h->k->v[1];
        out[2] = o->h->k->v[2];
        out[3] = o->h->k->v[3];
        return;
    }
    prev = cur = h->k;
    i = 0;
    if (i < n && (nx = cur->next) != 0 && cur->t <= t) {
    loop:
        cur = nx;
        i++;
        do {
            if (i < n && (nx = cur->next) != 0 && cur->t <= t) {
                prev = cur;
                goto loop;
            }
        } while (0);
    }
    r = (t - prev->t) / (cur->t - prev->t);
    switch (o->h->mode) {
    case 0:
    case 1:
        inv = 1.0f - r;
        out[0] = inv * prev->v[0] + r * cur->v[0];
        out[1] = inv * prev->v[1] + r * cur->v[1];
        out[2] = inv * prev->v[2] + r * cur->v[2];
        out[3] = inv * prev->v[3] + r * cur->v[3];
        break;
    case 2:
        break;
    }
}
