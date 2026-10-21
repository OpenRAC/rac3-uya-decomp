#include "common.h"

/* localdecomp:start func_003B4AE0 */
typedef struct {
    int oClass;
    char pad4[0x6C - 0x4];
    int index;
    char pad70[0x84 - 0x70];
    int flag;
    char pad88[0xC0 - 0x88];
    int w192;
    int w196;
} Vars;

typedef struct {
    char pad0[0x21];
    unsigned char b33;
    char pad22[0x68 - 0x22];
    Vars *vars;
    char pad6C[0xAA - 0x6C];
    short oClass;
} Obj;

extern int D_001E009C;
extern void func_00438760(int);

void func_003B4AE0(Obj *obj, Obj *other) {
    Vars *v = obj->vars;

    if (other == (Obj *)(D_001E009C + v->index * 256)) {
        return;
    }
    if (other->b33 != 255) {
        func_00438760(other->b33);
    }
    if (other->oClass != v->oClass) {
        return;
    }
    if (v->flag != 0) {
        v->w196++;
    } else {
        v->w192--;
    }
}
/* localdecomp:end func_003B4AE0 */
