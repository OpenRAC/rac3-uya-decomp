#include "common.h"

typedef struct {
    u8 pad0[392];
    u8 b392;
    u8 b393;
    u8 pad1[974];
    u8 b1368;
    u8 pad2[103];
} Player_003F07A0;

typedef struct {
    s32 delta;
    u8 val;
} Out_003F07A0;

extern Player_003F07A0 D_001CD0C0[];
extern s32 D_001D5FC8[2];
extern u8 D_001439FE[];
extern s32 func_003F0398(Out_003F07A0 *, Player_003F07A0 *);

void func_003F07A0(void) {
    Out_003F07A0 out;
    Player_003F07A0 *p = D_001CD0C0;
    s32 i;

    for (i = 0; i < 8; i++, p++) {
        if (p->b1368 != 0) {
            func_003F0398(&out, p);
            if (D_001439FE[i] != 0) {
                D_001D5FC8[i] += out.delta;
                if (D_001D5FC8[i] >= 256) {
                    p->b392 = 1;
                    D_001D5FC8[i] -= 255;
                } else {
                    p->b392 = 0;
                }
                p->b393 = out.val;
            }
        } else {
            p->b392 = 0;
            p->b393 = 0;
        }
    }
}
