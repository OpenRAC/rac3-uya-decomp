#include "common.h"
extern void func_00405060(void *);
void func_00405470(u8 *p) {
    func_00405060(p);
    *(s16 *)(p + 0x7E) = 0;
}
