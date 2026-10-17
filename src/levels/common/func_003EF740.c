#include "common.h"
typedef struct { s32 x0; u8 pad4[0xC64 - 4]; s32 xC64; } G_3EF740;
extern G_3EF740 D_00237880;
extern s16 D_001CD018[];
extern u8 D_001D667B;
extern void func_004C1C68(void);
extern void func_0013CA28(void);
extern void func_0013B620(void);
extern void func_004A7810(void);
extern void func_0045BEC8(void);
extern void func_00418028(void);
extern void func_00428750(s32, s32);
extern void func_0042D280(s32);
extern void func_00457418(s32);
extern void func_0045BB60(s32, s32, s32);
extern void func_004198E0(void);
extern void func_00474DB0(void);
extern void func_003EFF28(void);
void func_003EF740(s32 a0) {
    s32 n;
    func_004C1C68();
    func_0013CA28();
    func_0013B620();
    func_004A7810();
    func_0045BEC8();
    n = D_001CD018[0];
    if (D_00237880.x0 != 0) {
        n = D_00237880.xC64;
    }
    func_00418028();
    func_00428750(0, a0);
    func_0042D280(0);
    func_00457418(0);
    func_0045BB60(n, 1, 1024);
    func_004198E0();
    func_00474DB0();
    func_003EFF28();
    D_001D667B = 0;
}
