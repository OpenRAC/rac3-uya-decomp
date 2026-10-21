#include "common.h"

/* localdecomp:start func_004224C8 */
/* MATCH */
extern u8 D_00221370[];
extern s32 D_00221118[];
typedef struct { s32 a, b; } P_3936A8;
extern P_3936A8 D_00220AC0[];
extern s32 D_001E030C;
extern void func_0040BCB8();
void func_004224C8(s32 *hdr, s32 base, s32 *src, s32 n) {
    s32 *list = hdr + 4;
    s32 cnt = hdr[0];
    s32 off = hdr[2];
    s32 size = hdr[3];
    s32 i;
    for (i = 0; i < cnt; i++, list++) {
        s32 v = *list;
        if (v == 0) D_00221118[i] = (s32)D_00221370;
        else D_00221118[i] = v - (off - (s32)D_00221370);
    }
    func_0040BCB8(D_00221370, (u8 *)hdr + off, size);
    for (D_001E030C = 0; D_001E030C < n; D_001E030C++) {
        s32 a = *src++;
        s32 b = *src++;
        s32 c = *src++;
        s32 d = *src++;
        s32 e;
        __asm__("plzcw %0, %1" : "=r"(e) : "r"(d));
        e = 30 - e;
        D_00220AC0[D_001E030C].a = ((base + a) << 4) + b;
        D_00220AC0[D_001E030C].b = ((base + c) << 4) + e;
    }
}
/* localdecomp:end func_004224C8 */
