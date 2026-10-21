#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_004210F0);

/* localdecomp:start func_004212E0 */
typedef int Q __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 pad0[0x10]; V4 pos; } O_4212E0;
extern f32 func_004408C0_4212E0(f32, f32);
extern void func_0040C0F0_4212E0(void *, void *, f32);
extern void func_00448CD0_4212E0(void *, f32);
extern s32 func_00440848_4212E0(s32);
extern u8 *func_003CBFB8_4212E0(s32, void *, void *, s32, f32, s32);
extern u8 *func_003AD288_4212E0(s32, void *, void *, s32, f32);
extern void func_004A72A8_4212E0(s32, s32, void *, s32);
void func_004212E0(O_4212E0 *o, V4 *p) {
    V4 base, t, r, c;
    Q qa, qb;
    u8 *m;
    base = *p;
    r.x = func_004408C0_4212E0(-15.0f, 15.0f);
    r.y = func_004408C0_4212E0(-15.0f, 15.0f);
    r.z = func_004408C0_4212E0(10.0f, 20.0f);
    c = r;
    func_0040C0F0_4212E0(&c, &c, -0.5f);
    func_00448CD0_4212E0(&c, 0.3f);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(r));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(o->pos));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "0"(qb), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(qb));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(t));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(base));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "0"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(qa));
    if (func_00440848_4212E0(2) == 0) {
        m = func_003CBFB8_4212E0(0, &t, &c, 0, 0.0f, 200);
    } else {
        m = func_003AD288_4212E0(0, &c, &t, 0, 0.0f);
    }
    if (m != 0 && func_00440848_4212E0(2) == 0) {
        func_004A72A8_4212E0(0, 0, m, 0x1F7C);
    }
}
/* localdecomp:end func_004212E0 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00421438);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_004214C0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00421DD0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00421DD8);

