#include "common.h"

/* localdecomp:start func_00557478 */
typedef struct {
    u8 pad[0x1C];
    u8 *obj;
} E_00557478;
typedef struct {
    u8 pad[0x2AC];
    s32 id;
    u8 pad2B0[0x2FC - 0x2B0];
    s32 cnt;
    u8 pad300[0x310 - 0x300];
    u8 *arr[16];
} S_00557478;
typedef struct {
    u8 pad[0x70];
    s32 ids[16];
} T_00557478;
extern u8 *func_005573D0(void);
extern s32 func_00668F68(s32);
extern E_00557478 *func_00668FA0(s32, s32 *);

void func_00557478(u8 *a0, s32 a1) {
    S_00557478 *s = *(S_00557478 **)(a0 + 0x68);
    u8 *t;
    u8 *o;
    s32 h;
    s32 k = 0;
    s32 cur;
    E_00557478 *e;
    s->cnt = 0;
    t = func_005573D0();
    h = func_00668F68(s->id);
    cur = 0;
    while ((e = func_00668FA0(h, &cur)) != 0 && (o = e->obj) != 0) {
        s->arr[s->cnt] = o;
        if (t != 0 && a1 == 0) {
            (*(T_00557478 **)(t + 0x68))->ids[k] = **(s32 **)(o + 0x90);
            k++;
        }
        s->cnt++;
        cur++;
    }
}
/* localdecomp:end func_00557478 */
