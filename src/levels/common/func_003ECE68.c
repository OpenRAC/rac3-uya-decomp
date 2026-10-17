#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *vars;
    u8 pad6C[42];
    u16 timer;
} Obj3ECE68;

extern void func_0045C2F8(void *);
extern void func_0045C328(void *);

void func_003ECE68(Obj3ECE68 *obj) {
    u8 *vars = obj->vars;
    func_0045C2F8(vars + 592);
    func_0045C328(vars + 596);
    if (obj->timer < 0xFFFF) {
        obj->timer++;
    }
}
