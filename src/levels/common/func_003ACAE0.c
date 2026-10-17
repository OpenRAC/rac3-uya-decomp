#include "common.h"

typedef struct {
    char pad0[912];
    s32 target;
    char pad394[26];
    u8 active;
} Data003ACAE0;

typedef struct {
    char pad0[67];
    u8 anim;
    char pad44[36];
    Data003ACAE0 *data;
} Moby003ACAE0;

extern void func_004220E8(Moby003ACAE0 *, int, int, int);
extern void func_00422428(Moby003ACAE0 *, int, int);

void func_003ACAE0(Moby003ACAE0 *m)
{
    Data003ACAE0 *d = m->data;

    if (d->active) {
        if (m->anim != 0)
            func_004220E8(m, 0, 0, 4);
        func_00422428(m, 16, -1);
    } else if (d->target != -1) {
        if (m->anim != 24)
            func_004220E8(m, 24, 0, 4);
        func_00422428(m, 10, -1);
    } else {
        if (m->anim != 26)
            func_004220E8(m, 26, 0, 9);
        func_00422428(m, 13, -1);
    }
}
