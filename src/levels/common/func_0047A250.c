#include "common.h"

extern u8 D_001D672D[];
extern u8 D_001D8255;

u8 func_0047A250(void) {
    if (D_001D672D[0] != 0) {
        D_001D8255 = 0;
    }
    return D_001D8255;
}
