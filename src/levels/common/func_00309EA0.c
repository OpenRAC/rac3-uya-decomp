#include "common.h"

/* localdecomp:start func_00309EA0 */
typedef struct {
    u8 pad0[140];
    s32 a;
    u8 pad1[16];
} A00309EA0;

typedef struct {
    u8 pad0[160];
    s32 a;
    u8 pad1[12];
} B00309EA0;

extern A00309EA0 D_0026FDB0[30];
extern B00309EA0 D_00271070[16];
extern s32 D_001DC670;

void func_00309EA0(void) {
    s32 i;
    for (i = 29; i >= 0; i--) {
        D_0026FDB0[i].a = 0;
    }
    for (i = 15; i >= 0; i--) {
        D_00271070[i].a = 0;
    }
    D_001DC670 = 0;
}
/* localdecomp:end func_00309EA0 */
