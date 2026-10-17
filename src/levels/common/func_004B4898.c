#include "common.h"

typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[238];
} E_4B4898;

typedef struct {
    u8 pad0[0x1200];
    s32 w1200;
    u8 pad1204[0x1228 - 0x1204];
    s32 w1228;
    u8 pad122C[0x25C0 - 0x122C];
    s32 w25C0;
} S_4B4898;

extern S_4B4898 D_001A4BE0;
extern u8 D_001425C0[];
extern E_4B4898 D_002C3200[];
extern void func_004B4418(s32, s32);

void func_004B4898(void) {
    S_4B4898 *s = &D_001A4BE0;
    s32 i = s->w1228;
    if (i >= 0 && ((E_4B4898 *)((u8 *)D_002C3200 + D_001425C0[i] * 240))->b1 != 0 && s->w1200 != 0) {
        func_004B4418(s->w1200, s->w25C0);
    }
}
