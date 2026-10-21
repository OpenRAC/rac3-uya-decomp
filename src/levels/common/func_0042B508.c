#include "common.h"

/* localdecomp:start func_0042B508 */
typedef struct {
    char pad[1128];
    int active[5];
    int id[5];
} Unk1F4020;

extern Unk1F4020 D_001F4020;

int func_0042B508(int id)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (D_001F4020.active[i] != 0 && D_001F4020.id[i] == id) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_0042B508 */
