#include "common.h"

/* localdecomp:start func_004864A8 */
extern int D_001D8910;
extern int D_001D8914;
extern int D_001D8918;
extern int D_001D8868;
extern int D_001D886C;
extern int D_001D8878;
extern u8 *D_001D52FC[];
extern u8 D_001D672C[];
extern void func_005131A0(int, int);
extern void func_00512D70(int, int);
extern void func_00486438(int, int, int, int);
extern void func_00485EE0(void);
extern void func_00485FF8(void);
extern void func_0047B920(void);
extern void func_0047B8E0(int);
extern void func_004858E8(void);
extern int func_0047B380(void);
extern int func_0047C5C8(void);
extern void func_00513758(int);
extern void func_005120B8(void *);
extern void func_004A7368(int, int, int);
extern void func_00485D70(void);
extern void func_004863F0(void);
extern void func_004857E8(void);
extern void func_00485A48(void);
extern void func_00485B98(void);
extern void func_00484768(void);
extern void func_004848A8(void);
extern int func_0047A250(void);
extern void func_0047A268(void);

void func_004864A8(void *a0) {
    int v;

    func_005131A0(0x190002, 1);
    func_00512D70(0x190002, 1);
    if (D_001D8910 != D_001D8868 || D_001D8914 != D_001D886C || D_001D8918 != D_001D8878) {
        if (D_001D8910 >= 0 && D_001D8914 >= 0 && D_001D8918 >= 0) {
            func_00486438(D_001D8918, D_001D8910, D_001D8914, 0x706EC8FF);
        }
    }
    func_00486438(D_001D8878, D_001D8868, D_001D886C, 0x80FFFFFF);
    D_001D8910 = D_001D8868;
    D_001D8914 = D_001D886C;
    D_001D8918 = D_001D8878;
    func_00485EE0();
    func_00485FF8();
    func_0047B920();
    func_0047B8E0(0x19000E);
    func_0047B8E0(0x19000F);
    func_0047B8E0(0x190001);
    func_004858E8();
    v = *(int *)(D_001D52FC[0] + 452);
    if (v & 0x900) {
        func_00513758(func_0047B380());
        func_005120B8(a0);
    } else if (v & 0x10) {
        func_004A7368(4, 0, 0);
        func_00513758(func_0047C5C8());
        func_005120B8(a0);
    }
    func_00485D70();
    func_004863F0();
    func_004857E8();
    func_00485A48();
    func_00485B98();
    func_00484768();
    func_004848A8();
    if (func_0047A250()) {
        func_0047A268();
        func_005120B8(a0);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_004864A8 */
