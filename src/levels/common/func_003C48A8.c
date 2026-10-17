#include "common.h"
typedef struct M3C48A8 M3C48A8;
typedef struct {
    u8 pad0[80];
    s32 link;
    u8 pad84[1360 - 84];
    M3C48A8 *child;
} V3C48A8;
struct M3C48A8 {
    u8 pad0[32];
    u8 state;
    u8 pad21[52 - 33];
    u16 flags;
    u8 pad36[104 - 54];
    V3C48A8 *vars;
    u8 pad6C[152 - 108];
    s32 f98;
    u8 pad9C[256 - 156];
};
typedef struct {
    u8 pad0[258];
    u8 active;
    u8 pad103[264 - 259];
    s32 group;
} O3C48A8;
extern s16 *D_0021DEA0[];
extern M3C48A8 *D_001E009C;
extern s32 D_001E00D8;
extern void func_004A6DF8(M3C48A8 *m, s32 a1);
void func_003C48A8(void *a0, O3C48A8 *obj) {
    s16 *p;
    M3C48A8 *m;
    M3C48A8 *o;
    M3C48A8 *c;
    s32 g;

    p = D_0021DEA0[obj->group];
    while (g = obj->group, (g & 0xFF) != 255 && g <= D_001E00D8 && p != 0 &&
             (p[-1] >= 0 || p == D_0021DEA0[g])) {
        m = &D_001E009C[*p & 0x7FFF];
        if (m == 0) {
            break;
        }
        if (m->state == 254) {
            goto next;
        }
        if (m->state == 253) {
            goto next;
        }
        if (m->flags & 2) {
            goto next;
        }
        if (m->vars->link == -1) {
            goto next;
        }
        o = &D_001E009C[m->vars->link];
        c = o->vars->child;
        m->flags |= 2;
        o->f98 = 0;
        o->flags = (o->flags | 0x43) & ~0x1000;
        func_004A6DF8(o, 1);
        if (c != 0) {
            c->f98 = 0;
            c->flags = (c->flags | 0x41) & ~0x1000;
            func_004A6DF8(c, 1);
        }
next:
        p++;
    }
    obj->active = 0;
}
