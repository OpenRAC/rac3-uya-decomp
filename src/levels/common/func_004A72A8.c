#include "common.h"

/* localdecomp:start func_004A72A8 */
extern u8 D_001FDC50[];
extern u8 *D_001FD200[];
extern u8 D_001A30B0[];
extern s32 func_004A6F58(u8 *a0, s32 a1, s32 a2, s32 a3, s32 t0);
s32 func_004A72A8(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *ent = D_001FD200[D_001FDC50[a3]];
    u8 *tbl;
    s32 r;
    u8 *rec;
    if (ent == 0) {
        return -1;
    }
    tbl = *(u8 **)(ent + 40);
    if (tbl == 0) {
        return -1;
    }
    if (a0 >= ent[13]) {
        return -1;
    }
    r = func_004A6F58(tbl + a0 * 32, a1, a2, 0, 1024);
    if (r >= 0) {
        rec = D_001A30B0 + r * 128;
        *(s32 *)(rec + 220) = a2;
        *(s16 *)(rec + 202) = a0;
        *(s32 *)(rec + 264) = a3;
    }
    return r;
}
/* localdecomp:end func_004A72A8 */
