#include "common.h"

/* localdecomp:start func_004A47D8 */
extern int *D_001E10E8;
extern int *D_001E0E80;
extern int *D_001E0E84;
extern int D_001D4BB0;
extern int D_001D4BB4;
extern void func_00433A28(void);
extern void func_004C21C0(void);

void func_004A47D8(void)
{
    int *p;

    p = D_001E10E8;
    D_001E0E84 = p;
    p += 4;
    D_001E10E8 = p;
    D_001E0E80[0] = 0x20000000;
    D_001E0E80[1] = (int)D_001E10E8;
    D_001E0E80[2] = 0;
    D_001E0E80[3] = 0;
    func_00433A28();
    func_004C21C0();
    D_001E10E8[0] = 0x20000000;
    D_001E10E8[1] = (int)(D_001E0E80 + 4);
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0;
    D_001E10E8 = D_001E10E8 + 4;
    D_001E0E84[0] = 0x20000000;
    D_001E0E84[1] = (int)D_001E10E8;
    D_001E0E84[2] = 0;
    D_001E0E84[3] = 0;
    D_001D4BB0 = D_001D4BB4;
}
/* localdecomp:end func_004A47D8 */
