#include "common.h"

/* localdecomp:start func_00393690 */
typedef int Q_393690 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_393690;
typedef struct {
    V4_393690 v0;
    u8 pad10[36];
    s32 i34;
    u8 pad38[4];
    f32 f3C;
    u8 pad40[12];
    s32 i4C;
} P_393690;
typedef struct {
    u8 pad0[16];
    V4_393690 v10;
    u8 b20;
    u8 pad21[71];
    P_393690 *p68;
} O_393690;
typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[238];
} S_393690;
typedef struct {
    u8 pad0[32];
    f32 f20;
    u8 pad24[4];
    s32 i28;
    s32 i2C;
} E_393690;

extern s32 D_001DFBC0;
extern E_393690 D_001E2AC0;
extern u8 D_0014263F[];
extern S_393690 D_002C5640[];
extern s32 D_001D673C;
extern V4_393690 D_001EAAA0;

extern s32 func_004C7670(void);
extern void func_004C6EC8(void *, void *);
extern void func_004C4AD8(s32, void *, s32);
extern void func_004C41E8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern void func_00393BC0(void *);
extern s32 func_0032FE90(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern u32 func_003FC730(void);
extern void func_00393E28(void *, s32);
extern f32 func_004408C0(f32, f32);
extern void *func_00301508(void *, s32, f32, f32);
extern void func_00438908(void *, s32, s32, s32);
extern void func_00441FB8(void *, s32, s32);
extern void func_004C4AB8(s32);
extern void func_00436220(void *);

void func_00393690(O_393690 *o) {
    P_393690 *p = o->p68;
    V4_393690 a;
    V4_393690 b;
    V4_393690 c;
    V4_393690 buf;
    Q_393690 x, y;
    s32 n;
    s32 flag;
    s32 lo;
    u32 k;
    void *r;
    V4_393690 *pos;

    if (func_004C7670() != 0) {
        func_004C6EC8(&o->v10, &o->v10);
    }
    switch (o->b20) {
    case 0:
        func_004C4AD8(p->i4C, p, 0);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v0));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
        pos = &o->v10;
        p->i34++;
        if (D_001DFBC0 % 3 == 0 && p->i34 > 10) {
            if (p->i34 == 12 || p->i34 == 13) {
                D_001E2AC0.f20 = 0.45f;
                D_001E2AC0.i28 = 25;
                D_001E2AC0.i2C = 0;
            }
            n = (D_002C5640 + *D_0014263F)->unk1;
            func_004C41E8(pos, &a);
            func_0040C0F0(&a, &a, -10.0f);
            func_0040C0F0(&b, p, -6.0f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(c) : "j"(x));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(c));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
            if (func_003F8448(&c, &a, 0, o, 0) != 0) {
                flag = D_001D673C == 0;
                buf = D_001EAAA0;
                lo = n < 4;
                if (!lo) {
                    func_00393BC0(&buf);
                    func_0032FE90(&buf, 0.5f, 0, 2, 2, 2, 5, 2, 0, 0.0f, 0.0f, 2.0f,
                                  flag, 0, 0, 0, 0, 0, 0x10000, 0, 0xFF2E10, 0xFF8020, 0xFF7F40, 0xFF3020, 0xFF8F5F, 0xFF8020, 0x7FFF3030, 0x28FF8020, 0xFF8040, 0);
                    func_00443648(o, &buf, 0x210000, 0, 1, 0, 2.0f, p->f3C * 0.5f, 0.5f);
                } else {
                    func_0032FE90(&buf, 0.5f, 0, 2, 2, 2, 5, 2, 0, 0.0f, 0.0f, 2.0f,
                                  flag, 0, 0, 0, 0, 0, 0x10000, 0, 0xFF2E10, 0xFF8020, 0xFF7F40, 0xFF3020, 0xFF8F5F, 0xFF8020, 0x7FFF3030, 0x28FF8020, 0xFF8040, 0);
                    func_00443648(o, &buf, 0x210000, 0, 1, 0, 2.0f, p->f3C * 0.5f, 0.5f);
                }
                k = func_003FC730();
                if (k >= 2 && k != 11) {
                    func_00393E28(&buf, !lo);
                }
                r = func_00301508(&buf, 5, func_004408C0(3.5f, 4.5f), 1.04f);
                if (r != 0) {
                    if (!lo) {
                        func_00438908(r, 64, 16, 255);
                    } else {
                        func_00438908(r, 16, 16, 255);
                    }
                }
            }
        }
        if (p->i34 >= 41 || o->v10.x < 2.0f || 1021.0f < o->v10.x || o->v10.y < 2.0f || 1021.0f < o->v10.y
            || o->v10.z < 2.0f || 1021.0f < o->v10.z) {
            func_00441FB8(o, 1, -1);
        }
        break;
    case 1:
        func_004C4AB8(p->i4C);
        func_00436220(o);
        break;
    }
}
/* localdecomp:end func_00393690 */
