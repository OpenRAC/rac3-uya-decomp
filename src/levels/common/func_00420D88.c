#include "common.h"

typedef struct {
    s16 id;
    s16 arg;
    f32 f;
} B_00420D88;

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[30];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2C[20];
} T_00420D88;

extern u8 D_001D5471;
typedef struct {
    u8 pad0[68];
    s16 count;
    u8 pad46[346];
    u8 *list[1];
} G_00420D88;

extern G_00420D88 D_001E6E00;
extern T_00420D88 D_00244580[];
extern void func_0011A264(void *buf, s32 c, s32 n);
extern void func_00437350(u8 *m, s32 arg, T_00420D88 *e);

void func_00420D88(void) {
    B_00420D88 buf[2];
    u8 *m;
    T_00420D88 *e;
    s32 i;
    s32 j;
    s32 k;
    f32 f;

    if (D_001D5471 == 0) {
        return;
    }
    func_0011A264(buf, 0, 8);
    for (i = 0; i < D_001E6E00.count; i++) {
        m = D_001E6E00.list[i];
        if (*(s32 *)(m + 84) == 0) {
            for (j = 0; buf[j].id != 0; j++) {
                if (*(s16 *)(m + 170) != buf[j].id) {
                    continue;
                }
                f = buf[j].f;
                for (k = 0; k < 7; k++) {
                    if (D_00244580[k].b1 == 0) {
                        break;
                    }
                }
                if (k < 7) {
                    e = &D_00244580[k];
                    func_00437350(m, buf[j].arg, e);
                    e->f20 = f;
                    e->f24 = f;
                    e->f28 = f;
                }
            }
        }
    }
}
