#include "common.h"

/* localdecomp:start func_002F8918 */
typedef int Q_2F8918 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2F8918;
typedef struct {
    u8 pad0[109];
    u8 b109;
} T_2F8918;
typedef struct {
    u8 pad0[16];
    V4_2F8918 pos;
    u8 pad32[72];
    T_2F8918 *t;
} O_2F8918;
typedef struct {
    u8 pad0[24];
    s32 i24;
} E_2F8918;
extern E_2F8918 D_002BE748[];
extern s32 D_00142660[];
extern s32 D_001D6714;
extern O_2F8918 *D_001E00A0;
extern s32 D_001D545C;
extern s32 D_001A9280[];
extern s32 func_002F9520(void);
extern void func_00475A50(s32);
extern void func_00440A88(void *, f32, f32);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern void func_00467DA8(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);

void func_002F8918(O_2F8918 *o) {
    V4_2F8918 a, b;
    Q_2F8918 qa, qb;
    T_2F8918 *t = o->t;
    s32 r, k;
    f32 f20;

    s32 v = D_002BE748[func_002F9520()].i24;
    D_00142660[0] += v;
    if ((t->b109 & 2) || (D_001D6714 != 0 && o < D_001E00A0)) {
        D_001A9280[D_001D545C] += v;
    }
    func_00475A50(180);
    func_00440A88(&a, 0.011666667f, 0.016666668f);
    func_0040BE90(&b, &a, 10.0f);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(qb) : "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qb));
    r = func_00440848(2);
    if (r == 0) r = r - 1;
    f20 = func_004408C0(0.4f, 0.5f);
    func_00467DA8(&b, 25, 0x7f207f7f, 0, r, &a, 0, f20 * 0.2f, f20, 0.0f);
    func_00467DA8(&b, 25, 0x7f7f7f7f, 1, -r, &a, 0, f20 * 0.14f, f20 * 0.7f, 0.0f);
}
/* localdecomp:end func_002F8918 */
