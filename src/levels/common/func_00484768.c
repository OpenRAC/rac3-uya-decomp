#include "common.h"

/* localdecomp:start func_00484768 */
typedef struct {
    u8 pad[0x38];
    u16 h38;
    u8 pad2[0xF0 - 0x3A];
} S_484768;
extern s32 D_001D8874;
extern s32 D_001D87C0;
extern s32 D_001D87D0;
extern s32 D_001D87F0;
extern u8 D_001425C0[];
extern S_484768 D_002C5640[];
extern void func_005130C8(s32, u32);
extern void func_00512AB0(s32, s32, s32);
extern void func_005131A0(s32, u16);
void func_00484768(void) {
    s32 i;
    s32 *q;
    for (i = 0; i < 8; i++) {
        if (i == D_001D8874) {
            func_005130C8(0x19007B + i, 0x80FFFFFF);
        } else {
            func_005130C8(0x19007B + i, 0x706EC8FF);
        }
        switch (D_001D87C0) {
        case 0:
            q = &D_001D87D0 + i;
            if (*q != 0) {
                func_00512AB0(0x19007B + i, 1, 1);
                {
                    S_484768 *e = D_002C5640 + D_001425C0[*q];
                    func_005131A0(0x19007B + i, e->h38);
                }
            } else {
                func_00512AB0(0x19007B + i, 1, 0);
            }
            break;
        case 1:
            q = &D_001D87F0 + i;
            if (*q != 0) {
                func_00512AB0(0x19007B + i, 1, 1);
                {
                    S_484768 *e = D_002C5640 + D_001425C0[*q];
                    func_005131A0(0x19007B + i, e->h38);
                }
            } else {
                func_00512AB0(0x19007B + i, 1, 0);
            }
            break;
        }
    }
}
/* localdecomp:end func_00484768 */
