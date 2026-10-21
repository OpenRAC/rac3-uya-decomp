#include "common.h"

/* localdecomp:start func_003FE150 */
typedef struct {
    s32 val;
    s32 key;
    s32 pad[2];
} Unk003FE150Entry;

typedef struct {
    s32 pad[3];
    Unk003FE150Entry *entries;
    s32 count;
} Unk003FE150;

extern Unk003FE150 D_001E6540;

s32 func_003FE150(s32 a0) {
    s32 i;
    for (i = 0; i < D_001E6540.count; i++) {
        if (D_001E6540.entries[i].key == a0) {
            return D_001E6540.entries[i].val;
        }
    }
    return 0;
}
/* localdecomp:end func_003FE150 */
