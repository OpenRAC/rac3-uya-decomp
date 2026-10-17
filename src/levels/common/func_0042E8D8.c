#include "common.h"

extern u32 D_001D545C;
extern void func_0042E8D8();

typedef struct { u8 pad[0x10]; f32 f10; f32 f14; u8 pad2[0xE0]; f32 fF8; } O_39B0F8;
typedef struct { f32 x, y, z, w; } V_39B0F8;
extern u32 D_001D545C;
extern s32 D_002F14F0[];
extern O_39B0F8 *D_001EFEA0[];
extern V_39B0F8 D_00143230[];
void func_0042E8D8(void) {
    s32 i;
    if (D_001D545C < 0x13) {
        for (i = D_002F14F0[D_001D545C]; i < D_002F14F0[D_001D545C + 1]; i++) {
            O_39B0F8 *o = D_001EFEA0[i];
            if (o) {
                D_00143230[i].x = o->f10;
                D_00143230[i].y = o->f14;
                D_00143230[i].z = o->fF8;
            }
        }
    }
}
