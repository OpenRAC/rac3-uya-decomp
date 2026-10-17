#include "common.h"
typedef struct {
    s32 pad0;
    s32 pad4;
    u32 *src;
    u32 *base;
    s32 count;
} D_001E6540_t;
extern D_001E6540_t D_001E6540;
void func_003FE190(void) {
    s32 i;
    D_001E6540.base = D_001E6540.src;
    D_001E6540.count = *D_001E6540.base >> 4;
    for (i = 0; i < D_001E6540.count; i++) {
        *(u32 *)((u8 *)D_001E6540.base + i * 16) += (u32)D_001E6540.base;
    }
}
