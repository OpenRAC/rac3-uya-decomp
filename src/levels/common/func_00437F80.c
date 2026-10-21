#include "common.h"

/* localdecomp:start func_00437F80 */
extern u8 D_0021F260[];

extern void func_004C1AF0(void *);
extern u8 D_0021F260[];
extern void func_004C1E98();
extern void func_004C1FE8(s32, unsigned long);
extern u8 D_00110790[];
extern u8 D_00100080[];
extern u16 D_00110780[];
extern s32 D_001DFBDC_003BE1A0;
extern s32 D_001E10E8_003BE1A0;
extern s32 D_001DFBF8_003BE1A0;
extern s32 D_001DFBF0_003BE1A0;
extern s32 D_001E0090_003BE1A0;
extern u8 *D_001E0130_003BE1A0;
extern s32 D_001E10EC_003BE1A0;
extern s32 D_001E0098_003BE1A0;
extern s32 D_001E00E4_003BE1A0;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
void func_00437F80(void) {
    s32 a, b, c, d;
    func_004C1E98(D_00110790, D_00110780[0]);
    D_001DFBDC_003BE1A0 = 6;
    func_004C1AF0(D_00100080);
    func_004C1FE8(0x47, 0x5360B);
    a = D_001E10E8_003BE1A0;
    b = D_001DFBF8_003BE1A0;
    c = D_001D4BB4;
    D_001E0090_003BE1A0 = a;
    d = D_001DFBF0_003BE1A0;
    D_001D4BB0 = c;
    a += 0x10;
    D_001E10E8_003BE1A0 = a;
    D_001E0130_003BE1A0 = D_0021F260;
    D_001E10EC_003BE1A0 = b + 0xFFFF0000;
    D_001E0098_003BE1A0 = d;
    D_001E00E4_003BE1A0 = 0;
}
/* localdecomp:end func_00437F80 */
