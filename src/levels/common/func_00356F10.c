#include "common.h"

typedef struct {
    char pad0[72];
    f32 scale;
} Sub00356F10;

typedef struct {
    char pad0[544];
    char state[64];
    Sub00356F10 *sub;
    char pad264[288];
    s32 timer;
} Data00356F10;

typedef struct {
    char pad0[72];
    f32 scale;
    char pad4C[20];
    u8 flags;
    char pad61[7];
    Data00356F10 *data;
} Moby00356F10;

extern int func_00436340(Moby00356F10 *);
extern void func_00350C38(Moby00356F10 *, Data00356F10 *, int, int, int);
extern int func_003502D8(Moby00356F10 *, Data00356F10 *, void *);
extern void func_00425278(Moby00356F10 *, int, int);
extern void func_003518E8(Moby00356F10 *, Data00356F10 *);

int func_00356F10(Moby00356F10 *m)
{
    Data00356F10 *d = m->data;

    if (func_00436340(m)) {
        func_00350C38(m, d, 13, 0, 10);
        m->scale = 1.5f;
        d->sub->scale = 1.5f;
    }
    func_003502D8(m, d, d->state);
    if (m->flags & 2) {
        d->timer = 0;
        func_00350C38(m, d, 14, 0, 10);
        func_00425278(m, 26, -1);
        func_003518E8(m, d);
        return 1;
    }
    return 0;
}
