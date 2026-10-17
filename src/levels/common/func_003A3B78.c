#include "common.h"

typedef struct {
    char pad0[0x1C8];
    int mode;
} Vars;

typedef struct {
    char pad0[0x10];
    float x;
    float y;
    float z;
    char pad1C[0x68 - 0x1C];
    Vars *vars;
} Moby;

typedef struct {
    char pad0[0x80];
    float pos[4];
} Player;

extern Player D_001A4BE0;
extern float D_001DEA34;
extern float D_001DEA38;
extern int func_003A38F8(Moby *, float *);

int func_003A3B78(Moby *m) {
    float range;

    if (m->vars->mode == 2) {
        range = D_001DEA34;
    } else {
        range = D_001DEA38;
    }
    if (__builtin_fabsf(m->x - D_001A4BE0.pos[0]) < range &&
        __builtin_fabsf(m->z - D_001A4BE0.pos[2]) < range &&
        func_003A38F8(m, D_001A4BE0.pos) != 0) {
        return 1;
    }
    return 0;
}
