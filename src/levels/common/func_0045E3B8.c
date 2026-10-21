#include "common.h"

/* localdecomp:start func_0045E3B8 */
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_00143950;
extern u8 D_001A71C4[];
s32 func_0045E3B8(s32 a, s32 i) {
    if (D_00143950.arr[i] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
/* localdecomp:end func_0045E3B8 */
