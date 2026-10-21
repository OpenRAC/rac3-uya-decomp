#include "common.h"

/* localdecomp:start func_00458230 */
extern void func_004583C0(u8 *, u8 *, f32);
extern u8 *func_00445EB8(u8 *);
extern void func_004585E8(u8 *, u8 *);
extern s32 func_00459DA8(u8 *);
extern s32 func_00459E50(u8 *, u8 *);
extern void func_00443A90(u8 *, s32, s32, u8 *, f32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define U16(p, o) (*(u16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

void func_00458230(u8 *a0, u8 *a1) {
    s32 hit = 0;
    u8 *p;
    f32 y;
    f32 lim;

    func_004583C0(a0, a1, 0.0f);
    if (S32(a1, 216) != -1 && S16(a1, 192) != 0) {
        p = func_00445EB8(a0);
        if (p != 0 && U8(p, 73) != 0 && U16(p, 74) != 0 &&
            ((U16(p, 74) >> S32(a1, 216)) & 1)) {
            hit = 1;
            S32(a1, 148) |= 0x200;
        }
    }
    if (hit) {
        func_004585E8(a0, a1);
        func_004583C0(a0, a1, 0.0f);
    }
    y = F32(a0, 24);
    lim = F32(a1, 144);
    if (y <= lim) {
        if (lim <= y - F32(a1, 168)) {
            F32(a0, 24) = lim;
        }
        U16(a1, 194) = 0;
        U16(a1, 192)++;
    } else {
        U16(a1, 192) = 0;
        U16(a1, 194)++;
    }
    if (S32(a1, 156) & 1) {
        if (func_00459DA8(a0)) {
            S32(a1, 156) &= ~1;
        } else {
            S32(a1, 148) |= 0x100;
        }
    }
    if (S32(a1, 56) & 0x200) {
        if (func_00459E50(a0, a1)) {
            func_00443A90(a0, 0, 0x10000, a0 + 16, 255.0f);
        }
    }
}
/* localdecomp:end func_00458230 */
