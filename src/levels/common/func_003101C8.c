#include "common.h"

typedef struct {
    s32 a;
    s32 id;
    u8 data[8];
} E_3101C8;

extern E_3101C8 *D_001E17AC;
extern s32 func_0040BA90(u8 *);

void func_003101C8(s32 id) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_001E17AC[i].id == id && func_0040BA90(D_001E17AC[i].data)) {
            D_001E17AC[i].id = 0;
            D_001E17AC[i].a = 0;
        }
    }
}
