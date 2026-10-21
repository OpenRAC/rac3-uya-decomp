#include "common.h"

/* localdecomp:start func_002F9A40 */
typedef int Q_2F9A40 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_2F9A40;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
} S_2F9A40;
typedef struct {
    u8 pad0[0x68];
    S_2F9A40 *p68;
    u8 pad6C[0xC];
    u32 f78;
} O_2F9A40;
extern void func_0040BA90(void *);
void func_002F9A40(O_2F9A40 *o) {
    S_2F9A40 *s = o->p68;
    V4_2F9A40 v;
    f32 t;
    *(Q_2F9A40 *)&v = 0;
    v.x = 128.0f;
    v.y = 128.0f;
    v.z = 128.0f;
    v.w = 255.0f;
    func_0040BA90(&s->f10);
    t = (f32)s->f10 / 30.0f;
    o->f78 = 0xFF000000 | ((s32)((v.z - 64.0f) * t + 64.0f) << 16) | ((s32)((v.y - 64.0f) * t + 64.0f) << 8) | (s32)((v.x - 255.0f) * t + 255.0f);
}
/* localdecomp:end func_002F9A40 */
