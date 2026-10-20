#include "common.h"

typedef struct {
    u8 pad0[72];
    s16 index;
    u8 last;
    u8 pad75;
    u8 type;
    u8 pad77[3];
} E_0044C778;

extern u8 *D_001E009C;
extern u8 *D_001E0F54;
extern u8 *D_001E0E48;
extern s32 func_00448E90(void *a);

void func_0044C778(E_0044C778 *e, s32 val, s32 force) {
    u8 *p;
    u8 *q;
    s32 f;

    do {
        switch (e->type & 3) {
        case 0:
            p = D_001E009C + e->index * 256;
            f = *(u16 *)(p + 52) & 0xFFBE;
            *(u16 *)(p + 52) = f;
            q = *(u8 **)(p + 36);
            f |= *(u16 *)(q + 68) & 0x1000;
            *(u16 *)(p + 52) = f;
            f &= 0xFFFD;
            *(s32 *)(p + 152) = *(s32 *)(q + 16);
            *(u16 *)(p + 52) = f;
            *(u16 *)(p + 50) = val;
            if (force != 0 || func_00448E90(p + 16) != 0) {
                *(u16 *)(p + 52) &= 0xFF7F;
            } else {
                *(u16 *)(p + 52) |= 0x80;
            }
            break;
        case 1:
            p = D_001E0F54 + e->index * 32;
            p[28] = val;
            if (force != 0 || func_00448E90(p) != 0) {
                p[30] &= 0xFB;
            } else {
                p[30] |= 4;
            }
            break;
        case 2:
            p = D_001E0E48 + e->index * 32;
            if (force != 0 || func_00448E90(p) != 0) {
                p[22] &= 0xFE;
            } else {
                p[22] |= 1;
            }
            break;
        }
    } while ((e++)->last != 1);
}
