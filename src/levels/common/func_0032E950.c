#include "common.h"

/* localdecomp:start func_0032E950 */
typedef int u128_t __attribute__((mode(TI)));
typedef int Q_32E950 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32E950;
typedef struct {
    u8 pad[0x68];
    u8 *f68;
} O_32E950;
extern u128_t D_001EAAA0;
extern s32 D_001A71A0[];
extern void func_004C41E8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern s32 func_003FC730(void);
extern s32 func_003F9498(f32, void *, s32, s32);
s32 func_0032E950(V4_32E950 *out, V4_32E950 *q, O_32E950 *obj, f32 scale) {
    V4_32E950 v;
    V4_32E950 w;
    Q_32E950 x, y, r;
    u32 k;
    u8 *p;
    u8 *s;
    func_004C41E8((u8 *)obj + 0x10, &v);
    func_0040BE90(&v, &v, -scale);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*q));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(w) : "j"(r));
    if (func_003F8448(q, &w, 0x10, obj, 0) != 0) {
        k = func_003FC730();
        if (k >= 2) {
            if (k != 0xB && k != 7 && k != 0xD && k != 0xE) {
                p = obj->f68;
                *(u128_t *)out = D_001EAAA0;
                s = (u8 *)&D_001EAAA0 - 0x20;
                if (*(s32 *)(s + 0x18) != D_001A71A0[0]) {
                    if (func_003F9498(0.9f, q, 2, D_001A71A0[0]) == 0) {
                        s32 t = *(s32 *)(s + 0x18);
                        if (t != 0 && p != 0) *(s32 *)(p + 0x70) = t;
                        else *(s32 *)(p + 0x70) = 0;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_0032E950 */
