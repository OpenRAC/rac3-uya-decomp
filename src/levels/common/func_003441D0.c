#include "common.h"

/* localdecomp:start func_003441D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x50];
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5C;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    u8 pad6C[2];
    s16 h6E;
    f32 f70;
    f32 f74;
    u8 b78;
    u8 b79;
    u8 b7A;
    u8 b7B;
    u8 b7C;
    u8 pad7D;
    u16 h7E;
    u8 b80;
    u8 b81;
    u8 pad82[2];
    f32 f84;
    f32 f88;
} In_003441D0;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 b20;
    u8 pad21[0xB];
    f32 f2C;
    u8 b30;
    u8 pad31;
    u16 h32;
    u16 h34;
    u8 pad36[0x32];
    In_003441D0 *in;
    u8 pad6C[0x2A];
    s16 h96;
} Obj_003441D0;
extern s32 D_001DFFC0;
extern Obj_003441D0 *func_00435E70(s32, s32);
extern void func_0040C0F0(void *, s32, f32);
extern f32 func_00440978(void);
extern f32 func_00440918(f32, f32);
extern s32 func_004C4A18(void *, s32, f32, f32, f32);
extern void func_00439610(void *);
Obj_003441D0 *func_003441D0(u128_t *a0, s32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u16 a6, s32 a7, f32 f0, f32 f1, f32 f2, f32 f3, s32 s0, s32 s1) {
    Obj_003441D0 *p;
    In_003441D0 *q;

    if (D_001DFFC0 < 17) {
        return 0;
    }
    p = func_00435E70(0xA82, 0xC0);
    if (p != 0) {
        q = p->in;
        p->pos = *a0;
        func_0040C0F0(q, a1, f0 * 0.016666668f);
        p->b20 = 0;
        p->b30 = p->h32 = 0xFF;
        q->w50 = a7;
        q->w54 = 0;
        p->h34 |= 0x100;
        q->f60 = f0;
        q->f68 = f1;
        q->f70 = f2;
        q->b78 = a2;
        q->b79 = a3;
        q->b7A = a4;
        q->b7B = a5;
        q->f74 = f3;
        q->h7E = a6;
        q->w5C = 0;
        q->w58 = 0;
        q->b81 = s1;
        q->b80 = s0;
        p->f2C = s0 ? 0.025f : 0.015f;
        p->h96 = 0;
        q->f84 = func_00440978();
        q->f88 = func_00440918(3.0f, 5.0f);
        if (a7 == 0) {
            q->b7C = 1;
        } else {
            q->b7C = 0;
        }
        q->h6E = func_004C4A18(p, 0, 1.0f, 1.0f, 1.0f);
        func_00439610(p);
    }
    return p;
}
/* localdecomp:end func_003441D0 */
