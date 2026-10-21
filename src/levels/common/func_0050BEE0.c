#include "common.h"

/* localdecomp:start func_0050BEE0 */
typedef struct {
    u8 pad[16];
    u8 max;
} Item_0050BEE0;

typedef struct {
    u8 pad[72];
    Item_0050BEE0 *items[1];
} List_0050BEE0;

typedef struct {
    u8 pad[36];
    List_0050BEE0 *list;
    u8 pad2[27];
    u8 idx;
} Obj_0050BEE0;

typedef struct {
    u8 pad[3104];
    s32 a;
    s32 b;
    u8 pad2[6552];
    Obj_0050BEE0 *obj;
} State_0050BEE0;

extern State_0050BEE0 D_001A4BE0;

void func_0050BEE0(s32 a, s32 b) {
    Obj_0050BEE0 *o;

    if (a >= 0) {
        o = D_001A4BE0.obj;
        if (b < o->list->items[o->idx]->max) {
            D_001A4BE0.a = a;
            D_001A4BE0.b = b;
        }
    }
}
/* localdecomp:end func_0050BEE0 */
