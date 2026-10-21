#include "common.h"

/* localdecomp:start func_0049BF38 */
extern u8 *D_001D52FC[];
extern u8 D_001D672C[];

extern void func_00512D70(s32 a0, s32 a1);
extern void func_005131A0(s32 a0, s32 a1);
extern s32 func_00494DD0(s32 a0);
extern void func_00495868(s32 a0, s32 a1);
extern void func_0049CBD0(s32 a0);
extern void func_0049CC58(void);
extern void func_0049CDA8(void);
extern void func_0049D220(void);
extern void func_0049D7F0(void);
extern s32 func_0047A250(void);
extern void func_0047A268(void);
extern void func_005120B8(s32 a0);
extern s32 func_0047B380(void);
extern void func_00513758(s32 a0);

void func_0049BF38(s32 arg0) {
    s32 s = *(s32 *)(D_001D52FC[0] + 452);

    func_00512D70(0x540003, 1);
    func_005131A0(0x540003, 1);
    func_00495868(func_00494DD0(0), s);
    func_0049CBD0(arg0);
    func_0049CC58();
    func_0049CDA8();
    func_0049D220();
    func_0049D7F0();
    if (func_0047A250() != 0) {
        func_0047A268();
        func_005120B8(arg0);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_0049BF38 */
