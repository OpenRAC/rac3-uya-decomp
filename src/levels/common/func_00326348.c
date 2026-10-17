#include "common.h"

typedef struct {
    char pad0[0xB9];
    u8 done;
} State;

extern State D_001426E0;
extern s32 D_001DC960;
extern s32 func_00426718(s32);
extern s32 func_00426768(s32);
extern void func_0040C320(void);
extern void func_00425D78(s32, s32, s32);

void func_00326348(void) {
    s32 a;
    s32 b;
    s32 i;

    D_001DC960++;
    if (D_001426E0.done == 0) {
        a = 0;
        b = 0;
        for (i = 0; i < 36; i++) {
            a += func_00426718(i);
            b += func_00426768(i);
        }
        if (a >= b) {
            D_001426E0.done = 1;
            func_0040C320();
            func_00425D78(4784, -1, 0);
        }
    }
}
