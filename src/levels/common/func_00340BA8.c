#include "common.h"

/* localdecomp:start func_00340BA8 */
typedef int Q_340BA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_340BA8;
typedef struct O_340BA8 {
    u8 pad0[16];
    V4_340BA8 pos;
    u8 pad32[20];
    u16 h52;
    u8 pad54[98];
    s32 i152;
    u8 pad156[36];
    u8 m192[16];
    u8 pad208[32];
    V4_340BA8 v240;
} O_340BA8;
typedef struct {
    u8 pad0[16];
    O_340BA8 *c[4];
    s32 a32[4];
    s32 a48[4];
    u32 a64[3];
    u32 a76[3];
} S_340BA8;
typedef struct {
    u8 pad0[16];
    V4_340BA8 pos;
    u8 pad32[16];
    u8 b48;
    u8 pad49[55];
    S_340BA8 *s;
    u8 pad108[76];
    O_340BA8 *o;
} E_340BA8;
extern E_340BA8 *func_00435E70(s32, s32);
extern s32 func_0044B550(void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0044ADB0(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_00447748(void *, void *);
extern void func_0040C638(void *, void *);
s32 func_00340BA8(O_340BA8 *obj, V4_340BA8 *p1, V4_340BA8 *p2, O_340BA8 **kids, s32 n) {
    E_340BA8 *e;
    S_340BA8 *s;
    V4_340BA8 buf[9];
    Q_340BA8 qa, qb;
    s32 i;

    e = func_00435E70(2491, 128);
    if (e != 0) {
    e->o = obj;
    e->b48 = 255;
    s = e->s;
    e->pos = *p1;
    s->c[0] = obj;
    s->a32[0] = obj->h52;
    s->a48[0] = func_0044B550(obj);
    func_0040C8E0(&buf[0], obj->m192);
    for (i = 0; i < n && i < 3; i++) {
        O_340BA8 *k = kids[i];
        if (k != 0) {
            s->c[i + 1] = k;
            s->a32[i + 1] = kids[i]->h52;
            s->a48[i + 1] = func_0044B550(kids[i]);
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(obj->pos));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(kids[i]->pos));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qa));
            __asm__("sqc2 %1, %0" : "=m"(buf[4]) : "j"(qb) : "memory");
            func_0040C2D0(&buf[4], &buf[4], &buf[0]);
            func_0044ADB0(&buf[4], &s->a64[i]);
            func_0040C960(&buf[5], &buf[0], kids[i]->m192);
            func_00447748(&buf[5], &buf[8]);
            func_0044ADB0(&buf[8], &s->a76[i]);
            kids[i]->h52 |= 0x102;
            kids[i]->h52 |= 1;
            *(u8 *)((u8 *)kids[i] + 49) = 0;
            kids[i]->i152 = 0;
        }
    }
    obj->pos = *p1;
    obj->v240 = *p2;
    func_0040C638(obj->m192, &obj->v240);
    obj->h52 |= 0x103;
    *(u8 *)((u8 *)obj + 49) = 0;
    obj->i152 = 0;
    return 1;
    }
    return 0;
}
/* localdecomp:end func_00340BA8 */
