#include "common.h"

/* localdecomp:start func_004BE950 */
typedef struct {
    u8 pad0[0x34];
    u16 flags;
    u8 pad36[0x66];
    s32 f9C;
} M_4BE950;
typedef struct {
    u8 pad0[0xBF4];
    M_4BE950 *fBF4;
    M_4BE950 *fBF8;
    u8 padBFC[4];
    f32 fC00;
    f32 fC04;
    u8 padC08[0x16CC - 0xC08];
    f32 f16CC;
    u8 pad16D0[0x1B90 - 0x16D0];
    u8 f1B90[0x150];
    u8 f1CE0[0x25C0 - 0x1CE0];
    M_4BE950 *f25C0;
    u8 pad25C4[0x20];
    u8 f25E4;
    u8 f25E5;
    u8 f25E6;
} G_4BE950;
extern G_4BE950 D_001A4BE0;
extern f32 D_001DBC58;
extern void func_004BEAD0(s32);
extern void func_004BC080(void);
extern void func_004BE6E0(void);
extern void func_00422BE8(void *);
extern void func_004DCB58(s32);
extern void func_004B32E8(void);
extern void func_004B2890(void);
extern void func_004BF3E8(s32);
extern void func_004DC198(void);
extern void func_0041805C(M_4BE950 *);
extern void func_004B49D0(void);
extern void func_004CF3B8(s32, s32);
void func_004BE950(s32 type, s32 arg, M_4BE950 *m) {
    G_4BE950 *g = &D_001A4BE0;
    if (g->f25E4 == type) {
        return;
    }
    if (g->f25E4 != 0) {
        func_004BEAD0(0);
    }
    m->flags &= 0xFFBE;
    func_004BC080();
    g->f25E6 = 1;
    func_004BE6E0();
    g->f25C0 = g->fBF8;
    func_00422BE8(g->f1B90);
    func_00422BE8(g->f1CE0);
    g->f25C0->f9C = -1;
    func_004DCB58(1);
    func_004B32E8();
    func_004B2890();
    g->f25E4 = type;
    g->fBF4 = m;
    g->f25C0 = m;
    if ((u8)type == 2) {
        g->f16CC = D_001DBC58;
    }
    func_004BF3E8(1);
    g->f25C0->flags |= 6;
    g->fC00 = 1.0f;
    g->fC04 = 1.0f;
    func_004DC198();
    func_0041805C(g->f25C0);
    func_004B49D0();
    func_004CF3B8(arg, 2);
}
/* localdecomp:end func_004BE950 */
