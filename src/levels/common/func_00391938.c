#include "common.h"

/* localdecomp:start func_00391938 */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} G391938A;

typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G391938B;

typedef struct {
    u8 pad0[36];
    s32 unk24;
} V391938;

typedef struct {
    u8 pad0[104];
    V391938 *pVars;
} M391938;

extern G391938A D_001A1ED0;
extern G391938B D_001CFEC0;
extern void func_004C1FE8(s32, unsigned long);
extern void func_00403708(s32, s32, s32, s32, s32);

void func_00391938(M391938 *m) {
    V391938 *v = m->pVars;

    if (v->unk24 != 0) {
        func_004C1FE8(78, (long)((D_001A1ED0.unk8 >> 13) | 0x1000000) | 0x100000000);
        func_00403708(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, (v->unk24 << 24) | 0xFFFFFF);
        func_004C1FE8(78, 0x1000000 | (D_001A1ED0.unk8 >> 13));
    }
}
/* localdecomp:end func_00391938 */
