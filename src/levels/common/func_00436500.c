#include "common.h"

/* localdecomp:start func_00436500 */
typedef struct {
    u8 pad0[4];
    s16 h4;
} S_436500b;

typedef struct {
    u8 pad0[0x40];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    f32 f44;
    u8 pad48[0x58 - 0x48];
    S_436500b *p58;
    S_436500b *p5C;
} S_436500;

f32 func_00436500(S_436500 *s) {
    S_436500b *a;
    f32 t;

    if (s->b42 != 255) {
        a = s->p58;
    } else {
        a = s->p5C;
    }
    t = s->f44;
    if (t == 0.0f) {
        return a->h4 * 0.0625f;
    }
    if (s->b42 != s->b43 || s->b40 > s->b41) {
        return a->h4 * 0.0625f + t;
    }
    return (a->h4 * (1.0f - t) + s->p5C->h4 * t) * 0.0625f;
}
/* localdecomp:end func_00436500 */
