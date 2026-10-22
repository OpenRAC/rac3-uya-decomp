#include "common.h"

/* localdecomp:start func_00628F00 */
typedef struct { u8 pad[0x10]; u8 n; } C_00628F00;
typedef struct { u8 pad[0x48]; C_00628F00 *items[1]; } B_00628F00;
typedef struct { u8 pad[0x24]; B_00628F00 *b; u8 pad2[0x1B]; u8 idx; } A_00628F00;
typedef struct { u8 pad[0x630]; s32 a; s32 b; u8 pad2[0x2524 - 0x638]; A_00628F00 *q; } P_00628F00;

void func_00628F00(P_00628F00 *p, s32 a, s32 b) {
    if (a >= 0) {
        A_00628F00 *q = p->q;
        if (b < q->b->items[q->idx]->n) {
            p->a = a;
            p->b = b;
        }
    }
}
/* localdecomp:end func_00628F00 */
