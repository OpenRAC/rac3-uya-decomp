#include "common.h"

/* localdecomp:start func_0053D2A0 */
typedef struct { u8 pad[0x88]; s32 arr[1]; } T_0053D2A0;
extern s32 D_00352A50[];
extern T_0053D2A0 *D_00352C4C[];
extern void func_00660240(u32 *, s32 *, s32);
extern void func_0055CED0(s32, s32);
void func_0053D2A0(u8 *o, u32 *m) {
    u8 *s = *(u8 **)(o + 0x68);
    s32 buf[4];
    switch (m[0] & 0xF) {
    case 0:
        *(s32 *)(s + 0x40) = 1;
        break;
    case 1:
        func_00660240(m, buf, 4);
        if (*(s32 *)(s + 0x68) == -1 || (s32)(m[1] + (m[0] >> 13)) < *(s32 *)(s + 0x68)) {
            D_00352A50[0] = buf[0];
            *(s32 *)(s + 0x68) = m[1] + (m[0] >> 13);
        }
        break;
    case 2:
        func_0055CED0(*(s32 *)(s + 0xAC), D_00352C4C[0]->arr[*(s32 *)(s + 0x1C)]);
        *(s32 *)(s + 0xBC) = 0;
        *(s32 *)(s + 0xB8) += 1;
        break;
    }
}
/* localdecomp:end func_0053D2A0 */
