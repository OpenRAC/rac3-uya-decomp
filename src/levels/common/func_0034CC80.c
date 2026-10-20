#include "common.h"

typedef struct {
    u8 pad0[124];
    s32 f124;
    u8 pad128[8];
    s32 f136;
    u8 pad140[20];
} Sub_0034CC80;

typedef struct {
    u8 pad0[48];
    Sub_0034CC80 sub;
} Entry_0034CC80;

extern Entry_0034CC80 D_0027FBA0[];
extern void func_0034CF60(s32, Entry_0034CC80 *);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern void func_004082B0(void *, s32, s32, s32, f32, f32, f32);

void func_0034CC80(s32 arg0) {
    s32 i;
    Entry_0034CC80 *e;
    Sub_0034CC80 *s;

    for (i = 47; i >= 0; i--) {
        e = &D_0027FBA0[47 - i];
        s = &e->sub;
        if (s->f124 == arg0) {
            func_0034CF60(arg0, e);
            if (s->f136 == 0) {
                func_004082B0(s, 49, (func_00440878(80, 96) << 24) | 0x103080, 1, 0.5f, 0.1f, func_00440978());
                func_004082B0(s, 49, (func_00440878(80, 96) << 24) | 0xFFFFFF, 1, 0.5f, 0.1f, func_00440978());
            }
        }
    }
}
