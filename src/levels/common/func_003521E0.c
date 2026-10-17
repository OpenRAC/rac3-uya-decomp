#include "common.h"

typedef struct {
    f32 unk0;
    s32 pad[6];
} K3521E0;

typedef struct {
    f32 x;
    f32 y;
    s32 pad8[3];
    s32 frame;
    f32 t;
    f32 dt;
} E3521E0;

typedef struct {
    u8 pad0[32];
    s32 count;
    u8 pad24[12];
    f32 dx;
    f32 dy;
    u8 pad38[40];
    E3521E0 ents[1];
} S3521E0;

extern K3521E0 D_002B0ED0[];

void func_003521E0(s32 unused, S3521E0 *s) {
    s32 i;
    E3521E0 *e;

    for (i = 0, e = s->ents; i < s->count; i++, e++) {
        if (e->frame != -1) {
            e->t += e->dt;
            if (D_002B0ED0[e->frame].unk0 < e->t) {
                e->t -= D_002B0ED0[e->frame].unk0;
                e->frame++;
                if (e->frame >= 5) {
                    e->frame = -1;
                }
            }
            e->x += s->dx;
            e->y += s->dy;
        }
    }
}
