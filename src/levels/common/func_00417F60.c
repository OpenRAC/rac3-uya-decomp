#include "common.h"

typedef struct {
    s32 f0;
    u8 pad[32];
    s32 f24;
    s32 f28;
    u8 pad2[20];
    s32 f40;
    s32 f44;
} S_00417F60;

typedef struct {
    u8 pad[36];
    s32 f24;
    u8 pad2[68];
    s32 f6C;
    u8 pad3[36];
    s32 f94;
} P_00417F60;

typedef struct {
    u16 h0;
    u8 pad[10];
} T_00417F60;

extern S_00417F60 D_002E5F70;
extern P_00417F60 D_001CCFD0;
extern T_00417F60 D_001A7E18[];
extern s32 D_001D6694;
extern s32 D_001DFBC0;
extern void func_00419640(s32);

s32 func_00417F60(s32 id, s32 idx) {
    S_00417F60 *s = &D_002E5F70;
    P_00417F60 *p;

    if (s->f0 != 0) {
        return 0;
    }
    if (s->f24 == -1) {
        p = &D_001CCFD0;
        if (p->f6C == 0 && p->f24 == s->f24 && p->f94 == 0) {
            if (D_001A7E18[idx].h0 == 0xFFFF || D_001D6694 == 6 || D_001DFBC0 < 6) {
                return 0;
            }
            s->f28 = idx;
            s->f24 = id;
            s->f40 = 0;
            s->f44 = 0;
            func_00419640(id);
            return 1;
        }
    }
    return 0;
}
