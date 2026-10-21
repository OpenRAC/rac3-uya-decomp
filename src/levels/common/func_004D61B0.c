#include "common.h"

/* localdecomp:start func_004D61B0 */
extern void func_004D61B0();

typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_004D7058();
extern void func_004D6698(S_3BA368 *p);
void func_004D61B0(S_3BA368 *p) {
    s32 r = 0;
    if (p->hAA == 0x1E01) {
        p->x64 = func_004D7058;
        func_004D6698(p);
        r = 1;
    }
    if (r) p->h34 &= ~2;
    else p->h34 |= 2;
}
/* localdecomp:end func_004D61B0 */
