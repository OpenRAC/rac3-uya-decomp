#include "common.h"

typedef struct {
    u8 pad[0x1C4];
    s32 flags;
} S_49EA68;

extern S_49EA68 *D_001D52FC;
extern u8 D_001D672C[];
extern s32 func_0049F628(void);
extern s32 func_00494DD0(s32);
extern void func_00495868(s32, s32);
extern void func_0049F068(void);
extern void func_0049F018(s32);
extern s32 func_0047A250(void);
extern void func_0047A268(void);
extern s32 func_0047B380(void);
extern void func_00513758(s32);
extern void func_005120B8(s32);

void func_0049EA68(s32 a0) {
    if (func_0049F628() == 0) {
        func_00495868(func_00494DD0(0), D_001D52FC->flags);
        func_0049F068();
        func_0049F018(a0);
    }
    if (func_0047A250()) {
        func_0047A268();
        func_005120B8(a0);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
