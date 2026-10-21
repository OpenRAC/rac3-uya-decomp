#include "common.h"

/* localdecomp:start func_00669250 */
typedef struct {
    s32 state;
    s32 id;
} Sub_669250;

typedef struct Node_669250 {
    u8 pad0[8];
    Sub_669250 sub;
    u8 pad10[0x74];
    struct Node_669250 *next;
} Node_669250;

extern Node_669250 *D_0024D064;
extern void func_00669AC0(Node_669250 *, Node_669250 **);

void func_00669250(s32 id) {
    Node_669250 *p;

    for (p = D_0024D064; p != 0; p = p->next) {
        Sub_669250 *s = &p->sub;
        if (s->state == 0 && s->id == id) {
            func_00669AC0(p, &D_0024D064);
            return;
        }
    }
}
/* localdecomp:end func_00669250 */
