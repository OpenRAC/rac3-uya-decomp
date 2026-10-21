#include "common.h"

/* localdecomp:start func_004DB4D0 */
extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D5628;
extern s32 D_001D55FC;
extern u8 D_001D3EF0[];
extern void func_004DAA88(u8 **, s32, s32, s32, s32, s32, s32, s32);
extern void func_004DAD68(u8 **, s32);
extern void func_004DB0C0(u8 **, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004D8F90(u8 **, s32, s32, s32, s32, s32, s32);
void func_004DB4D0(void) {
    u8 *p;
    p = D_001D3EF0;
    func_004DAA88(&p, D_001D5600, D_001D5604, D_001D5600 >> 6, 0, 0, (D_001D5600 + 1) * 16, (D_001D5604 + 1) * 16);
    func_004DAD68(&p, 1);
    func_004DB0C0(&p, D_001D5600, D_001D5604, D_001D5600 >> 6, 0, 0, (D_001D5600 + 1) * 16, (D_001D5604 + 1) * 16, 0xFF82FF);
    func_004D8F90(&p, D_001D5628, 256, 256, 0, 1, 128);
    D_001D55FC = p - D_001D3EF0;
}
/* localdecomp:end func_004DB4D0 */
