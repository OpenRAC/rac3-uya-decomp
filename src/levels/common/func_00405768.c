#include "common.h"

/* localdecomp:start func_00405768 */
extern void func_004C1FE8(s32, unsigned long);
extern void func_00405768();

extern void func_004A4768(void);
extern void func_004A46C8(void);
extern void func_004A47D8(void);
extern void func_004C1FE8(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_00405768(void) {
    func_004A4768();
    func_004A46C8();
    func_004A47D8();
    func_004C1FE8(0x47, 0x5360B);
    func_004C1FE8(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_00405768 */
