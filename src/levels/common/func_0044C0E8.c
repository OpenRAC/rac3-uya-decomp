#include "common.h"

/* localdecomp:start func_0044C0E8 */
typedef int s128_44C0E8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x40]; void *p40; u8 pad44[0x4C - 0x44]; u8 b4C; } M_44C0E8;
extern void func_0040C960(void *, void *, void *);
extern void func_0040C638(void *, void *);
void func_0044C0E8(M_44C0E8 *m, void *a, void *out) {
    s128_44C0E8 t[3];
    s128_44C0E8 u[3];
    if (m->p40 == 0) {
        func_0040C960(out, a, m);
        return;
    }
    func_0040C638(t, m->p40);
    switch (m->b4C & 0xC0) {
    case 0x40:
        func_0040C960(u, t, m);
        func_0040C960(out, a, u);
        break;
    case 0x80:
        func_0040C960(u, m, t);
        func_0040C960(out, a, u);
        break;
    default:
        func_0040C960(u, a, m);
        func_0040C960(out, t, u);
        break;
    }
}
/* localdecomp:end func_0044C0E8 */
