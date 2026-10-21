#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0xF0 - 0x14];
} T_47AF70;
typedef struct {
    u8 pad0[0x50];
    s32 f50;
    u8 pad54[0x60 - 0x54];
    s32 f60;
    u8 pad64[0x80 - 0x64];
    s32 f80;
} G_47AF70;
typedef struct {
    u8 pad0[0x74];
    s32 f74;
    u8 pad78[0x80 - 0x78];
    s32 f80;
    s32 f84;
} H_47AF70;
extern G_47AF70 D_002E9FD8;
extern u8 D_001425C0[];
extern T_47AF70 D_002C5640[];
extern H_47AF70 *D_001DFD98;
extern s32 D_001D4BB4;
extern void func_0045CA60(s32);
extern void func_00429DB0(s32);
extern void func_00503930(s32);
extern void func_004C1E50(s32);
extern void func_004C1C68(void);
extern void func_004C1D30(void);
extern void func_00419F40(s32, s32, s32);
extern void func_00419D98(s32);
extern void func_005138B0(s32 *);
extern void func_00513840(s32);
extern void func_005120B8(s32);

/* localdecomp:start func_0047AF70 */
void func_0047AF70(s32 a0) {
    s32 x;

    if (D_002E9FD8.f50 != 0 && D_002E9FD8.f60 != D_002E9FD8.f50) {
        func_0045CA60(1);
        func_00429DB0((D_001425C0[D_002E9FD8.f50] + D_002C5640)->f10);
        func_00503930(D_002E9FD8.f50);
        func_0045CA60(1);
    }
    func_004C1E50(1);
    func_004C1C68();
    D_001D4BB4 = D_002E9FD8.f80;
    func_00419F40(0, D_001DFD98->f74, 0);
    func_00419D98(2);
    if (D_001DFD98->f80 != 0) {
        func_00419D98(3);
    }
    if (D_001DFD98->f84 != 0) {
        func_00419D98(4);
    }
    func_004C1D30();
    func_004C1E50(1);
    x = 0;
    func_005138B0(&x);
    func_00513840(x);
    func_005120B8(a0);
}
/* localdecomp:end func_0047AF70 */
