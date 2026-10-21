#include "common.h"

/* localdecomp:start func_003D07C0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x60];
    s32 i60;
    s32 i64;
    u8 pad68[8];
    u8 b70[0x10];
    u8 b80[0x10];
} O_3D07C0;
extern u8 *D_001E0180;
extern u8 *D_0016C580[];
extern f32 D_001D9950;
extern u8 D_0023AD40[];
extern s32 D_001D9910;
extern s32 D_001D9920;
extern s32 D_001D98E0;
extern s32 D_001D9940;
extern s32 D_001D9930;
extern s32 D_001D98F0;
extern s32 D_001D9900;
extern void func_0040C638(void *, void *);
extern void func_0040BBA8(void *, s32, s32);
extern void func_00437350(u8 *, s32, void *);
extern void func_0040CAC0(void *, s32, f32);
extern void func_00454448();

void func_003D07C0(s32 a0, O_3D07C0 *obj) {
    u8 *src = D_001E0180 + obj->i64 * 128;

    *(u128_t *)(D_0016C580[0] + 0x10) = *(u128_t *)(src + 0x30);
    *(u128_t *)(D_0016C580[0] + 0xF0) = *(u128_t *)(src + 0x70);
    func_0040C638(D_0016C580[0] + 0xC0, D_0016C580[0] + 0xF0);
    if (obj->i60) {
        func_0040BBA8(obj->b70, 0, 0x40);
        func_00437350(D_0016C580[0], 0, obj->b70);
        func_0040CAC0(obj->b80, 1, -1.3962634f);
    }
    D_001D9950 = *(f32 *)(D_0016C580[0] + 0x18);
    func_00454448(D_0016C580[0], D_0023AD40, 0, 0, &D_001D9910, &D_001D9920, &D_001D98E0, &D_001D9940, &D_001D9930, &D_001D98F0, &D_001D9900);
}
/* localdecomp:end func_003D07C0 */
