#include "common.h"

extern s32 func_004D1990(void *);
extern s32 func_004CF3A0();
extern void func_0011AF48();
extern s32 func_004D1B90();
extern s32 D_001E1238;

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } S_3AD288;
/* .sdata: bare references the assembler expands with lui (size unknown). */
extern S_3AD288 *D_001E1238_003AD288[] __attribute__((section(".sdata")));
extern u8 D_001DB8B0[];
extern u8 D_001DB898[];
extern s32 func_004D2050();
extern void func_004CF0E8();
extern s32 func_00135C10();
extern s32 func_00135CE0();
extern void func_00135C60();
extern void func_004D1FE0();
extern void func_004CFF18();
extern s32 func_004D1990();
extern void func_0011AF48();
extern s32 func_004CF3A0();
s32 func_004D1B90(s32 *a) {
    s32 ret = 1;
    s32 v, h, w, hh;
    while (func_00135CE0(a) == 0) {
        if (func_004D1990(a) == 1) {
            ret = -1;
            func_0011AF48(D_001DB898);
            break;
        }
        while ((v = func_004D2050(D_001E1238)) == 0) {
            func_004CF0E8();
        }
        if (func_00135C10(a, v, 0x340) < 0) {
            func_004CF3A0(D_001DB8B0);
        }
        if (a[2] == 0) {
            S_3AD288 *p;
            hh = a[0];
            w = a[1];
            h = 0;
            p = (S_3AD288 *)D_001E1238;
            if (h < p->x10) {
                do {
                    func_004CFF18(p->x4 + h * 0x27E40 + 0x40, p->x0 + h * 0xD0000, 0, hh, w);
                    func_004CFF18(D_001E1238_003AD288[0]->x4 + h * 0x27E40 + 0x13F40, D_001E1238_003AD288[0]->x0 + h * 0xD0000, 1, hh, w);
                    h++;
                    p = D_001E1238_003AD288[0];
                } while (h < p->x10);
            }
        }
        func_004D1FE0(D_001E1238);
        func_004CF0E8();
    }
    func_00135C60(a);
    return ret;
}
