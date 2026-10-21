#include "common.h"

/* localdecomp:start func_004966C0 */
extern u8 *D_001D52FC[];
extern u8 D_001D672C[];
extern void func_00496D70(void);
extern s32 func_00494DD0(s32);
extern void func_00495868(s32, s32);
extern void func_00496DC0(void);
extern s32 func_0047A250(void);
extern void func_0047A268(void);
extern void func_005120B8(void *p);
extern s32 func_0047B380(void);
extern void func_00513758(s32);

void func_004966C0(void *p) {
    func_00496D70();
    func_00495868(func_00494DD0(0), *(s32 *)(D_001D52FC[0] + 452));
    func_00496DC0();
    if (func_0047A250() != 0) {
        func_0047A268();
        func_005120B8(p);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_004966C0 */
