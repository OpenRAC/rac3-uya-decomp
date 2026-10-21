#include "common.h"

/* localdecomp:start func_005197F0 */
extern void func_005197F0();
extern s32 func_005121D8();

extern s32 func_005121D8();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
void func_005197F0(T_E8 *a0) {
    s32 i;
    for (i = 0; i < a0->x2C->x48; i++) {
        s32 *p = (s32 *)((u8 *)(i << 2) + (s32)a0->x2C);
        if (*p != 0) {
            func_005121D8(*p);
        }
        *p = 0;
    }
}
/* localdecomp:end func_005197F0 */
