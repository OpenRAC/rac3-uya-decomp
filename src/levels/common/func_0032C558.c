#include "common.h"

/* localdecomp:start func_0032C558 */
typedef struct {
    char pad0[0x24];
    int f36;
    char pad28[0x30 - 0x28];
} Ent48;

typedef struct {
    int a[64];
    int b[64];
    int c[8];
    int d544;
    int d548;
    int d552;
} State;

extern Ent48 D_00277110[];
extern State D_00276EE0;

void func_0032C558(void) {
    int i;

    for (i = 99; i >= 0; i--) {
        D_00277110[i].f36 = 0;
    }
    D_00276EE0.d552 = 5;
    D_00276EE0.d548 = 0;
    D_00276EE0.d544 = 0;
    for (i = 0; i < 64; i++) {
        D_00276EE0.a[i] = 0;
        D_00276EE0.b[i] = 0;
    }
    for (i = 7; i >= 0; i--) {
        D_00276EE0.c[i] = 0;
    }
}
/* localdecomp:end func_0032C558 */
