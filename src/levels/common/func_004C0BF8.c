#include "common.h"

typedef struct {
    u8 p0[0x20];
    s32 w32;
} E_4C0BF8;

typedef struct {
    u8 p0[0x80];
    s32 idx;
    s32 active;
    u8 p88[0x9C];
    E_4C0BF8 e[1];
} B_4C0BF8;

extern B_4C0BF8 D_00244740;
extern s32 D_00142660[];
extern char *func_004181A0(s32 id);
extern void func_00512FE8(s32 id, char *s);
extern void func_00512AB0(s32 id, s32 a, s32 b);

void func_004C0BF8(void) {
    B_4C0BF8 *b = &D_00244740;
    s32 idx = b->idx;

    if (b->active == 0) {
        func_00512FE8(0x480014, func_004181A0(2252));
        func_00512FE8(0x480015, func_004181A0(256));
        func_00512AB0(0x480016, 1, 0);
        return;
    }
    if (b->e[idx].w32 <= D_00142660[0]) {
        func_00512FE8(0x480014, func_004181A0(2274));
        func_00512FE8(0x480015, func_004181A0(2271));
        func_00512FE8(0x480016, func_004181A0(2256));
    } else {
        func_00512FE8(0x480016, func_004181A0(2255));
        func_00512FE8(0x480015, func_004181A0(2251));
    }
    func_00512AB0(0x480016, 1, 1);
}
