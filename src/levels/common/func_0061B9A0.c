#include "common.h"

/* localdecomp:start func_0061B9A0 */
typedef struct H_0061B9A0 {
    u32 handle;
    struct H_0061B9A0 *next;
} H_0061B9A0;
extern s32 D_00246150[11];
extern u8 *D_0024CFE0[10];
extern H_0061B9A0 *D_0024CFA0[8];

H_0061B9A0 *func_0061B9A0(u32 h) {
    u32 idx = h & 0xFFF;
    u32 t = (h >> 22) & 0x3C;
    H_0061B9A0 *e = (H_0061B9A0 *)(*(u8 **)((u8 *)D_0024CFE0 + t) + idx * *(s32 *)((u8 *)D_00246150 + t));
    if (e->handle == h) {
        return e;
    }
    for (e = *(H_0061B9A0 **)((u8 *)D_0024CFA0 + t); e != 0; e = e->next) {
        if (e->handle == h) {
            return e;
        }
    }
    return 0;
}
/* localdecomp:end func_0061B9A0 */
