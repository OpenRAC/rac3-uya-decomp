#include "common.h"

/* localdecomp:start func_002FE070 */
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P_2FE070;

extern int D_001D66B0;
extern u8 *D_00221288[];
extern int func_00440848(int);
extern f32 func_00440918(f32, f32);
extern P_2FE070 *func_00466F98(f32 *, void *, int, int, int, int, f32, f32, f32, f32, f32);

void func_002FE070(f32 *pos, f32 scale) {
    f32 buf[4];
    f32 s = scale * 210000.0f;
    P_2FE070 *p;
    int r;

    if (func_00440848(2)) {
        r = func_00440918(1.0f, -1.0f);
        p = func_00466F98(pos, &D_001D66B0, 3, 6, 0x20FF40, r,
                          s * 6.0f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p != 0) {
            p->b2 = D_00221288[0][1];
        }
    }
    buf[0] = pos[0] + func_00440918(0.0f, 0.04f);
    buf[1] = pos[1] + func_00440918(0.0f, 0.04f);
    buf[2] = pos[2] + func_00440918(0.0f, 0.04f);
    if (func_00440848(2)) {
        r = func_00440918(1.0f, -1.0f);
        p = func_00466F98(buf, &D_001D66B0, 3, 127, 0x20FF40, r,
                          s * 2.4f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p != 0) {
            p->b3 = func_00440848(2) ? 72 : 68;
            p->b2 = D_00221288[0][0];
        }
    }
}
/* localdecomp:end func_002FE070 */
