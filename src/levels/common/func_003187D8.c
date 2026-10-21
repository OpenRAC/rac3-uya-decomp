#include "common.h"

/* localdecomp:start func_003187D8 */
typedef int Q_3187D8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3187D8;
typedef struct {
    V4_3187D8 v0;
    V4_3187D8 v10;
    u8 pad20[8];
    f32 f28;
    f32 f2C;
    s32 f30;
    s32 f34;
    u8 pad38[4];
    s32 f3C;
    s32 f40;
    s32 f44;
    u8 pad48[8];
} E_3187D8;
typedef struct {
    u8 pad[0x68];
    s32 *f68;
} O_3187D8;
typedef struct {
    u8 pad[0x25C0];
    s32 f25C0;
} S_1A4BE0;
extern E_3187D8 D_00272800[];
extern S_1A4BE0 D_001A4BE0;
extern void func_004C41E8(s32, V4_3187D8 *);
extern f32 func_0040CEC8(f32, f32);
extern void func_0040BE90(V4_3187D8 *, V4_3187D8 *, f32);
extern s32 func_0040BA90(s32 *);
void func_003187D8(O_3187D8 *obj) {
    V4_3187D8 t0;
    Q_3187D8 qa, qb;
    E_3187D8 *p;
    s32 i;
    s32 *cnt = obj->f68;
    for (i = 0; i < 64; i++) {
        p = &D_00272800[i];
        if (p->f44 == (s32)obj) {
            p->f34 = (s32)((f32)p->f30 * ((f32)p->f3C / (f32)p->f40));
            p->f2C = func_0040CEC8(p->f2C, p->f28);
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(p->v10));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(p->v0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(p->v0) : "j"(qa));
            func_004C41E8(D_001A4BE0.f25C0 + 0x10, &t0);
            func_0040BE90(&t0, &t0, -0.0009f);
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(p->v10));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(t0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qa));
            __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(qb));
            if (func_0040BA90(&p->f3C)) {
                if (p->f34 > 0) {
                    p->f34 = p->f34 - 1;
                } else {
                    p->f44 = 0;
                    (*cnt)--;
                }
            }
        }
    }
}
/* localdecomp:end func_003187D8 */
