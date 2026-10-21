#include "common.h"

/* localdecomp:start func_003D2DC8 */
typedef int Q_3D2DC8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D2DC8;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P_3D2DC8;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[68];
    s16 h70;
    u8 pad72[168];
} S_3D2DC8;
typedef struct {
    u8 pad0[16];
    V4_3D2DC8 pos;
    u8 pad32[152];
    struct O_3D2DC8 *p184;
    u8 b188;
} O_3D2DC8;

extern s32 D_001D66B0;
extern u8 *D_00221288[];
extern u8 D_001A4C60[];
extern u8 D_001425C0[];
extern S_3D2DC8 D_002C5640[];
extern volatile s32 D_001DFDB8;
extern s32 func_00440848(s32);
extern f32 func_00440918(f32, f32);
extern P_3D2DC8 *func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00440B30(void *, f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_0046FE70(void *, void *, s32, f32);
extern f32 func_0040BFE8(void *, void *);
extern s32 func_004166F8(s32);
extern void func_004C5910(s32, s32);
extern void func_00416CC8(s32);
extern void func_00416640(s32, s32);
extern void func_00390208(void);
extern void func_00436220(void *);

void func_003D2DC8(O_3D2DC8 *obj) {
    V4_3D2DC8 pos, buf, w, d;
    Q_3D2DC8 x, y, r;
    P_3D2DC8 *p;
    s32 id, n;
    S_3D2DC8 *e;
    V4_3D2DC8 *b;
    f32 sc = 105000.0f;

    if (obj->p184) {
        obj->pos = ((O_3D2DC8 *)obj->p184)->pos;
    }
    pos = obj->pos;
    pos.z += 0.5f;
    if (func_00440848(2)) {
        n = func_00440918(1.0f, -1.0f);
        p = func_00466F98(&pos, &D_001D66B0, 15, 6, 0x409020, n,
                          420000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (p != 0) {
            p->b2 = D_00221288[0][1];
        }
    }
    buf.x = pos.x + func_00440918(0.0f, 0.04f);
    buf.y = pos.y + func_00440918(0.0f, 0.04f);
    buf.z = pos.z + func_00440918(0.0f, 0.04f);
    b = &buf;
    n = func_00440918(1.0f, -1.0f);
    p = func_00466F98(b, &D_001D66B0, 15, 127, 0x408020, n,
                      sc * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
    if (p != 0) {
        p->b3 = func_00440848(2) ? 72 : 68;
        p->b2 = D_00221288[0][0];
    }
    func_00440B30(&w, 0.025f, 0.15f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(w));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(w) : "j"(r));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    func_0040C0F0(&d, &d, 0.01250000111758709f);
    func_0046FE70(&w, &d, 15, 1.0f);
    if (obj->b188) {
        if (func_0040BFE8(&obj->pos, D_001A4C60) < 10.0f) {
            id = *(s32 *)(D_001A4C60 + 4520);
            if (id != 9) {
                n = func_004166F8(id);
                e = D_002C5640;
                if (e[D_001425C0[id]].b1 != n) {
                    if (e[D_001425C0[id]].b1 == n - 1 && id != 127) {
                        D_001DFDB8 = 1;
                        func_004C5910(id, e[D_001425C0[id]].h70);
                        func_00416CC8(e[D_001425C0[id]].h70);
                        D_001DFDB8 = 0;
                    } else {
                        func_00416640(id, 0);
                        func_00416CC8(id);
                        func_00390208();
                    }
                    func_00436220(obj);
                }
            }
        }
    }
}
/* localdecomp:end func_003D2DC8 */
