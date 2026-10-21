#include "common.h"

/* localdecomp:start func_003CBEB8 */
typedef int Q_3CBEB8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CBEB8;
typedef struct {
    u8 pad0[176];
    V4_3CBEB8 v176;
    u8 pad192[4];
    s32 i196;
    u8 pad200[8];
    u8 b208[16];
} S_3CBEB8;
typedef struct {
    u8 pad0[16];
    V4_3CBEB8 pos;
    u8 state;
    u8 pad33[71];
    S_3CBEB8 *s;
} O_3CBEB8;
extern void func_003CC220(void *, void *);
extern void func_003CC9F0(void *);
extern s32 func_0040BA90(void *);
extern void func_003CC4F0(void *, s32, s32, s32, void *, s32);
extern void func_00436220(void *);
extern void func_004026A0(void *, void *);
extern void func_003CC400();
void func_003CBEB8(O_3CBEB8 *o) {
    S_3CBEB8 *s = o->s;
    V4_3CBEB8 old;
    V4_3CBEB8 *p;
    Q_3CBEB8 a, b;

    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        p = &o->pos;
        old = o->pos;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(s->v176));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(a));
        func_003CC220(o, &old);
        func_003CC9F0(o);
        if (func_0040BA90(s->b208) != 0) {
            o->state = 2;
            func_003CC4F0(p, 20, 5, 0, o, s->i196 != 0);
        }
        break;
    case 2:
        func_00436220(o);
        return;
    default:
        break;
    }
    func_004026A0(func_003CC400, o);
}
/* localdecomp:end func_003CBEB8 */
