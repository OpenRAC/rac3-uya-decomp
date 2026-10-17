#include "common.h"

typedef struct S_4DCF08_Obj {
    u8 pad0[0x64];
    void (*fn)(struct S_4DCF08_Obj *);
} S_4DCF08_Obj;

typedef struct {
    u8 pad0[0x1A58];
    S_4DCF08_Obj *obj;
    u8 pad1A5C[0xB64];
    s32 f25C0;
} S_4DCF08;

extern s32 D_001DBD94;
extern S_4DCF08 D_001A4BE0;
extern u8 D_001A65F0[];
extern S_4DCF08_Obj *func_00435E70(s32, s32);
extern void func_00452E70(S_4DCF08_Obj *, s32);
extern void func_0044CB08(s32, S_4DCF08_Obj *, s32, s32);
extern void func_004E5E40(void *, s32);

void func_004DCF08(void) {
    S_4DCF08 *s;
    if (D_001DBD94 == 0) {
        return;
    }
    s = &D_001A4BE0;
    if (s->obj == 0) {
        s->obj = func_00435E70(6837, 128);
        if (s->obj == 0) {
            goto end;
        }
        func_00452E70(s->obj, s->f25C0);
        if (s->obj == 0) {
            goto end;
        }
    }
    func_0044CB08(s->f25C0, s->obj, 2, 0);
    s->obj->fn(s->obj);
end:
    func_004E5E40(D_001A65F0, 1);
}
