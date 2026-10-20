#include "common.h"

typedef struct {
    u8 p0[0x1C4];
    s32 f1C4;
} S_004903D0;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} E_004903D0;

typedef struct {
    s32 a;
    s32 b;
} P_004903D0;

extern S_004903D0 *D_001D52FC;
extern E_004903D0 D_002EB688[];
extern P_004903D0 D_002E9E00[];
extern s32 D_002E9E08[];
extern s32 D_002E9E0C[];
extern char D_001E0B40[8];
extern char D_001D8F30[];
extern u8 D_001D672C;

extern s32 func_00494DD0(s32);
extern void func_00495868(s32, s32);
extern s32 func_0048F078(void);
extern void func_00513758(s32);
extern void func_005120B8(s32);
extern void func_004A7368(s32, s32, s32);
extern s32 func_004181A0(s32);
extern s32 func_00490890(void);
extern s32 func_0011B2E8(char *, ...);
extern s32 func_00494E58(s32);
extern s32 func_00512D70(s32, s32);
extern s32 func_00512FE8(s32, s32);
extern void func_005131A0(s32, s32);
extern s32 func_00490878(s32);
extern char *func_004950A8(s32, s32, s32);
extern void func_00495108(s32, s32, s32);
extern u8 func_0047A250(void);
extern void func_0047A268(void);
extern s32 func_0047B380(void);

void func_004903D0(s32 arg0) {
    s32 s;
    s32 idx;
    s32 r;
    s32 x;
    s32 a;
    u32 i;
    char *buf;
    s32 t;

    func_00495868(func_00494DD0(0), D_001D52FC->f1C4);
    if (D_001D52FC->f1C4 & 0x10) {
        func_00513758(func_0048F078());
        func_005120B8(arg0);
        func_004A7368(4, 0, 0);
    }
    t = func_004181A0(595);
    a = func_00490890();
    func_0011B2E8(D_001E0B40, t, a, 30);
    idx = func_00494E58(func_00494DD0(0));
    r = D_002EB688[idx].f0;
    if (r < 30) {
        x = r;
        if ((u32)(r - 1) < 2 || r == 4 || r == 8 || r == 0x1B || r == 0x1C || r == 9 || r == 0x1D
            || r == 5 || r == 0xD || r == 0x17 || r == 0xA || r == 0x12 || r == 0xE) {
            if (r > 0) a = D_002E9E00[x % 60].b;
            else a = D_002E9E0C[0];
        } else {
            if (r > 0) a = D_002E9E00[r % 60].a;
            else a = D_002E9E08[0];
        }
        s = a;
    } else {
        if (r > 0) s = D_002E9E00[r % 60].b;
        else s = D_002E9E0C[0];
    }
    func_00512D70(0x530005, 0);
    if (s >= 0) {
        func_00512D70(0x530005, 1);
        func_00512FE8(0x530005, func_004181A0(s));
    }
    if (func_00490878(D_002EB688[idx].fC)) {
        func_00512FE8(0x530007, func_004181A0(D_002EB688[idx].f8));
        func_005131A0(0x530003, D_002EB688[idx].f10);
    } else {
        func_00512FE8(0x530007, func_004181A0(5838));
        func_005131A0(0x530003, 31);
    }
    for (i = 0; i < 30; i++) {
        buf = func_004950A8(func_00494DD0(0), 0, i);
        func_0011B2E8(buf, D_001D8F30, func_004181A0(D_002EB688[i].f4));
        if (func_00490878(D_002EB688[i].fC)) {
            func_00495108(func_00494DD0(0), i, 0);
        } else {
            func_00495108(func_00494DD0(0), i, 1);
        }
    }
    if (func_0047A250()) {
        func_0047A268();
        func_005120B8(arg0);
        if (D_001D672C == 0) {
            func_00513758(func_0047B380());
        }
    }
}
