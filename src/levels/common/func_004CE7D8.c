#include "common.h"

extern void func_004CB460(void *);
 
void func_004CE7D8(void *p, s32 i) {
    func_004CB460((u8 *)p + (i * 0x230 + 0x4610));
}
