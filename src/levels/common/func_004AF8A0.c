#include "common.h"

/* localdecomp:start func_004AF8A0 */
typedef struct {
    s32 d;
    u8 v4[4];
    u16 id;
    s16 mode;
    s16 b2;
    s16 aa;
} E_4AF8A0;

typedef struct {
    s32 count;
    E_4AF8A0 e[1];
} T_4AF8A0;

extern void func_0041C590(void *, s32, s32);

void func_004AF8A0(s32 x, s32 id, u8 *obj, s32 mode, T_4AF8A0 *t) {
    s16 b2;
    s16 aa;
    s16 d;
    s32 i;
    E_4AF8A0 *e;
    E_4AF8A0 *f;

    b2 = *(s16 *)(obj + 0xB2);
    aa = *(s16 *)(obj + 0xAA);
    if (mode == 1) {
        d = x - (s32)obj;
    } else {
        d = x - *(u16 *)(obj + 0x68);
    }
    for (i = 0; i < t->count; i++) {
        f = &t->e[i];
        if (f->d == d && f->id == id && b2 == f->b2 && aa == f->aa) {
            mode = f->mode;
            if (mode != 0) {
                func_0041C590(f->v4, x, id);
                return;
            }
        }
    }
    e = &t->e[t->count++];
    e->d = d;
    func_0041C590(e->v4, x, id);
    e->id = id;
    e->mode = mode;
    e->b2 = b2;
    e->aa = aa;
}
/* localdecomp:end func_004AF8A0 */
