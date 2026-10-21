#include "common.h"

/* localdecomp:start func_003252F0 */
typedef struct { u8 pad0[4]; void *next; void *f8; } Node_003252F0;
typedef struct { u8 pad0[8]; s32 (*test)(void *); } Cb_003252F0;
typedef struct {
    u8 pad0[48];
    s32 f30;
    u8 pad34[300];
    Cb_003252F0 *cb[16];
    u8 pad1A0[256];
    void *list[16];
} Obj_003252F0;
extern Node_003252F0 *func_00445F18(void *);
extern void func_003B4B70(void *, void *);
extern void func_00325E48(void *, Obj_003252F0 *, s32);
extern void func_003B1158(s32);
void func_003252F0(void *a, Obj_003252F0 *o) {
    s32 i;
    void *p;
    void *q;
    Cb_003252F0 *cb;
    Node_003252F0 *n;
    for (i = 0; i < 16; i++) {
        q = o->list[i];
        if (q != 0) {
            p = q;
            cb = o->cb[i];
            do {
                n = func_00445F18(p);
                if (cb->test(p) == 0) {
                    func_003B4B70(n->f8, p);
                }
                p = n->next;
            } while (p != 0);
            func_00325E48(a, o, i);
        }
    }
    func_003B1158(o->f30);
}
/* localdecomp:end func_003252F0 */
