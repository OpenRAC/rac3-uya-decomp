#include "common.h"

/* localdecomp:start func_00523248 */
typedef int Q_523248 __attribute__((mode(TI)));

typedef struct {
    Q_523248 a;
    Q_523248 b;
    u8 pad20[0x10];
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
} E_523248;

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[8];
    s32 f30;
    s32 f34;
    s32 f38;
    u8 pad3c[0x20];
    E_523248 *f5C;
} M_523248;

extern void func_005FCE18(s32);
extern s32 func_005FCD98(u8 *, E_523248 *, f32, f32, f32);

void func_00523248(u8 *self, Q_523248 *a, Q_523248 *b, s32 c) {
    M_523248 *m = *(M_523248 **)(self + 0x68);
    E_523248 *e = &m->f5C[m->f24];
    s32 n;

    e->a = *a;
    e->b = *b;
    if (e->f38 >= 0) {
        func_005FCE18(e->f38);
    }
    e->f38 = func_005FCD98(self, e, 1.0f, 1.0f, 1.0f);
    e->f30 = c;
    e->f3C = 1;
    e->f34 = 0;
    n = m->f24;
    m->f38 = n;
    m->f24 = n + 1;
    if (n + 1 >= 35) {
        m->f30 = 1;
        m->f24 = 0;
    } else if (m->f30 != 1) {
        m->f34++;
    }
}
/* localdecomp:end func_00523248 */
