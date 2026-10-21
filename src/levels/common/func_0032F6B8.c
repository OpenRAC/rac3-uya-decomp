#include "common.h"

/* localdecomp:start func_0032F6B8 */
typedef struct {
    float m[16];
    float f64[4];
    float f80[8];
    long l112;
    char pad78[0x80 - 0x78];
    long l128;
} Cam;

void func_0032F6B8(Cam *c) {
    c->l112 = 0;
    c->f80[0] = 0.0f;
    c->f80[1] = 0.0f;
    c->f80[2] = 1.0f;
    c->f80[3] = 0.0f;
    c->f80[4] = 0.0f;
    c->f80[5] = 1.0f;
    c->f80[6] = 1.0f;
    c->f80[7] = 1.0f;
    c->m[2] = -2.0f;
    c->m[6] = 2.0f;
    c->m[10] = -2.0f;
    c->m[14] = 2.0f;
    c->m[1] = -2.0f;
    c->m[9] = 2.0f;
    c->m[0] = 0.0f;
    c->m[4] = 0.0f;
    c->m[8] = 0.0f;
    c->m[12] = 0.0f;
    c->m[3] = 1.0f;
    c->m[7] = 1.0f;
    c->m[11] = 1.0f;
    c->l128 = 0xFF9000000260;
    c->m[5] = -2.0f;
    c->m[13] = 2.0f;
    c->m[15] = 1.0f;
}
/* localdecomp:end func_0032F6B8 */
