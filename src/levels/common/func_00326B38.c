#include "common.h"

typedef struct {
    u8 pad0[118];
    u16 unk76;
    u8 pad78[38];
    u16 unk9E;
} S_001CCFD0;

typedef struct {
    u8 pad0[108];
    u8 unk6C;
    u8 pad6D[67];
    s32 unkB0[4];
    s32 unkC0[4];
    s32 unkD0[4];
    s32 unkE0[4];
} S_326B38;

typedef struct {
    u8 pad0[132];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90[16];
    s32 unkD0[16];
} S_326B38q;

extern S_001CCFD0 D_001CCFD0;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 *D_001E009C;
extern u8 *func_003252E8(u8 *);
extern s32 func_003B4340(u8 *);
extern f32 func_003B4480(u8 *, s32, s32, s32, s32);
extern s32 func_003B4700(u8 *);
extern s32 func_003B4730(u8 *, s32);

void func_00326B38(u8 *obj) {
    u8 *v = func_003252E8(obj);
    S_326B38 *p = *(S_326B38 **)(obj + 104);
    S_326B38q *q = *(S_326B38q **)(v + 104);
    u8 *m;
    s32 i;
    s32 j;
    s32 k;
    s32 *slots;

    if (p->unk6C != 0) {
        for (j = 15; j >= 0; j--) {
            q->unk90[j] = -1;
        }
        q->unk84 = -1;
        q->unk8C = 0;
        q->unk88 = 0;
        if ((u32)(D_001CCFD0.unk76 - 6) >= 2) {
            D_001CCFD0.unk76 = 5;
        }
        if ((u32)(D_001CCFD0.unk9E - 6) >= 2) {
            D_001CCFD0.unk9E = 5;
        }
    }
    for (i = 0; i < 4; i++) {
        if (p->unkB0[i] == -1) {
            continue;
        }
        k = p->unkD0[i];
        if (k != -1 && (D_001BBC40[k + D_001D545C * 16] & 0x80)) {
            continue;
        }
        k = p->unkE0[i];
        if (k != -1) {
            m = D_001E009C + k * 256;
            if (*(s16 *)(m + 170) == 6629) {
                if (func_003B4340(m) != 0) {
                    if (func_003B4480(m, 0, 0, 0, 0) == 1.0f) {
                        continue;
                    }
                } else if (func_003B4700(m) != 0) {
                    if (func_003B4730(m, 0) != 0) {
                        continue;
                    }
                }
            } else {
                if (m == 0) {
                    continue;
                }
                k = m[32];
                if (k == 254) {
                    continue;
                }
                if (k == 253) {
                    continue;
                }
            }
        }
        slots = q->unk90;
        j = 0;
        do {
            if (slots[j] == -1) {
                slots[j] = p->unkB0[i];
                q->unkD0[j] = p->unkC0[i] * 60;
                break;
            }
            j++;
        } while (j < 16);
        q->unk88 = 1;
    }
}
