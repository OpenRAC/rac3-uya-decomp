#include "common.h"

/* localdecomp:start func_004886C8 */
typedef struct {
    s32 id;
    u8 flag;
    u8 pad[171];
} E_004886C8;
extern s32 D_001D8A40;
extern s32 D_001D8A5C;
extern E_004886C8 D_00233E58[];
s32 func_004886C8(void) {
    s32 r;
    s32 i;
    r = i = 0;
    if (D_001D8A40 >= 0) {
        for (i = 0; i < 30; i++) {
            if (D_00233E58[i].id == D_001D8A40 && D_00233E58[i].flag != 0) {
                D_001D8A5C = i;
                r = 1;
                break;
            }
        }
    }
    D_001D8A40 = -1;
    return r;
}
/* localdecomp:end func_004886C8 */
