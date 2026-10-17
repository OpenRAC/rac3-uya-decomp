#include "common.h"

extern void func_00495C98(void *, s32);
extern s32 func_00512480(s32, f32, f32);

extern void func_004A7368(s32, s32, s32);
extern void func_0047B8E0(s32);
typedef struct {
    u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[8]; s32 f1C; u8 p20[0x30];
    f32 f50; f32 f54; u8 p58[4]; f32 f5C; u8 p60[8]; f32 f68; u8 p6C[0xC]; f32 f78;
} S_3B5440;
typedef struct { u8 p[0x40]; s32 f40; } E_3B5440;
void func_00495C98(void *arg0, s32 b) {
    S_3B5440 *o = arg0;
    f32 base = o->f50;
    f32 step = o->f54;
    f32 y;
    if (b & 0x1000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n - 1;
        if (n > 0) {
            while (j > 0 && ((E_3B5440 *)func_004950A8(o, 0, j))->f40 == 4) j--;
            if (((E_3B5440 *)func_004950A8(o, 0, j))->f40 != 4) {
                d = n - j;
                if (d <= o->f8 + 1) {
                    o->f8 = j - o->f4;
                } else {
                    s32 t;
                    t = o->f4 + 1;
                    o->f4 = t - (d - o->f8);
                    o->f8 = -1;
                }
            }
        }
        ((s32 (*)(s32, s32, s32))func_004A7368)(3, 0, 0);
        if (o->f8 < 0) {
            o->f8 = 0;
            if (o->f4 - 1 >= 0) o->f1C = 2;
        }
    } else if (b & 0x4000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n + 1;
        if (n < o->fC - 1) {
            while (j < o->fC - 1 && ((E_3B5440 *)func_004950A8(o, 0, j))->f40 == 4) j++;
            if (((E_3B5440 *)func_004950A8(o, 0, j))->f40 != 4) {
                d = j - n;
                if (d <= o->f10 - o->f8) {
                    o->f8 = j - o->f4;
                } else {
                    o->f8 = o->f10;
                    o->f4 = j - o->f10;
                }
            }
        }
        ((s32 (*)(s32, s32, s32))func_004A7368)(3, 0, 0);
        if (o->f10 - 1 < o->f8) {
            o->f8 = o->f10 - 1;
            {
                s32 t = o->f4 + 1;
                if (!(o->fC - o->f10 < t)) o->f1C = 1;
            }
        }
    }
    y = base + (f32)o->f8 * step;
    func_00512480(0x4F00B0, o->f5C, y - o->f68);
    func_00512480(0x4F00AF, o->f5C, y - o->f78);
    func_00512480(0x4F00B1, o->f5C, y + o->f68);
    func_0047B8E0(0x4F00AF);
}
