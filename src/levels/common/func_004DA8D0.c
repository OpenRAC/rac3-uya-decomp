#include "common.h"

/* localdecomp:start func_004DA8D0 */
extern s32 D_001D5608;
extern s32 D_001D561C;
extern s32 D_001D5620;
extern s32 D_001D55F4;
extern s32 D_001DBCF8;
extern u8 D_001D2A50[];
extern void func_004D9680(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_004D9C20();
extern void func_004D8F90(u8 **, s32, s32, s32, s32, s32, s32);
void func_004DA8D0(void) {
    u8 *p = D_001D2A50;
    func_004D9680(&p, D_001D5608, 0x40, 0x40, D_001D5620, 0x80, 0x80);
    func_004D9680(&p, D_001D5620, 0x80, 0x80, D_001D561C, 0x100, 0x100);
    func_004D9C20(&p, D_001D561C, D_001D5620);
    func_004D8F90(&p, D_001D561C, 0x100, 0x100, 1, 0, D_001DBCF8);
    D_001D55F4 = p - D_001D2A50;
}
/* localdecomp:end func_004DA8D0 */
