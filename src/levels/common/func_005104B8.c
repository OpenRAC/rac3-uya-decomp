#include "common.h"

extern s32 D_001A71A4[];
extern s32 D_001D545C;
extern s32 func_005103C8(void);
/* localdecomp:start func_005104B8 */
s32 func_005104B8(void) {
    s32 r = 0;
    s32 t;
    if (func_005103C8() == 0) {
        if (D_001A71A4[0] == 49) {
            t = D_001D545C;
            if (t == 4 || t == 11) {
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_005104B8 */
