#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004F02A0;
typedef struct { f32 m[16]; } __attribute__((aligned(16))) M_004F02A0;
typedef struct {
    u8 pad[240];
    u8 mat[64];
} C_004F02A0;
extern C_004F02A0 *D_001A71A0[];
extern void func_0040C658(void *, void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
extern f32 func_0040C490(f32, f32);
/* localdecomp:start func_004F02A0 */
void func_004F02A0(V4_004F02A0 *in, f32 *out) {
    M_004F02A0 m0, m1;
    V4_004F02A0 v;
    f32 sq;
    v = *in;
    func_0040C658(&m0, D_001A71A0[0]->mat);
    func_0040C8E0(&m1, &m0);
    func_0040C2F8(&v, &v, &m1);
    __asm__("sqrt.s %0, %1" : "=f"(sq) : "f"(v.x * v.x + v.z * v.z));
    out[0] = func_0040C490(sq, v.y);
    out[1] = -func_0040C490(v.z, v.x);
}
/* localdecomp:end func_004F02A0 */
