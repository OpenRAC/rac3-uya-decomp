#include "common.h"

/* localdecomp:start func_00327298 */
typedef struct {
    u8 pad0[20];
    s32 idx;
} S_327298_Vars;
typedef struct {
    u8 pad0[104];
    S_327298_Vars *vars;
} S_327298_Moby;
typedef struct {
    u8 pad0[56];
    void (*fn)(void *a0, s32 a1, f32 f12);
} S_327298_Cls;
extern u8 *D_001E009C[];
extern S_327298_Moby *func_003252E8(void);
extern S_327298_Cls *func_00438488(s32, s32, s32);
void func_00327298(s32 a0, f32 f12) {
    S_327298_Vars *v = func_003252E8()->vars;
    if (v->idx != -1) {
        func_00438488(6877, 0, 104)->fn(D_001E009C[0] + (v->idx << 8), a0, f12);
    }
}
/* localdecomp:end func_00327298 */
