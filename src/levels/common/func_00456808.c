#include "common.h"
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[130];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[100];
} __attribute__((aligned(16))) Ent_00456808;
extern Ent_00456808 D_002C5640[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
void func_00456808(void) {
    Ent_00456808 e;
    s32 i;
    for (i = 0; i < 156; i++) {
        e = D_002C5640[i];
        if (e.f0 != 0 && e.f1 == 0) {
            if (D_00142CA0[i] != 0) {
                e = D_002C5640[D_001425C0[i]];
                if (e.f84 != 0) {
                    D_001427F0[i] = e.f8A;
                }
            }
        }
    }
}
