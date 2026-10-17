#include "common.h"

extern u8 D_001A5A46[];
extern s32 D_001D5A50;
extern u8 D_001DA700;
extern void func_00663C40(void);
extern void func_00664570(void);
extern void func_001999A8(void *);
extern void func_001999B0(void *);
extern void func_00674B08(void);
extern void func_00619A38(void);
extern void func_0061A9D8(void);
extern void func_00666300(void);
extern void func_00668DF8(void);
extern void func_0065FC50(void);
extern void func_0066A498(void);
extern void func_0051DDD8(void);
extern void func_00528570(void);
extern void func_00556200(void);
extern void func_00557200(void);

void func_006199A0(void) {
    D_001A5A46[0] = 0;
    D_001D5A50 = 5;
    func_001999A8(func_00663C40);
    func_001999B0(func_00664570);
    func_00674B08();
    func_00619A38();
    func_0061A9D8();
    func_00666300();
    func_00668DF8();
    D_001DA700 = 0;
    func_0065FC50();
    func_0066A498();
    func_0051DDD8();
    func_00528570();
    func_00556200();
    func_00557200();
}
