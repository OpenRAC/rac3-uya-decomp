#include "common.h"

/* localdecomp:start func_004CEBF0 */
extern s32 func_004CEBF0(s32, s32, s32 (*)(s32, s32), s32, s32);

extern s32 D_001E123C;
extern s32 D_001E1240;
extern s32 D_001E1244;
extern s32 D_001E1248;
extern s32 D_001E1250;
extern s32 D_001E1254;
extern s32 D_001E1258;
extern s32 D_001E125C;
extern s32 D_001E1238_003AA2E8;
extern s32 D_001E124C_003AA2E8;
extern s32 D_001E1260_003AA2E8;
extern s32 D_001E1264_003AA2E8;
extern s32 D_001E1268_003AA2E8;
extern s32 D_001E1270[];
extern s32 D_001D4D40;
extern void func_00411EB0();
extern s32 func_004CEDB8();
extern void func_004CF308();
extern void func_004CF130();
s32 func_004CEBF0(s32 a, s32 b, s32 (*alloc)(s32, s32), s32 c, s32 flag) {
    s32 i;
    s32 *p;
    s32 r;
    D_001E123C = alloc(0x1A0000, 0x40);
    p = D_001E1270;
    D_001E1240 = alloc(0x4FC80, 0x40);
    D_001E1244 = alloc(0x1010, 0x40);
    D_001E1238_003AA2E8 = alloc(0x14, 0x40);
    D_001E1248 = alloc(0xEC800, 0x40);
    D_001E124C_003AA2E8 = alloc(0x5000C, 0x40);
    D_001E1250 = alloc(0xC000, 0x40);
    D_001E1254 = alloc(0x80000, 0x40);
    D_001E1258 = alloc(0x4000, 0x40);
    D_001E125C = alloc(0x3000, 0x40);
    D_001E1260_003AA2E8 = alloc(0xC, 0x40);
    D_001E1264_003AA2E8 = alloc(0xB8, 0x40);
    D_001E1268_003AA2E8 = alloc(0x68, 0x40);
    for (i = 1; i >= 0; i--) {
        *p++ = alloc(0x4000, 0x80);
    }
    func_00411EB0(flag != 0, flag != 0);
    func_004CF130(a, b, c);
    r = func_004CEDB8(D_001E1264_003AA2E8, D_001E124C_003AA2E8, D_001E1260_003AA2E8);
    func_004CF308();
    D_001D4D40 = D_001D4D40 & ~0x80;
    return r;
}
/* localdecomp:end func_004CEBF0 */
