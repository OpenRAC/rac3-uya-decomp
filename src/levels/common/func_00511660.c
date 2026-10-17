#include "common.h"

extern void *func_00511660();
extern void func_00511628();

extern s32 *func_0051DC48(s32 *);
void *func_00511660(void *p) {
    func_0051DC48((s32 *)p);
    func_00511628(p);
    return p;
}
