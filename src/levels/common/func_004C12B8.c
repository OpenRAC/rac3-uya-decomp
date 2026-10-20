#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Ent004C12B8;

extern Ent004C12B8 D_002F1C60[];
extern char D_001DAE80[];
extern s32 D_001DAC10;
extern u8 D_001DAC09;
extern s32 D_001DAC0C;
extern s32 func_00494DD0(s32);
extern char *func_004950A8(s32, s32, s32);
extern s32 func_004181A0(s32);
extern void func_0011B2E8(char *, char *, s32);
extern s32 func_004B7558(s32);
extern void func_00495108(s32, s32, s32);

void func_004C12B8(void) {
    u32 i;
    s32 n;
    char *buf;

    n = 0;
    for (i = 0; i < 10; i++) {
        if (D_002F1C60[i].unk8 == 255) {
            continue;
        }
        buf = func_004950A8(func_00494DD0(0), 0, n);
        func_0011B2E8(buf, D_001DAE80, func_004181A0(D_002F1C60[i].unk0));
        if (func_004B7558(D_002F1C60[i].unkC)) {
            func_00495108(func_00494DD0(0), n, 0);
        } else {
            func_00495108(func_00494DD0(0), n, 2);
        }
        if (D_001DAC10 < 5 && D_002F1C60[i].unkC == -1) {
            D_001DAC09 = 0;
            D_001DAC0C = 0;
            func_00495108(func_00494DD0(0), n, 3);
        } else if (D_002F1C60[i].unkC == D_001DAC10) {
            D_001DAC0C = D_002F1C60[i].unkC;
            D_001DAC09 = 1;
            func_00495108(func_00494DD0(0), n, 3);
        }
        n++;
    }
}
