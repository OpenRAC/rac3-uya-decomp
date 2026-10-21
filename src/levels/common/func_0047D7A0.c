#include "common.h"

/* localdecomp:start func_0047D7A0 */
extern void func_004179B8(s32);
extern void func_00432680(s32);
extern void func_0047B560(s32);
extern s32 func_0047B6F8(s32);
extern s32 D_001D8420;
extern s32 D_001D841C;
extern s32 D_001D842C;
extern s32 D_001D8430;
extern s32 D_001D8424;
extern s32 D_001D8428;
extern u8 D_001D672C[];
extern u8 D_001D672C_003B1518[];
void func_0047D7A0(void) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;

    if (D_001D672C[0] != 0) {
        func_0047B560(0);
    }
    temp_2 = func_0047B6F8(1);
    D_001D8420 = temp_2;
    D_001D841C = (s32) ((temp_2 + 0xF) & 0xFFFFFFF0);
    if (D_001D672C_003B1518[0] == 0) {
        temp_2_2 = func_0047B6F8(1);
        D_001D842C = temp_2_2;
        temp_3 = (temp_2_2 + 0xF) & 0xFFFFFFF0;
        D_001D8430 = temp_3;
        func_004179B8(temp_3);
        temp_2_3 = func_0047B6F8(1);
        D_001D8424 = temp_2_3;
        temp_3_2 = (temp_2_3 + 0xF) & 0xFFFFFFF0;
        D_001D8428 = temp_3_2;
        func_00432680(temp_3_2);
    }
}
/* localdecomp:end func_0047D7A0 */
