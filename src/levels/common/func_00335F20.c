#include "common.h"

/* localdecomp:start func_00335F20 */
typedef int u128_335F20 __attribute__((mode(TI)));
typedef struct { u8 pad[0x94]; u8 *(*fn)(s32); } V_335F20;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad44[0xC]; s32 x50; } S_335F20;
typedef struct { u8 pad[0x68]; S_335F20 *x68; } O_335F20;
extern V_335F20 *func_00438488(s32, s32, s32);
extern s32 D_001E009C[];
void func_00335F20(O_335F20 *o, u128_335F20 *src) {
    S_335F20 *s = o->x68;
    V_335F20 *v = func_00438488(s->x40, 4, 156);
    *src = *(u128_335F20 *)(v->fn(D_001E009C[0] + (s->x50 << 8)) + 0x4B0);
}
/* localdecomp:end func_00335F20 */
