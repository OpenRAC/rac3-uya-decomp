#include "common.h"
typedef struct {
    s32 type;
    s32 id;
    s32 seq;
    s32 val;
} Msg_00669D48;
typedef struct {
    u8 pad0[48];
    u8 flag;
    u8 pad1[60 - 49];
    s32 val;
    s32 seq;
} Rec_00669D48;
extern s32 D_001A5E58[];
extern Rec_00669D48 *func_006698E8(s32);
void func_00669D48(u8 *p) {
    Msg_00669D48 *m = (Msg_00669D48 *)(p + 8);
    Rec_00669D48 *r;
    s32 v;
    if (m->type != 6) return;
    v = m->val;
    r = func_006698E8(m->id);
    if (r == 0) return;
    if (r->seq < m->seq) {
        r->val = v;
    } else {
        if (r->seq != m->seq) return;
        if (r->val == v) return;
        if (r->val < v) return;
        r->val = v;
    }
    if (v == D_001A5E58[0]) r->flag = 1;
    r->seq = m->seq;
}
