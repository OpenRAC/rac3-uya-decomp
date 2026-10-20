#include "common.h"

typedef int s128_003985C0 __attribute__((mode(TI)));

typedef struct {
    u8 pad[112];
    f32 f112;
    u8 pad2[124];
} Ent_003985C0;

extern u8 D_001425FF[];
extern Ent_003985C0 D_002C5640[];
extern u8 D_001EEB00[];
extern void func_0040BE90(void *, f32);
extern s32 func_003FB1D0(void *, s32, void *, s32, f32);
extern void func_004445E0(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_003985C0(u8 *obj, s32 unused, s32 arg) {
    s128_003985C0 v;
    s128_003985C0 q;
    f32 scale;
    s32 r;

    func_0040BE90(&v, -3.0f);
    scale = (D_002C5640 + D_001425FF[0])->f112;
    r = func_003FB1D0(obj + 16, 16, obj, 0, 0.75f);
    q = *(s128_003985C0 *)(obj + 16);
    func_004445E0(obj, &q, D_001EEB00, r, arg, 0x1110000, 3, 1, -1, scale, 1.0f, 1.0f);
}
