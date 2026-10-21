#include "common.h"

/* localdecomp:start func_004C8E78 */
typedef struct {
    s32 pad0;
    f32 *scale;
    u8 pad8[24];
    s32 f32;
    s32 pad36;
    s32 *f40;
    s32 *f44;
    u8 pad48[8];
    u8 b56;
    u8 b57;
    u8 b58;
} Obj_004C8E78;
extern void func_004C8C60(Obj_004C8E78 *);
extern s32 func_004C9B50(s32);
extern s32 *func_0051DC40(s32, s32);
void func_004C8E78(Obj_004C8E78 *p) {
    s32 *q;
    s32 t;
    f32 *s;
    func_004C8C60(p);
    if (p->f32 != 0) {
        q = func_0051DC40(16, func_004C9B50(p->f32));
        p->f40 = q;
        t = p->f32;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[0] = 0;
        q = func_0051DC40(16, func_004C9B50(t));
        p->f44 = q;
        s = p->scale;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[0] = 0;
        s[0] = 1.0f;
        p->scale[1] = 1.0f;
        p->scale[2] = 1.0f;
    }
    p->b56 = 0;
    p->b57 = 0;
    p->b58 = 0;
}
/* localdecomp:end func_004C8E78 */
