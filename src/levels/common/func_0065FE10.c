#include "common.h"
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
extern N_65FE10 *D_001DAAE4;
extern void func_00660140(N_65FE10 *);
void func_0065FE10(N_65FE10 *n) {
    N_65FE10 *prev = 0;
    N_65FE10 *c = D_001DAAE4;
    while (c) {
        if (c == n) {
            if (prev == 0) {
                D_001DAAE4 = n->next;
            } else {
                prev->next = n->next;
            }
            n->next = 0;
            func_00660140(n);
            break;
        }
        prev = c;
        c = c->next;
    }
}
