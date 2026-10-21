#include "common.h"

/* localdecomp:start func_004D1FE0 */
extern void func_004D1FE0();

typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD6D8;
void func_00124920(void);
void func_00124970(void);
void func_004D1FE0(S_3AD6D8 *p) {
    func_00124920();
    *(s32 *)(p->x8 * 0x27E40 + p->x4) = 2;
    p->xC++;
    p->x8 = (p->x8 + 1) % p->x10;
    func_00124970();
}
/* localdecomp:end func_004D1FE0 */
