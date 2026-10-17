#include "common.h"
typedef struct {
    u8 pad[16];
    void (*fn)(u8 *, void *);
} Vt00327228;
extern u8 *func_003252E8(void *);
extern Vt00327228 *func_00438488(s32 a0, s32 a1, s32 a2);
extern u8 *D_001E009C;
void func_00327228(void *a0) {
    u8 *s = *(u8 **)(func_003252E8(a0) + 104);
    if (*(s32 *)(s + 20) == -1) {
        return;
    }
    func_00438488(6877, 0, 104)->fn(D_001E009C + (*(s32 *)(s + 20) << 8), a0);
}
