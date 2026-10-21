#include "common.h"

/* localdecomp:start func_00510E70 */
extern void func_00510E70();

typedef struct { u8 b[16]; } B16_003E0930;
extern B16_003E0930 D_001DC0D0;
extern void func_00511628();
extern void func_00510B80();
extern void func_00510E40();
extern void func_00510B50();
void func_00510E70(u8 **o) {
    B16_003E0930 tmp;
    func_00511628(*o + 0x1C4);
    func_00511628(*o + 0x21CC);
    func_00510B80(o);
    func_00510E40(o);
    func_00510B50(o);
    tmp = D_001DC0D0;
    *(B16_003E0930 *)*o = tmp;
    *(s32 *)(*o + 0x1BC) = -1;
}
/* localdecomp:end func_00510E70 */
