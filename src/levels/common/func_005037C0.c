#include "common.h"

typedef struct {
    u8 pad0[4648];
    s32 w1228;
    u8 pad1[9720 - 4652];
    s32 w25F8;
    u8 pad2[10368 - 9724];
    u16 h2880;
    u16 h2882;
    u8 pad3[10432 - 10372];
    u8 b28C0;
} Veldin1A4BE0;

typedef struct {
    u8 pad0[372];
    u16 h174;
    u16 pad1;
    u32 w178;
    u32 w17C;
} Veldin1A7C10;

typedef struct {
    u8 pad0[16];
    s32 w10;
} Veldin142660;

typedef struct {
    u8 pad0[138];
    u16 h8A;
    u8 pad1[240 - 140];
} Veldin2C5640;

extern Veldin1A4BE0 D_001A4BE0;
extern Veldin1A7C10 D_001A7C10;
extern Veldin142660 D_00142660;
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern Veldin2C5640 D_002C5640[];
extern s32 D_001D4C40;
extern u32 D_001D4C38;
extern s32 D_001D545C;
extern void func_00503760(s32);
extern s32 func_0050D978(s32);
void func_005037C0(void) {
    s32 cur;
    s32 start;
    u32 t;
    Veldin2C5640 *e;

    if (D_001A4BE0.b28C0 == 0) {
        return;
    }
    D_001A4BE0.b28C0 = 0;
    if (D_001A4BE0.w1228 != 9) {
        start = D_00142660.w10;
        do {
            func_00503760(3);
            cur = D_00142660.w10;
            if (D_001427F0[cur] != 0) {
                break;
            }
            e = &D_002C5640[D_001425C0[cur]];
            if (e->h8A == 0) {
                break;
            }
        } while (cur != start);
    } else {
        cur = func_0050D978(D_001D4C40);
    }
    if (D_001A4BE0.w1228 == cur) {
        return;
    }
    if (D_001A7C10.h174 < 0xFFFF) {
        D_001A7C10.h174++;
    }
    t = D_001D4C38;
    if (D_001A7C10.w178 < t) {
        D_001A7C10.w178 = t;
    }
    D_001A7C10.w17C = D_001A7C10.w17C | (1 << D_001D545C) | 0x80000000;
    D_001A4BE0.w25F8 = cur;
    D_001A4BE0.h2880 = 0;
    D_001A4BE0.h2882 = 0;
}
