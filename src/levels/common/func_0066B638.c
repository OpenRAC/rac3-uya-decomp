#include "common.h"

typedef struct Node0066B638 {
    u8 pad[32];
    struct Node0066B638 *prev;
    struct Node0066B638 *next;
} Node0066B638;

extern Node0066B638 *D_0024D078;
extern Node0066B638 *D_0024D07C;
extern Node0066B638 *D_001E17EC;

Node0066B638 *func_0066B638(void) {
    Node0066B638 *n = D_0024D078;
    Node0066B638 *h;
    if (n != 0 && n->next != 0) {
        D_0024D078 = n->next;
        h = D_0024D07C;
        n->next->prev = 0;
        n->prev = 0;
        n->next = h;
        if (h != 0) {
            h->prev = n;
        }
        D_001E17EC = n;
        return n;
    }
    return 0;
}
