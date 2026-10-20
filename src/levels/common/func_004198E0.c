#include "common.h"

typedef struct {
    s32 pad0;
    s32 unk4;
    s32 pad8[6];
    s32 unk20;
    s32 unk24;
    s32 pad28[15];
    s32 unk64;
    s32 pad68;
    s32 unk6C;
    s32 pad70[3];
    s32 unk7C;
    s32 pad80[4];
} Ent004198E0;

extern Ent004198E0 D_002E6110[];
extern s32 D_001DFD80;
extern s32 D_001DFD84;
extern u8 *D_001DFDF8;
extern u8 *D_001DFDFC;
extern u8 *D_001DFE00;
extern s32 D_001DFE04;
extern s32 D_001DFE0C;
extern s32 D_001DFE10;
extern s32 D_001DFE14;
extern s32 D_001DFE18;
extern s32 D_001DFE1C;
extern char D_001D68A8[];
extern void func_0041A170(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0041A098(s32, s32, char *, s32);
extern void func_0040BBD0(u8 *, s32);
extern void func_0040BBA8(s32, s32, s32);
extern void func_0041AA38(s32);

void func_004198E0(void) {
    s32 i;
    u8 *a;
    s32 v;

    D_001DFD80 = 0;
    D_001DFD84 = 0;
    for (i = 0; i < 13; i++) {
        D_002E6110[i].unk64 = -1;
        D_002E6110[i].unk20 = 0x10000;
        func_0041A170(i, 0xFFFF, 0, 0, 0, 0, 1);
        D_002E6110[i].unk7C = 0;
        D_002E6110[i].unk6C = -6;
        D_002E6110[i].unk4 = 0;
        D_002E6110[i].unk24 = 0;
    }
    if (D_001DFDF8 == 0) {
        D_001DFDF8 = (u8 *)func_0041A098(0, 0, D_001D68A8, 382);
        D_001DFE04 = func_0041A098(0, 0, D_001D68A8, 383);
        D_001DFE0C = func_0041A098(0, 0, D_001D68A8, 384);
    }
    a = D_001DFDF8;
    D_001DFDFC = a;
    D_001DFE00 = a;
    if (a != 0) {
        func_0040BBD0(a, 0);
        v = D_001DFE0C;
        D_001DFE10 = 0;
        D_001DFE14 = 0;
        D_001DFE18 = v;
        D_001DFE1C = v;
        func_0040BBA8(v, 0, 0);
    }
    D_001DFDF8[32] = 255;
    func_0041AA38(0);
}
