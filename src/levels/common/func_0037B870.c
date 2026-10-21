#include "common.h"

/* localdecomp:start func_0037B870 */
typedef int Q_37B870 __attribute__((mode(TI)));
typedef struct {
    Q_37B870 q0;
    Q_37B870 q16;
    u8 pad32[32];
    u8 v64[16];
    f32 a[3];
    f32 b[3];
    f32 c[3];
    f32 d[3];
    f32 e[3];
    f32 f[3];
    s32 g152;
    s32 g156;
    void *owner;
    s32 id;
    u8 pad168[8];
} E_37B870;
typedef struct {
    u8 pad0[44];
    f32 f44;
    u8 pad48[32];
    s32 count;
    u8 pad84[60];
    E_37B870 ent[12];
} S_37B870;
typedef struct {
    u8 pad0[104];
    S_37B870 *s;
} O_37B870;
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_00440978(void);
extern void func_00440CF8(void *, f32, f32, f32);
void func_0037B870(O_37B870 *obj, s32 id, s32 v) {
    S_37B870 *s = obj->s;
    E_37B870 *e;
    s32 i;
    f32 r;
    u8 *v64;

    for (i = 0; i < 12; i++) {
        if (s->ent[i].id == id) {
            return;
        }
    }
    for (i = 0; i < 12; i++) {
        if (s->ent[i].owner == 0) {
            e = &s->ent[i];
            e->owner = obj;
            v64 = e->v64;
            e->id = id;
            s->count++;
            e->a[0] = func_004408C0(-3.1415927f, 3.1415927f);
            e->a[1] = func_004408C0(-3.1415927f, 3.1415927f);
            e->a[2] = func_004408C0(-3.1415927f, 3.1415927f);
            e->d[0] = func_004408C0(-3.1415927f, 3.1415927f);
            e->d[1] = func_004408C0(-3.1415927f, 3.1415927f);
            e->d[2] = func_004408C0(-3.1415927f, 3.1415927f);
            e->b[0] = func_00440918(0.2f, 0.5f) * 0.5f;
            e->b[1] = func_00440918(0.2f, 0.5f) * 0.5f;
            e->b[2] = func_00440918(0.2f, 0.5f) * 0.5f;
            e->e[0] = func_00440918(0.2f, 0.5f) * 0.5f;
            e->e[1] = func_00440918(0.2f, 0.5f) * 0.5f;
            e->e[2] = func_00440918(0.2f, 0.5f) * 0.5f;
            e->c[0] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->c[1] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->c[2] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->f[0] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->f[1] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->f[2] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->g156 = v;
            e->g152 = v;
            __asm__("sq $0,%0" : "=m"(e->q16));
            __asm__("sq $0,%0" : "=m"(e->q0));
            r = func_00440978();
            func_00440CF8(v64, s->f44, r, func_00440978());
            return;
        }
    }
}
/* localdecomp:end func_0037B870 */
