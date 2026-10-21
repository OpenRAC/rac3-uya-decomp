#include "common.h"

/* localdecomp:start func_004D0BB8 */
typedef struct {
    s32 base;
    s32 pad4;
    s32 total;
    s32 start;
    s32 used;
    s32 off;
    s32 size;
    s32 pad1c[9];
    s32 sema;
} Ring_004D0BB8;
extern void func_0011EE60(s32);
extern void func_0011EE40(s32);
void func_004D0BB8(Ring_004D0BB8 *r, s32 *p1, s32 *p2, s32 *p3, s32 *p4) {
    s32 pos;
    s32 avail;
    s32 end;
    func_0011EE60(r->sema);
    pos = (((r->start + r->used) << 11) + r->off) % r->size;
    end = r->used + 2;
    avail = ((r->total - end) << 11) - r->off;
    if (r->size - pos >= avail) {
        *p1 = r->base + pos;
        *p2 = avail;
        *p3 = 0;
        *p4 = 0;
    } else {
        *p1 = r->base + pos;
        *p2 = r->size - pos;
        *p3 = r->base;
        *p4 = avail - (r->size - pos);
    }
    func_0011EE40(r->sema);
}
/* localdecomp:end func_004D0BB8 */
