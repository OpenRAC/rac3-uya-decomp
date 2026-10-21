#include "common.h"

/* localdecomp:start func_004BEB70 */
typedef struct {
    s32 id;
    u8 pad4[14];
    u8 b12;
    u8 pad13[1];
} Item_004BEB70;

typedef struct {
    u8 pad0[92];
    s32 f5C;
    u8 pad60[32];
    s32 f80;
    u8 pad84[188];
    Item_004BEB70 b[76];
    u8 pad[1876 - 320 - 1520];
    s32 f754;
} Menu_004BEB70;

typedef struct {
    u8 pad0[132];
    u16 h84;
    u16 h86;
    u8 pad88[2];
    u16 h8A;
    u8 pad8C[100];
} Ent_004BEB70;

extern Menu_004BEB70 D_00244740;
extern s32 D_00142660[];
extern u8 D_001425C0[];
extern u8 D_00142CA0[];
extern s32 D_001427F0[];
extern Ent_004BEB70 D_002C5640[];
extern u8 D_001E10A0;
extern void func_00512D70(s32, s32);
extern void func_004BB0F0(u8 *, s32);
extern void func_00512ED8(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_00512480(s32, f32, f32);
extern void func_00513548(s32, f32, f32);
extern s32 func_005130C8(s32, u32);

void func_004BEB70(s32 show) {
    Menu_004BEB70 *g;
    Item_004BEB70 *items;
    Item_004BEB70 *e;
    Ent_004BEB70 *ent;
    Ent_004BEB70 *p;
    s32 ok;
    s32 i;
    s32 have;
    s32 need;
    s32 cost;
    u32 col;
    f32 x;
    f32 y;
    f32 z;

    g = &D_00244740;
    ok = 1;
    if (g->f5C == 0) {
        show = 0;
    }
    items = g->b;
    e = &items[g->f80];
    func_00512D70(0x48002E, show);
    func_00512D70(0x480030, show);
    func_00512D70(0x48002F, show);
    if (show == 0) {
        return;
    }
    if (e->b12 == 1) {
        g->f754 = 0;
        for (i = 0; i < 156; i++) {
            if (D_00142CA0[i] == 0) {
                continue;
            }
            p = &D_002C5640[D_001425C0[i]];
            if (p->h84 == 0) {
                continue;
            }
            need = p->h8A;
            have = D_001427F0[i];
            if (have >= need) {
                continue;
            }
            if (D_00244740.f5C != 0) {
                if (i == 16 || i == 17 || i == 19 || i == 21 || i == 22) {
                    continue;
                }
            }
            D_00244740.f754 += p->h86 * (need - have);
        }
        func_004BB0F0(&D_001E10A0, D_00244740.f754);
        if (D_00142660[0] < D_00244740.f754) {
            ok = 0;
        }
    } else {
        ent = &D_002C5640[D_001425C0[items[g->f80].id]];
        cost = ent->h86;
        ok = cost < D_00142660[0];
        func_004BB0F0(&D_001E10A0, cost);
    }
    func_00512ED8(0x480025, &x, &y, &z, &y);
    col = 0x80707070;
    func_00512480(0x48002E, z + 0.05f, 0.565f);
    func_00512480(0x48002F, x - 0.03f, 0.566f);
    func_00513548(0x48002F, z - x + 0.04f, 0.006f);
    func_00512ED8(0x48002E, &x, &y, &y, &y);
    func_00512480(0x480030, x - 0.015f, 0.565f);
    func_005130C8(0x480021, 0x80707070);
    func_005130C8(0x480025, 0x80707070);
    col = ok ? 0x8066CCFF : col;
    func_005130C8(0x480030, col);
    func_005130C8(0x48002E, col);
}
/* localdecomp:end func_004BEB70 */
