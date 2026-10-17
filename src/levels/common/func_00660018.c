#include "common.h"

typedef struct {
    u32 bits;
    s32 base;
    u8 pad[0x48];
    s32 field_50;
} Packet;

extern s32 D_001A5E50[];
extern Packet *func_00660120(void);
extern void func_0058F1B0(void *, void *, s32);
extern void func_00660308(void *);

s32 func_00660018(s32 a0, s32 a1, s32 a2, u32 *a3) {
    s32 *g = D_001A5E50;
    s32 n = ((*a3 >> 4) & 0x3F) + 12;
    Packet *s;

    if (g[2] != a2) {
        s = func_00660120();
        func_0058F1B0(s, a3, n);
        s->field_50 = -1;
        if (s->base + (s32)(s->bits >> 13) - g[74] < 0 && (s->bits & 0xFFFFE000)) {
            func_00660308(s);
        }
    }
    return n;
}
