#include "common.h"

/* localdecomp:start func_004D7F00 */
extern void func_004D30D0();
extern void func_004D4890();
extern void func_004D75D8();

extern s16 D_0016C5AC[];
 
void func_004D7F00(void) {
    func_004D4890();
    func_004D30D0();
    func_004D75D8();
    D_0016C5AC[0] = 1;
}
/* localdecomp:end func_004D7F00 */
