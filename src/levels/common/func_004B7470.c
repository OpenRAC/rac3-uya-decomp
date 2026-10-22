#include "common.h"

typedef struct {
    u8 used;
    u8 pad1[3];
    u16 id;
    u8 pad6[0x5A];
} S_4B7470;

extern S_4B7470 D_002393F0[];
extern S_4B7470 *func_004B7010(void);
extern void func_004B70D0(S_4B7470 *, s32, s32);

u32 func_004B7470(s32 n, s32 *args) {
    S_4B7470 *e;
    s32 i;
    u32 r;
    if (n & 1) {
        return 0xFFFFFFFF;
    }
    e = func_004B7010();
    if (e != 0) {
        for (i = 0; i < n; i += 2) {
            func_004B70D0(e, args[0], args[1]);
            args += 2;
        }
    }
    r = 0xFFFFFFFF;
    if (e != 0) {
        r = e->id | (((u32)((u8 *)e - (u8 *)D_002393F0) / 0x60) << 16);
    }
    return r;
}
