#include "common.h"

/* localdecomp:start func_0045FEC8 */
typedef int V128_0045FEC8 __attribute__((mode(TI)));
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    u16 h10;
    u16 h12;
    u16 h14;
    s16 h16;
    s16 h18;
} Q_0045FEC8;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    u16 hA;
    s32 wC;
    V128_0045FEC8 v10;
    Q_0045FEC8 q;
} Node_0045FEC8;
typedef struct {
    u8 pad[0xC];
    float fC;
} Src_0045FEC8;
extern u8 *D_00221174[];
extern u8 *D_00221118[];
extern Node_0045FEC8 *func_0045E438(s32);
extern float func_004408C0(float, float);
extern void func_0044ADB0(void *, void *);
extern void func_0044AEB8(void *, void *);
Node_0045FEC8 *func_0045FEC8(V128_0045FEC8 *a0, Src_0045FEC8 *a1, Src_0045FEC8 *a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8) {
    V128_0045FEC8 va;
    V128_0045FEC8 vb;
    Node_0045FEC8 *p;
    Q_0045FEC8 *q;
    s32 *r;
    p = func_0045E438(2);
    if (p != 0) {
        p->v10 = *a0;
        p->wC = 0;
        p->w4 = a3;
        p->b1 = 0;
        p->b9 = 0x44;
        p->b3 = 0x44;
        p->b8 = (s32)func_004408C0(*(float *)&p->wC, 255.0f);
        if (a8 == -1) {
            p->b2 = *D_00221174[0];
        } else {
            p->b2 = *D_00221118[a8 & 0xFFFF];
            if (a8 & 0x10000) {
                p->b3 = 0x48;
            }
        }
        p->hA = a5;
        q = &p->q;
        r = &p->q.w4;
        q->h16 = (s32)(a1->fC * 210000.0f / 1000.0f);
        q->h18 = (s32)(a2->fC * 210000.0f / 1000.0f);
        func_0044ADB0(a1, q);
        func_0044ADB0(a2, r);
        func_0044AEB8(&va, q);
        func_0044AEB8(&vb, r);
        q->w8 = a3;
        q->wC = a4;
        q->h10 = a5;
        q->h12 = a6;
        q->h14 = a7;
    }
    return p;
}
/* localdecomp:end func_0045FEC8 */
