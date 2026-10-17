#include "common.h"
typedef int u128_335EC0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x94]; u8 *(*fn)(s32); } V_335EC0;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad44[0xC]; s32 x50; } S_335EC0;
typedef struct { u8 pad[0x68]; S_335EC0 *x68; } O_335EC0;
extern V_335EC0 *func_00438488(s32, s32, s32);
extern s32 D_001E009C[];
void func_00335EC0(O_335EC0 *o, u128_335EC0 *src) {
    S_335EC0 *s = o->x68;
    V_335EC0 *v = func_00438488(s->x40, 4, 156);
    *(u128_335EC0 *)(v->fn(D_001E009C[0] + (s->x50 << 8)) + 0x4B0) = *src;
}
