#include "common.h"

/* localdecomp:start func_00483E10 */
typedef struct {
    u8 pad0[4];
    s32 i4;
    u8 pad8[54];
    s16 h62;
    u8 pad64[176];
} E_483E10;
extern s32 D_001D8718;
extern s32 D_001D871C;
extern s32 D_001D8748[2];
extern s32 D_001D87A0;
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern E_483E10 D_002C5640[];
extern char D_002EA868[];
extern char D_002EA8E8[];
extern char D_001D87A8[];
extern char D_001D87B0[];
extern char D_001D87B8[];
extern s32 func_00483CA8(s32, s32);
extern s32 func_00483CC8(s32, s32);
extern s32 func_004181A0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_005131A0(s32, s32);
extern void func_00512D70(s32, s32);
extern void func_00513D28(s32);

void func_00483E10(void) {
    s32 v = func_00483CA8(D_001D8718, D_001D871C);
    if (D_00142CA0[v] != 0) {
        func_0011B2E8(D_002EA868, D_001D87A8, func_004181A0(((E_483E10 *)D_002C5640 + D_001425C0[v])->i4));
        func_0011B2E8(D_002EA8E8, D_001D87A8, func_004181A0(((E_483E10 *)D_002C5640 + D_001425C0[v])->h62));
        func_005131A0(0xF000B, D_001D8748[func_00483CC8(D_001D8718, D_001D871C)] + 1);
        func_005131A0(0xF000D, D_001D8748[func_00483CC8(D_001D8718, D_001D871C)] + 1);
        func_00512D70(0xF000B, 1);
        func_00512D70(0xF000D, 1);
    } else {
        func_0011B2E8(D_002EA868, D_001D87B0);
        func_0011B2E8(D_002EA8E8, D_001D87B8);
        func_005131A0(0xF000B, 3);
        func_005131A0(0xF000D, 3);
    }
    if (D_001D87A0 != v) {
        func_00513D28(0xF0008);
    }
    D_001D87A0 = v;
}
/* localdecomp:end func_00483E10 */
