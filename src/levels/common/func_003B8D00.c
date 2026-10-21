#include "common.h"

/* localdecomp:start func_003B8D00 */
typedef int Q_3B8D00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B8D00;
typedef struct {
    u8 pad0[0x24];
    f32 weight;
    u8 pad28[8];
    s32 type;
    u8 pad34[0xC];
} E_3B8D00;
typedef struct {
    E_3B8D00 e[64];
    s32 n;
    s32 id;
} T_3B8D00;
extern f32 func_00418328(f32, f32);
extern void func_003B8EA0(E_3B8D00 *, V4_3B8D00 *, f32, void *);
extern void func_003B8F30(E_3B8D00 *, V4_3B8D00 *, f32, void *);
extern void func_003B9038(E_3B8D00 *, V4_3B8D00 *, f32, void *);
extern void func_003E4A38(V4_3B8D00 *, V4_3B8D00 *, void *);
void func_003B8D00(u8 *o, T_3B8D00 *t, V4_3B8D00 *out, void *arg, f32 f) {
    s32 found = 0;
    s32 i;
    f32 r;
    E_3B8D00 *e;
    Q_3B8D00 a, b, c;
    if (o != 0 && *(s16 *)(o + 0xAA) == t->id && t->n != 0) {
        i = 0;
        r = func_00418328(0.0f, 1.0f);
        for (; i < t->n && !found; i++) {
            e = &t->e[i];
            if (r <= e->weight) {
                found = 1;
                if (e->type == 1) {
                    func_003B8EA0(e, out, f, arg);
                }
                if (e->type == 2) {
                    func_003B8F30(e, out, f, arg);
                }
                if (e->type == 3) {
                    func_003B9038(e, out, f, arg);
                }
            } else {
                r -= e->weight;
            }
        }
        if (found) {
            func_003E4A38(out, out, o + 0xC0);
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_3B8D00 *)(o + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*out));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(c));
            return;
        }
    }
    __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(out));
}
/* localdecomp:end func_003B8D00 */
