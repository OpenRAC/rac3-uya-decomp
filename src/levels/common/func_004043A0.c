#include "common.h"

typedef struct {
    u8 data[176];
} Slot4043A0;

extern Slot4043A0 D_001EE490[];
extern void *D_001D6C50;
extern void func_003EDB00(Slot4043A0 *, void *);

void func_004043A0(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_001D6C50 != 0) {
            func_003EDB00(&D_001EE490[i], D_001D6C50);
        }
    }
}
