#include "common.h"

/* localdecomp:start func_0051C1D8 */
extern s32 *func_00511BF8();
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
void **func_00511CE8(s32 *, s32);
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
typedef struct S_003E9C50_obj S_003E9C50_obj;
typedef struct {
    u8 pad0[8];
    void (*f8)(S_003E9C50_obj *, s32);
    void (*fC)(S_003E9C50_obj *);
} S_003E9C50_vt;
struct S_003E9C50_obj { s32 f0; S_003E9C50_vt *vt; };
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3EB180;
extern u8 D_001DC258;
extern void **func_00511CE8();

s32 *func_00511BF8(s32 *);                  /* extern */
void **func_00511CE8(s32 *, s32);           /* extern */
void func_0051DC38_003EB358(void *);
extern u8 D_001DC100_003EB358;
extern u8 D_001DC258;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001E1660[];

void func_0051C1D8(void *arg0, s32 arg1) {
    s32 *var_v0;
    void **temp_v0;

    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001DC258;
    if (D_001E1660->f4 != 0) {
        var_v0 = (s32 *)D_001E1660;
    } else {
        var_v0 = func_00511BF8((s32 *)D_001E1660);
    }
    temp_v0 = func_00511CE8(var_v0, 1);
    if (temp_v0 != 0) {
        (*(s32 (**)(void **, s32))((u8 *)(*temp_v0) + 0xC))(temp_v0, (*(s32 *)((u8 *)(arg0) + 0x2C)));
        (*(s32 *)((u8 *)(arg0) + 0x2C)) = 0;
    }
    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001DC100_003EB358;
    if (arg1 & 1) {
        func_0051DC38_003EB358(arg0);
    }
}
/* localdecomp:end func_0051C1D8 */
