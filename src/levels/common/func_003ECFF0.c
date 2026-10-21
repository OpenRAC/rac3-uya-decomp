#include "common.h"

/* localdecomp:start func_003ECFF0 */
typedef int Q_3ECFF0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3ECFF0;
extern V4_3ECFF0 D_001E2A40;
extern u8 D_001A30B0[];
extern void func_0040C2D0(void *, void *, void *);
extern s32 func_0040BA90(void *);
extern s32 func_004A74A0(s32, s32, void *, s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440848(s32);
static __inline__ f32 ABS_3ECFF0(f32 x) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
void func_003ECFF0(u8 *p) {
    V4_3ECFF0 t0, t1, t2, t3, t4;
    Q_3ECFF0 a, b, c, d, e, g;
    u8 *r = p + 0x50;
    u8 *q;
    u8 *ent;
    f32 one = 1.0f;
    f32 neg, ux, vx, uy, vy, uz, vz;
    s32 idx;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001E2A40));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_3ECFF0 *)(p + 0x40)));
    t1.x = *(f32 *)(p + 0xC);
    t1.y = *(f32 *)(p + 0xC);
    t1.z = *(f32 *)(p + 0xC);
    q = *(u8 **)(p + 8);
    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(c));
    t0.w = 0;
    func_0040C2D0(&t2, &t0, r);
    func_0040C2D0(&t3, &t1, r);
    vx = ABS_3ECFF0(t2.x);
    ux = ABS_3ECFF0(t3.x);
    if (vx <= ux + one && (vy = ABS_3ECFF0(t2.y), uy = ABS_3ECFF0(t3.y), vy <= uy + one) && (vz = ABS_3ECFF0(t2.z), uz = ABS_3ECFF0(t3.z), vz <= uz + one)) {
        ent = D_001A30B0 + (*(s32 *)(q + 0x10) << 7);
        if (*(u8 **)(ent + 0x100) != p || ent[0xD0] == 0) {
            if (func_0040BA90(q + 0xC) != 0) {
                idx = func_004A74A0(*(s32 *)q, 0, p, 0x400);
                *(s32 *)(q + 0x10) = idx;
                if (idx != -1) {
                    neg = -1.0f;
                    t4.x = func_004408C0(neg, one);
                    t4.y = func_004408C0(neg, one);
                    t4.z = func_004408C0(neg, one);
                    func_0040C2D0(&t4, &t4, p + 0x10);
                    __asm__("lqc2 %0, %1" : "=j"(e) : "m"(*(V4_3ECFF0 *)(p + 0x40)));
                    __asm__("lqc2 %0, %1" : "=j"(d) : "m"(t4));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(g) : "j"(d), "j"(e));
                    __asm__("sqc2 %1, %0" : "=m"(t4) : "j"(g));
                    *(V4_3ECFF0 *)(D_001A30B0 + (*(s32 *)(q + 0x10) << 7) + 0xE0) = t4;
                }
                if (*(s32 *)(q + 8) > 0) {
                    s32 rr = func_00440848(*(s32 *)(q + 8) - *(s32 *)(q + 4));
                    *(s32 *)(q + 0xC) = (s32)((f32)(*(s32 *)(q + 4) + rr) * 60.0f);
                }
            } else {
                *(s32 *)(q + 0x10) = -1;
            }
        }
    }
}
/* localdecomp:end func_003ECFF0 */
