#include "common.h"

/* localdecomp:start func_004F11B8 */
typedef struct { s16 active; s16 a; s16 b; s16 c; } E_4F11B8;
typedef struct { u8 pad[0x274C]; E_4F11B8 e[8]; } S_4F11B8;
extern S_4F11B8 D_001A4BE0;
void func_004F11B8(s32 a, s32 b, s32 c) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_001A4BE0.e[i].active == 0) {
            D_001A4BE0.e[i].active = 1;
            D_001A4BE0.e[i].c = c;
            D_001A4BE0.e[i].b = b;
            D_001A4BE0.e[i].a = a;
            return;
        }
    }
}
/* localdecomp:end func_004F11B8 */
