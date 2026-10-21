#include "common.h"

/* localdecomp:start func_004E4E00 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    s32 count;
    s32 pad[3];
    Vec4 pts[1];
} Path4E4E00;

typedef struct {
    u8 pad0[12];
    f32 radius;
    Path4E4E00 *obj;
    s32 id;
    u8 pad1[8];
} Ent4E4E00;

typedef struct {
    u8 pad0[0x1F6];
    s16 h1F6;
    u8 pad1[0x25CC - 0x1F8];
    u32 w25CC;
    u8 pad2[0x25E4 - 0x25D0];
    u8 b25E4;
} G4E4E00;

extern Ent4E4E00 *D_001DFD10;
extern s32 D_001DFD14;
extern G4E4E00 D_001A4BE0;
extern f32 func_0040BFB0(void *, void *);
extern f32 func_0040BFE8(void *, void *);
extern s32 func_00473340(Path4E4E00 *, Vec4 *, Vec4 *, s32 *, f32 *, s32, f32, f32, f32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);

s32 func_004E4E00(Vec4 *pos, Path4E4E00 **outObj, Vec4 *target, s32 *outA, f32 *outF, s32 *outId,
                  Path4E4E00 *exclude, Path4E4E00 *only, s32 noCheck) {
    Vec4 p;
    Vec4 t1;
    Vec4 t2;
    s32 a;
    f32 f;
    s32 i;
    s32 ok;
    f32 maxDist;
    f32 maxDz;
    Path4E4E00 *o;
    f32 d;
    f32 dz;
    Vec4 *pp;

    pp = &p;
    *pp = *pos;
    for (i = 0; i < D_001DFD14; i++) {
        if (exclude != 0 && D_001DFD10[i].obj == exclude) {
            continue;
        }
        if (D_001A4BE0.b25E4 == 5) {
            o = D_001DFD10[i].obj;
            if (o != 0) {
                f32 d = o->pts[0].x - o->pts[o->count - 1].x;
                if (__builtin_fabsf(d) < 0.1f) {
                    continue;
                }
            }
        }
        if (only != 0 && D_001DFD10[i].obj != only) {
            continue;
        }
        if (D_001DFD10[i].obj->count == 0) {
            continue;
        }
        d = func_0040BFB0(&D_001DFD10[i], pp);
        if (D_001DFD10[i].radius < d) {
            continue;
        }
        if (func_00473340(D_001DFD10[i].obj, pp, target, &a, &f, D_001DFD10[i].id, 12.0f, 10.0f, 0.0f) == 0) {
            continue;
        }
        maxDist = 0.9f;
        maxDz = 1.5f;
        if (D_001A4BE0.w25CC < 2) {
            maxDist = 0.3f;
        }
        if (D_001A4BE0.h1F6 != 0) {
            maxDist += 0.5f;
            maxDz = 10.0f;
        }
        ok = 1;
        if (noCheck == 0) {
            t1 = *target;
            t2 = t1;
            t1.z += 0.25f;
            t2.z -= 1.0f;
            if (func_003F8448(&t1, &t2, 2, 0, 0) == 0) {
                ok = 0;
            }
        }
        d = func_0040BFE8(pp, target);
        __asm__("abs.s %0, %1" : "=f"(dz) : "f"(pp->z - target->z));
        if (d < maxDist && dz < maxDz) {
            if (ok != 0) {
                *outObj = D_001DFD10[i].obj;
                *outA = a;
                *outF = f;
                *outId = D_001DFD10[i].id;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_004E4E00 */
