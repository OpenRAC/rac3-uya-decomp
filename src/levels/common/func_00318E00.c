#include "common.h"

/* localdecomp:start func_00318E00 */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 v0;
    s128 v10;
    s128 v20;
    s128 v30;
    s128 v40;
    f32 f50[3];
    f32 f5c[3];
    f32 f68[3];
    f32 f74[3];
    f32 f80[3];
    f32 f8c[3];
    s32 i98;
    s32 i9c;
    s32 ia0;
    s32 ia4;
    s32 ia8;
    s32 pad;
} P_318E00;

extern P_318E00 D_00273C00[];
extern s128 D_001A4CC0;
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);

void func_00318E00(s32 id, s128 *p, s32 arg) {
    s32 i;
    P_318E00 *q;
    P_318E00 *base = D_00273C00;

    for (i = 0; i < 6; i++) {
        q = &base[i];
        if (q->i9c == 0) {
            q->i9c = id;
            q->v20 = D_001A4CC0;
            q->v40 = *p;
            q->f50[0] = func_004408C0(-3.1415927f, 3.1415927f);
            q->f50[1] = func_004408C0(-3.1415927f, 3.1415927f);
            q->f50[2] = func_004408C0(-3.1415927f, 3.1415927f);
            q->f74[0] = func_004408C0(-3.1415927f, 3.1415927f);
            q->f74[1] = func_004408C0(-3.1415927f, 3.1415927f);
            q->f74[2] = func_004408C0(-3.1415927f, 3.1415927f);
            q->f5c[0] = func_00440918(0.001f, 0.005f);
            q->f5c[1] = func_00440918(0.001f, 0.005f);
            q->f5c[2] = func_00440918(0.001f, 0.005f);
            q->f80[0] = func_00440918(0.001f, 0.005f);
            q->f80[1] = func_00440918(0.001f, 0.005f);
            q->f80[2] = func_00440918(0.001f, 0.005f);
            q->f68[0] = func_004408C0(3.25f, 4.75f);
            q->f68[1] = func_004408C0(3.25f, 4.75f);
            q->f68[2] = func_004408C0(3.25f, 4.75f);
            q->f8c[0] = func_004408C0(3.25f, 4.75f);
            q->f8c[1] = func_004408C0(3.25f, 4.75f);
            q->f8c[2] = func_004408C0(3.25f, 4.75f);
            q->i98 = 20;
            __asm__ __volatile__("sq $0, %0" : "=m"(q->v0));
            q->ia4 = arg;
            __asm__ __volatile__("sq $0, %0" : "=m"(q->v10));
            do { q->ia8 = 0; } while (0);
            q->ia0 = arg;
            break;
        }
    }
}
/* localdecomp:end func_00318E00 */
