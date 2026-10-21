#include "common.h"

/* localdecomp:start func_004C07D8 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6A38 - 0x4958];
    u8 fX[1];
} S_func_004C07D8;
extern S_func_004C07D8 D_00160C40[];
extern u8 D_002F2D18[];
extern s16 D_001CCFD4[];
extern u8 D_00244ED0[];
extern u8 D_002496D0[];
extern void func_00512478(s32);
extern s32 func_00477B88(void);
extern s32 func_004759F0(void);
extern s32 func_004780F8(void);
extern void func_004BD480(void *);
extern s32 func_005136D8(s32, s32);
extern void func_004BD808(s32, void *);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
extern s32 func_00513A90(s32, s32);
extern s32 func_005131A0(s32, s32);
extern s32 func_00512AB0(s32, s32, s32);
extern void func_004C0930(void);
extern void func_004C0BF8(void);
void func_004C07D8(void) {
    func_00512478(1);
    func_00477B88();
    func_004759F0();
    func_004780F8();
    func_004BD480(D_002F2D18);
    func_005136D8(27, 0x480000);
    func_004BD808(0, D_002F2D18);
    if (D_001CCFD4[0] == 0) {
        func_00490B98(func_00490968(0), (s32)D_00244ED0, 0, D_00160C40->f4954, (s32)D_00160C40->fX);
        func_00513A90(0x480019, (s32)func_00490968(0));
        func_00490B98(func_00490968(1), (s32)D_002496D0, 0, D_00160C40->f4954, (s32)D_00160C40->fX);
        func_00513A90(0x48001A, (s32)func_00490968(1));
        func_005131A0(0x480019, 43);
        func_005131A0(0x48001A, 44);
        func_00512AB0(0x480019, 0x8000, 1);
        func_00512AB0(0x48001A, 0x8000, 1);
    }
    func_00512478(0);
    func_004C0930();
    func_004C0BF8();
}
/* localdecomp:end func_004C07D8 */
