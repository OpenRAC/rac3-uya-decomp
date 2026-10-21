#include "common.h"

/* localdecomp:start func_004D3460 */
extern s32 D_001DBCE0[4] __attribute__((section(".sdata")));
extern s32 D_001DBCE0_004D3460[4] __attribute__((section(".sdata")));
extern s32 D_001DB904;
extern s32 D_001DFA10;
extern s32 D_001DFA10_004D3460[4] __attribute__((section(".sdata")));
extern s32 D_001DFA08[4] __attribute__((section(".sdata")));
extern s32 D_001DFA0C[4] __attribute__((section(".sdata")));
extern s32 D_001DFBDC[4] __attribute__((section(".sdata")));
extern s32 D_001DBCFC;
extern s32 D_001DBCFC_004D3460[4] __attribute__((section(".sdata")));
extern s32 D_001A1ED0[];
extern u8 D_00100AE0[];
extern u8 D_0023C180[];
extern void func_003FFAC8(void);
extern void func_003FE8F8(void);
extern void func_004D36B8(void);
extern void func_004ADBC0(void);
extern void func_004C2A38(s32);
extern void func_004C2280(void);
extern void func_00401978(s32);
extern void func_004025B0(void);
extern void func_00401AA8(void);
extern void func_004C2220(void);
extern void func_00438120(void);
extern void func_004024E8(void);
extern void func_004C1FE8(s32, unsigned long);
extern void func_0011F0A0(s32);
extern void func_0045E810(void);
extern void func_004C1AF0(void *);
extern void func_004C1E50(s32);
extern void func_004AEC50(void *);
extern void func_004ADB20(void);
extern void func_004379E0(void);
extern void func_004026F0(void);
extern void func_003FEBC8(s32);
extern void func_004DA990(s32);
extern void func_004DAA10(void);
extern void func_004DB630(s32);

void func_004D3460(void) {
    s32 t;
    D_001DBCE0[0] = 0;
    func_003FFAC8();
    func_003FE8F8();
    if (D_001DB904 & 1) func_004D36B8();
    if (D_001DB904 & 2) {
        func_004ADBC0();
        func_004C2A38(0x2010000);
        t = D_001DFA10_004D3460[0];
    } else {
        t = D_001DFA10;
    }
    if (t) {
        func_004C2280();
        func_00401978(1);
        func_004025B0();
        func_00401AA8();
        func_004C2220();
    }
    if (D_001DB904 & 0xC) {
        func_00438120();
        func_004C2A38(0x2080000);
    }
    func_00401978(1);
    if (D_001DFA08[0]) func_004024E8();
    func_004C2280();
    func_004C1FE8(8, 5);
    func_004C1FE8(71, 0x53001);
    func_0011F0A0(0);
    func_0045E810();
    D_001DFBDC[0] = 9;
    func_004C1FE8(71, 0x5360B);
    func_004C1AF0(D_00100AE0);
    func_0011F0A0(0);
    if (D_001DB904 & 2) {
        func_004C1E50(2);
        func_004AEC50(D_0023C180);
        func_004ADB20();
    }
    if (D_001DB904 & 0xC) {
        func_004C1E50(16);
        func_004379E0();
    }
    func_00401AA8();
    if (D_001DFA0C[0]) {
        func_00401978(1);
        func_004C1FE8(78, (D_001A1ED0[2] >> 13) | 0x31000000 | 0x100000000UL);
        func_004C2280();
        func_004026F0();
        func_004C1FE8(78, 0x31000000 | (D_001A1ED0[2] >> 13));
        func_00401AA8();
    }
    func_003FEBC8(0);
    if (D_001DBCE0_004D3460[0]) {
        func_004DA990(0);
        func_004DAA10();
        t = D_001DBCFC_004D3460[0];
    } else {
        t = D_001DBCFC;
    }
    if (t) {
        func_004DB630(0);
        D_001DBCFC_004D3460[0] = 0;
    }
}
/* localdecomp:end func_004D3460 */
