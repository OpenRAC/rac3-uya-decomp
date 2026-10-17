#include "common.h"

typedef struct { u8 p0[17664]; } E_005D4D78;

extern E_005D4D78 D_002FB100[];
extern u8 D_001D7EA8[2];
extern s32 D_001D7E98[2];
extern E_005D4D78 *D_001D7EB0[2];
extern void func_0060E900(s32, s32, s32);

void func_005D4D78(s32 a0, E_005D4D78 *e) {
    s32 i = e - D_002FB100;
    if (D_001D7EA8[i] != 0) {
        D_001D7E98[i] = a0;
        D_001D7EB0[i] = e;
        func_0060E900(0x90000, 1, 1);
    }
}
