#include "common.h"

/* localdecomp:start func_0061BB00 */
typedef struct O_61BB00 {
    u32 id;
    s32 owner;
    struct O_61BB00 *prev;
} O_61BB00;

typedef struct N_61BB00 {
    u32 f0;
    struct N_61BB00 *next;
    struct N_61BB00 *prev;
} N_61BB00;

extern N_61BB00 *D_0024CFA0[8];
extern N_61BB00 *D_0024CFC0[8];
extern N_61BB00 *func_0061B9A0(u32);

N_61BB00 *func_0061BB00(u32 *key) {
    u32 id = *key;
    u32 k = (id >> 24) & 0xF;
    N_61BB00 *n = func_0061B9A0(id);
    N_61BB00 **head;
    N_61BB00 **freel;
    N_61BB00 *nx;

    if (n == 0) {
        return 0;
    }
    freel = &D_0024CFC0[k];
    head = &D_0024CFA0[k];
    nx = n->next;
    if (n->prev != 0) {
        n->prev->next = nx;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    if (*head == n) {
        *head = n->next;
    }
    n->prev = 0;
    n->next = *freel;
    n->f0 = 0xFFFFFFFF;
    if (*freel != 0) {
        (*freel)->prev = n;
    }
    *freel = n;
    return nx;
}
/* localdecomp:end func_0061BB00 */
