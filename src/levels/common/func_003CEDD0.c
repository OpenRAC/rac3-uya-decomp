#include "common.h"

/* localdecomp:start func_003CEDD0 */
typedef struct {
    u8 pad0[44];
    s32 w2C;
    u8 pad1[64 - 48];
    s32 w40;
} Obj3CEDD0;

typedef struct {
    u8 pad0[32];
    u8 b20;
    u8 pad1[170 - 33];
    s16 hAA;
} Moby3CEDD0;

typedef struct {
    void (*f0)(Moby3CEDD0 *);
    s32 pad;
    s32 (*f8)(Moby3CEDD0 *);
} Vt3CEDD0;

extern u8 *D_001E009C;
extern s32 D_001E00D8;
extern u16 *D_0021DEA0[];
extern Vt3CEDD0 *func_00438488(s32, s32, s32);
s32 func_003CEDD0(s32 a0, Obj3CEDD0 *obj) {
    u8 *m;
    u8 *p;
    u16 *list;
    Moby3CEDD0 *e;
    Vt3CEDD0 *h;

    if (obj->w40 != -1) {
        m = D_001E009C + (obj->w40 << 8);
        if (*(u16 *)(m + 52) & 2) {
            return 0;
        }
        p = *(u8 **)(*(u8 **)(m + 104) + 284);
        if (p == 0) {
            return 0;
        }
        obj->w2C = p[33];
    }
    for (list = D_0021DEA0[obj->w2C];
         (obj->w2C & 0xFF) != 255 && obj->w2C <= D_001E00D8 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_0021DEA0[obj->w2C]);
         list++) {
        e = (Moby3CEDD0 *)(D_001E009C + ((*list & 0x7FFF) << 8));
        if (e == 0) {
            break;
        }
        if (e->b20 == 254) {
            continue;
        }
        if (e->b20 == 253) {
            continue;
        }
        if (obj->w40 != -1) {
            h = func_00438488(e->hAA, 1, 28);
            if (h == 0) {
                continue;
            }
            if (h->f8(e) != 0) {
                continue;
            }
        }
        h = func_00438488(7032, 0, 16);
        h->f0(e);
    }
    return 1;
}
/* localdecomp:end func_003CEDD0 */
