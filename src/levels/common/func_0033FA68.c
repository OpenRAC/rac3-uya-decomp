#include "common.h"

/* localdecomp:start func_0033FA68 */
extern s16 D_001E1950[];
extern s16 D_001E1960[];
extern s16 D_001E1968[];
extern s32 D_001DD198;
extern s32 D_001DD19C;
extern s32 D_001E1970[];
extern s32 D_001E1974[];
extern f32 D_001E1978;
void func_0033FA68(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_001E1950[i] = 2;
        D_001E1960[i] = 2;
        D_001E1968[i] = 1;
    }
    D_001E1970[0] = D_001DD198;
    D_001E1974[0] = D_001DD19C;
    D_001E1978 = 1.0f;
}
/* localdecomp:end func_0033FA68 */
