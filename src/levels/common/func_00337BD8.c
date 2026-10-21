#include "common.h"

typedef int Q_337BD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_337BD8;
typedef struct {
    u8 pad0[32];
    f32 x, y, z;
} S_337BD8;
typedef struct {
    u8 pad0[120];
    s16 h120;
} T_337BD8;
typedef struct {
    u8 pad0[104];
    T_337BD8 *p104;
} O_337BD8;
extern V4_337BD8 D_001E2A40;
extern V4_337BD8 D_001EAAA0;
extern S_337BD8 D_001EAA80;
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(void *, void *, f32);
extern void func_00462B40(void *, void *);
extern s32 func_00440878(s32, s32);
extern void func_00462FD0(void *, void *, s32, s32, s32, s32, f32);
extern void func_003378E0(void *, s32);

/* localdecomp:start func_00337BD8 */
void func_00337BD8(O_337BD8 *obj) {
    V4_337BD8 dir;
    V4_337BD8 pos;
    Q_337BD8 a, b, r;
    f32 pitch;
    f32 t;
    s32 i;

    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001E2A40));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001EAAA0));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(r));
    pitch = -func_0040C490(func_0040BF68(&dir), dir.z);
    func_0040C490(dir.x, dir.y);
    for (i = 19; i >= 0; i--) {
        Q_337BD8 p, q;
        t = func_0040CEC8(func_00440918(0.0f, 3.1415927f), pitch);
        func_00440CF8(&dir, 0.2f, func_0040CEC8(func_00440918(0.0f, 3.1415927f), pitch), t);
        func_0040BE90(&pos, &dir, func_004408C0(1.0f, 3.0f));
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(D_001EAAA0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(p) : "j"(p), "j"(q));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(p));
        func_00462B40(&pos, &dir);
    }
    for (i = 9; i >= 0; i--) {
        pos.x = D_001EAA80.x + func_00440918(0.0f, 0.1f);
        pos.y = D_001EAA80.y + func_00440918(0.0f, 0.1f);
        pos.z = D_001EAA80.z + func_00440918(0.0f, 0.1f);
        t = func_0040CEC8(func_00440918(0.0f, 3.1415927f), pitch);
        func_00440CF8(&dir, 0.05f, func_0040CEC8(func_00440918(0.0f, 3.1415927f), pitch), t);
        func_00462FD0(&pos, &dir, 0x4F007FFF, 0x1FFFFFFF, func_00440878(10, 20), 1, 20000.0f);
    }
    if (obj->p104->h120 == 40) {
        func_003378E0(&D_001EAAA0, 10);
    }
}
/* localdecomp:end func_00337BD8 */
