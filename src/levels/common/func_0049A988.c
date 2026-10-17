#include "common.h"
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
extern O_49A988 *func_00490968(s32);
extern void func_0047B7B8(s32);
extern s32 D_001D950C;
extern s32 D_001D9510;
void func_0049A988(void) {
    O_49A988 *o = func_00490968(0);
    o->vt->fn(o);
    func_0047B7B8(D_001D950C);
    func_0047B7B8(D_001D9510);
}
