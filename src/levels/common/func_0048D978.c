#include "common.h"

/* localdecomp:start func_0048D978 */
extern void func_0048D978(void);

extern void func_004C1E50(s32);
extern void func_00411D38(void);
extern s32 D_001D5520[];
extern void func_00412088(s32, s32, s32, s32, s32, s32);
void func_0048D978(void) {
    func_004C1E50(1);
    func_00411D38();
    if (D_001D5520[0] != 0) {
        func_00412088(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_00412088(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
}
/* localdecomp:end func_0048D978 */
