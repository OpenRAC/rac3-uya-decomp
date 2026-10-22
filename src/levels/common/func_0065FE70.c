#include "common.h"

typedef struct N_0065FE70 {
    u32 bits;
    s32 base;
    u8 pad8[0x50 - 8];
    s32 id;
    u8 pad54;
    u8 keep;
    u8 pad56[2];
    struct N_0065FE70 *next;
} N_0065FE70;
typedef struct {
    u8 pad[0x128];
    s32 time;
} G_0065FE70;
extern N_0065FE70 *D_001DAAE4;
extern G_0065FE70 D_001A5E50;
extern s32 D_0024D85C;
extern void func_006600D8(N_0065FE70 *);
extern void func_00660140(N_0065FE70 *);

void func_0065FE70(void) {
    N_0065FE70 *prev = 0;
    N_0065FE70 *n = D_001DAAE4;
    N_0065FE70 *dead = 0;
    N_0065FE70 *next;
    while (n != 0) {
        if (n->keep == 0 && D_001A5E50.time >= n->base + (s32)(n->bits >> 13)) {
            next = n->next;
            if (prev == 0) {
                D_001DAAE4 = next;
            } else {
                prev->next = next;
            }
            n->next = dead;
            dead = n;
            n = next;
        } else {
            prev = n;
            n = n->next;
        }
    }
    while (dead != 0) {
        n = dead;
        if (n->id == -1 || n->id == D_0024D85C) {
            func_006600D8(dead);
        }
        dead = dead->next;
        func_00660140(n);
    }
}
