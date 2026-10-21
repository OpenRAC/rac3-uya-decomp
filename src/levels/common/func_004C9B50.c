#include "common.h"

/* localdecomp:start func_004C9B50 */
extern void *func_004C9B50();
void func_00116F98(void *, s32, void *);
extern u8 D_001DB338[];

void func_00116F98(void *, s32, void *);
extern u8 D_001DB338[];
extern u8 D_001DB380[];
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;

void *func_004C9B50(S_003A6910 *pool) {
    void **p;
    u32 used;
    u32 next;

    p = pool->free;
    if (p != 0) {
        pool->free = *p;
        pool->count++;
        return p;
    }
    used = pool->used;
    next = used + pool->elem;
    if (pool->size < next) {
        func_00116F98(D_001DB338, 0x54, D_001DB380);
        return 0;
    }
    { u8 *r = pool->base + used; pool->used = next; pool->count++; return r; }
}
/* localdecomp:end func_004C9B50 */
