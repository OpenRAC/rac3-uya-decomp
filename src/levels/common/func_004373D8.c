#include "common.h"

/* localdecomp:start func_004373D8 */
extern void func_0040BBA8();
extern void func_004373D8();
extern void func_0040BBA8(void *, int, int);

typedef struct N_BD778 { u8 p0[8]; struct N_BD778 *next; } N_BD778;
typedef struct { u8 p0[0x54]; N_BD778 *head; } L_BD778;
extern void func_0040BBA8(void *, s32, s32);
void func_004373D8(L_BD778 *l, N_BD778 *n) {
    N_BD778 *p;
    N_BD778 *h;
    if (n != 0) {
        h = l->head;
        if (h == n) {
            l->head = n->next;
        } else if (h != 0) {
            p = h;
            while (p->next != 0 && p->next != n) {
                p = p->next;
            }
            if (p->next == n) {
                p->next = n->next;
            }
        }
        func_0040BBA8(n, 0, 0x40);
    }
}
/* localdecomp:end func_004373D8 */
