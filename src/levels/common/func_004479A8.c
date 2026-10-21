#include "common.h"

/* localdecomp:start func_004479A8 */
typedef struct {
    s16 cur;
    s16 flag;
    u8 s0, s1, s2;
    u8 e0, e1, e2;
    u8 pad[2];
    s16 total;
    s16 total2;
} Fade004479A8;

extern s32 func_0040BAC0(Fade004479A8 *p);
extern void func_00438908(void *obj, s32 r, s32 g, s32 b);

void func_004479A8(void *obj, Fade004479A8 *p) {
    s32 r, g, b;
    float t;
    if (p->cur == 0) return;
    if (func_0040BAC0(p)) {
        if (p->flag) {
            func_00438908(obj, p->s0, p->s1, p->s2);
            return;
        }
        p->flag = 1;
        p->cur = p->total2;
    }
    if (p->flag == 0) {
        t = ((float)p->total - (float)p->cur) / (float)p->total;
        if (p->e0) r = (float)p->s0 + (float)(p->e0 - p->s0) * t; else r = p->s0;
        if (p->e1) g = (float)p->s1 + (float)(p->e1 - p->s1) * t; else g = p->s1;
        if (p->e2) b = (float)p->s2 + (float)(p->e2 - p->s2) * t; else b = p->s2;
    } else {
        t = ((float)p->total2 - (float)p->cur) / (float)p->total2;
        if (p->e0) r = (float)p->e0 + (float)(p->s0 - p->e0) * t; else r = p->s0;
        if (p->e1) g = (float)p->e1 + (float)(p->s1 - p->e1) * t; else g = p->s1;
        if (p->e2) b = (float)p->e2 + (float)(p->s2 - p->e2) * t; else b = p->s2;
    }
    func_00438908(obj, r, g, b);
}
/* localdecomp:end func_004479A8 */
