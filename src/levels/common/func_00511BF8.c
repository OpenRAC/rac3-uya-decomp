#include "common.h"

/* localdecomp:start func_00511BF8 */
extern void *func_00511BF8();

void func_0040BBA8(void *, s32, s32);
typedef struct { u8 pad0[0x4]; u8 *f4; } S_001DA9B8_003E16B8;
extern S_001DA9B8_003E16B8 D_001E1660[];
extern u8 D_0026DA10[];

void *func_00511BF8() {
    D_001E1660->f4 = D_0026DA10;
    func_0040BBA8(D_0026DA10 + 0x18, 0, 8);
    func_0040BBA8(D_001E1660->f4, 0, 0x14);
    func_0040BBA8(D_001E1660->f4 + 0x20, 0, 0x30);
    func_0040BBA8(D_001E1660->f4 + 0x50, 0, 0x10);
    func_0040BBA8(D_001E1660->f4 + 0x64, 0, 0x10);
    (*(s32 *)((u8 *)(D_001E1660->f4) + 0x60)) = 0;
    (*(s32 *)((u8 *)(D_001E1660->f4) + 0x74)) = 0;
    (*(s32 *)((u8 *)(D_001E1660->f4) + 0x14)) = 0;
    return D_001E1660;
}
/* localdecomp:end func_00511BF8 */
