#include "common.h"

extern void func_004A46C8(void);

extern s32 func_004A45B0(s32, s32);
s32 func_004A48F8_003C8C40(s32);                         /* extern */
extern s32 D_001DFBC0;
extern void *D_001E0E70_003C8C40;
extern s32 D_001E0ED0;

void func_004A46C8(void) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 var_s0;

    var_s0 = 0;
    temp_s1 = D_001DFBC0 - D_001E0ED0;
    temp_s1_2 = (temp_s1 >= 3) ? 2 : temp_s1;
    if ((*(s16 *)((u8 *)(D_001E0E70_003C8C40) + 6)) > 0) {
        do {
            func_004A45B0(var_s0, temp_s1_2);
            func_004A48F8_003C8C40(var_s0);
            var_s0 += 1;
        } while (var_s0 < (*(s16 *)((u8 *)(D_001E0E70_003C8C40) + 6)));
    }
    D_001E0ED0 = D_001DFBC0;
}
