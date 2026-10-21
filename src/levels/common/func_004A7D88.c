#include "common.h"

/* localdecomp:start func_004A7D88 */
extern s32 D_0023ACF0[];

typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A02D8;
extern u32 D_001D54D0;
extern s16 D_001D6700[4];
extern s16 D_001D6706;
extern s16 D_001D6708;
extern s16 D_001D670A;
extern s16 D_001D670C;
extern O_3A02D8 *func_00435E70_003A02D8(s32, s32);
extern void func_004A7D30(void);
void func_004A7D88(O_3A02D8 *o) {
    s16 *k;
    O_3A02D8 **t;
    O_3A02D8 *p;
    s32 i;
    if (o == 0) o = D_0016C580_003A02D8.f0;
    func_004A7D30();
    o->f30 = 0xFF;
    t = (O_3A02D8 **)D_0023ACF0;
    k = &D_001D6700[(D_001D54D0 >> 2) & 3];
    t[0] = func_00435E70_003A02D8(*k, 0x80);
    t[1] = p = func_00435E70_003A02D8(*k, 0x80);
    p->f34 |= 0x8000;
    t[2] = func_00435E70_003A02D8(D_001D6706, 0x80);
    t[3] = func_00435E70_003A02D8(D_001D6708, 0x80);
    t[4] = p = func_00435E70_003A02D8(D_001D6708, 0x80);
    p->f34 |= 0x8000;
    t[5] = func_00435E70_003A02D8(D_001D670A, 0x80);
    t[6] = p = func_00435E70_003A02D8(D_001D670A, 0x80);
    p->f34 |= 0x8000;
    t[7] = func_00435E70_003A02D8(D_001D670C, 0x80);
    t[8] = p = func_00435E70_003A02D8(D_001D670C, 0x80);
    p->f34 |= 0x8000;
    for (i = 0; t[i] != 0; i++) {
        if (t[i]->f63 != 0) t[i]->f63 = 8;
        t[i]->f34 |= 0x124;
        t[i]->f32 = 0x1FF;
        t[i]->f68->f8 = (u8 *)t[i]->f68 + 0x30;
    }
    o->f34 |= 0x20;
    o->f68->f8 = (u8 *)o->f68 + 0x30;
}
/* localdecomp:end func_004A7D88 */
