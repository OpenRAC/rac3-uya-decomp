#include "common.h"

/* localdecomp:start func_003275E8 */
typedef struct {
    char pad0[0x58];
    void (*fn88)(int);
    char pad5C[0x60 - 0x5C];
    void (*fn96)(int);
} Iface;

typedef struct {
    char pad0[0x14];
    int index;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Obj;

extern int D_001E009C;
extern Obj *func_003252E8(int);
extern Iface *func_00438488(int, int, int);

void func_003275E8(int arg) {
    Vars *v = func_003252E8(arg)->vars;
    Iface *it;

    if (v->index != -1) {
        it = func_00438488(6877, 0, 104);
        it->fn96(D_001E009C + v->index * 256);
        if (arg != 0) {
            it->fn88(D_001E009C + v->index * 256);
        }
    }
}
/* localdecomp:end func_003275E8 */
