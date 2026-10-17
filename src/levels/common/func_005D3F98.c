#include "common.h"
typedef struct { s32 f0; s32 f4; } S_005D3F98;
extern u8 D_0024CE50[];
extern u8 D_00297080[];
extern u8 D_00296C80[];
extern void func_005FD728();
extern void func_00610850();
extern void func_0060E0E0();
extern void *func_0060D998();
extern void *func_005D3F08();
extern void func_0060C870();
extern s32 func_0060DA68();
extern s32 *func_005D9528();
extern void *func_005D9560();
extern s32 *func_005D95E8();
extern s32 *func_005D9618();
extern s32 func_0060D740();
extern s32 D_0024145C;
extern u8 D_001A4854[];
extern void func_005D41C0();
extern s32 func_0060DAA0();
extern void func_0060DBB8();
s32 func_005D3F98(void) {
    s32 ok = 1;
    s32 t, u, v;
    s32 i;
    u8 *s;
    void *q;
    func_005FD728(1);
    func_00610850();
    func_0060E0E0(0);
    func_0060D998();
    s = D_0024CE50;
    if (*(s32 *)(s + 4) != 0) q = s; else q = func_0060D998();
    t = ok != 0;
    for (i = 0; i < 5; i++) {
        func_0060C870(func_005D3F08(i), i);
        func_0060DA68(q, i, func_005D3F08(i));
    }
    func_0060D740(q, 0, func_005D9528());
    func_0060D740(q, 1, func_005D9560(0));
    func_0060D740(q, 2, func_005D9560(1));
    func_0060D740(q, 3, func_005D9560(2));
    func_0060D740(q, 4, func_005D9560(3));
    func_0060D740(q, 5, func_005D95E8());
    func_0060D740(q, 6, func_005D9618(0));
    func_0060D740(q, 7, func_005D9618(1));
    func_0060D740(q, 8, func_005D9618(1));
    func_0060D740(q, 9, func_005D9618(1));
    u = func_0060DAA0(q, 0, 0x400, D_00297080, 0x10) != 0;
    ok = t & u;
    u = func_0060DAA0(q, 1, 0x1E800, D_00296C80, 100) != 0;
    ok = ok & u;
    func_0060DBB8(q, 0);
    if (D_0024145C != 39 && D_001A4854[0] == 39) func_005D41C0();
    return ok;
}
