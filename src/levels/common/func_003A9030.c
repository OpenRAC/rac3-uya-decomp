#include "common.h"

/* localdecomp:start func_003A9030 */
typedef struct { u8 pad0[0x10]; s32 f10; } T_3A9030;
typedef struct { u8 pad0[0x23]; u8 f23; T_3A9030 *f24; u8 pad28[0xC]; u16 f34; u8 pad36[0x62]; s32 f98; } M_3A9030;
typedef struct { u8 pad0[0x10]; u8 f10[0x10]; s32 f20; s32 f24; s16 f28; s16 f2A; s16 f2C; u8 f2E; u8 f2F; u8 f30; } V_3A9030;
typedef struct { u8 pad0[0x68]; V_3A9030 *f68; u8 pad6C[0x4C]; M_3A9030 *fB8; } O_3A9030;
extern void func_003DFEF0(M_3A9030 *m, s16 *a, s16 *b, V_3A9030 *v, u8 *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0047D488(s32 a, s32 b, O_3A9030 *o);
extern void func_0040E0A0(O_3A9030 *o);

void func_003A9030(O_3A9030 *o) {
    V_3A9030 *v = o->f68;
    if (v->f30 != 0 && v->f28 == 1) {
        M_3A9030 *m = o->fB8;
        m->f23 = 0x80;
        m->f34 = (m->f34 | 1) & ~2;
        func_0047D488(1, 0, o);
        func_0040E0A0(o);
    } else if (v->f28 == 2) {
        M_3A9030 *m = o->fB8;
        m->f34 = (m->f34 & 0xFFBC) | 0x1000;
        m->f98 = m->f24->f10;
        func_0047D488(0, 0, o);
        func_0040E0A0(o);
    } else {
        func_003DFEF0(o->fB8, &v->f2A, &v->f28, v, v->f10, v->f2E, v->f2F, v->f2C, v->f20, v->f24);
    }
}
/* localdecomp:end func_003A9030 */
