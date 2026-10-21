#include "common.h"

/* localdecomp:start func_0048F358 */
typedef struct {
    u8 p0[0x1C4];
    s32 w452;
} P_48F358;

extern s32 D_001D8EA8;
extern P_48F358 *D_001D52FC[];
extern u8 D_001D672C[];
extern s32 func_00494DD0(s32 a);
extern s32 func_00494E58(s32 a);
extern s32 func_00417EA0(void);
extern s32 func_004A7368(s32 a, s32 b, s32 c);
extern void func_00495868(s32 a, s32 b);
extern void func_0048F958(void);
extern void func_0048F880(void *a, s32 b);
extern s32 func_004949B0(void);
extern s32 func_004948D0(void);
extern void func_00417DA0(s32 a, s32 b);
extern s32 func_0047A250(void);
extern void func_0047A268(void);
extern void func_005120B8(void *a);
extern s32 func_0047B380(void);
extern void func_00513758(s32 a);

void func_0048F358(void *a) {
    s32 s = D_001D8EA8;

    switch (s) {
    case 0:
        s = D_001D52FC[0]->w452;
        if (func_00494E58(func_00494DD0(0)) == 3 && func_00417EA0() == 0 && (s & 0x4000)) {
            func_004A7368(3, 0, 0);
            s &= ~0x4000;
        }
        func_00495868(func_00494DD0(0), s);
        func_0048F958();
        func_0048F880(a, s);
        break;
    case 1:
        if (func_004949B0() == 0) {
            D_001D8EA8 = 0;
            if (func_004948D0() == s) {
                func_00417DA0(-1, 1);
            }
        }
        break;
    }
    if (func_0047A250()) {
        func_0047A268();
        func_005120B8(a);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_0048F358 */
