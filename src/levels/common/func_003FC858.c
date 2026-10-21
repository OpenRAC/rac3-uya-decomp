#include "common.h"

/* localdecomp:start func_003FC858 */
typedef struct {
    u8 pad0[24];
    s32 w24;
    u8 pad1C[12];
    s16 h28;
} S_3FC858;

extern void func_004C1E50(s32);
extern void func_004C1BB0(void);
extern void func_004C1C68(void);
extern void func_00402A10(s32);
extern s32 func_00457270(s32);
extern s32 D_001D4BB4;
extern s32 D_001D4CEC;
extern S_3FC858 D_001E6540;

void func_003FC858(void) {
    func_004C1E50(1);
    func_004C1BB0();
    func_004C1C68();
    D_001D4BB4 = D_001E6540.w24;
    func_00402A10(30);
    if (func_00457270(4) != 0 && (D_001D4CEC & 1)) {
        D_001E6540.h28 = 0;
    }
}
/* localdecomp:end func_003FC858 */
