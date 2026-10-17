#include "common.h"

typedef struct {
    u8 pad0[0x25E4];
    u8 mode;
    u8 pad25E5[6];
    u8 field_25EB;
    u8 pad25EC[0x288];
    s16 field_2874;
} Game;

typedef struct {
    u8 pad0[0x24];
    s32 field_24;
    u8 pad28[0xC8];
} Entry;

extern Game D_001A4BE0;
extern s32 D_001DBC14;
extern u8 D_001425C0[];
extern Entry D_002C5F80[];
extern s32 func_004F4418(s32);
extern s32 func_004EBE50(void);

s32 func_004EBEA0(s32 a0) {
    switch (D_001A4BE0.mode) {
    case 1:
        return D_001DBC14 == 0 ? 20 : 29;
    case 3:
        return 1;
    }
    if (a0 != 0 && D_001A4BE0.field_25EB != 0 && D_001A4BE0.field_2874 == 0) {
        s32 i = func_004F4418(0);
        return ((Entry *)(D_001425C0[i] * 240 + (u8 *)D_002C5F80))->field_24;
    }
    return func_004EBE50() ? 74 : 0;
}
