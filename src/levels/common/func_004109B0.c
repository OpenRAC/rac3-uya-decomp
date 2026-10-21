#include "common.h"

/* localdecomp:start func_004109B0 */
typedef int Q_4109B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4109B0;
typedef struct {
    u8 pad0[0x30];
    Q_4109B0 q30;
    f32 f40;
    s32 i44;
    u8 pad48[0x18];
    f32 f60;
    s32 i64;
    u8 pad68[0x18];
    s32 i80;
    u8 pad84[8];
    s32 i8C;
    u8 pad90[0x10];
    Q_4109B0 qA0;
    s32 iB0;
    f32 fB4;
    f32 fB8;
    u8 padBC[0x34];
    u8 mF0[0x50];
    Q_4109B0 q140;
} O_4109B0;
extern void func_0040C638(void *, void *);
extern void func_00411538(void *, void *, void *);
extern void func_00440CF8(void *, f32, f32, f32);
void func_004109B0(O_4109B0 *o, Q_4109B0 *src, f32 a, f32 b) {
    V_4109B0 v;
    V_4109B0 c0, c1;
    *(Q_4109B0 *)&v = 0;
    o->i44 = 0;
    __asm__("sq $0, %0" : "=m"(o->qA0));
    o->i64 = 0;
    o->i80 = 0;
    o->i8C = 0;
    o->iB0 = 0;
    o->f40 = a;
    o->f60 = b;
    v.y = b;
    v.z = a;
    func_0040C638(o, &v);
    o->q30 = *src;
    o->q140 = *src;
    *(Q_4109B0 *)&c0 = *src;
    *(Q_4109B0 *)&c1 = *src;
    func_00411538(o, &c0, &c1);
    if (o->f60 > o->fB4) {
        o->f60 = o->fB4;
    } else if (o->f60 < o->fB8) {
        o->f60 = o->fB8;
    }
    func_00440CF8(o->mF0, 1.0f, o->f40, -o->f60);
}
/* localdecomp:end func_004109B0 */
