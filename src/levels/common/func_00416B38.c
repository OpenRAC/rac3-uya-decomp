#include "common.h"

/* localdecomp:start func_00416B38 */
typedef struct {
    u8 pad0[0x84];
    u16 field_84;
    u8 pad86[8];
    u16 field_8E;
    u8 pad90[0x60];
} Entry;

extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern u8 D_00142D40[];
extern s32 D_001427F0[];
extern Entry D_002C5640[];
extern s32 func_004344A0(void);
extern void func_00416BF8(s32);
extern void func_00416A10(s32);

void func_00416B38(s32 idx) {
    Entry *e;

    if (D_00142CA0[idx] == 0) {
        D_00142CA0[idx] = 1;
        D_00142D40[idx] = 1;
        e = &D_002C5640[D_001425C0[idx]];
        func_004344A0();
        if (e->field_84 != 0 && D_001427F0[idx] == 0) {
            D_001427F0[idx] = e->field_8E;
        }
        func_00416BF8(idx);
        func_00416A10(idx);
    }
}
/* localdecomp:end func_00416B38 */
