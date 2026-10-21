#include "common.h"

/* localdecomp:start func_00434AA8 */
typedef struct { u8 b[16]; } V16_434AA8;
typedef struct { u8 a, b; } PR_434AA8;
typedef struct {
    s16 h0;
    u8 p2[6];
    s16 h8;
    u8 pA[14];
    u16 flags;
    s16 h26;
    s16 arr[8];
    s16 h44;
    s16 h46;
} O_434AA8;
typedef struct {
    s32 f0;
    u8 b4, b5, b6, b7;
    s32 f8;
    s32 f12;
    u8 b16;
} R_434AA8;

extern V16_434AA8 D_001D7B48;
extern O_434AA8 *D_002E9A30[];
extern s32 func_00434A28(u8 *p);

s32 func_00434AA8(R_434AA8 *out, s32 *count, s32 max, s32 filter) {
    PR_434AA8 *lists[4];
    s32 i, j;
    *(V16_434AA8 *)lists = D_001D7B48;
    *count = 0;
    for (i = 0; lists[i] != 0; i++) {
        for (j = 0; !func_00434A28((u8 *)&lists[i][j]) && *count < max; j++) {
            u8 a = lists[i][j].a;
            O_434AA8 *p = &D_002E9A30[a - 1][lists[i][j].b];
            s32 skip;
            if (p->flags & 2) continue;
            if (p->h44 == 0) continue;
            if ((p->flags & 1) && p->h44 == 2) continue;
            skip = 1;
            if (filter != -1) {
                if (a == filter) skip = 0;
            } else {
                skip = 0;
            }
            if (skip) continue;
            out[*count].b16 = a - 1;
            out[*count].f0 = p->h8;
            out[*count].b4 = p->h44 == 2;
            out[*count].b6 = *(u8 *)p;
            {
                R_434AA8 *o = &out[*count];
                s32 v;
                if (o->b4 != 0) v = 2260;
                else v = p->arr[p->h46];
                o->f8 = v;
            }
            out[*count].b5 = (p->h0 & 0xFF00) >> 8;
            out[*count].f12 = p->h26;
            (*count)++;
        }
    }
    {
        s32 r = 0;
        if (*count > 0) r = !(max < *count);
        return r;
    }
}
/* localdecomp:end func_00434AA8 */
