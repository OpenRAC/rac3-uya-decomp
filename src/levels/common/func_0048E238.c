#include "common.h"

/* localdecomp:start func_0048E238 */
extern s32 D_001D8E18[2];
extern s32 func_00513698(void);
extern s32 func_00494DD0(s32);
extern s32 func_00494E58(s32);
extern void func_00513928(s32);
extern void func_0048E630(void);
extern void func_0045CA60(s32);
extern void func_00494A90(void);

void func_0048E238(void) {
    s32 i;

    i = func_00513698();
    D_001D8E18[i] = func_00494E58(func_00494DD0(func_00513698()));
    func_00513928(16);
    func_00513928(17);
    func_00513928(20);
    func_0048E630();
    func_0045CA60(1);
    func_00494A90();
}
/* localdecomp:end func_0048E238 */
