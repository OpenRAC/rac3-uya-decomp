#include "common.h"

/* localdecomp:start func_0063C408 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_0063C1A0(u8 *, s32);
extern void func_005A9628(u8 *, u8 *);

void func_0063C408(u8 *o) {
    u8 *p;
    u8 *q;
    u8 *r;
    if (*(s16 *)(o + 0x24A2) == 0) {
        q = o + 0x760;
        p = o;
        do {
            if (p[0x761] != 0) {
                r = func_0063C1A0(o, *(s16 *)(p + 0x802));
                if (r != 0) {
                    func_005A9628(r, q);
                }
            }
            __asm__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x7A0)));
            __asm__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x7C0)));
            *(f32 *)(p + 0x80C) = 1.0f;
            p += 0xB0;
            q += 0xB0;
        } while ((s32)p < (s32)(o + 0x840));
        *(s16 *)(o + 0x24A2) = 1;
    }
}
/* localdecomp:end func_0063C408 */
