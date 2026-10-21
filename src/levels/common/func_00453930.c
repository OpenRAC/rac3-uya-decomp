#include "common.h"

/* localdecomp:start func_00453930 */
extern s32 D_001DFBC0;
extern s32 D_001D677C;
extern s32 D_001D6778;
extern s32 D_001D6774;
extern s32 D_001F0068[];
extern s32 D_001F0168[];
void func_00453930(void) {
    s32 n;
    s32 i;
    if (D_001DFBC0 != D_001D677C) {
        n = D_001D6778;
        D_001D677C = D_001DFBC0;
        D_001D6774 = 0;
        for (i = 0; i < n; i++) {
            D_001F0068[D_001D6774] = D_001F0168[D_001D6774];
            D_001D6774++;
        }
        D_001D6778 = 0;
    }
}
/* localdecomp:end func_00453930 */
