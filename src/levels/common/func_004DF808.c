#include "common.h"

/* localdecomp:start func_004DF808 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 pad[8944];
    u128_t q[8];
    s32 i[8];
    f32 a[8];
    f32 b[8];
    s16 count;
} S_4DF808;

extern S_4DF808 D_001A4BE0;
extern void func_004DF4A0(void);

void func_004DF808(u128_t *v, s32 n, f32 x, f32 y) {
    S_4DF808 *s = &D_001A4BE0;

    if (s->count < 8) {
        s->q[s->count] = *v;
        s->i[s->count] = n;
        s->a[s->count] = x;
        s->b[s->count] = y;
        func_004DF4A0();
        s->count++;
    }
}
/* localdecomp:end func_004DF808 */
