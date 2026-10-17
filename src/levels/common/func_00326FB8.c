#include "common.h"

typedef struct { u8 p0[8]; s32 w8; } S_326FB8;
extern S_326FB8 *func_00445F18(void);
extern void func_003B4A50(s32, s32, s32);

void func_00326FB8(s32 a, s32 b) {
    S_326FB8 *s = func_00445F18();
    if (s->w8 != 0) {
        func_003B4A50(s->w8, a, b);
    }
}
