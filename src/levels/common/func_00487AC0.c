#include "common.h"

/* localdecomp:start func_00487AC0 */
typedef struct VObj_487AC0 VObj_487AC0;
typedef struct {
    u8 pad[12];
    void (*fn)(VObj_487AC0 *self);
} VTbl_487AC0;
struct VObj_487AC0 {
    s32 pad;
    VTbl_487AC0 *vtbl;
};

extern s32 D_001D8A70;
extern s32 D_001D8A74;
extern s32 D_001D8A78;
extern s32 D_001D8A80;
extern s32 D_001D8A9C;

extern void func_0047B7B8(s32 a);
extern void func_004A6E88(s32 a);
extern VObj_487AC0 *func_00490968(s32 i);
extern void func_0045CA60(s32 a);

void func_00487AC0(void) {
    VObj_487AC0 *o;
    func_0047B7B8(D_001D8A70);
    func_0047B7B8(D_001D8A74);
    func_0047B7B8(D_001D8A78);
    func_0047B7B8(D_001D8A80);
    if (D_001D8A9C != -1) {
        func_004A6E88(D_001D8A9C);
        D_001D8A9C = -1;
    }
    o = func_00490968(0);
    o->vtbl->fn(o);
    o = func_00490968(1);
    o->vtbl->fn(o);
    o = func_00490968(2);
    o->vtbl->fn(o);
    func_0045CA60(1);
}
/* localdecomp:end func_00487AC0 */
