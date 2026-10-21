#include "common.h"

/* localdecomp:start func_00328EE0 */
typedef struct {
    u8 pad0[16];
    s32 e;
    u8 pad20[36];
} S_328EE0;

extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern S_328EE0 D_002AEA90[];
extern u8 D_001426E0[];
extern s32 func_00328B90(u8 *);
extern s32 func_00328D28(u8 *);
extern s32 func_00328BE0(u8 *);

s32 func_00328EE0(u8 *m) {
    u8 *v = *(u8 **)(m + 104);
    s32 id;
    s32 ok;
    s32 e;

    if (func_00328B90(m) == 0) {
        return 0;
    }
    if (func_00328D28(m) == 0) {
        return 0;
    }
    if (func_00328BE0(m) == 0) {
        return 0;
    }
    id = *(s32 *)(v + 12);
    ok = 1;
    if (id != -1 && (D_001BBC40[id + D_001D545C * 16] & 0x80)) {
        ok = 0;
    }
    if (v[83] == 255 || (e = (v[83] + D_002AEA90)->e) == 0) {
        return ok;
    }
    if (id != -1) {
        return ok && D_001426E0[e] == 0;
    }
    return D_001426E0[e] == 0;
}
/* localdecomp:end func_00328EE0 */
