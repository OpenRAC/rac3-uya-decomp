#include "common.h"

/* localdecomp:start func_0047ECD8 */
extern s32 func_0047ACC0(void);
extern u8 D_001D672C[];

extern u8 D_001D672C[];
extern s32 D_001D83C0_g;
extern void func_004035F8(s32, s32, s32, s32);
extern void func_0047ED80(void);
void func_0047ECD8(void) {
    if (D_001D672C[0] == 0) func_0047ACC0();
    if (D_001D83C0_g != 0) {
        func_004035F8(0, 0, 0, 0x30);
        func_0047ED80();
    }
}
/* localdecomp:end func_0047ECD8 */
