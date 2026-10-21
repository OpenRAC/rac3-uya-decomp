#include "common.h"

typedef int u128_0030B160 __attribute__((mode(TI)));

typedef struct {
    char pad0[0x4C];
    float f4C;
    char pad50[0x58 - 0x50];
    int count;
} Owner0030B160;

typedef struct {
    char pad0[0x68];
    Owner0030B160 *owner;
} Obj0030B160;

typedef struct {
    u128_0030B160 q0;
    u128_0030B160 q1;
    char pad20[0x40 - 0x20];
    float v40[4];
    float a[3];
    float b[3];
    float c[3];
    float d[3];
    float e[3];
    float f[3];
    int x98;
    int x9C;
    Obj0030B160 *obj;
    char padA4[0xB0 - 0xA4];
} Ent0030B160;

extern Ent0030B160 D_00271070[];
extern float func_004408C0(float, float);
extern float func_00440918(float, float);
extern float func_00440978(void);
extern void func_00440CF8(float *, float, float, float);

/* localdecomp:start func_0030B160 */
void func_0030B160(Obj0030B160 *obj, int arg1)
{
    Owner0030B160 *owner = obj->owner;
    Ent0030B160 *base = D_00271070;
    int i;

    for (i = 0; i < 16; i++) {
        Ent0030B160 *e = &base[i];
        if (e->obj == 0) {
            float r;
            e->obj = obj;
            owner->count++;
            e->a[0] = func_004408C0(-3.1415927f, 3.1415927f);
            e->a[1] = func_004408C0(-3.1415927f, 3.1415927f);
            e->a[2] = func_004408C0(-3.1415927f, 3.1415927f);
            e->d[0] = func_004408C0(-3.1415927f, 3.1415927f);
            e->d[1] = func_004408C0(-3.1415927f, 3.1415927f);
            e->d[2] = func_004408C0(-3.1415927f, 3.1415927f);
            e->b[0] = func_00440918(0.1f, 0.5f);
            e->b[1] = func_00440918(0.1f, 0.5f);
            e->b[2] = func_00440918(0.1f, 0.5f);
            e->e[0] = func_00440918(0.1f, 0.5f);
            e->e[1] = func_00440918(0.1f, 0.5f);
            e->e[2] = func_00440918(0.1f, 0.5f);
            e->c[0] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->c[1] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->c[2] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->f[0] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->f[1] = func_004408C0(3.25f, 4.75f) * 0.25f;
            e->f[2] = func_004408C0(3.25f, 4.75f) * 0.25f;
            __asm__("sq $0,%0" : "=m"(e->q0));
            __asm__("sq $0,%0" : "=m"(e->q1));
            e->x9C = arg1;
            e->x98 = arg1;
            r = func_00440978();
            func_00440CF8(e->v40, owner->f4C, r, func_00440978());
            return;
        }
    }
}
/* localdecomp:end func_0030B160 */
