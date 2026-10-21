#include "common.h"

/* localdecomp:start func_004C1C68 */
typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern void func_004C1C68(void);
extern void func_004C1C00(void);
extern s32 D_001E10E0[];

extern Struct227600 D_001EA9C0;
extern s32 D_001E10E0[];
extern u32 *D_001E10E8_g;
extern s32 D_001E10F4_g;
extern void func_004C1C00(void);
void func_004C1C68(void) {
    u8 *p = (u8 *)&D_001EA9C0;
    D_001E10E0[0] = *(s32 *)(p + 0xC);
    D_001E10E0[1] = *(s32 *)(p + 0x10);
    D_001E10E8_g = *(u32 **)(p + 0xC);
    D_001E10F4_g = 0;
    func_004C1C00();
}
/* localdecomp:end func_004C1C68 */
