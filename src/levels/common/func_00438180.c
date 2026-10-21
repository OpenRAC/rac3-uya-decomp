#include "common.h"

/* localdecomp:start func_00438180 */
typedef int Q_438180 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_438180;
typedef struct {
    s32 f0;
    u16 x, y, z;
    s16 s10;
    s16 s12;
    u8 b14, b15;
    u8 b16, b17, b18, b19, b20, b21, b22, b23, b24, b25;
    s16 s26, s28;
    u8 pad[2];
} E_438180;
typedef struct {
    u8 pad0[64];
    u8 b64, b65, b66, b67;
    u8 pad1[112];
    s32 f180;
} G_438180;

extern s32 D_001E0134;
extern E_438180 *D_001E0140;
extern s32 D_001D6694;
extern G_438180 D_001A30B0;
extern u8 D_001DFA64;
extern u8 D_001DFA65;
extern u8 D_001DFA66;
extern f32 D_001DFA68;
extern f32 D_001DFA6C;
extern f32 D_001DFA70;
extern f32 D_001DFA74;
extern f32 func_0040BF90(V4_438180 *);
extern void func_004388E8(u8 *, u32, s32, s32, s32);
extern void func_0045BB60(s32, s32, s32);
extern void func_003FEBC8(s32);

void func_00438180(u8 *obj) {
    V4_438180 t;
    V4_438180 d;
    Q_438180 a, b, r;
    f32 best;
    f32 f;
    s32 i;
    s32 bi;

    bi = -1;
    best = 1000000.0f;
    for (i = 0; i < D_001E0134; i++) {
        t.x = (f32)D_001E0140[i].x * 0.25f;
        t.y = (f32)D_001E0140[i].y * 0.25f;
        t.z = (f32)D_001E0140[i].z * 0.25f;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_438180 *)(obj + 16)));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(t));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
        f = func_0040BF90(&d);
        if (f < best) {
            best = f;
            bi = i;
        }
    }
    if (bi == -1) return;
    if (best > 400.0f) return;
    func_004388E8(obj, (D_001E0140[bi].b18 << 16) + (D_001E0140[bi].b17 << 8) | D_001E0140[bi].b16, 0, 0, 0);
    *(s32 *)(obj + 56) = D_001E0140[bi].f0;
    if (D_001D6694 != 2) {
        if (D_001E0140[bi].b22) {
            D_001A30B0.f180 = D_001E0140[bi].s10;
            D_001A30B0.b64 = D_001E0140[bi].b19;
            D_001A30B0.b65 = D_001E0140[bi].b20;
            D_001A30B0.b66 = D_001E0140[bi].b21;
            D_001A30B0.b67 |= 7;
        }
        if (D_001D6694 != 2) {
            func_0045BB60(D_001E0140[bi].s12, 1, 1024);
        }
    }
    if (D_001E0140[bi].s26 < D_001E0140[bi].s28) {
        D_001DFA64 = D_001E0140[bi].b23;
        D_001DFA65 = D_001E0140[bi].b24;
        D_001DFA66 = D_001E0140[bi].b25;
        D_001DFA68 = (f32)D_001E0140[bi].s26 * 1024.0f;
        D_001DFA6C = (f32)D_001E0140[bi].s28 * 1024.0f;
        D_001DFA70 = (f32)D_001E0140[bi].b14;
        D_001DFA74 = (f32)D_001E0140[bi].b15;
        func_003FEBC8(0);
    }
}
/* localdecomp:end func_00438180 */
