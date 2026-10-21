#include "common.h"

/* localdecomp:start func_0031A698 */
typedef int Q_31A698 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_31A698;
typedef struct { f32 u, v; } UV_31A698;
typedef struct { s16 a, b; } IX_31A698;
typedef struct {
    V4_31A698 v[4];
    u32 col[4];
    UV_31A698 uv[4];
    unsigned long tag[4];
} Quad_31A698;
typedef struct {
    Q_31A698 m[3];
    V4_31A698 pos;
} M_31A698;
typedef struct {
    u8 pad0[16];
    f32 x, y, z;
    u8 pad28[76];
    s32 *p104;
    u8 pad108[84];
    Q_31A698 m[3];
} O_31A698;
extern V4_31A698 D_002AD5F0[];
extern IX_31A698 D_002ADC30[][4];
extern UV_31A698 D_002ADF50[];
extern UV_31A698 D_002ADF54[];
extern V4_31A698 D_002AE280[];
extern V4_31A698 D_002AE5A0[];
extern V4_31A698 D_001E2A40;
extern unsigned long func_00401CD0(s32);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040BEF8(void *, void *);
extern void func_00405A58(void *, void *, s32);
void func_0031A698(O_31A698 *obj) {
    Quad_31A698 q;
    M_31A698 mt;
    M_31A698 *mp;
    V4_31A698 dir;
    V4_31A698 p;
    s32 *c;
    u32 col;
    s32 i, j;
    Q_31A698 x, y;

    c = obj->p104;
    q.tag[1] = func_00401CD0(5);
    q.tag[2] = 0xFF9000000260;
    q.tag[3] = 0x8000000048;
    mt.m[0] = obj->m[0];
    mt.m[1] = obj->m[1];
    mt.m[2] = obj->m[2];
    mt.pos.x = obj->x;
    mt.pos.y = obj->y;
    mt.pos.z = obj->z;
    q.tag[0] = 0;
    mt.pos.w = 1.0f;
    col = (*c << 24) | 0xFF0000;
    q.col[3] = col;
    q.col[2] = col;
    q.col[1] = col;
    q.col[0] = col;
    mp = &mt;
    for (i = 0; i < 50; i++) {
        func_0040BE90(&p, &D_002AE5A0[i], 1.0f);
        func_0040C2F8(&p, &p, &mt);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(x));
        func_0040C0F0(&dir, &dir, 1.0f);
        func_0040C2D0(&p, &D_002AE280[i], mp);
        func_0040BEF8(&dir, &p);
        for (j = 0; j < 4; j++) {
            V4_31A698 *s = &D_002AD5F0[D_002ADC30[i][j].a];
            s32 k = D_002ADC30[i][j].b;
            func_0040BE90(&q.v[j], s, 1.0f);
            q.uv[j].u = D_002ADF50[k].u;
            q.uv[j].v = D_002ADF54[k].u;
            if (s->z == 0.001432f) {
                q.col[j] = 0xFF0000;
            }
        }
        func_00405A58(&q, &mt, 0);
    }
}
/* localdecomp:end func_0031A698 */
