#include "common.h"

typedef struct {
    u8 pad0[0x4500];
} D_002FB100_t;
extern D_002FB100_t D_002FB100[];

D_002FB100_t *func_006197C0(s32 i) {
    return &D_002FB100[i];
}
