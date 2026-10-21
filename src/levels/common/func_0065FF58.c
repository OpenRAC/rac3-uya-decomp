#include "common.h"

typedef struct N_0065FF58 {
    u8 pad[0x4C];
    s32 time;
    s32 id;
    u8 pad54;
    u8 active;
    u8 pad56[2];
    struct N_0065FF58 *next;
} N_0065FF58;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x128 - 8];
    s32 f128;
    u8 pad12C[0x170 - 0x12C];
    s32 f170;
    u8 pad174[0x7D4 - 0x174];
    u8 f7D4;
} G_0065FF58;
extern N_0065FF58 *D_001DAAE4;
extern G_0065FF58 D_001A5E50;
extern s32 D_0024D85C;
extern s32 D_00240758;
extern s32 func_006602F0(N_0065FF58 *);
extern void func_0014AD08(s32, s32, s32, s32, s32, N_0065FF58 *);

void func_0065FF58(void) {
    N_0065FF58 *n;
    for (n = D_001DAAE4; n != 0; n = n->next) {
        if (n->active != 0 && D_001A5E50.f128 >= n->time) {
            if (n->id != D_0024D85C && D_001A5E50.f170 == 0) {
                s32 c = D_001A5E50.f7D4 | 0x40;
                func_0014AD08(c, D_001A5E50.f4, n->id, D_00240758, func_006602F0(n), n);
            }
            n->active = 0;
        }
    }
}
