#include "common.h"

typedef struct Node006699B0 {
    u8 pad[128];
    struct Node006699B0 *prev;
    struct Node006699B0 *next;
} Node006699B0;

extern Node006699B0 *D_0024D068;
extern Node006699B0 *D_0024D06C;
extern Node006699B0 *D_001E17DC;

Node006699B0 *func_006699B0(void) {
    Node006699B0 *n = D_0024D068;
    Node006699B0 *h;
    if (n != 0 && n->next != 0) {
        D_0024D068 = n->next;
        h = D_0024D06C;
        n->next->prev = 0;
        n->prev = 0;
        n->next = h;
        if (h != 0) {
            h->prev = n;
        }
        D_001E17DC = n;
        return n;
    }
    return 0;
}
