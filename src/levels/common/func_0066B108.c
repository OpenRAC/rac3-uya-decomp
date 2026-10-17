#include "common.h"

extern s32 D_001A5E58[];
extern void func_0061BB00(void);
extern void func_0066B188(u8 *, s32, u8, u8);

void func_0066B108(u8 *m, s32 a, u8 b, u8 c) {
    if (*(s32 *)(m + 52) == D_001A5E58[0]) {
        func_0061BB00();
    }
    func_0066B188(m, a, b, c);
    *(s32 *)(m + 52) = -1;
    *(s32 *)(m + 4) = -1;
}
