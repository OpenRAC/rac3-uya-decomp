#include "common.h"

/* localdecomp:start func_004BB0F0 */
extern s32 D_00244784[];
extern char D_001DADC0[];
extern char D_001DADD0[];
extern char D_001DADD8[];
extern s32 func_0011B2E8(char *, const char *, ...);

void func_004BB0F0(char *buf, s32 v) {
    if (D_00244784[0] == 0) {
        if (v > 999999) {
            func_0011B2E8(buf, D_001DADC0, v / 1000000, (v / 1000) % 1000, v % 1000);
        } else if (v >= 1000) {
            func_0011B2E8(buf, D_001DADD0, v / 1000, v % 1000);
        } else {
            func_0011B2E8(buf, D_001DADD8, v);
        }
    } else {
        func_0011B2E8(buf, D_001DADD8, v);
    }
}
/* localdecomp:end func_004BB0F0 */
