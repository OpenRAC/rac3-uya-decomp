#include "common.h"

/* localdecomp:start func_0047D5F0 */
extern s32 D_001D841C;
extern s32 D_001D8434;

extern s32 D_001D841C;
extern s32 D_001D8434;
extern s32 D_001D83C0_g;
extern void func_00479210(void *); // Ensure this prototype matches exactly
extern void func_0042FF20(void (*)(), s32, void (*)());
extern void func_0047D3E0();
extern void func_0047D2B8();


void func_0047D5F0(void) {
    func_00479210((void *)(s32)D_001D841C);
    
    // Explicit sequence point
    *(volatile s32 *)&D_001D83C0_g = 1; 
    
    func_0042FF20(func_0047D3E0, D_001D8434, func_0047D2B8);
}
/* localdecomp:end func_0047D5F0 */
