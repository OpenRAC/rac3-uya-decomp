#include "common.h"

/* localdecomp:start func_00401878 */
extern s32 func_00413718(void);
extern void func_00412D40(s32);
extern void func_004010D0(s32);
extern void func_00413938(void);
extern s32 D_001DBD04[];
extern s32 D_001DF9C4[];
extern s32 D_001DBCFC;

void func_00401878(void) {
    if (func_00413718() == 1) {
        func_00412D40(0);
        D_001DF9C4[0] = 0x100FF;
        D_001DBCFC = D_001DBD04[0];
        func_004010D0(0);
    }
    func_00413938();
}
/* localdecomp:end func_00401878 */
