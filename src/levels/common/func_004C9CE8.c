#include "common.h"

extern void *func_004C9B50();

typedef struct {
    s32 *p0; s32 *p4; s32 *p8; s32 *pC;
    u8 sub10[0x3C]; u8 sub4C[0x3C]; u8 b88; u8 pad89[0x188 - 0x89];
    s32 f188, f18C, f190; u8 pad194[4]; s32 f198; u8 pad19C[8];
    s32 f1A4, f1A8, f1AC; u8 pad1B0[4]; s32 f1B4; u8 f1B8[0x78];
} O_3A6A00;
extern s32 D_001D67C8;
extern u8 D_001DB3D0[], D_001DB3E0[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_0051DC40(s32, s32);
extern void func_004C8E78();
extern void func_004C9050(u8 *, u8 *, s32);
extern void func_004C9080(void *, f32);
extern void func_004C8B28(void *, s32);
extern s32 func_004C8AE0(void *);
void func_004C9CE8(O_3A6A00 *o, s32 a) {
    s32 *t;
    o->b88 = 0;
    o->f18C = 0;
    o->f188 = 0;
    o->f1A8 = 0;
    o->f1A4 = 1;
    o->f1AC = 0;
    o->f1B4 = 0x28;
    o->f190 = 1;
    func_0011A264((s32)o->f1B8, 0, 0x78);
    if (a != 0) {
        {
            s32 *t0 = (s32 *)func_0051DC40(0x10, (s32)func_004C9B50(a));
            ((f32 *)t0)[0] = 255.0f;
            ((f32 *)t0)[1] = 108.0f;
            t0[2] = 0;
            t0[3] = 0;
            o->p0 = t0;
        }
        {
            s32 *t1 = (s32 *)func_0051DC40(0x10, (s32)func_004C9B50(a));
            ((f32 *)t1)[0] = 0.0f;
            ((f32 *)t1)[1] = 0.0f;
            t1[0] = 0x600E5092;
            t1[2] = 0;
            t1[3] = 0;
            o->p8 = t1;
        }
        {
            s32 *t2 = (s32 *)func_0051DC40(0x10, (s32)func_004C9B50(a));
            o->p4 = t2;
            t2[1] = 0;
            t2[2] = 0;
            t2[3] = 0;
            t2[0] = 0;
        }
        {
            s32 *t3 = (s32 *)func_0051DC40(0x10, (s32)func_004C9B50(a));
            o->pC = t3;
            t3[1] = 0;
            t3[2] = 0;
            t3[3] = 0;
            t3[0] = 0;
        }
    }
    func_004C8E78(o->sub10, D_001DB3D0, a);
    func_004C9050(o->sub10, (u8 *)D_001D67C8 + 0x7090, 0xC);
    func_004C9080(o->sub10, 0.02f);
    func_004C8B28(o->sub10, 1);
    *(s32 *)func_004C8AE0(o->sub10) = 0x332299DE;
    func_004C8E78(o->sub4C, D_001DB3E0, a);
    func_004C9050(o->sub4C, (u8 *)D_001D67C8 + 0x7090, 0xD);
    func_004C8B28(o->sub4C, 1);
    *(s32 *)func_004C8AE0(o->sub4C) = 0x332299DE;
    *o->pC = 0x8066CCFF;
    o->f198 = 0;
    *o->p4 = 0;
}
