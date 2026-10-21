#include "common.h"

/* localdecomp:start func_003B4C58 */
typedef struct {
    u8 pad0[8];
    s32 (*f8)(void *);
    void (*f12)(void *);
} V_3B4C58;
typedef struct {
    u8 pad0[108];
    s32 i108;
} S_3B4C58;
typedef struct {
    u8 pad0[104];
    S_3B4C58 *s;
} O_3B4C58;
extern u8 *D_001E009C;
extern V_3B4C58 *func_00326898(void);
void func_003B4C58(O_3B4C58 *o) {
    s32 i = o->s->i108;
    V_3B4C58 *v;
    u8 *p;
    if (i != -1) {
        p = D_001E009C + (i << 8);
        v = func_00326898();
        if (v->f8(p) == 0) {
            v->f12(p);
        }
    }
}
/* localdecomp:end func_003B4C58 */
