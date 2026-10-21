#include "common.h"

/* localdecomp:start func_002FB230 */
typedef int Q_2FB230 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    Q_2FB230 v10;
    u8 pad20[0x14];
    u16 f34;
    u8 pad36[0x86];
    u8 fBC;
} O_2FB230;
extern u8 D_001EEB00[];
extern f32 func_00444F60(f32, f32, f32);
extern s32 func_003FB1D0(void *, s32, void *, s32, f32);
extern void func_004445E0(void *, void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_00436220(void *);
void func_002FB230(O_2FB230 *o) {
    Q_2FB230 q;
    f32 r;
    s32 n;
    o->f34 |= 0x41;
    r = func_00444F60(0.5f, 5.5f, (f32)o->fBC / 15.0f);
    n = func_003FB1D0(&o->v10, 0x10, o, 0, r);
    q = o->v10;
    func_004445E0(o, &q, D_001EEB00, n, 0, 0x1030001, 2, 1, 1.0f, 1.0f, 1.0f, -1);
    o->fBC++;
    if (o->fBC >= 0x10) {
        func_00436220(o);
    }
}
/* localdecomp:end func_002FB230 */
