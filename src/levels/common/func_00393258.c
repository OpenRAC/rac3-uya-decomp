#include "common.h"

typedef struct {
    u8 pad0[52];
    f32 f34;
    u8 pad38[72 - 56];
    f32 f48;
    u8 pad4C[96 - 76];
    s32 w60;
    u8 pad64[104 - 100];
    s32 w68;
    u8 pad6C[112 - 108];
    s32 w70;
    u8 pad74[124 - 116];
    s32 w7C;
} S_393258;

extern S_393258 *D_001E209C;
extern void func_003933C8(S_393258 *a0, f32 f12, s32 a1, s32 a2, f32 f13, s32 a3, s32 t0, f32 f14);

void func_00393258(s32 id) {
    s32 i;
    S_393258 *p;
    for (i = 0; i < 300; i++) {
        if (D_001E209C[i].w7C == id) {
            p = &D_001E209C[i];
            func_003933C8(p, p->f48, p->w68, p->w60, p->f34, 46, p->w70, 0.25f);
        }
    }
}
