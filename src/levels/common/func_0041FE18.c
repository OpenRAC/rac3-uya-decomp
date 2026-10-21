#include "common.h"

/* localdecomp:start func_0041FE18 */
extern s32 D_001A1EDC[];
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001D545C;
extern s32 D_001D76D8;
extern u8 D_001DFC40[];
extern u8 D_001FDC50[];
extern u8 D_00200E70[];
extern u8 D_002006F0[];
extern u8 D_0023C880[];
extern u8 D_00243C80[];
extern u8 D_00243880[];
extern u8 D_00238670[];
extern u8 D_0023A470[];
extern u8 D_00239E70[];
extern void func_0045B560(void);
extern void func_004C1BB0(void);
extern void func_004201F8(void);
extern void func_0040BBA8(void *, s32, s32);
extern void func_003FF970(void);
extern void func_003FFAC8(void);
extern void func_00405400(void);
extern void func_004C1C68(void);
extern void func_0045F4D0(void);
extern void func_004C2808(void);
extern void func_004384E8(void);
extern void func_004200A8(void);
extern void func_00449A50(s32);
extern void func_004344A0(void);

void func_0041FE18(void) {
    s32 v;
    s32 t;
    func_0045B560();
    func_004C1BB0();
    func_004201F8();
    v = D_001A1EDC[0];
    D_001D4BB0 = v;
    D_001D4BB4 = v;
    func_0040BBA8(D_001DFC40, 0x87654321, 16);
    func_0040BBA8(D_001FDC50, -1, 8192);
    func_0040BBA8(D_00200E70, -1, 3840);
    func_0040BBA8(D_002006F0, 0, 240);
    func_0040BBA8(D_0023C880, -1, 8192);
    func_0040BBA8(D_00243C80, -1, 2048);
    func_0040BBA8(D_00243880, 0, 128);
    func_0040BBA8(D_00238670, -1, 4096);
    func_0040BBA8(D_0023A470, -1, 1024);
    func_0040BBA8(D_00239E70, 0, 64);
    func_003FF970();
    func_003FFAC8();
    func_00405400();
    func_004C1C68();
    func_0045F4D0();
    func_004C2808();
    func_004384E8();
    func_004200A8();
    t = D_001D545C;
    if (t != 0) {
        func_00449A50(t % 60);
        func_004344A0();
    }
    D_001D76D8 = 0;
}
/* localdecomp:end func_0041FE18 */
