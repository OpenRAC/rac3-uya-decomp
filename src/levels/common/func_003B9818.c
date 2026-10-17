#include "common.h"

typedef int q128 __attribute__((mode(TI)));

typedef struct Moby {
    char pad0[0x10];
    q128 pos;
    unsigned char state;
    char pad21[0x30 - 0x21];
    unsigned char b48;
    unsigned char b49;
    unsigned short h50;
    char pad34[0x38 - 0x34];
    unsigned long d56;
    char pad40[0xB8 - 0x40];
    struct Moby *parent;
} Moby;

extern Moby *func_004452B0(int, int);
extern void func_00451098(Moby *, int, int, int);
extern void func_00448A30(Moby *);

Moby *func_003B9818(Moby *src) {
    Moby *m = func_004452B0(6455, 128);

    if (m != 0) {
        m->parent = src;
        m->b48 = src->b48;
        m->h50 = src->h50;
        m->b49 = src->b49;
        m->state = 1;
        m->d56 = src->d56;
        m->pos = src->pos;
        func_00451098(m, 0, 0, 0);
        func_00448A30(m);
    }
    return m;
}
