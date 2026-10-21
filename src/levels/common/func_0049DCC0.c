#include "common.h"

/* localdecomp:start func_0049DCC0 */
typedef struct {
    u8 pad0[0x1C4];
    s32 field_1C4;
} Obj49DCC0;

extern Obj49DCC0 *D_001D52FC[];
extern u8 D_001D672C[];
extern s32 func_00494DD0(s32);
extern void func_00495868(s32, s32);
extern void func_0049E5B8(void);
extern void func_0049E4E0(s32);
extern s32 func_0047A250(void);
extern void func_0047A268(void);
extern void func_005120B8(s32);
extern s32 func_0047B380(void);
extern void func_00513758(s32);

void func_0049DCC0(s32 a) {
    func_00495868(func_00494DD0(0), D_001D52FC[0]->field_1C4);
    func_0049E5B8();
    func_0049E4E0(a);
    if (func_0047A250()) {
        func_0047A268();
        func_005120B8(a);
        if (!D_001D672C[0]) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_0049DCC0 */
