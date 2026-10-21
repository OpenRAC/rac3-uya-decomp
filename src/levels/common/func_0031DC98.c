#include "common.h"

/* localdecomp:start func_0031DC98 */
typedef int Q_31DC98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_31DC98;
typedef struct { u8 b0; u8 b1; u8 pad[238]; } E_31DC98;
extern E_31DC98 D_002C5640[];
extern u8 D_0014263F[];
extern f32 func_0040BF38(void *);
extern f32 func_00440978(void);
extern void func_004082B0(void *, s32, u32, s32, f32, f32, f32);
extern void func_00408090(void *, void *, s32, u32, u32, f32, f32, s32, f32);
void func_0031DC98(u8 *obj) {
    V_31DC98 v;
    f32 *p;
    u32 c1, c2, c3;
    s32 n;
    *(Q_31DC98 *)&v = 0;
    v.w = 1.0f;
    p = *(f32 **)(obj + 0x68);
    p[5] -= 0.1f;
    if (p[5] <= -8.0f) {
        p[5] += 8.0f;
    }
    p[6] += func_0040BF38(p);
    c1 = 0x40801010;
    c2 = 0x7F801010;
    c3 = 0x00801010;
    n = (D_002C5640 + D_0014263F[0])->b1;
    if (n >= 4) {
        c1 = 0x40801030;
        c2 = 0x7F801030;
        c3 = 0x00801030;
    }
    func_004082B0(obj + 0x10, 49, c1, 1, 0.35f, 0.0f, func_00440978());
    func_004082B0(obj + 0x10, 49, 0x707F7F7F, 1, 0.25f, 0.0f, func_00440978());
    func_004082B0(obj + 0x10, 47, 0x407F7F7F, 1, 0.11f, 0.0f, func_00440978());
    if (p[6] > 1.5f) {
        func_00408090(obj, &v, 1, 0x7F804040, 0x00804040, 0.05f, 1.8f, 23, p[5]);
        func_00408090(obj, &v, 1, c2, c3, 0.22f, 1.8f, 23, p[5]);
        func_00408090(obj, &v, 1, c2, c3, 0.22f, 1.8f, 23, p[5]);
    }
}
/* localdecomp:end func_0031DC98 */
