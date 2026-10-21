#include "common.h"

/* localdecomp:start func_003F3918 */
typedef int Q_3F3918 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x30];
    Q_3F3918 v30;
    u8 p40[0x24];
    f32 f64;
    f32 f68;
    f32 f6C;
    void *f70;
    u8 p74[9];
    u8 f7D;
    s16 f7E;
    u8 p80[0xE];
    s16 f8E;
} O_3F3918;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 pC[4];
    u8 p10[0x40];
    O_3F3918 *f50;
    u8 p54[0xC];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 p6C[0x124];
    f32 f190;
    f32 f194;
    f32 f198;
    u8 p19C[0x104];
    s16 f2A0;
    u8 p2A2[0x1B2];
    s32 f454;
    u8 p458[8];
} S_3F3918;
extern S_3F3918 D_001E2AC0[];
extern u8 D_001E5590[];
extern void func_004DE160(s32);
extern O_3F3918 *func_003F1368(s32, s32);
extern void func_003F2CC8(s32, s32);
extern void func_003F1628(O_3F3918 *);
extern void func_003F1220(s32);
extern void func_003F0EF0(s32);
void func_003F3918(s32 a, s32 b) {
    S_3F3918 *p;
    O_3F3918 *q, *r;
    f32 *d, *e, *g;
    p = &D_001E2AC0[a];
    func_004DE160(0);
    if (p->f50) {
        p->f50->f8E = 0;
        p->f50->f7D = 0;
        p->f50->f7E = 0;
    }
    p->f50 = func_003F1368(a, 0);
    p->f50->f8E = 1;
    p->f50->f70 = D_001E5590 + a * 0x780;
    p->f50->f7D = 0;
    p->f2A0 = 0;
    func_003F2CC8(a, 1);
    if (b != 0) {
        p->f454 = 0;
    }
    func_003F1628(p->f50);
    func_003F1220(a);
    q = p->f50;
    *(Q_3F3918 *)p = q->v30;
    d = &q->f64;
    d[0] = p->f0;
    d[1] = p->f4;
    d[2] = p->f8;
    e = &p->f190;
    g = &p->f60;
    g[0] = e[0];
    g[1] = e[1];
    g[2] = e[2];
    func_003F0EF0(a);
}
/* localdecomp:end func_003F3918 */
