#include "common.h"

typedef struct Moby Moby;

typedef struct {
    char pad0[0x550];
    Moby *child;
} Vars;

struct Moby {
    char pad0[0x42];
    unsigned char anim;
    char pad43[0x48 - 0x43];
    float animSpeed;
    char pad4C[0x68 - 0x4C];
    Vars *vars;
};

extern void func_00441C78(Moby *, int, int, int);

void func_003C9350(Moby *m, int anim, int a2, int a3, float speed) {
    Vars *v = m->vars;

    if (m->anim != anim) {
        func_00441C78(m, anim, a2, a3);
        m->animSpeed = speed;
        if (v->child != 0) {
            func_00441C78(v->child, anim, a2, a3);
            v->child->animSpeed = speed;
        }
    }
}
