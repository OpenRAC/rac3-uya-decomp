#include "common.h"

/* localdecomp:start func_004A48F8 */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
typedef struct { u8 pad[6]; s16 n; u8 pad2[0x18]; Q_3C8E70 *arr[1]; } P_3C8E70;
extern P_3C8E70 *D_001E0E70[];
extern void func_004A4B00(Q_3C8E70 *);
extern void func_004A4958(Q_3C8E70 *);
void func_004A48F8(s32 i) {
    P_3C8E70 *p = D_001E0E70[0];
    if (i < p->n) {
        Q_3C8E70 *q = p->arr[i];
        if (q->flags & 1) func_004A4B00(q);
        else func_004A4958(q);
    }
}
/* localdecomp:end func_004A48F8 */
