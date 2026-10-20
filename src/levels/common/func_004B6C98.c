#include "common.h"

typedef struct {
    s32 id;
    u8 pad4[12];
    u8 b16;
    u8 b17;
    u8 pad18[2];
} Slot_004B6C98;

typedef struct {
    u8 pad0[128];
    s32 cur;
    u8 pad84[188];
    Slot_004B6C98 slots[79];
    u8 pad76C[16];
    s32 unk77C;
} S_00244740;

typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} S_002C5640;

typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} Info_004B6C98;

extern S_00244740 D_00244740[];
extern u8 D_001425C0[];
extern S_002C5640 D_002C5640[];
extern s32 func_00417810(Info_004B6C98 *, s32, s32);

s32 func_004B6C98(void) {
    Info_004B6C98 info;
    s32 val = 0;
    s32 cur = D_00244740[0].cur;

    if (D_00244740[0].slots[cur].b17 != 0) {
        val = 0;
        if (func_00417810(&info, D_00244740[0].slots[cur].id, 5) != 0) {
            val = info.value;
        }
    } else if (D_00244740[0].slots[cur].b16 == 0) {
        val = (D_001425C0[D_00244740[0].slots[cur].id])[D_002C5640].value;
    }
    if (D_00244740[0].unk77C != 0) {
        val = val * 9 / 10;
    }
    return val;
}
