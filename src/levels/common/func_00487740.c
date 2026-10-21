#include "common.h"

/* localdecomp:start func_00487740 */
typedef struct {
    s32 obj;
    u8 pad[81];
    char name[91];
} Slot_00487740;

extern s32 D_001D8A64;
extern Slot_00487740 D_00233E58[];
extern char D_00233EAD[];
extern char D_001D8BD8[];
extern s32 func_00435C80(s32);
extern s32 func_00435D18(s32);
extern u8 *func_00434A78(s32);
extern s32 func_004181A0(s32);
extern void func_0011B2E8(char *, char *, s32);

void func_00487740(s32 i) {
    s32 obj;
    s32 v;
    u8 *m;

    if (D_001D8A64 < 0) {
        return;
    }
    obj = D_00233E58[i].obj;
    v = func_00435C80(obj);
    if (v == 0) {
        v = func_00435D18(obj);
    }
    if (v != 0) {
        m = func_00434A78(v);
    } else {
        m = 0;
    }
    if (m != 0) {
        v = func_004181A0(*(s16 *)(m + 8));
        func_0011B2E8(D_00233EAD + i * 176, D_001D8BD8, v);
        return;
    }
    D_00233E58[i].name[0] = 0;
}
/* localdecomp:end func_00487740 */
