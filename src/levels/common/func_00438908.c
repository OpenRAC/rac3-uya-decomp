#include "common.h"

/* localdecomp:start func_00438908 */
typedef struct {
    u8 pad[0x38];
    unsigned long v;
} Obj_00438908;
void func_00438908(Obj_00438908 *p, unsigned long a, unsigned long b, unsigned long c) {
    unsigned long v = *(volatile unsigned long *)&p->v;
    unsigned long r = ((v << 32) >> 32) | (a << 32) | (b << 40) | (c << 48);
    __asm__ __volatile__("nop");
    p->v = r;
}
/* localdecomp:end func_00438908 */
