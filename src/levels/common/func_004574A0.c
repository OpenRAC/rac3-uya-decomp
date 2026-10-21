#include "common.h"

/* localdecomp:start func_004574A0 */
typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
extern S_4574A0 *func_00458650(M_4574A0 *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern s32 func_0040BAC0(s16 *);
extern s32 func_00440878(s32, s32);
extern s32 func_00457590(M_4574A0 *, f32 *, f32);
s32 func_004574A0(M_4574A0 *m, f32 *pos, f32 a) {
    S_4574A0 *s = func_00458650(m);
    if (s == 0) {
        return 8;
    }
    a = func_0040CEC8(func_0040C490(pos[0] - m->x, pos[1] - m->y), a);
    if (s->fDC != 0.0f) {
        a = func_0040CEC8(a, s->fDC);
        if (func_0040BAC0(&s->hE0) != 0) {
            s->fDC = -s->fDC;
            s->hE0 = func_00440878(s->hE2, s->hE4);
        }
    }
    return func_00457590(m, pos, a);
}
/* localdecomp:end func_004574A0 */
