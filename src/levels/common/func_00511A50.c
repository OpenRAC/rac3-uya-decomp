#include "common.h"

extern void func_00511A50();

extern void func_00510F18(void *);
 
typedef struct { void *arr[5]; s32 idx; } S_3E1510;
 
void func_00511A50(void *p) {
    S_3E1510 *q = *(S_3E1510 **)((u8 *)p + 0x4);
    void *x = q->arr[q->idx];
    if (x != 0) {
        func_00510F18(x);
    }
}
