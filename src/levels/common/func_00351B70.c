#include "common.h"

/* localdecomp:start func_00351B70 */
typedef struct {
    s32 f0;
    u8 pad4[0x1C];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 pad30[0x10];
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    f32 f54;
    f32 f58;
} S_351B70;
typedef struct { u8 pad0[0x20]; u8 f20; u8 pad21[0x47]; S_351B70 *f68; } O_351B70;
extern s32 D_001F1600[];
extern void func_00351CE0(O_351B70 *o, S_351B70 *s);
extern s32 func_003E4190(s32 *p);
extern s32 func_003520F8(O_351B70 *o, S_351B70 *s);
extern void func_003521E0(O_351B70 *o, S_351B70 *s);
extern s32 func_00352288(O_351B70 *o, S_351B70 *s);
extern s32 func_00352398(O_351B70 *o, S_351B70 *s);
extern s32 func_004182E0(s32 a, s32 b);
extern void func_00352550(void);
extern void func_003DB440(void (*f)(void), O_351B70 *o);

void func_00351B70(O_351B70 *o) {
    S_351B70 *s = o->f68;
    if (o->f20 == 0) {
        func_00351CE0(o, s);
    }
    if (D_001F1600[0] != s->f0) {
        return;
    }
    if (s->f20 > 0) {
        if (func_003E4190(&s->f2C) != 0 && func_003520F8(o, s) != 0) {
            s->f2C = func_004182E0(s->f24, s->f28);
        }
        func_003521E0(o, s);
    }
    if (s->f40 > 0) {
        if (func_003E4190(&s->f4C) != 0 && func_00352288(o, s) != 0) {
            s->f4C = func_004182E0(s->f44, s->f48);
        }
    }
    if (s->f50 != 0) {
        s->f58 += s->f54;
        while (s->f58 > 1.0f) {
            if (func_00352398(o, s) != 0) {
                s->f58 -= 1.0f;
            } else {
                s->f58 -= 0.25f;
            }
        }
    }
    func_003DB440(func_00352550, o);
}
/* localdecomp:end func_00351B70 */
