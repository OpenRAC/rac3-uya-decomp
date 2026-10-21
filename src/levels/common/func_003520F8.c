#include "common.h"

/* localdecomp:start func_003520F8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q;
    float f10;
    s32 f14;
    s32 f18;
    float f1C;
} E_3520F8;
typedef struct {
    u8 pad0[0x20];
    s32 n;
    u8 pad24[0x14];
    float f38;
    float f3C;
    u8 pad40[0x20];
    E_3520F8 e[1];
} S_3520F8;
extern s32 func_00351E50(void *, S_3520F8 *, u128_t *, float);
extern float func_00418328(float, float);
extern float D_001DCFC4;
extern float D_001DCFC8;
s32 func_003520F8(void *a, S_3520F8 *s) {
    u128_t buf;
    s32 r;
    s32 i;
    E_3520F8 *e;
    r = func_00351E50(a, s, &buf, 1.0f);
    if (r != 0) {
        if (r == -1) {
            return 1;
        }
        for (i = 0; i < s->n; i++) {
            if (s->e[i].f14 == -1) {
                break;
            }
        }
        if (i < s->n) {
            e = &s->e[i];
            e->q = buf;
            e->f10 = func_00418328(s->f38, s->f3C);
            e->f14 = 0;
            e->f18 = 0;
            e->f1C = func_00418328(D_001DCFC4, D_001DCFC8);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003520F8 */
