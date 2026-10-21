#include "common.h"

/* localdecomp:start func_0061AF30 */
typedef struct O_61AF30 {
    u32 id;
    s32 owner;
    s32 active;
    struct O_61AF30 *next;
    u8 pad10[0x1C];
    u8 f2C;
} O_61AF30;

extern O_61AF30 *D_0024CF40[];
extern s32 D_0024D858[];
extern s32 D_0024D85C[];
extern void func_0061BA40(O_61AF30 *, s32);

void func_0061AF30(void) {
    s32 i;
    O_61AF30 *o;
    s32 hit;

    if (D_0024D858[0] == D_0024D85C[0]) {
        for (i = 0; i < 8; i++) {
            for (o = D_0024CF40[i]; o != 0; o = o->next) {
                hit = o->owner == -1;
                if (hit) {
                    if (((o->id & 0x0F000000) >> 24) == 7 && o->f2C != 0) {
                        hit = 0;
                    }
                    if (hit) {
                        func_0061BA40(o, 1);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_0061AF30 */
