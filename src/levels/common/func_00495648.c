#include "common.h"

/* localdecomp:start func_00495648 */
extern void func_00495648();

extern s32 func_004950C8(void *, s32, s32);
extern s32 func_00512BA0(s32, s32, s32);
typedef struct { u8 p[0x10]; s32 n; } S_B4E78;
void func_00495648(S_B4E78 *s) {
    s32 i, t;
    for (i = 0; ; ) {
        t = s->n + 2;
        if (i >= t) break;
        func_00512BA0(func_004950C8(s, 0, i), 1, 3);
        func_00512BA0(func_004950C8(s, 1, i), 2, 3);
        i++;
    }
}
/* localdecomp:end func_00495648 */
