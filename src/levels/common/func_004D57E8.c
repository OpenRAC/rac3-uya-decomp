#include "common.h"

/* localdecomp:start func_004D57E8 */
extern u8 D_001E1384[];
extern u8 D_001E13B0[];
extern s32 D_001DBCFC[];
u8 func_004D4548(void);
s32 func_004D57E8(s32 a) {
    s32 r = 0;
    if ((D_001E1384[0] = func_004D4548()) != 0 && a) {
        r = D_001E13B0[0] != 0;
    }
    D_001DBCFC[0] = 1;
    return r;
}
/* localdecomp:end func_004D57E8 */
