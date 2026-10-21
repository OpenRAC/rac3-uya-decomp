#include "common.h"

/* localdecomp:start func_004541C0 */
typedef struct { s32 a; s32 id; u8 data[0xA428]; } S_4541C0;
extern S_4541C0 D_002D1710[];

void *func_004541C0(s32 id, s32 i) {
    if (D_002D1710[i].id != id) {
        return 0;
    }
    return D_002D1710[i].data;
}
/* localdecomp:end func_004541C0 */
