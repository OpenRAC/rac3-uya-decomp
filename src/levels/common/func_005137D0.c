#include "common.h"

/* localdecomp:start func_005137D0 */
extern s32 func_005137D0(s32 arg0);

extern s32 func_00511200(s32, s32);
s32 *func_00511BF8_003E2ED8(s32 *);                  /* extern */
s32 func_00511E28_003E2ED8(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2ED8;
extern S_001DA9B8_003E2ED8 D_001E1660_003E2ED8[];

s32 func_005137D0(s32 arg0) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = -1;
    if (D_001E1660_003E2ED8->f4 != 0) {
        var_v0 = D_001E1660_003E2ED8;
    } else {
        var_v0 = func_00511BF8_003E2ED8(D_001E1660_003E2ED8);
    }
    temp_v0 = func_00511E28_003E2ED8(var_v0);
    if (temp_v0 != 0) {
        var_s1 = func_00511200(temp_v0, arg0);
    }
    return var_s1;
}
/* localdecomp:end func_005137D0 */
