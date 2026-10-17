#include "common.h"

extern void func_0041A6C0(void *);
 
void func_0041A7B0(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xD2;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_0041A6C0(p);
}
