#include "common.h"

/* localdecomp:start func_00436C90 */
typedef struct N436C90 {
    u8 pad[28];
    struct N436C90 *next;
} N436C90;

typedef struct {
    u8 pad[80];
    N436C90 *head;
} L436C90;

extern void func_0040BBA8(void *, s32, s32);

void func_00436C90(L436C90 *l, N436C90 **pp) {
    N436C90 *p;

    if (*pp == 0) {
        return;
    }
    if (l->head == *pp) {
        l->head = (*pp)->next;
    } else {
        p = l->head;
        while (p->next != 0 && p->next != *pp) {
            p = p->next;
        }
        if (p->next == *pp) {
            p->next = (*pp)->next;
        }
    }
    func_0040BBA8(*pp, 0, 64);
    *pp = 0;
}
/* localdecomp:end func_00436C90 */
