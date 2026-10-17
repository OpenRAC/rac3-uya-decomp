#include "common.h"

typedef struct S_61AEB0 S_61AEB0;

typedef struct {
    u8 pad[12];
    void (*fn)(S_61AEB0 *);
} V_61AEB0;

struct S_61AEB0 {
    u8 pad[12];
    S_61AEB0 *next;
    u8 pad2[4];
    V_61AEB0 *vt;
};

extern S_61AEB0 *D_0024CF40[];

void func_0061AEB0(void) {
    s32 i;
    S_61AEB0 *p;
    S_61AEB0 *q;

    for (i = 0; i < 8; i++) {
        p = D_0024CF40[i];
        while (p != 0) {
            q = p;
            p = p->next;
            q->vt->fn(q);
        }
    }
}
