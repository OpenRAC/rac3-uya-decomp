#include "common.h"

typedef struct {
    void *obj;
    u8 count;
    u8 team;
    u8 pad[2];
} Ent_00453620;

typedef struct {
    Ent_00453620 ent[28];
} Slot_00453620;

typedef struct {
    u8 pad[0x25C0];
    void *player;
} Game_00453620;

extern Slot_00453620 *D_001DFCC8;
extern s32 *D_001DFCCC;
extern s32 D_001DFBC0;
extern void *D_001A71A0[];
extern Game_00453620 D_001A4BE0[];

extern void func_00452F80(s32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern f32 func_00453408(void *, void *, s32, s32, f32, s32, s32);

void *func_00453620(void *self, s32 idx, s32 *outTeam, s32 team, s32 a4, s32 a5, s32 useSub, s32 a7, f32 range) {
    Ent_00453620 *e;
    void *sub;
    void *osub;
    void *obj;
    void *best;
    void *o;
    f32 bestD;
    f32 d;
    s32 n;
    s32 k;

    if (idx < 0 || idx >= *D_001DFCCC) {
        return 0;
    }
    if (D_001DFBC0 < 2) {
        return 0;
    }
    sub = useSub ? (u8 *)self + 16 : 0;
    func_00452F80(idx);
    e = D_001DFCC8[idx].ent;
    n = e->count;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        o = e->obj;
        if (o == 0) {
            return 0;
        }
        *outTeam = e->team;
        osub = (u8 *)o + 16;
        if (useSub == 0) {
            osub = 0;
        }
        if (team != 0) {
            if (useSub != 0 && func_003F8448(sub, osub, 2, self, 0) == 0) {
                return 0;
            }
            if (*outTeam == team || e->obj == D_001A71A0[0]) {
                return e->obj;
            }
            return 0;
        }
        if (useSub != 0 && func_003F8448(sub, osub, 2, self, 0) == 0) {
            return 0;
        }
        return e->obj;
    }
    bestD = 9999999.0f;
    best = 0;
    for (k = 0; k < n; k++, e++) {
        obj = e->obj;
        if (obj != 0) {
            d = func_00453408(self, obj, a4, a5, range, useSub, a7);
            if (d < bestD && obj != self) {
                if (team != 0) {
                    if (e->team == team || obj == D_001A4BE0[0].player) {
                        best = e->obj;
                        bestD = d;
                        *outTeam = e->team;
                    }
                } else {
                    bestD = d;
                    best = e->obj;
                    *outTeam = e->team;
                }
            }
        }
    }
    return best;
}
