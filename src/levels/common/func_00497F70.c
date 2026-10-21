#include "common.h"

/* localdecomp:start func_00497F70 */
extern u8 *D_001D52FC[];
extern s32 D_001D9430;
extern u8 D_001D672C[];
extern s32 func_00494DD0(s32);
extern void func_00495868(s32, s32);
extern void func_00498978(void);
extern void func_00498900(s32);
extern s32 func_0047A250(void);
extern void func_0047A268(void);
extern void func_005120B8(s32);
extern s32 func_0047B380(void);
extern void func_00513758(s32);

void func_00497F70(s32 a) {
    s32 flags;

    flags = *(s32 *)(D_001D52FC[0] + 452);
    if (D_001D9430 != 0) {
        flags &= ~0x5000;
    }
    func_00495868(func_00494DD0(0), flags);
    func_00498978();
    func_00498900(a);
    if (func_0047A250() != 0) {
        func_0047A268();
        func_005120B8(a);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_00497F70 */
