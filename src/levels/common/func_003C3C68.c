#include "common.h"

/* localdecomp:start func_003C3C68 */
typedef struct {
    u8 pad0[88];
    s32 a[6];
    s32 b[4];
    s32 c[4];
    u8 pad1[224];
    u8 d[16];
} Obj_003C3C68;

extern void func_0044C658(void *, s32);
extern void func_003C4428(void *, Obj_003C3C68 *);
extern void func_0045E580(s32);

void func_003C3C68(void *self, Obj_003C3C68 *o) {
    s32 i;

    func_0044C658(o->d, 0);
    func_003C4428(self, o);
    for (i = 0; i < 6; i++) {
        if (o->a[i] != 0) {
            func_0045E580(o->a[i]);
            o->a[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (o->b[i] != 0) {
            func_0045E580(o->b[i]);
            o->b[i] = 0;
        }
        if (o->c[i] != 0) {
            func_0045E580(o->c[i]);
            o->c[i] = 0;
        }
    }
}
/* localdecomp:end func_003C3C68 */
