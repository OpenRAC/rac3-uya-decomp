#include "common.h"

/* localdecomp:start func_004A45B0 */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001E0E70_003C8B28;
extern s32 D_001E0E90[2];
extern void func_0040C678(void *, void *);
s32 func_004A45B0(s32 idx, s32 n) {
    f32 v[4] __attribute__((aligned(16)));
    s16 *p = D_001E0E70_003C8B28->arr[idx];
    if (n > 0) {
        s32 dx = (u16)p[5], dy = (u16)p[6], dz = (u16)p[7];
        s32 a, b, c;
        s32 x = (u16)p[2], y = (u16)p[3], z = (u16)p[4];
        do {
            a = x + dx;
            b = y + dy;
            c = z + dz;
            x = a;
            y = b;
            z = c;
        } while (--n);
        p[4] = c;
        p[3] = b;
        p[2] = a;
    }
    __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(v));
    if (p[2] != 0) v[0] = p[2] * 9.58738019107841e-05f;
    if (p[3] != 0) v[1] = p[3] * 9.58738019107841e-05f;
    if (p[4] != 0) v[2] = p[4] * 9.58738019107841e-05f;
    func_0040C678(D_001E0E90, v);
}
/* localdecomp:end func_004A45B0 */
