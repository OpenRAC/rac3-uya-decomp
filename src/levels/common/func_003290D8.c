#include "common.h"

/* localdecomp:start func_003290D8 */
typedef struct Node_003290D8 {
    u8 pad[104];
    struct Node_003290D8 *link;
    struct Node_003290D8 *next;
} Node_003290D8;
typedef struct {
    s32 pad0;
    Node_003290D8 *head;
    Node_003290D8 *found;
    s32 index;
} List_003290D8;
extern s32 func_00328AA8(Node_003290D8 *);
extern s32 func_00328B90(Node_003290D8 *);
extern s32 func_00328BE0(Node_003290D8 *);
extern void func_00328FE0(s32, List_003290D8 *);
void func_003290D8(s32 a, List_003290D8 *l) {
    Node_003290D8 *n;
    Node_003290D8 *link;
    s32 i = 0;
    n = l->head;
    goto check;
next:
    i++;
check:
    if (n == 0) goto fail;
    link = n->link;
    if (func_00328AA8(n) == 0) {
        n = link->next;
        goto next;
    }
    if (func_00328B90(n) == 0) {
        n = link->next;
        goto next;
    }
    if (func_00328BE0(n) == 0) {
        l->found = n;
        l->index = i;
        return;
    }
    n = link->next;
    goto next;
fail:
    func_00328FE0(a, l);
}
/* localdecomp:end func_003290D8 */
