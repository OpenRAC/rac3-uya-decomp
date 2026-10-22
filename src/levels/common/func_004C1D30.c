#include "common.h"

/* localdecomp:start func_004C1D30 */
extern void func_0011F0A0(s32);
extern void func_004C1D30();
extern void func_004C1CB0();
extern void func_004C1E50();
extern void func_004C1E50(s32);
extern void func_0011F0A0();
extern void func_004AF9A8();

extern volatile s32 D_001DAE90;
extern s32 D_001E10F8;
extern s32 D_001E10F0;
extern s32 D_001E10F4;
extern s32 D_001E10E0[];
extern u32 *D_001E10E8;
extern s32 *func_0012D650();
extern void func_0012D938();
extern void func_0011F0A0();
extern void func_004AF9A8();
extern void func_004C1CB0();
extern void func_004C1E50(s32);
void func_004C1D30(void) {
    s32 t;
    s32 flags;
    s32 lim;
    s32 c;
    s32 *r;
    t = (s32)D_001E10E8 - D_001E10E0[D_001E10F4];
    flags = D_001DAE90 | 0x1F;
    lim = D_001E10F8;
    if (t >= lim) lim = t;
    D_001DAE90 = flags;
    c = D_001E10F0 < t;
    D_001E10F8 = lim;
    if (c == 0 || D_001E10F4 == 0) {
        D_001E10E8[0] = 0x70000000;
        D_001E10E8[1] = 0;
        D_001E10E8[2] = 0;
        D_001E10E8[3] = 0;
        r = func_0012D650(1);
        *r |= 0xC0;
        func_0011F0A0(0);
        func_0012D938(r, D_001E10E0[D_001E10F4]);
        if (c != 0) {
            func_004C1E50(1);
            func_004C1CB0();
        }
    } else {
        D_001DAE90 = 0;
        func_004AF9A8();
    }
}
/* localdecomp:end func_004C1D30 */
