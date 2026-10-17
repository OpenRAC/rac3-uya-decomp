#include "common.h"

typedef struct O { struct VT *vt; u8 pad[0x18]; } O;
struct VT { u8 pad[0x10]; void (*fn)(O *, s32); };
typedef struct { u8 pad[0x64]; void (*fn[4])(void); s32 count; } Q_3E1548;
typedef struct { u8 pad[0x50]; void (*fn[4])(void); s32 count; } Q_3E15D8;
typedef struct { u32 i, max, wrap; s32 c; s32 (*fn)(s32, u32); } S_E19C8;

void func_00512150(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x10);
    if (fn != 0) {
        fn();
    }
}
