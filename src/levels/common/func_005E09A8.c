#include "common.h"
typedef struct { u8 pad[356]; s32 a; s32 b; } S;
extern S D_001A4560;
void func_005E09A8(void) {
    S *p = &D_001A4560;
    if (p->a < 0) {
        p->b = 0;
        p->a = 32;
    }
}
