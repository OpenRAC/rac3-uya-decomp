#include "common.h"

/* localdecomp:start func_00619880 */
typedef struct { u8 pad[8]; s32 f8; u8 pad2[0x169 - 0xC]; u8 f169; u8 pad3[2]; s32 f16C; } S_619880;
extern S_619880 D_001A5E50;
extern s32 *D_002412A0;
extern u8 D_001A5990[];
extern void *D_00240770;
extern void func_0061E448(void);
extern void func_0061AA38(s32, s32);
extern void func_0065F168(s32);
extern void func_0066B5A8(void);
extern void func_00619B58(void);
extern s32 func_005A6F30(s32, void *, s32);
extern void func_00670060(void);
extern void func_00672470(void);
extern void func_0054BE68(void);

void func_00619880(void) {
    s32 i;

    func_0061E448();
    func_0061AA38(D_001A5E50.f8, D_001A5E50.f16C);
    for (i = 0; i < *D_002412A0; i++) {
        func_0065F168(i);
    }
    {
        s32 j;
        for (j = 7; j >= 0; j--) {
            D_001A5990[0xA4 + j] = 0;
        }
    }
    func_0066B5A8();
    func_00619B58();
    func_005A6F30(0, func_00672470, 0);
    D_001A5E50.f169 = 0;
    func_00670060();
    D_00240770 = func_0054BE68;
}
/* localdecomp:end func_00619880 */
