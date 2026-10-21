#include "common.h"

/* localdecomp:start func_00669808 */
typedef struct {
    s32 type;
    s32 id;
} Msg_00669808;
typedef struct {
    s32 len;
    u8 pad4[4];
    Msg_00669808 msg;
} Pkt_00669808;
extern s32 D_001E17E0;
extern s32 D_0024D064[];
extern s32 D_0024D070[2];
extern u8 *func_006698E8(s32);
extern void func_00669D48(Pkt_00669808 *);
extern s32 func_00669A68(void *);
extern void func_0011D380(s32, Pkt_00669808 *, s32);
extern void func_00669250(s32);

s32 func_00669808(s32 a0, s32 a1, s32 a2, Pkt_00669808 *p) {
    Msg_00669808 *m = &p->msg;
    u8 *r;
    s32 h;
    D_001E17E0 = D_0024D070[0] + 1;
    r = func_006698E8(m->id);
    h = 0;
    if (p->msg.type == 6) {
        func_00669D48(p);
        return p->len;
    }
    if (r != 0) {
        h = func_00669A68(r + 0x38);
    } else if (p->msg.type == 0 || p->msg.type == 3) {
        h = func_00669A68(D_0024D064);
    }
    if (h != 0) {
        func_0011D380(h, p, p->len);
    } else if (m->type == 2 && r == 0) {
        func_00669250(m->id);
    }
    return p->len;
}
/* localdecomp:end func_00669808 */
