#include "common.h"

typedef struct {
    u8 pad0[36];
    s32 w36;
    u8 pad28[68];
    s32 w108;
    u8 pad70[6];
    s16 h118;
    u8 pad78[28];
    s32 w148;
    s16 h152;
    u8 pad9A[4];
    s16 h158;
} S_001CCFD0;

typedef struct {
    s32 w0;
    u8 pad4[32];
    s32 w36;
} S_002E5F70;

typedef struct {
    u8 pad0[132];
    s32 w132;
    s32 w136;
    s32 w140;
    s32 arr144[16];
    s32 arr208[16];
} Obj_003260C8;

extern S_001CCFD0 D_001CCFD0;
extern S_002E5F70 D_002E5F70;
extern void func_0040BA90(s32 *);
extern s32 func_0045B9C8(void);
extern void func_0045CEC0(s32, s32);

void func_003260C8(void *a0, Obj_003260C8 *a1) {
    s32 i;

    if (a1->w136 == 0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        if (a1->arr144[i] != -1) {
            func_0040BA90(&a1->arr208[i]);
        }
    }
    if (a1->w140 != 0) {
        if (D_001CCFD0.h118 != 0 || D_001CCFD0.h158 != 3 || D_001CCFD0.h152 >= 7000) {
            return;
        }
        func_0045B9C8();
        a1->w140 = 0;
        a1->w132 = -1;
    } else if (a1->w132 != -1) {
        if (D_001CCFD0.w108 == 0 && D_001CCFD0.w36 == -1 && D_001CCFD0.w148 == 0
            && D_002E5F70.w0 == 0 && D_002E5F70.w36 == D_001CCFD0.w36) {
            func_0045CEC0((a1->w132 & 0x3FFF) + 6000, 0);
            a1->w140 = 1;
        }
    } else {
        a1->w136 = 0;
        for (i = 0; i < 16; i++) {
            if (a1->arr144[i] != -1) {
                a1->w136 = 1;
                if (a1->arr208[i] == 0) {
                    a1->w132 = a1->arr144[i];
                    a1->arr144[i] = -1;
                    return;
                }
            }
        }
    }
}
