#include "common.h"
typedef struct {
    u8 pad[336];
    u8 sub[784];
} Entry_3EAAE0;
extern Entry_3EAAE0 D_001E2AC0[];
void func_003EAAE0(u8 *a0) {
    Entry_3EAAE0 *e = D_001E2AC0;
    u8 *p = e[*(s32 *)(a0 + 148)].sub;
    if (*(s32 *)(p + 252) != *(s16 *)(a0 + 134) && *(s32 *)(p + 256) != 6) {
        a0[125] = 0;
        *(s16 *)(a0 + 126) = 3;
    }
}
