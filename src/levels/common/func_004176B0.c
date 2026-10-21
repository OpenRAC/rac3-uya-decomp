#include "common.h"

/* localdecomp:start func_004176B0 */
typedef struct { s32 a[5]; } S5_004176B0;
extern S5_004176B0 D_001D6650;
s32 func_004176B0(s32 i) {
    S5_004176B0 t = D_001D6650;
    return t.a[i];
}
/* localdecomp:end func_004176B0 */
