#include "common.h"

typedef struct {
    s32 x0;
    s32 x4;
} Single_474DB0;

extern Single_474DB0 D_001E1660[];
extern u8 D_00221880[];
extern u8 D_00221480[];
extern s32 D_001D545C;
extern void func_004C78D8(s32 a);
extern void func_00514D70(void);
extern void func_00512378(s32 a);
extern Single_474DB0 *func_00511BF8();
extern s32 func_00474B08(s32 a);
extern void func_00510A00(s32 a, s32 b);
extern void func_00511D00(Single_474DB0 *p, s32 i, s32 v);
extern s32 func_00490930(void);
extern s32 func_00490968(s32 a);
extern s32 func_004909F0(void);
extern s32 func_00490A20(s32 a);
extern void func_005119A0(Single_474DB0 *p, s32 i, s32 v);
extern s32 func_00511D38(Single_474DB0 *p, s32 i, s32 n, void *buf, s32 m);
extern void func_00511E50(Single_474DB0 *p, s32 a);
extern s32 func_00417EC8(s32 a);
extern s32 func_00475D20(s32 a);
extern s32 func_00477DE8(s32 a);
extern s32 func_00478B18(s32 a);
extern s32 func_00478C58(void);
extern void func_00512020(s32 a);
extern void func_005137D0(s32 a);

s32 func_00474DB0(void) {
    s32 ok = 1;
    s32 i;
    Single_474DB0 *p;
    Single_474DB0 *q;

    func_004C78D8(1);
    func_00514D70();
    func_00512378(0);
    func_00511BF8();
    p = D_001E1660;
    if (p->x4) {
        q = p;
    } else {
        q = func_00511BF8(p);
    }
    for (i = 0; i < 1; i++) {
        func_00510A00(func_00474B08(i), i);
        func_00511D00(q, i, func_00474B08(i));
    }
    func_005119A0(q, 0, func_00490930());
    func_005119A0(q, 1, func_00490968(0));
    func_005119A0(q, 2, func_00490968(1));
    func_005119A0(q, 3, func_00490968(2));
    func_005119A0(q, 4, func_00490968(3));
    func_005119A0(q, 5, func_004909F0());
    func_005119A0(q, 6, func_00490A20(0));
    func_005119A0(q, 7, func_00490A20(1));
    func_005119A0(q, 8, func_00490A20(1));
    func_005119A0(q, 9, func_00490A20(1));
    ok = (ok != 0) & (func_00511D38(q, 0, 0x400, D_00221880, 16) != 0);
    ok = (ok != 0) & (func_00511D38(q, 1, 0x12000, D_00221480, 100) != 0);
    func_00511E50(q, 0);
    if (!func_00417EC8(D_001D545C)) {
        func_00512020(func_00475D20(0));
        func_00512020(func_00477DE8(0));
        func_00512020(func_00478B18(0));
        func_00512020(func_00478C58());
        func_005137D0(func_00475D20(0));
        func_005137D0(func_00477DE8(0));
        func_005137D0(func_00478B18(0));
        func_005137D0(func_00478C58());
    }
    return ok;
}
