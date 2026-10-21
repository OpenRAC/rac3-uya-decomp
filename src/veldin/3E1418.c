#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E1418);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E1558);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E1560);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E1568);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E1748);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E1918);

/* localdecomp:start func_003E1A20 */
typedef int Q __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct M__3E1A20 M_3E1A20;
struct M__3E1A20 {
    u8 pad0[0x10]; V4 pos;
    u8 state; u8 pad21[2]; u8 x23;
    u8 pad24[0x34 - 0x24]; u16 x34;
    u8 pad36[0x68 - 0x36]; u8 *x68;
    u8 pad6C[0xAA - 0x6C - 0];
};
typedef struct { u8 pad0[0x23]; u8 x23; u8 pad24[0xAA - 0x24]; s16 xAA; } C_3E1A20;
typedef struct {
    u8 pad0[0x10]; V4 pos;
    u8 state; u8 pad21[2]; u8 x23;
    u8 pad24[0x34 - 0x24]; u16 x34;
    u8 pad36[0x68 - 0x36]; u8 *x68;
    u8 pad6C[0xB8 - 0x6C]; C_3E1A20 *xB8;
    u8 padBC[0xC0 - 0xBC]; u8 xC0[16];
} O_3E1A20;
extern f32 D_001DFBD0_3E1A20;
extern void func_0044DC80_3E1A20(void *, void *);
extern void func_003F63A8_3E1A20(void *);
extern void func_0040C2D0_3E1A20(void *, void *, void *);
extern s32 func_00440848_3E1A20(s32);
extern void func_003E1918_3E1A20(void *);
extern s32 func_0040BAC0_3E1A20(void *);
extern void func_00441FB8_3E1A20(void *, s32, s32);
extern void func_00436220_3E1A20(void *);
void func_003E1A20(O_3E1A20 *o) {
    V4 buf, t;
    u8 *v = o->x68;
    Q qa, qb;
    func_0044DC80_3E1A20(o, &buf);
    func_003F63A8_3E1A20(o);
    func_0040C2D0_3E1A20(&t, v + 0x20, o->xC0);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(t));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(o->pos));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "0"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(qa));
    switch (o->state) {
    case 0:
        if (o->xB8) {
            o->x23 = o->xB8->x23;
        }
        if (o->xB8->xAA != 0x1A54 || func_00440848_3E1A20(4) == 0) {
            func_003E1918_3E1A20(o);
        }
        if (func_0040BAC0_3E1A20(v + 0x34) == 0) {
            if (!(0.95f < D_001DFBD0_3E1A20) || func_00440848_3E1A20(10) != 0) {
                return;
            }
        }
        func_00441FB8_3E1A20(o, 1, -1);
        o->x34 |= 0x2800;
        break;
    case 1:
        if (o->x23 < 2) {
            func_00436220_3E1A20(o);
        } else {
            o->x23 -= 2;
        }
        break;
    }
}
/* localdecomp:end func_003E1A20 */

LINKER_REMNANT("asm/veldin/remnants", func_003E1B60);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E1B68);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E2118);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E2218);

