#include "common.h"

/* localdecomp:start func_0048E830 */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} E_002EB338;

extern s32 D_001D8E18[2];
extern s32 D_001D8E28[2];
extern s32 D_001D8E68;
extern E_002EB338 D_002EB338[];
extern s32 func_00513698(void);
extern s32 func_00494DD0(s32);
extern s32 func_00494E58(s32);
extern s32 func_005131A0(s32, s32);
extern s32 func_00512D70(s32, s32);

void func_0048E830(void)
{
    s32 i;

    D_001D8E18[func_00513698()] = func_00494E58(func_00494DD0(0));
    i = func_00513698();
    if (D_001D8E28[i] != D_001D8E18[func_00513698()]) {
        D_001D8E68 = 30;
    }
    if (D_001D8E68 != 0) {
        if (--D_001D8E68 == 0) {
            func_005131A0(0x1C0003, D_002EB338[D_001D8E18[func_00513698()]].unkC);
            func_00512D70(0x1C0003, 1);
        }
    }
    D_001D8E28[func_00513698()] = D_001D8E18[func_00513698()];
}
/* localdecomp:end func_0048E830 */
