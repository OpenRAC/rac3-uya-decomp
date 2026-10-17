#include "common.h"

typedef struct S_0066BA18 { u8 pad[36]; struct S_0066BA18 *next; u8 pad2[48]; s32 id; } S_0066BA18;
extern S_0066BA18 *D_0024D07C[];

S_0066BA18 *func_0066BA18(s32 id) {
    S_0066BA18 *p = D_0024D07C[0];
    while (p != 0) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return 0;
}
