#include "common.h"

/* localdecomp:start func_004D3168 */
extern void func_003FE8F8(void);
extern void func_00437500(void);
extern void func_004002A0(void);
extern void func_004D31C0(void);
extern void func_004130D8(void);
extern s32 D_001DFBDC;
extern void (*D_001DB8F0)(void);
void func_004D3168(void) {
    void (*fn)(void);
    func_003FE8F8();
    func_00437500();
    func_004002A0();
    fn = D_001DB8F0;
    D_001DFBDC = -1;
    if (fn != 0) fn();
    func_004D31C0();
    func_004130D8();
}
/* localdecomp:end func_004D3168 */
