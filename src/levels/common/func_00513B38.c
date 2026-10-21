#include "common.h"

/* localdecomp:start func_00513B38 */
extern s32 func_00512AB0(s32, s32, s32);
extern s32 func_00513B38(s32, s32, s32);
extern s32 func_00512AB0();
extern s32 D_001DC1F0;

void *func_00511368_003E3250(s32, s32);                      /* extern */
s32 *func_00511BF8_003E3250(s32 *);                  /* extern */
s32 func_00511E28_003E3250(s32 *);                       /* extern */
s32 func_00512AB0(s32, s32, s32);
void func_0051B7B0(void *, s32);
extern s32 D_001DC1F0;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E3250;
extern S_001DA9B8_003E3250 D_001E1660_003E3250[];

s32 func_00513B38(s32 arg0, s32 arg1, s32 arg2) {
    s32 *var_v0;
    s32 var_s4;
    void *var_s0;

    var_s4 = 0;
    if (D_001E1660_003E3250->f4 != 0) {
        var_v0 = D_001E1660_003E3250;
    } else {
        var_v0 = func_00511BF8_003E3250(D_001E1660_003E3250);
    }
    var_s0 = func_00511368_003E3250(func_00511E28_003E3250(var_v0), arg0);
    if ((var_s0 == 0) || ((*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(var_s0) + 8))) + 0x10))(var_s0, D_001DC1F0) == 0)) {
        var_s0 = 0;
    }
    if (var_s0 != 0) {
        var_s4 = 1;
        func_00512AB0(arg0, 0x8000, arg1);
        func_0051B7B0(var_s0, arg2);
    }
    return var_s4;
}
/* localdecomp:end func_00513B38 */
