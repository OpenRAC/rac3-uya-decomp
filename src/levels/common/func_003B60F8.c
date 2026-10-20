#include "common.h"

typedef struct {
    s32 type;
    u8 pad0[32];
    s32 x36;
    u8 pad1[64];
    s32 x104;
    s32 x108;
    s32 x112;
    s32 x116;
    u8 pad2[8];
    s32 x128;
} S_3B60F8;

typedef struct {
    u8 pad0[32];
    u8 b32;
    u8 pad1[155];
    u8 b188;
} M_3B60F8;

typedef struct {
    u8 pad[8];
    s32 (*fn)(u8 *);
} V_3B60F8;

extern u8 *D_001E009C[];
extern s32 func_003B59B0(M_3B60F8 *, S_3B60F8 *);
extern void func_003B5368(M_3B60F8 *, S_3B60F8 *, s32, s32, s32);
extern V_3B60F8 *func_00326898(void);
extern void func_003B56B8(M_3B60F8 *, S_3B60F8 *, s32);
extern void func_003B5940(M_3B60F8 *, S_3B60F8 *);
extern void func_00441FB8(M_3B60F8 *, s32, s32);
extern void func_003B5A90(M_3B60F8 *, S_3B60F8 *, s32);
extern void func_003B5D68(M_3B60F8 *, S_3B60F8 *, s32);

void func_003B60F8(M_3B60F8 *m, S_3B60F8 *s, s32 arg, f32 t) {
    if (s->x108 != -1) {
        if (s->type == 6476) {
            if (func_003B59B0(m, s)) {
                s->x36 = s->x128;
            } else {
                s->x36 = 1;
            }
            return;
        }
        if (t == 1.0f && s->x112 == 0) {
            func_003B5368(m, s, s->type, arg, 1);
            return;
        }
        if (t == 0.0f && s->x116 == 0) {
            func_003B5368(m, s, s->type, arg, 1);
            return;
        }
        if (!func_00326898()->fn(D_001E009C[0] + (s->x108 << 8))) {
            s->x36 = 1;
            return;
        }
        func_003B56B8(m, s, arg);
        func_003B5940(m, s);
        s->x36 = s->x128;
        m->b188 = m->b32;
        func_00441FB8(m, 4, -1);
        return;
    }
    if (s->type == 6317) {
        func_003B5A90(m, s, arg);
    } else if (s->type == 6836) {
        func_003B5D68(m, s, arg);
    } else {
        func_003B5368(m, s, s->type, arg, 1);
    }
}
