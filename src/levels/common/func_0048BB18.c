#include "common.h"

/* localdecomp:start func_0048BB18 */
typedef struct {
    u8 pad[0x1C4];
    s32 flags;
} S_48BB18;

extern S_48BB18 *D_001D52FC;
extern s16 D_001CCFD4[];
extern void func_0047B428(void);
extern void func_0048BC68(void);
extern s32 func_0047B380(void);
extern s32 func_0048B5F8(void);
extern void func_00513758(s32);
extern void func_005120B8(s32);

void func_0048BB18(s32 a0) {
    func_0047B428();
    func_0048BC68();
    if ((D_001D52FC->flags & 0xD10) && D_001CCFD4[0] == 0) {
        func_00513758(func_0047B380());
        func_005120B8(a0);
    } else if (D_001D52FC->flags & 0x80) {
        func_00513758(func_0048B5F8());
        func_005120B8(a0);
    }
}
/* localdecomp:end func_0048BB18 */
