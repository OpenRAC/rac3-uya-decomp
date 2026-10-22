#include "common.h"

/* localdecomp:start func_0061B088 */
typedef struct {
    u32 handle;
    s32 pad;
    s32 state;
} S_0061B088;
extern s32 D_00246080[8];
extern u8 *D_0024CF80[8];

u32 func_0061B088(s32 type, s32 sub, s32 idx) {
    s32 stride = D_00246080[type];
    S_0061B088 *e = (S_0061B088 *)(D_0024CF80[type] + idx * stride);
    s32 gen = 0;
    if (e != 0 && (e->state == 2 || e->state == 0)) {
        gen = ((e->handle & 0xFFF000) >> 12) + 1;
        e->handle = (e->handle & 0xFF000FFF) | ((gen << 12) & 0xFFF000);
    }
    return (type << 24) | (sub << 28) | (idx & 0xFFF) | ((gen << 12) & 0xFFF000);
}
/* localdecomp:end func_0061B088 */
