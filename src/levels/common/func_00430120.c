#include "common.h"

/* localdecomp:start func_00430120 */
extern u16 D_001D75A0;
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 f148; u8 p14C[0x18]; s32 f164; s32 f168; u8 p16C[8]; s32 f174; } S_00397100;
extern S_00397100 D_00142430[];
extern s32 D_001D545C;
extern s32 D_001D4BE0;
extern u8 D_001A9318[];
extern void func_0012BE28();
extern void func_0013AD58();
extern void func_0042DB40();
extern void func_00432680();
void func_00430120(s32 a, s32 b) {
    S_00397100 *p = D_00142430;
    func_0012BE28(&D_001D4BE0);
    func_0013AD58(&D_001D4BE0);
    func_0042DB40(D_001A9318 + (D_001D545C << 11));
    func_00432680(a);
    p->f174 = a;
    p->h18 = D_001D75A0;
    p->f148 = 0;
    if (b == -1) {
        *(s32 *)((u8 *)p + *(s32 *)&D_001D75A0 * 0x1C + 0x30) = D_001D545C;
    } else {
        *(s32 *)((u8 *)p + *(s32 *)&D_001D75A0 * 0x1C + 0x30) = b;
    }
    if (D_00142430->f164 < 0) {
        D_00142430->f168 = 0;
        D_00142430->f164 = 0x13;
    }
}
/* localdecomp:end func_00430120 */
