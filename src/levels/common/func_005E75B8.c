#include "common.h"

typedef struct {
    u8 pad0[0x1C4];
    s32 unk1C4;
    u8 pad1C8[0x4];
    s32 unk1CC;
    u8 pad1D0[0x5C0 - 0x1D0];
} D_00225900_t;

typedef struct {
    u8 pad0[0x2534];
    D_00225900_t *unk2534;
} func_006197C0_t;

extern s32 func_0060F870(void);
extern func_006197C0_t *func_006197C0(s32);
extern void func_005D4508(s32, s32);
extern s32 func_005E57B0(s32);
extern void func_005E6028(s32, s32);
extern void func_005E89A0(s32);
extern void func_005E8A80(void);
extern void func_005E8C28(void);
extern void func_005E90B0(void);
extern void func_005E9748(void);
extern s32 func_005E6F30(void);
extern void func_005E6F38(void);
extern void func_0060DE20(s32);
extern s32 func_005E6F40(void);
extern void func_0060F998(s32);
extern D_00225900_t D_00225900[];
extern s32 D_001D856C;
extern u8 D_00242B2C;

void func_005E75B8(s32 arg0) {
    s32 mode = 0;
    func_006197C0_t *p;
    s32 val;

    switch (func_0060F870()) {
    case 0:
        mode = 0;
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    }
    p = func_006197C0(func_0060F870());
    p->unk2534->unk1CC = 2;
    val = p->unk2534->unk1C4;
    D_001D856C = p->unk2534 - D_00225900;
    func_005D4508(func_0060F870(), 10);
    func_005E6028(func_005E57B0(mode), val);
    func_005E89A0(arg0);
    func_005E8A80();
    func_005E8C28();
    func_005E90B0();
    func_005E9748();
    if (func_005E6F30()) {
        func_005E6F38();
        func_0060DE20(arg0);
        if (D_00242B2C == 0) {
            func_0060F998(func_005E6F40());
        }
    }
}
