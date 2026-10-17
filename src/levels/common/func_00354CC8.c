#include "common.h"
typedef int u128_354CC8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x3DA]; s16 x3DA; } V_354CC8;
typedef struct { u8 pad[0x10]; u128_354CC8 pos; u8 pad20[0x48]; V_354CC8 *x68; } O_354CC8;
extern s32 func_00354AF8(O_354CC8 *);
extern void func_00405688(u128_354CC8 *, u128_354CC8 *);
extern void func_004056C0(u128_354CC8 *, u128_354CC8 *);
void func_00354CC8(O_354CC8 *o, u128_354CC8 *v) {
    u128_354CC8 t = *v;
    if (o->x68->x3DA != 0 || func_00354AF8(o) != 0) {
        func_00405688(&o->pos, &t);
    } else {
        func_004056C0(&o->pos, &t);
    }
}
