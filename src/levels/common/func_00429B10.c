#include "common.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Req_00429B10;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
} Ent_00160C40;

typedef struct {
    u8 pad[0x458C];
    s32 base;
    s32 pad4590;
    Ent_00160C40 ent[1];
} S_00160C40;

extern S_00160C40 D_00160C40;
extern s32 D_001D4B38;
extern void func_0011F0A0(s32);
extern s32 func_0011F1E0(Req_00429B10 *, s32);
extern s32 func_0011F1C0(s32);
extern s32 func_0045C940();
extern void func_00429AC0();

void func_00429B10(s32 *a0, s32 a1)
{
    Req_00429B10 req;
    s32 n;
    s32 *q;
    s32 *r;
    s32 h;

    if (a1 == 0) {
        a0[0] = -1;
        return;
    }
    n = D_00160C40.ent[a0[0]].d;
    if (n != 0) {
        q = (s32 *)a0[2];
        r = q + 6;
        req.a = (s32)q;
        req.b = D_001D4B38 + a0[1] * 0xC800;
        req.c = n << 11;
        req.d = 0;
        q[5] = 0xC000;
        r[10] = 0xC000;
        r[11] = 0xC000;
        func_0011F0A0(0);
        h = func_0011F1E0(&req, 1);
        while (func_0011F1C0(h) >= 0) {
        }
    }
    func_0045C940(a0[2], D_00160C40.ent[a0[0]].a + D_00160C40.base,
                  D_00160C40.ent[a0[0]].b, func_00429AC0, a0);
}
