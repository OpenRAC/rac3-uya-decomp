#include "common.h"

/* localdecomp:start func_003FE278 */
typedef struct {
    u8 pad0[24];
    s32 type;
    s32 count;
    u8 pad20[36 - 32];
    s32 value;
} Ent003FE278;

typedef struct {
    u8 pad0[34];
    s16 idx;
    u8 pad24[44 - 36];
    s32 value;
    u8 pad30[880 - 48];
    s32 step;
    s32 base;
} State003FE278;

extern State003FE278 D_001E6540;
extern s16 D_001E6568[];
extern Ent003FE278 D_001E68D0[];
extern s32 func_003FE310(void);

void func_003FE278(void)
{
    State003FE278 *st;
    s32 type;

    if (func_003FE310() != 0) {
        st = &D_001E6540;
        type = D_001E68D0[st->idx].type;
        switch (type) {
        case 0:
            st->value = D_001E68D0[st->idx].value;
            break;
        case 1:
        case 2:
            st->value = st->base + st->step * (D_001E68D0[st->idx].count - 1);
            break;
        }
    } else {
        D_001E6568[0] = 5;
    }
}
/* localdecomp:end func_003FE278 */
