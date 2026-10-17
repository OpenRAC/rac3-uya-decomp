#include "common.h"

typedef struct {
    u8 pad[0x80];
} S_1A30B0;

extern S_1A30B0 D_001A30B0[];
extern s32 D_001A71A0[];
extern void func_00474E20(s32);
extern void func_00408760(void *);

void func_003505C8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i = *(s32 *)(v + 0x20);

    if (i != -1) {
        u8 *p = (u8 *)&D_001A30B0[i];
        if (*(s32 *)(p + 0xDC) == D_001A71A0[0] && *(p + 0xD0) != 0) {
            func_00474E20(i);
        }
    }
    *(s32 *)(v + 0x20) = -1;
    func_00408760(m);
}
