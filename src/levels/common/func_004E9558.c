#include "common.h"

/* localdecomp:start func_004E9558 */
typedef struct {
    u8 pad0[9664];
    s32 unk25C0;
    s32 unk25C4;
    s32 pad25C8;
    s32 unk25CC;
    u8 pad25D0[24];
    u8 unk25E8;
    u8 pad25E9[4];
    u8 unk25ED;
    u8 pad25EE;
    u8 unk25EF;
} S_001A4BE0;

extern S_001A4BE0 D_001A4BE0[];
extern s32 func_004E5540(void);
extern void func_004E7148(void);
extern void func_004E7FD8(s32);
extern void func_0050E500(void);
extern void func_004DF888(void);
extern void func_004E93B8(void);

void func_004E9558(void) {
    if (func_004E5540() != 0 || D_001A4BE0[0].unk25C4 == 176) {
        D_001A4BE0[0].unk25E8 = 1;
        D_001A4BE0[0].unk25ED = 1;
    }
    if (func_004E5540() != 0 || D_001A4BE0[0].unk25C4 == 49 || D_001A4BE0[0].unk25CC == 3 ||
        D_001A4BE0[0].unk25C4 == 18 || D_001A4BE0[0].unk25C4 == 135 ||
        D_001A4BE0[0].unk25C4 == 176) {
        D_001A4BE0[0].unk25EF = 1;
    } else {
        D_001A4BE0[0].unk25EF = 0;
    }
    func_004E7148();
    func_004E7FD8(D_001A4BE0[0].unk25C0);
    func_0050E500();
    func_004DF888();
    func_004E93B8();
}
/* localdecomp:end func_004E9558 */
