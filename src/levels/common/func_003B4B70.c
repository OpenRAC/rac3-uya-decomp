#include "common.h"
typedef struct M_3B4B70 M_3B4B70;
typedef struct {
    s32 w0;
    u8 pad4[0x6C - 0x4];
    s32 w6C;
    u8 pad70[0x84 - 0x70];
    s32 w84;
    u8 pad88[0xC0 - 0x88];
    s32 wC0;
    s32 wC4;
    u8 padC8[0x11C - 0xC8];
    M_3B4B70 *p11C;
} V_3B4B70;
struct M_3B4B70 {
    u8 pad[0x21];
    u8 b21;
    u8 pad22[0x68 - 0x22];
    V_3B4B70 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
};
typedef struct { u8 pad[0xC]; void (*fn)(M_3B4B70 *); } C_3B4B70;
extern s32 D_001E009C[];
extern void func_00438760(s32, M_3B4B70 *);
extern void func_003B4A50(M_3B4B70 *, M_3B4B70 *, s32);
extern C_3B4B70 *func_00326878(s32);
void func_003B4B70(M_3B4B70 *m, M_3B4B70 *o) {
    V_3B4B70 *v = m->p68;
    if (v->w6C != -1 && o == (M_3B4B70 *)(D_001E009C[0] + (v->w6C << 8))) {
        return;
    }
    if (o->b21 != 255) {
        func_00438760(o->b21, o);
    }
    if (o->hAA == v->w0) {
        func_003B4A50(m, o, 0);
        if (v->w6C != -1 && v->w84 != 0) {
            v->wC4++;
        } else {
            v->wC0--;
        }
        if (o == v->p11C) {
            v->p11C = 0;
        }
    }
    func_00326878(o->hAA)->fn(o);
}
