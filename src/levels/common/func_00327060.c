#include "common.h"

typedef struct {
    u8 pad[104];
    s32 *pvar;
} Moby_00327060;

extern Moby_00327060 *func_003252E8(void);
extern void func_004282C0(s32, s32);

void func_00327060(s32 a) {
    s32 *p = func_003252E8()->pvar;

    if (a < 0) {
        func_004282C0(*p, 0);
    } else {
        func_004282C0(a, 0);
    }
}
