#include "common.h"
typedef struct {
    u8 pad[164];
    u8 f164[16];
} S_001A5990;
extern S_001A5990 D_001A5990;
s32 func_005C2098(s32 a0, s32 a1) {
    if (D_001A5990.f164[a1] != 0) {
        switch (a0) {
        case 64:
            return 68;
        case 4:
            return 1;
        case 8:
            return 2;
        }
    }
    return a0;
}
