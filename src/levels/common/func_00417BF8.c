#include "common.h"

extern void func_00417B68(s32 *);
extern void func_00417B48(s32 *);
void func_00417BF8(s32 *p) {
    func_00417B68(p);
    *p = 0;
    func_00417B48(p);
}
