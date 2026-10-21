#include "common.h"

/* localdecomp:start func_003274D8 */
typedef struct {
    u8 pad0[0x44];
    s32 (*fn)(u8 *, s32);
} S_3274D8_Cls;

typedef struct {
    u8 pad0[0x14];
    s32 w14;
    s32 w18;
} S_3274D8_Vars;

typedef struct {
    u8 pad0[0x68];
    S_3274D8_Vars *vars;
} S_3274D8_Moby;

extern u8 *D_001E009C;
extern S_3274D8_Moby *func_003252E8(void);
extern S_3274D8_Cls *func_00438488(s32, s32, s32);

s32 func_003274D8(s32 a0) {
    S_3274D8_Vars *v = func_003252E8()->vars;
    S_3274D8_Cls *c;
    if (v->w14 == -1) {
        return 0;
    }
    c = func_00438488(6877, 0, 104);
    if (a0 == -2) {
        return c->fn(D_001E009C + (v->w14 << 8), v->w18);
    }
    return c->fn(D_001E009C + (v->w14 << 8), a0);
}
/* localdecomp:end func_003274D8 */
