#include "common.h"

typedef struct {
    u8 pad0[0x14];
    u16 unk14;
    u16 unk16;
    u8 pad18[0x7];
    u8 unk1F;
} func_005F3D60_t;

extern s32 D_0025F794[];
extern u8 D_002BC840[];
extern func_005F3D60_t *D_0024CAE4;
extern func_005F3D60_t *D_0024CAE8;
extern s32 D_0024CAF4;
extern u8 *D_0024CB1C;
extern s32 D_0024CB10;
extern s32 D_0024CB14;
extern s32 D_001E1288;
extern s32 *D_002412A0;
extern func_005F3D60_t *D_0024CB38[];
extern func_005F3D60_t *D_0024CB48[];
extern s32 D_0024CB68[];
extern s32 D_0024CB78[];
extern s32 D_0024CB88[];

void func_005F3D60(void) {
    func_005F3D60_t *p;
    func_005F3D60_t *q;
    s32 i;

    D_0024CAF4 = D_0025F794[0];
    D_0024CB1C = D_002BC840;
    D_0024CB10 = 0;
    D_0024CB14 = 0;
    D_001E1288 = 0;
    for (p = D_0024CAE4; p != D_0024CAE8; p++) {
        p->unk16 = 0;
        p->unk14 = 0xFFFF;
        p->unk1F = 0xFF;
    }
    if (*D_002412A0 < 2) {
        return;
    }
    for (i = 0; i < *D_002412A0; i++) {
        D_0024CB68[i] = 0;
        D_0024CB78[i] = 0;
        D_0024CB88[i] = 0;
        for (q = D_0024CB38[i]; q != D_0024CB48[i]; q++) {
            q->unk16 = 0;
            q->unk14 = 0xFFFF;
            q->unk1F = 0xFF;
        }
    }
}
