#include "common.h"

/* localdecomp:start func_0031D9D0 */
typedef int Q_31D9D0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_31D9D0;
extern void func_0031DC98(void);
extern f32 func_004408C0(f32, f32);
extern void func_004C4190(void *, void *, f32);
extern void func_004C6EC8(void *, void *);
extern void func_004C4AD8(s32, void *, s32);
extern void func_0031DB28(void *, void *);
extern s32 func_0040D0C0(void *, f32);
extern s32 func_0040BA90(void *);
extern void func_004C4AB8(s32);
extern void func_00436220(void *);
extern void func_004026A0(void *, void *);

void func_0031D9D0(u8 *obj)
{
    V4_31D9D0 a, b;
    u8 s = obj[0x20];
    u8 *q = *(u8 **)(obj + 0x68);
    u8 *p;
    switch (s) {
    case 0:
        obj[0x20] = 1;
    case 1:
        p = obj + 0x10;
        a = *(V4_31D9D0 *)p;
        {
            Q_31D9D0 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_31D9D0 *)(obj + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_31D9D0 *)q));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_31D9D0 *)(obj + 0x10)) : "j"(x));
        }
        func_004C4190(p, q, func_004408C0(4.0f, 7.0f) * 0.000277777785f);
        func_004C6EC8(p, p);
        func_004C4AD8(*(s32 *)(q + 0x1C), q, 0);
        func_0031DB28(obj, &a);
        b = *(V4_31D9D0 *)(obj + 0x10);
        *(f32 *)((u8 *)&b + 0xC) = 0.1f;
        if (func_0040D0C0(&b, 96.0f) > 0) {
            if (func_0040BA90(q + 0x10) != 0) obj[0x20] = 2;
            break;
        }
        goto C;
    case 2:
C:
        func_004C4AB8(*(s32 *)(q + 0x1C));
        func_00436220(obj);
        return;
    default:
        break;
    }
    func_004026A0(func_0031DC98, obj);
}
/* localdecomp:end func_0031D9D0 */
