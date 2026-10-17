#include "common.h"

extern s32 D_001DEA38;
extern s32 D_001DEA48;

void *func_003CB410(void *self, s32 index, s32 *count) {
    switch (index) {
    case 0:
        *count = 12;
        return &D_001DEA38;
    case 1:
        *count = 28;
        return &D_001DEA48;
    }
    return 0;
}
