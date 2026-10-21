#include "common.h"

/* localdecomp:start func_00328AA8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 pad[44];
} E_00328AA8;

extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern E_00328AA8 D_002AEA90[];
extern u8 D_001426E0[];

s32 func_00328AA8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    E_00328AA8 *e;
    s32 k;
    if (v[83] == 255) {
        s32 k0 = *(s32 *)(v + 4);
        if (k0 == -1) {
            return 1;
        }
        return D_001BBC40[k0 + D_001D545C * 16] >> 7;
    }
    e = &D_002AEA90[v[83]];
    k = *(s32 *)(v + 4);
    if (k == -1) {
        if (e->w8 == 0) {
            return 1;
        }
        return D_001426E0[e->w8] != 0;
    }
    if (D_001BBC40[k + D_001D545C * 16] & 0x80) {
        return 1;
    }
    if (e->w8 != 0 && D_001426E0[e->w8] != 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00328AA8 */
