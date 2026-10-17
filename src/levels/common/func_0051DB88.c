#include "common.h"

extern void * func_0051DB20();
 
s32 func_0051DB88(void *p, u32 n) {
    if (*(u32 *)((u8 *)p + 0xC) < n) {
        return 0;
    }
    return (s32)func_0051DB20(p);
}
