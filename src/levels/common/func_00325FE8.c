#include "common.h"

typedef int Q_325FE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_325FE8;

typedef struct {
    u8 pad0[0x80];
    V4_325FE8 v80;
    u8 pad90[8];
    f32 f98;
} S_325FE8;

typedef struct {
    u8 pad0[0x30];
    V4_325FE8 v30;
    u8 pad40[0x30];
    V4_325FE8 v70;
} E_325FE8;

extern void func_003C1740(s32 a, V4_325FE8 *v);
extern void func_003C17B0(s32 a, V4_325FE8 *v);
extern void func_003E4590(V4_325FE8 *out, V4_325FE8 *a, V4_325FE8 *b, f32 t);
extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);
extern f32 func_003E5630(f32 a, f32 b);
extern f32 func_003E5678(f32 a, f32 b);
extern f32 func_0040E380(void);
extern S_325FE8 D_001A4BE0;
extern E_325FE8 *D_001DEB00;

void func_00325FE8(u8 *m) {
    V4_325FE8 pos;
    V4_325FE8 rot;
    V4_325FE8 r0;
    V4_325FE8 r1;
    s32 *v;
    f32 f;
    f32 t;
    f32 a;

    v = *(s32 **)(m + 0x68);
    if (m[0x42] == 1) {
        f = func_0040E380();
    } else {
        f = 170.0f;
    }
    t = f / 170.0f;
    if (v[1] == -1 || v[2] == -1) {
        Q_325FE8 x, y, r;
        S_325FE8 *d = &D_001A4BE0;
        a = func_003E5630(t * 0.6981317f - 0.34906584f, d->f98);
        pos.x = func_003E4B30(a) * 5.0f;
        pos.y = func_003E4B48(a) * 5.0f;
        *(s32 *)&pos.z = 0;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d->v80));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(r));
        {
            f32 pz = pos.z;
            __asm__("sq $0, %0" : "=m"(rot));
            pos.z = pz + 1.0f;
        }
        rot.z = func_003E5630(a, 3.14159f);
        rot.y = t * -0.17f;
    } else {
        func_003E4590(&pos, &D_001DEB00[v[1]].v30, &D_001DEB00[v[2]].v30, t);
        r0 = D_001DEB00[v[1]].v70;
        r1 = D_001DEB00[v[2]].v70;
        rot.z = func_003E5630(func_003E5678(r1.z, r0.z) * t, r0.z);
        rot.y = func_003E5630(func_003E5678(r1.y, r0.y) * t, r0.y);
        rot.x = func_003E5630(func_003E5678(r1.x, r0.x) * t, r0.x);
    }
    func_003C1740(0, &pos);
    func_003C17B0(0, &rot);
}
