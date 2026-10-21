#include "common.h"

/* localdecomp:start func_00432CB0 */
extern void func_0012BE28();
extern void func_0013AD58();
extern void func_0042DB40();
extern u8 D_002E74B8[];
extern u8 D_002E7748[];
extern u32 D_001D545C;
extern u8 D_001C5BD0[], D_001C5BD8[], D_001CBBD0[];
extern s32 func_00432850();

extern s32 func_00432CB0(s32, s32);
typedef struct { u8 b[8]; } V8_399C90;
typedef struct { s32 f0, f4, f8, fC; V8_399C90 f10; s32 f18; } E_399C90;
typedef struct { u8 p0[0x18]; s16 h18; u8 p1a[0x16]; E_399C90 e[4]; u8 pA0[0xA8]; s32 f148; s32 f14C; s32 f150; u8 p154[8]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[0x10]; s32 f17C; } S_399C90;
typedef struct { s32 f0; u8 p4[0x2E]; u8 b32; } T_399C90;
extern S_399C90 D_00142430_00399C90;
extern T_399C90 D_00142660_00399C90;
extern s32 D_001D4CF0;
extern u32 D_001D545C;
extern s32 D_001D5528;
extern s32 D_001D4CEC_00399C90;
extern V8_399C90 D_001D4BE0;
extern u8 D_001A9318[];
extern u8 D_001D5570[8];
extern u8 D_001C5BD0[];
extern u8 D_001CBBD0[];
extern u8 D_002E74B8[];
extern u8 D_002E7748[];
extern void func_0042E8D8();
s32 func_00432CB0(s32 a, s32 b) {
    u8 *q;
    s32 old;
    if ((u32)(D_001D4CF0 - 0x1E) < 7) return 0;
    if (b == 0x18) return 0;
    if ((u32)(b - 0x1F) < 5) b = 3;
    if (D_001D545C == 0x1E) return 0;
    if (D_001D545C == 0x24) return 0;
    if (b == 0x1E) return 0;
    if (b == 0x24) return 0;
    func_0012BE28(&D_001D4BE0);
    func_0013AD58(&D_001D4BE0);
    func_0042E8D8();
    func_0042DB40(D_001A9318 + (D_001D545C << 11));
    if (D_00142430_00399C90.f148 == -1 || ((S_399C90 *)((u8 *)&D_00142430_00399C90 + D_00142430_00399C90.f148 * 0xA0))->h18 < 0) return a == 0;
    D_00142430_00399C90.f17C |= a;
    if (D_00142430_00399C90.f17C != 0) {
        if (a == 0) D_001D4CEC_00399C90 |= 0x200;
        if (D_00142430_00399C90.f15C < 3 && D_00142430_00399C90.f164 < 0) {
            D_00142430_00399C90.f150 = D_001D545C;
            old = 0;
            if (b >= 0) {
                D_001D545C = b;
                q = &D_001D5570[b];
                old = *q;
                if (old == 0) *q = 1;
            }
            D_00142430_00399C90.e[D_00142430_00399C90.h18].f4 = D_00142660_00399C90.f0;
            D_00142430_00399C90.e[D_00142430_00399C90.h18].f0 = D_001D545C;
            D_00142430_00399C90.e[D_00142430_00399C90.h18].fC = D_001D5528;
            *(V8_399C90 *)((u8 *)&D_00142430_00399C90 + D_00142430_00399C90.h18 * 0x1C + 0x40) = D_001D4BE0;
            D_00142430_00399C90.e[D_00142430_00399C90.h18].f8 = D_00142660_00399C90.b32;
            func_00432850(D_001C5BD0, 0, D_002E74B8);
            func_00432850(D_001CBBD0, D_00142430_00399C90.f150, D_002E7748);
            if (b >= 0) {
                D_001D5570[D_001D545C] = old;
                D_001D545C = D_00142430_00399C90.f150;
            }
            if (D_00142430_00399C90.f164 < 0) {
                D_00142430_00399C90.f164 = 0xF;
                D_00142430_00399C90.f168 = D_00142430_00399C90.f148;
            }
        }
    }
    return D_00142430_00399C90.f164 == 0xF;
}
/* localdecomp:end func_00432CB0 */
