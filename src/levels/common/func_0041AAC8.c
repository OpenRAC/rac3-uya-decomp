#include "common.h"

/* localdecomp:start func_0041AAC8 */
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
extern void func_0041AA38(s32);
void func_0041AAC8(S_38F3A0 *p) {
    func_0041AA38(0);
    p->w58 = 0xD2; p->w5C = 0xC8; p->w74 = -2; p->w78 = 30; p->h48 = 0; p->h4A = 0; p->w70 = 0;
}
/* localdecomp:end func_0041AAC8 */
