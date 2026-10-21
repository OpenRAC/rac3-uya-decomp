#include "common.h"

/* localdecomp:start func_003DC7D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3DC7D8;
typedef int Q_3DC7D8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    V_3DC7D8 f10;
    u8 pad20[0xC0 - 0x20];
    V_3DC7D8 fC0;
} S_3DC7D8;
extern void func_0040C2D0(void *, void *, void *);
void func_003DC7D8(S_3DC7D8 *obj, V_3DC7D8 *out) {
    V_3DC7D8 v;
    Q_3DC7D8 x, y;
    V_3DC7D8 *m = &obj->fC0;
    *(Q_3DC7D8 *)&v = 0;
    v.x = -0.1f;
    v.w = 1.0f;
    func_0040C2D0(&v, &v, m);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->f10));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
}
/* localdecomp:end func_003DC7D8 */
