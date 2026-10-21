#include "common.h"

/* localdecomp:start func_0031A3C8 */
typedef int Q_31A3C8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_31A3C8;
typedef struct { s16 a, b; } P_31A3C8;
typedef struct { f32 u, v; } UV_31A3C8;
typedef struct {
    V4_31A3C8 verts[4];
    u32 colors[4];
    UV_31A3C8 uv[4];
    unsigned long gif[4];
} Quad_31A3C8;
typedef struct {
    u8 pad0[16];
    V4_31A3C8 pos;
    u8 pad20[72];
    s32 *p104;
    u8 pad6C[84];
    V4_31A3C8 m[3];
} O_31A3C8;
extern V4_31A3C8 D_001E2A40;
extern V4_31A3C8 D_002AD2D0[];
extern P_31A3C8 D_002AC960[][4];
extern V4_31A3C8 D_002ACFB0[];
extern V4_31A3C8 D_002AC320[];
extern f32 D_002ACC80[];
extern f32 D_002ACC84[];
extern long func_00401CD0(s32);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_0040BEF8(void *, void *);
extern void func_00405A58(void *, void *, s32);
void func_0031A3C8(O_31A3C8 *obj) {
    s32 *p = obj->p104;
    Quad_31A3C8 q;
    V4_31A3C8 mtx[4];
    V4_31A3C8 *m;
    V4_31A3C8 dir;
    V4_31A3C8 pos;
    s32 i, j;
    u32 col;

    q.gif[1] = func_00401CD0(5);
    q.gif[2] = 0xFF9000000260;
    q.gif[3] = 0x8000000048;
    mtx[0] = obj->m[0];
    mtx[1] = obj->m[1];
    mtx[2] = obj->m[2];
    mtx[3].x = obj->pos.x;
    mtx[3].y = obj->pos.y;
    mtx[3].z = obj->pos.z;
    q.gif[0] = 0;
    mtx[3].w = 1.0f;
    col = (*p << 24) | 0xFF0000;
    q.colors[3] = col;
    q.colors[2] = col;
    q.colors[1] = col;
    q.colors[0] = col;
    m = mtx;
    for (i = 0; i < 50; i++) {
        Q_31A3C8 a, b, r;
        func_0040BE90(&pos, &D_002AD2D0[i], 1.0f);
        func_0040C2F8(&pos, &pos, mtx);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(r));
        func_0040C0F0(&dir, &dir, 1.0f);
        func_0040C2D0(&pos, &D_002ACFB0[i], m);
        func_0040BEF8(&dir, &pos);
        for (j = 0; j < 4; j++) {
            V4_31A3C8 *v = &D_002AC320[D_002AC960[i][j].a];
            s32 k = D_002AC960[i][j].b;
            func_0040BE90(&q.verts[j], v, 1.0f);
            q.uv[j].u = D_002ACC80[k * 2];
            q.uv[j].v = D_002ACC84[k * 2];
            if (v->z == -0.002112f) {
                q.colors[j] = 0xFF0000;
            }
        }
        func_00405A58(&q, mtx, 0);
    }
}
/* localdecomp:end func_0031A3C8 */
