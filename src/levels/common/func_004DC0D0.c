#include "common.h"

/* localdecomp:start func_004DC0D0 */
typedef struct {
    u8 pad0[0x1474];
    u8 b1474;
    u8 pad1475[0x116F];
    u8 b25E4;
    u8 pad25E5[6];
    u8 b25EB;
    u8 pad25EC[0x288];
    s16 h2874;
} S_4DC0D0;
typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0xC8];
} E_4DC0D0;
extern S_4DC0D0 D_001A4BE0;
extern s32 D_001DBD94;
extern u8 D_001425C0[];
extern E_4DC0D0 D_002C5640[];
extern s32 func_004E5470(s32);
extern s32 func_004DC080(void);
s32 func_004DC0D0(s32 a) {
    switch (D_001A4BE0.b25E4) {
    case 1:
        return D_001DBD94 == 0 ? 0x14 : 0x1D;
    case 3:
        return 1;
    default:
        if (a && D_001A4BE0.b25EB && D_001A4BE0.h2874 == 0) {
            s32 i = func_004E5470(0);
            u8 k = D_001425C0[i];
            return (k + D_002C5640)->w24;
        }
        if (func_004DC080() == 0) {
            return D_001A4BE0.b1474 ? 0x55 : 0;
        }
        return 0x4A;
    }
}
/* localdecomp:end func_004DC0D0 */
