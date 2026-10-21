#include "common.h"

/* localdecomp:start func_0032C980 */
typedef int Q_32C980 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_32C980;
typedef struct {
    V_32C980 p;
    V_32C980 q;
    u8 pad20[4];
    s32 id;
    u8 pad28[8];
} E_32C980;
extern E_32C980 D_00277110[100];
extern void func_0040C0F0(void *, void *, f32);
extern void func_0032D670(s32, void *, void *);
void func_0032C980(s32 id) {
    V_32C980 v;
    Q_32C980 x, y;
    s32 i;
    for (i = 0; i < 100; i++) {
        E_32C980 *e = &D_00277110[i];
        if (e->id == id) {
            func_0040C0F0(&v, &e->q, 2.1f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e->p));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
            func_0032D670(id, e, &v);
        }
    }
}
/* localdecomp:end func_0032C980 */
