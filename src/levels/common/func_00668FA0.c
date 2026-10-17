#include "common.h"

typedef struct {
    s32 f0;
    s32 count;
    s32 list[10];
} Ent668FA0;

extern Ent668FA0 D_0033BA90[];
extern s32 func_006698E8(s32);

s32 func_00668FA0(s32 idx, s32 *cursor) {
    s32 r;

    while (*cursor < D_0033BA90[idx].count) {
        r = func_006698E8(D_0033BA90[idx].list[*cursor]);
        if (r != 0) {
            return r;
        }
        (*cursor)++;
    }
    return 0;
}
