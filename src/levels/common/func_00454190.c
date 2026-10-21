#include "common.h"

/* localdecomp:start func_00454190 */
typedef struct { s32 a; s32 id; u8 pad[0x18]; u8 data[0xA410]; } S_454190;
extern S_454190 D_002D1710[];

void *func_00454190(s32 id, s32 i) {
    if (D_002D1710[i].id != id) {
        return 0;
    }
    return D_002D1710[i].data;
}
/* localdecomp:end func_00454190 */
