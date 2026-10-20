#include "common.h"

typedef struct {
    u8 p0[0xC];
    f32 f12;
    s32 w16;
    f32 f20;
    u8 p18[0xC];
    s32 w36;
    u8 p28[0x24];
    s32 w76;
    u8 p50[0x10];
    s32 w96;
    s32 w100;
    s32 w104;
    u8 p6C[0xC];
    s32 w120;
    s32 w124;
    u8 p80[0xC];
    s32 w140;
    u8 p90[0x30];
    s32 w192;
    s32 w196;
    u8 pC8[0x48];
    s32 w272;
    s32 w276;
    u8 p118[4];
    s32 w284;
} V_3B47D8;

typedef struct {
    u8 p0[0x20];
    u8 b32;
    u8 p21[0x13];
    u16 h52;
    u8 p36[0x32];
    V_3B47D8 *pVar;
    u8 p6C[0x50];
    u8 b188;
} M_3B47D8;

extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern void func_00441FB8(M_3B47D8 *m, s32 a, s32 b);
extern void func_003B60F8(M_3B47D8 *m, V_3B47D8 *v, s32 n, f32 f);

void func_003B47D8(M_3B47D8 *m) {
    V_3B47D8 *v = m->pVar;

    v->w104 = 255;
    v->w36 = 0;
    v->w96 = 0;
    v->w100 = 0;
    v->w76 = 0;
    v->w192 = 0;
    v->w196 = 0;
    v->w120 = 0;
    v->w124 = 0;
    v->w140 = 0;
    v->w284 = 0;
    if (m->b32 == 4) {
        m->b188 = 2;
    } else {
        func_00441FB8(m, 2, -1);
    }
    m->h52 &= ~2;
    if (v->w16 <= 0) {
        return;
    }
    if (v->w272 != -1 && !(D_001BBC40[v->w272 + D_001D545C * 16] & 0x80)) {
        return;
    }
    if (v->w276 != -1 && (D_001BBC40[v->w276 + D_001D545C * 16] & 0x80)) {
        return;
    }
    func_003B60F8(m, v, v->w16, v->f20);
    if (v->f12 != v->f20) {
        v->w96 = 0;
        v->w100 = 0;
    }
}
