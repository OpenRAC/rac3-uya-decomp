#include "common.h"

typedef struct S_61BBB8 S_61BBB8;

typedef struct {
    u8 pad[16];
    void (*fn)(S_61BBB8 *);
} V_61BBB8;

struct S_61BBB8 {
    u8 pad[4];
    S_61BBB8 *next;
    u8 pad2[4];
    V_61BBB8 *vt;
};

extern S_61BBB8 *D_0024CFA0[];

void func_0061BBB8(void) {
    s32 i;
    S_61BBB8 *p;
    S_61BBB8 *q;

    for (i = 0; i < 8; i++) {
        p = D_0024CFA0[i];
        while (p != 0) {
            q = p;
            p = p->next;
            q->vt->fn(q);
        }
    }
}
