#include "common.h"

/* localdecomp:start func_004B9418 */
typedef struct {
    s32 i0; s32 w;
} E_4B9418;
typedef struct {
    u8 pad0[40];
    s32 i40;
    u8 pad44[32];
    s32 i76;
    u8 pad80[48];
    s32 idx;
    s32 state;
    u8 pad136[188];
    struct { s32 cost; u8 pad[8]; s32 val; u8 pad2[12]; u8 flag; u8 pad3[7]; } e[40];
    u8 padz[1856 - 324 - 1440];
    s32 i1856;
    u8 padq[40];
    s32 i1900;
} S_4B9418;
typedef struct {
    u8 pad[452];
    u32 flags;
} P_4B9418;
extern S_4B9418 D_00244740;
extern s32 D_00142660[];
extern P_4B9418 *D_001D52FC;
extern u32 D_001E1010;
extern s32 D_001D54D0;
extern s32 func_004A7200(s32, s32, s32);
extern void func_00432FB8(s32);
extern void func_004B7798(void);
extern void func_004BBDD8(void);

void func_004B9418(u8 *out) {
    S_4B9418 *s = &D_00244740;
    s32 idx = s->idx;
    s32 cost = s->e[idx].cost;
    if (s->state == 1) {
        *out = 0;
        if (D_00142660[0] < cost || s->e[idx].flag != 0) {
            func_004A7200(2, 17, s->i40);
            s->state = 0;
        } else {
            func_004A7200(0, 17, s->i40);
            s->state = 2;
        }
    } else if (s->state == 2) {
        if ((D_001D52FC->flags & 0x10) && !(D_001E1010 & 0x10)) {
            *out = 0;
            s->state = 3;
        } else if (D_001D52FC->flags & 0x40) {
            if (!(D_001E1010 & 0x40)) {
                *out = 1;
                D_00244740.state = 3;
            }
        }
    } else if (s->state == 3) {
        if (*out) {
            s32 v = D_00142660[0];
            if (v >= cost) {
                s->i1900 = 1;
                D_00142660[0] = v - cost;
                D_001D54D0 = s->i76;
                func_00432FB8(s->e[idx].val);
                func_004B7798();
                if (s->i1856 < s->idx) s->idx = s->i1856;
                func_004A7200(7, 17, s->i40);
            } else {
                func_004A7200(0, 17, s->i40);
            }
        } else {
            func_004A7200(0, 17, s->i40);
        }
        D_00244740.state = 0;
        func_004BBDD8();
    }
}
/* localdecomp:end func_004B9418 */
