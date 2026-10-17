#include "common.h"

extern s32 D_001DB178[];
extern s32 D_001DB178[2];
extern s32 D_001DB160[];
extern s32 D_001DB160[2];
extern u8 *func_004C8E40(u8 *);

u8 *func_004CBAB0(u8 *p) {
    u8 *q;
    u8 *a, *b, *c;
    s32 i;
    func_004C8E40(p);
    func_004C8E40(p + 0x3C);
    func_004C8E40(p + 0x78);
    func_004C9650(p + 0xD0);
    func_004C93D0(p + 0x110);
    func_004C8E40(p + 0x140);
    func_004C8E40(p + 0x17C);
    func_004C9650(p + 0x1D0);
    func_004C93D0(p + 0x210);
    func_004C8E40(p + 0x244);
    func_004C8E40(p + 0x280);
    q = p + 0x2BC;
    for (i = 7; i != -1; i--) { func_004C8E40(q); q += 0x3C; }
    func_004C8E40(p + 0x49C);
    func_004C8E40(p + 0x4D8);
    func_004C8E40(p + 0x514);
    func_004C8E40(p + 0x550);
    func_004C8E40(p + 0x58C);
    func_004C93D0(p + 0x5C8);
    func_004C93D0(p + 0x5F8);
    func_004C8E40(p + 0x628);
    q = p + 0x664;
    for (i = 7; i != -1; i--) { func_004C93D0(q); q += 0x30; }
    func_004CB5D8(p + 0x7E8);
    func_004CB5D8(p + 0x870);
    func_004CB5D8(p + 0x8F8);
    func_004CB5D8(p + 0x980);
    func_004CB5D8(p + 0xA08);
    func_004CB5D8(p + 0xA90);
    func_004C8788(p + 0xB18);
    *(u8 **)(p + 0xB18) = (u8 *)D_001DB178;
    func_004C8788(p + 0xB1C);
    *(u8 **)(p + 0xB1C) = (u8 *)D_001DB160;
    return p;
}
