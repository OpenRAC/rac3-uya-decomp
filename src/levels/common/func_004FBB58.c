#include "common.h"

/* localdecomp:start func_004FBB58 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4FBB58;

typedef struct {
    s32 unk0;
    f32 unk4;
    s32 unk8;
    u8 pad0C[0x10];
    s32 unk1C;
    f32 unk20;
} Vars4FBB58;

typedef struct {
    u8 pad00[0x10];
    V4FBB58 pos;
    u8 pad20[0x11];
    u8 unk31;
    u8 pad32[2];
    u16 unk34;
    u8 pad36[0x32];
    Vars4FBB58 *pVars;
} Moby4FBB58;

typedef struct {
    u8 pad000[0x80];
    V4FBB58 vec80;
    u8 pad090[0x8];
    f32 unk98;
    u8 pad09C[0x212 - 0x9C];
    s16 unk212;
    u8 pad214[0x5EC - 0x214];
    f32 unk5EC;
    u8 pad5F0[0xA24 - 0x5F0];
    Moby4FBB58 *unkA24;
    s32 unkA28;
    u8 padA2C[0xA38 - 0xA2C];
    s32 unkA38;
    u8 padA3C[4];
    f32 unkA40;
    f32 unkA44;
    u8 padA48[0x25C4 - 0xA48];
    s32 unk25C4;
    u8 pad25C8[4];
    s32 unk25CC;
} G4FBB58;

extern G4FBB58 D_001A4BE0;

typedef struct {
    V4FBB58 pos;
    u8 pad10[0x2544 - 0x10];
    s32 unk2544;
} H4FBB58;

extern H4FBB58 D_001A4C60;
extern Moby4FBB58 *D_001F03E8[];
extern f32 func_0040BFB0(V4FBB58 *, V4FBB58 *);
extern f32 func_0040BFE8(V4FBB58 *, V4FBB58 *);
extern f32 func_004E56A8(Moby4FBB58 *, s32 *, f32, f32, f32, f32);
extern s32 func_00440760(V4FBB58 *, s32, s32);
extern s32 func_003F8448(V4FBB58 *, V4FBB58 *, s32, s32, s32);

s32 func_004FBB58(void) {
    V4FBB58 from;
    V4FBB58 to;
    s32 hit;
    Moby4FBB58 *m;
    Moby4FBB58 *best;
    Vars4FBB58 *vars;
    f32 bestDist;
    f32 dist;
    f32 d;
    f32 a, b, r, maxDist;
    s32 i;
    G4FBB58 *g;
    Vars4FBB58 *bv;

    if (D_001A4BE0.unk25CC == 13) {
        return D_001A4BE0.unkA28;
    }
    D_001A4BE0.unkA28 = 0;
    if (D_001A4BE0.unk212 != 0) {
        return 0;
    }
    bestDist = 100000000.0f;
    best = 0;
    for (i = 0; i < 32; i++) {
        m = D_001F03E8[i];
        if (m == 0) {
            break;
        }
        if (m->unk34 & 1) {
            continue;
        }
        if (!(m->unk34 & 0x1000)) {
            continue;
        }
        vars = m->pVars;
        if (vars->unk0 != 0) {
            continue;
        }
        d = func_0040BFB0(&D_001A4C60.pos, &m->pos);
        if (vars->unk20 != 0.0f && vars->unk20 < d) {
            continue;
        }
        if (30.0f < d) {
            continue;
        }
        a = 0.5235988f;
        b = -1.0f;
        if (D_001A4C60.unk2544 == 1 || D_001A4C60.unk2544 == 29) {
            b = 0.08726646f;
            a = b;
        }
        g = &D_001A4BE0;
        r = g->unk98;
        if (g->unk25CC == 15) {
            r = g->unk5EC;
        }
        maxDist = 30.0f;
        if (vars->unk20 != 0.0f) {
            maxDist = vars->unk20;
        }
        dist = func_004E56A8(m, &hit, r, maxDist, a, b);
        if (hit != 0) {
            continue;
        }
        if (func_0040BFE8(&g->vec80, &m->pos) < 4.0f) {
            continue;
        }
        if (m->unk31 == 0) {
            dist += 10.0f;
        }
        if (vars->unk1C >= 0 && func_00440760(&g->vec80, vars->unk1C, 0) != 0) {
            continue;
        }
        if (dist < bestDist) {
            bestDist = dist;
            best = m;
        }
    }
    if (best != 0) {
        D_001A4BE0.unkA24 = best;
        from = D_001A4BE0.vec80;
        from.z += 0.5f;
        to = best->pos;
        bv = best->pVars;
        D_001A4BE0.unkA38 = bv->unk8;
        D_001A4BE0.unkA40 = bv->unk4;
        D_001A4BE0.unkA44 = bestDist;
        if (func_003F8448(&from, &to, 2, 0, 0) == 0) {
            D_001A4BE0.unkA28 = 1;
        }
    }
    return D_001A4BE0.unkA28;
}
/* localdecomp:end func_004FBB58 */
