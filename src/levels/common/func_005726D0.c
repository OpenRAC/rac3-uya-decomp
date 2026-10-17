#include "common.h"
typedef struct { u8 p0[0x1C]; u8 *w1C; } E_5726D0;
extern E_5726D0 *D_0024B950;
extern u8 *func_00577EE8(s32, s32);
void func_005726D0(void) {
    u8 *v = func_00577EE8(0, 33);
    *(s16 *)(D_0024B950[*(s16 *)(v + 132)].w1C + 70) = 30;
}
