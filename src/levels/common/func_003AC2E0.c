#include "common.h"

typedef int (*F_3AC2E0)(int);

typedef struct {
    u8 pad[0xC90];
    int list[31];
    int idx;
} S_3AC2E0;

extern s16 *D_0021DEA0[];
extern int D_001E00D8;
extern int D_001E009C;
extern F_3AC2E0 *func_00438488(int, int, int);

int func_003AC2E0(void *a0, S_3AC2E0 *a1) {
    s16 *p = D_0021DEA0[a1->list[a1->idx]];
    s16 last = -1;
    int cur;
    u8 *m;
    int r;

    while ((cur = a1->list[a1->idx], (cur & 0xFF) != 0xFF) && cur <= D_001E00D8 && p != 0
           && (p[-1] >= 0 || p == D_0021DEA0[a1->list[a1->idx]])) {
        m = (u8 *)D_001E009C + ((*p & 0x7FFF) << 8);
        if (m == 0) {
            return 0;
        }
        if (*(s16 *)(m + 0xAA) != last) {
            r = (*func_00438488(*(s16 *)(m + 0xAA), 2, 12))(a1->list[a1->idx]);
            if (r != 0) {
                return r;
            }
            last = *(s16 *)(m + 0xAA);
        }
        p++;
    }
    return 0;
}
