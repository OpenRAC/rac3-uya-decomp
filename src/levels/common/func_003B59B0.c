#include "common.h"

/* localdecomp:start func_003B59B0 */
typedef struct {
    void (*f0)(void *, s32);
    u8 pad4[16];
    void (*f20)(void *, u8 *);
} Cls_003B59B0;

extern u8 *D_001E009C;
extern Cls_003B59B0 *func_00326898(void);
extern void *func_00326510(s32);
extern void func_003B5048(void *, void *, s32);

s32 func_003B59B0(void *a0, s32 *a1) {
    Cls_003B59B0 *c = func_00326898();
    u8 *e = D_001E009C + (a1[27] << 8);
    void *o;
    s32 i;
    for (i = 3; i >= 0; i--) {
        a1[40 + i] = -1;
    }
    o = func_00326510(a1[0]);
    if (o == 0) {
        return 0;
    }
    c->f20(o, e);
    func_003B5048(a0, o, 0);
    c->f0(o, 0);
    a1[48]++;
    return 1;
}
/* localdecomp:end func_003B59B0 */
