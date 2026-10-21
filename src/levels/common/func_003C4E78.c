#include "common.h"

/* localdecomp:start func_003C4E78 */
typedef struct {
    u8 pad0[257];
    u8 unk101;
    u8 pad102[1724 - 258];
    s32 unk6BC;
} V3C4E78;

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[104 - 33];
    V3C4E78 *pVars;
} M3C4E78;

extern s32 D_001DEE94;
extern s32 func_003C3E18(M3C4E78 *, V3C4E78 *);
extern void func_003C5E20(M3C4E78 *, V3C4E78 *, s32);
extern void func_00441FB8(M3C4E78 *, s32, s32);
extern void func_003C5670(M3C4E78 *, V3C4E78 *);
extern void func_003C3A10(M3C4E78 *, V3C4E78 *);

void func_003C4E78(M3C4E78 *m, s32 id, s32 b) {
    V3C4E78 *v = m->pVars;
    s32 old;

    if (id < 0) {
        id = func_003C3E18(m, v);
    }
    old = v->unk6BC;
    v->unk6BC = id;
    D_001DEE94 = id;
    v->unk101 = b;
    func_003C5E20(m, v, id != old);
    if ((u32)(m->state - 4) >= 2) {
        func_00441FB8(m, 3, -1);
        func_003C5670(m, v);
        func_003C3A10(m, v);
    }
}
/* localdecomp:end func_003C4E78 */
