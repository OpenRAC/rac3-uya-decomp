#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 *unk8;
} Vars668EC0;

typedef struct {
    u8 pad0[48];
    u8 unk30;
    u8 pad31[104 - 49];
    Vars668EC0 *pVars;
} Moby668EC0;

extern Moby668EC0 *func_005A8280(s32, s32);
extern void func_00669B18(void);
extern s32 *D_0024CF20[];
extern Moby668EC0 *D_0024D040[];

void func_00668EC0(void) {
    s32 i;
    s32 *src;
    Vars668EC0 *v;

    for (i = 0; i < 8; i++) {
        src = D_0024CF20[i];
        if (src != 0) {
            D_0024D040[i] = func_005A8280(5949, 336);
            D_0024D040[i]->unk30 = 255;
            v = D_0024D040[i]->pVars;
            v->unk4 = src[0];
            v->unk8 = src;
            v->unk0 = 0;
        }
    }
    func_00669B18();
}
