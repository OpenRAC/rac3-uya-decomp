#include "common.h"

/* localdecomp:start func_00429C30 */
extern void func_00429AC0();
extern s32 func_0045C940();

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_00160C40_00395AC8;
typedef struct { u8 pad[0x34]; s32 f34[(0x35840 - 0x34) / 4]; } T_00395AC8;
extern T_00395AC8 D_0016C690_00395AC8;
extern s32 D_001D6DE0;
extern s32 D_001D6DE4;
extern volatile s32 D_001D6DE8;
extern s32 func_0045C940();
extern void func_00429AC0();
extern void func_00429B10();
s32 func_00429C30(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 t;
    if (D_00160C40_00395AC8.el[a0].f8 != 0) {
        t = D_001D6DE0;
        if (t == -1) {
            D_001D6DE0 = a0;
            D_001D6DE4 = a1;
            D_001D6DE8 = a2;
            if (a1 >= 0) {
                D_0016C690_00395AC8.f34[a1] = t;
            }
            if (D_00160C40_00395AC8.el[a0].f10 != 0 && a3 == 0) {
                return func_0045C940(a2, D_00160C40_00395AC8.el[a0].fC + D_00160C40_00395AC8.g458C, D_00160C40_00395AC8.el[a0].f10, func_00429B10, &D_001D6DE0);
            }
            return func_0045C940(a2, D_00160C40_00395AC8.el[a0].f4 + D_00160C40_00395AC8.g458C, D_00160C40_00395AC8.el[a0].f8, func_00429AC0, &D_001D6DE0);
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_00429C30 */
