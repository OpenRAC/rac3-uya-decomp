#include "common.h"

typedef struct {
    u8 pad0[0x40];
    u8 mtx[0x15];
    u8 alpha;
    u8 pad56[0x60 - 0x56];
} Elem_003D4478;

typedef struct {
    Elem_003D4478 elem[10];
    u8 pad[0x3C4 - 0x3C0];
    s16 h3C4;
    s16 h3C6;
    u8 pad3C8[0x3D0 - 0x3C8];
    u8 mode;
    u8 pad3D1;
    u8 count;
    u8 pad3D3[0x3D8 - 0x3D3];
    f32 w;
    f32 h;
    u8 pad3E0[0x3EC - 0x3E0];
    u32 color;
} Hdr_003D4478;

typedef struct {
    f32 v[4][4];
    u32 color[4];
    f32 uv[8];
    u8 pad[0x20];
} Quad_003D4478;

typedef struct {
    u8 pad[0x68];
    Hdr_003D4478 *data;
} Moby_003D4478;

extern s32 func_00440848(s32);
extern void func_004075A8(Quad_003D4478 *, s32, s32, s32);
extern void func_0040C638(void *, void *);
extern void func_003D4420(void *, void *, f32 *, f32, f32, f32);
extern void func_00405A58(Quad_003D4478 *, s32, s32);

void func_003D4478(Moby_003D4478 *moby) {
    Quad_003D4478 q;
    u8 mtx[48];
    Hdr_003D4478 *hdr;
    Elem_003D4478 *e;
    u32 color;
    s32 odd;
    s32 i;

    hdr = moby->data;
    for (i = 0; i < hdr->count && i < 10; i++) {
        e = &hdr->elem[i];
        odd = i % 2;
        q.uv[0] = 0.0f;
        q.uv[1] = 0.0f;
        q.uv[2] = 0.0f;
        q.uv[3] = 1.0f;
        q.uv[4] = 1.0f;
        q.uv[5] = 0.0f;
        q.uv[6] = 1.0f;
        q.uv[7] = 1.0f;
        switch (hdr->mode) {
        case 1:
            color = hdr->color;
            break;
        case 2:
            color = odd ? 0x7F00E7B9 : 0x7F297E38;
            break;
        case 3:
            func_00440848(2);
            color = 0x7F54F6D9;
            break;
        default:
            color = 0x7F808080;
            break;
        }
        color &= 0xFFFFFF;
        color += e->alpha << 24;
        q.color[3] = color;
        q.color[2] = color;
        q.color[1] = color;
        q.color[0] = color;
        func_004075A8(&q, odd ? hdr->h3C4 : hdr->h3C6, 0, 128);
        func_0040C638(mtx, hdr->elem[i].mtx);
        func_003D4420(e, mtx, q.v[0], 0.0f, hdr->w, -hdr->h);
        func_003D4420(e, mtx, q.v[1], 0.0f, hdr->w, hdr->h);
        func_003D4420(e, mtx, q.v[2], 0.0f, -hdr->w, -hdr->h);
        func_003D4420(e, mtx, q.v[3], 0.0f, -hdr->w, hdr->h);
        func_00405A58(&q, 0, 0);
    }
}
