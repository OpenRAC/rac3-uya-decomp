#include "common.h"

/* localdecomp:start func_0050D8F8 */
typedef struct {
    u8 pad[138];
    u16 h8A;
    u8 pad2[240 - 140];
} S_50D8F8;

extern s32 D_001A5E08[];
extern u8 D_001425C0[];
extern S_50D8F8 D_002C5640[];
extern s32 D_001427F0[];

s32 func_0050D8F8(s32 i, s32 n) {
    if (i == -1) {
        i = D_001A5E08[0];
    }
    if ((D_001425C0[i] + D_002C5640)->h8A == 0) {
        return 1;
    }
    if (D_001427F0[i] < n) {
        return 0;
    }
    D_001427F0[i] -= n;
    return 1;
}
/* localdecomp:end func_0050D8F8 */
