#include "common.h"

/* localdecomp:start func_004DDCE8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_4DDCE8;

typedef struct {
    V_4DDCE8 v0;
    s32 w10;
    u8 pad14[0x20 - 0x14];
    V_4DDCE8 v20;
} S_4DDCE8;

extern S_4DDCE8 D_001A6720;
extern void func_004CF3B8(s32 a, s32 b);

void func_004DDCE8(V_4DDCE8 *a, V_4DDCE8 b, s32 c) {
    u8 *p;
    D_001A6720.v0 = *a;
    D_001A6720.v20 = b;
    p = (u8 *)&D_001A6720 - 0x1B40;
    *(s32 *)(p + 0x1B50) = c;
    if ((u32)(*(s32 *)(p + 0x25C4) - 0x66) >= 4) {
        func_004CF3B8(0x66, 2);
    }
}
/* localdecomp:end func_004DDCE8 */
