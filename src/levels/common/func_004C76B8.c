#include "common.h"

/* localdecomp:start func_004C76B8 */
typedef struct B_004C76B8 { u8 pad[0x24]; struct C_004C76B8 *c; u8 pad2[0x70]; s32 v; } B_004C76B8;
typedef struct C_004C76B8 { u8 pad[0x10]; s32 v; } C_004C76B8;
extern B_004C76B8 *D_001E1150[4];
void func_004C76B8(void) {
    s32 i;
    B_004C76B8 **pp = D_001E1150;
    for (i = 3; i >= 0; i--, pp++) {
        B_004C76B8 *p = *pp;
        if (p != 0) {
            p->v = p->c->v;
        }
    }
}
/* localdecomp:end func_004C76B8 */
