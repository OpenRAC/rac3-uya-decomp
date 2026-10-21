#include "common.h"

typedef int Q_3186A8 __attribute__((mode(TI)));
typedef struct {
    Q_3186A8 q0;
    Q_3186A8 q10;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3c;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4c;
} S_3186A8;
typedef struct {
    s32 f0;
    u8 pad4[0x18 - 4];
    s32 f18;
} T_3186A8;
extern S_3186A8 D_00272800[];
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern f32 func_00440918(f32, f32);

/* localdecomp:start func_003186A8 */
void func_003186A8(u8 *a0, Q_3186A8 *a1, s32 a2) {
    S_3186A8 *e;
    T_3186A8 *t = *(T_3186A8 **)(a0 + 0x68);
    s32 r;
    f32 v;
    s32 i;

    for (i = 0; i < 64; i++) {
        e = &D_00272800[i];
        if (e->f44 == 0) {
            e->f44 = (s32)a0;
            e->f30 = a2;
            e->q0 = *a1;
            __asm__("sq $0, %0" : "=m"(e->q10));
            if (t->f18) {
                e->f38 = 0x204060;
            } else {
                e->f38 = 0x800000;
            }
            e->f20 = func_004408C0(0.1f, 0.3f);
            e->f24 = func_004408C0(0.4f, 0.5f);
            r = func_00440878(25, 40);
            e->f3c = r;
            e->f40 = r;
            e->f2c = func_00440978();
            v = func_00440918(180.0f, 360.0f);
            e->f28 = (v * 0.017453292f) * 0.016666668f;
            t->f0++;
            break;
        }
    }
}
/* localdecomp:end func_003186A8 */
