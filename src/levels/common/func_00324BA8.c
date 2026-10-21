#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad[48];
} E_00324BA8;
extern E_00324BA8 D_002AEA90[];
extern s32 D_001D545C;
/* localdecomp:start func_00324BA8 */
s32 func_00324BA8(s32 *key) {
    s32 i = 0;
    E_00324BA8 *p = D_002AEA90;
    while (p->f0 > 0) {
        if (p->f0 == D_001D545C && p->f4 == *key) {
            break;
        }
        p++;
        i++;
    }
    return p->f0 < 0 ? 255 : i;
}
/* localdecomp:end func_00324BA8 */
