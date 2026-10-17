#include "common.h"

extern u8 *D_001E0130;
extern u8 D_0021F260[];

extern void func_004378F0(void);
extern void func_00437EB0(void);
extern void func_00437B48(void);
extern void func_00437C88(void);
extern s32 D_001E00E4[];
extern u8 *D_001E0130;
extern u8 D_0021F260[];
void func_004380C0(void) {
    func_004378F0();
    func_00437EB0();
    if (D_001E00E4[0] != 0) {
        func_00437B48();
    }
    if (D_001E0130 > D_0021F260) {
        func_00437C88();
    }
}
