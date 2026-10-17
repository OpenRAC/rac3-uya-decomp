#include "common.h"

typedef struct S_65FC50 S_65FC50;

struct S_65FC50 {
    u8 pad[88];
    S_65FC50 *next;
};

extern S_65FC50 D_0030C500[];
extern S_65FC50 *D_001DAAE0;
extern void func_00660170(S_65FC50 *);

void func_0065FC50(void) {
    s32 i;

    for (i = 0; i < 192; i++) {
        func_00660170(&D_0030C500[i]);
    }
    for (i = 190; i >= 0; i--) {
        D_0030C500[i].next = &D_0030C500[i + 1];
    }
    D_001DAAE0 = D_0030C500;
}
