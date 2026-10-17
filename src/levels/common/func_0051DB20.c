#include "common.h"

typedef struct { s32 f0; u8 *base; u32 size; s32 elem; u32 used; s32 count; void **freelist; } P_3ECCA0;
void *func_0051DB20(P_3ECCA0 *p) {
    void **n = p->freelist;
    u32 off, end;
    if (n != 0) {
        p->freelist = *n;
        p->count++;
        return n;
    }
    off = p->used;
    end = off + p->elem;
    if (p->size < end) return 0;
    { u8 *r = p->base + off; p->used = end; p->count++; return r; }
}
