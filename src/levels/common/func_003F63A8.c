#include "common.h"

/* localdecomp:start func_003F63A8 */
typedef int Q_3F63A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3F63A8;
typedef struct {
    u8 pad0[16];
    V4_3F63A8 pos;
    u8 pad20[72];
    u8 *s;
    u8 pad6C[84];
    u8 mC0[64];
} O_3F63A8;
extern void func_0044E088(void *, void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040CB80(void *, void *);
extern void func_0040C960(void *, void *, void *);
void func_003F63A8(O_3F63A8 *obj) {
    u8 *s = obj->s;
    V4_3F63A8 v[6];

    Q_3F63A8 x, y;
    func_0044E088(&obj->pos, s, s, *(f32 *)(s + 0x48));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3F63A8 *)s));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(x));
    func_0040C2D0(&v[0], s + 0x20, obj->mC0);
    func_0040CB80(s + 0x10, &v[3]);
    func_0040C960(obj->mC0, &v[3], obj->mC0);
    func_0040C2D0(&v[1], s + 0x20, obj->mC0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v[0]));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v[1]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
    __asm__("sqc2 %1, %0" : "=m"(v[2]) : "j"(x), "j"(y));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v[2]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(y));
}
/* localdecomp:end func_003F63A8 */
