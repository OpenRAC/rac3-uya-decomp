#include "common.h"

/* localdecomp:start func_0044B7F0 */
typedef int Q_44B7F0 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[62];
    Q_44B7F0 q64;
    Q_44B7F0 q80;
    Q_44B7F0 q96;
    f32 f112;
    u8 pad116[4];
    void *p120;
} S_44B7F0;
extern void func_004373D8(void *);
void func_0044B7F0(void *a, S_44B7F0 *s) {
    void *p = s->p120;
    if (p != 0 && p == a && s->b1 != 0) {
        func_004373D8(p);
    }
    __asm__("sq $0,%0" : "=m"(s->q96));
    __asm__("sq $0,%0" : "=m"(s->q64));
    __asm__("sq $0,%0" : "=m"(s->q80));
    s->b1 = 0;
    s->f112 = 1.0f;
}
/* localdecomp:end func_0044B7F0 */
