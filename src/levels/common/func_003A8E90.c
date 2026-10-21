#include "common.h"

/* localdecomp:start func_003A8E90 */
extern s32 D_001DE4D8;
extern s32 D_001DE4B8;

void *func_003A8E90(void *self, s32 index, s32 *count) {
    switch (index) {
    case 0:
        *count = 4;
        return &D_001DE4D8;
    case 1:
        *count = 28;
        return &D_001DE4B8;
    }
    return 0;
}
/* localdecomp:end func_003A8E90 */
