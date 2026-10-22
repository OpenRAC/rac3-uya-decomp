#include "common.h"

/* localdecomp:start func_004B31E0 */
typedef struct {
    u8 pad0[0x80];
    u8 f80[0x238 - 0x80];
    s32 f238;
    u8 pad23C[0x25C0 - 0x23C];
    s32 f25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 f25E4;
    u8 pad25E5[0x25F8 - 0x25E5];
    s32 f25F8;
    u8 pad25FC[0x2888 - 0x25FC];
    s16 f2888;
    s16 f288A;
    s16 f288C;
} G_4B31E0;
extern G_4B31E0 D_001A4BE0;
extern void func_004DC1C8(void);
extern void func_004BF818(void);
extern void func_004B97B8(void);
extern void func_004D5DE0(void);
extern void func_004BAB88(void);
extern void func_004C5E48(void);
extern void func_004B2848(void);
extern void func_004B6270(void);
extern void func_004B4C48(void);
extern void func_004DF0A8(void);
extern void func_004B49D0(void);
extern void func_00405100(void *p);
extern void func_004B63C8(void);
extern void func_0041805C(s32 a);

void func_004B31E0(void) {
    func_004DC1C8();
    func_004BF818();
    func_004B97B8();
    D_001A4BE0.f238 = 4;
    func_004D5DE0();
    func_004BAB88();
    if (D_001A4BE0.f25E4 == 0) {
        return;
    }
    func_004C5E48();
    func_004B2848();
    if (D_001A4BE0.f25E4 == 0) {
        return;
    }
    func_004B6270();
    func_004B4C48();
    func_004DF0A8();
    func_004B49D0();
    func_00405100(D_001A4BE0.f80);
    if (D_001A4BE0.f25E4 == 3) {
        if (D_001A4BE0.f25F8 != 0 && D_001A4BE0.f25F8 != 0x1E) {
            if (D_001A4BE0.f288C == 0) {
                D_001A4BE0.f2888 = 1;
                D_001A4BE0.f288C = 0x12;
                D_001A4BE0.f288A = 1;
            }
        } else {
            D_001A4BE0.f25F8 = 0;
        }
    }
    func_004B63C8();
    func_0041805C(D_001A4BE0.f25C0);
}
/* localdecomp:end func_004B31E0 */
