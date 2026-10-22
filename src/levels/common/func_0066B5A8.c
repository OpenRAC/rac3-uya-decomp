#include "common.h"

/* localdecomp:start func_0066B5A8 */
typedef struct N_0066B5A8 {
    u8 pad0[0x20];
    struct N_0066B5A8 *prev;
    struct N_0066B5A8 *next;
    s32 f28;
    s32 f2C;
    s32 f30;
    u8 pad34[0x40 - 0x34];
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    u8 pad50[0x60 - 0x50];
    s32 f60;
    u8 pad64[0x70 - 0x64];
} N_0066B5A8;
extern N_0066B5A8 D_00351460[];
extern N_0066B5A8 D_003513F0[];
extern s32 D_0024D07C[1];
extern N_0066B5A8 *D_001E17E8;

void func_0066B5A8(void) {
    s32 i;
    for (i = 0; i < 50; i++) {
        N_0066B5A8 *p = &D_00351460[i];
        p->f28 = 0;
        p->f4C = 0;
        p->f40 = 0;
        p->f44 = 0;
        p->f48 = 0;
        p->f2C = 0;
        p->f30 = 0;
        p->f60 = 0;
        if (i == 0) {
            D_00351460[0].prev = 0;
        } else {
            p->prev = &D_003513F0[i];
        }
        if (i == 49) {
            (&D_00351460[49])->next = 0;
        } else {
            p->next = p + 1;
        }
    }
    D_0024D07C[0] = 0;
    D_001E17E8 = D_00351460;
}
/* localdecomp:end func_0066B5A8 */
