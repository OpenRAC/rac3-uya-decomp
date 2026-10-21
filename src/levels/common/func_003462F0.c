#include "common.h"

/* localdecomp:start func_003462F0 */
typedef struct {
    u8 pad0[16];
    u8 pos[20];
    s32 active;
    s32 visible;
    s32 target;
} Vars3462F0;

extern s32 func_004C73B0(s32);
extern s32 func_004C7670(void);
extern void func_004C3500(void *, void *, s32, s32, f32);
extern s32 D_00277100[];

void func_003462F0(u8 *self) {
    Vars3462F0 *v = *(Vars3462F0 **)(self + 104);

    if (v->target != 0) {
        if ((u32)(func_004C73B0(v->target) - 1) < 2) {
            v->visible = 0;
        } else if (v->active == 0 || (D_00277100[0] >= 9 && func_004C7670() == 0)) {
            v->visible = 0;
        } else {
            v->visible = 1;
        }
    }
    if (v->active != 0 && v->visible != 0) {
        func_004C3500(v, v->pos, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_003462F0 */
