#include "common.h"

extern void func_004ACF88(void);

typedef struct { u8 pad[0x20]; void *p20; u8 pad2[0x1C]; s32 p40; } S2_3A2BC0;
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x1C]; S2_3A2BC0 *f50; u8 pad3[0x14C]; s32 f1A0[4]; } B_3A2BC0;
extern B_3A2BC0 D_001E6E00;
extern S2_3A2BC0 D_002EE7E0[];
extern s32 D_001D9AC0;
extern void *D_001D9B40;
extern s32 D_001D9B50;
void func_004ACF88(void) {
    B_3A2BC0 *base = &D_001E6E00;
    s32 idx = -1;
    S2_3A2BC0 *p;
    if (base->f30 == 0) idx = 3;
    if (idx != -1) {
        p = D_002EE7E0;
        base->f50 = p;
        D_001D9B40 = &D_001D9AC0;
        p->p20 = &D_001D9B50;
        p->p40 = base->f1A0[idx];
    }
}
