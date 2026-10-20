#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 (*check)(s32);
} VT_00325E48;

typedef struct {
    s32 unk0;
    s32 next;
} Node_00325E48;

typedef struct {
    u8 pad0[352];
    VT_00325E48 *vt[16];
    s32 free[32];
    s32 count[16];
    s32 stamp[16];
    s32 head[16];
} S_00325E48;

extern s32 D_001DFBC0;
extern Node_00325E48 *func_00445F18(s32);

void func_00325E48(s32 a0, S_00325E48 *s, s32 i)
{
    s32 prev;
    s32 cur;
    s32 next;
    Node_00325E48 *node;
    VT_00325E48 *vt;

    if (s->head[i] == 0) {
        return;
    }
    if (s->stamp[i] == D_001DFBC0) {
        return;
    }
    s->stamp[i] = D_001DFBC0;
    prev = 0;
    cur = s->head[i];
    vt = s->vt[i];
    while (cur != 0) {
        node = func_00445F18(cur);
        next = node->next;
        if (vt->check(cur) != 0) {
            if (prev != 0) {
                func_00445F18(prev)->next = next;
            } else {
                s->head[i] = next;
            }
            node->next = s->free[i];
            s->free[i] = cur;
            s->count[i]++;
            cur = next;
        } else {
            prev = cur;
            cur = next;
        }
    }
}
