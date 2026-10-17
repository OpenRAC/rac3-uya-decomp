#include "common.h"

typedef struct {
    char pad0[0x24];
    int w36;
} Vars;

typedef struct Moby {
    char pad0[0x20];
    unsigned char state;
    char pad21[0x68 - 0x21];
    Vars *vars;
    char pad6C[0xAA - 0x6C];
    short oClass;
    char padAC[0x100 - 0xAC];
} Moby;

extern Moby *D_001DFA20;
extern Moby *D_001DFA24;

void func_003AC310(void) {
    Moby *m;
    int state;
    short oClass;

    for (m = D_001DFA20; m <= D_001DFA24; m++) {
        if (m == 0) {
            continue;
        }
        state = m->state;
        if (state == 254) {
            continue;
        }
        if (state == 255) {
            continue;
        }
        oClass = m->oClass;
        if (oClass == 7172 || oClass == 7174) {
            m->state = 1;
            if (oClass == 7172) {
                m->vars->w36 += 3;
            }
        }
    }
}
