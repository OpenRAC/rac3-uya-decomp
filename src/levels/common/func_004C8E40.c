#include "common.h"

/* localdecomp:start func_004C8E40 */
extern u8 *func_004C8C48(u8 *);

extern u8 *func_004C8C48(u8 *);
extern u8 D_001DB260[];
u8 *func_004C8E40(u8 *p) {
    func_004C8C48(p);
    *(u8 **)(p + 0x24) = D_001DB260;
    return p;
}
/* localdecomp:end func_004C8E40 */
