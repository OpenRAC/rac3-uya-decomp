#include "common.h"

extern s32 D_001D55C8;
extern s32 *D_001D55C4[];

typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
s32 func_0040D940(u8 *str, s32 len, f32 scale) {
    s32 idx[2];
    f32 q = scale * 0.25f;
    s32 i;
    s32 ok;
    f32 kern;
    f32 x;
    f32 first;
    idx[0] = 0;
    idx[1] = 0;
    func_0040D4E8(str, 0, &idx[0]);
    kern = 0.0f;
    first = (f32)(-(s32)(((E_389D18 *)D_001D55C4[0])[idx[0]].w0 >> 25)) * q;
    x = 0.0f;
    ok = 1;
    i = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            E_389D18 *e;
            f32 w, b, c, adv;
            i += func_0040D4E8(str, i, &idx[0]);
            e = &((E_389D18 *)D_001D55C4[0])[idx[0]];
            w = (f32)((e->w4 >> 23) & 0x3F) * scale;
            b = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * q;
            c = (f32)(((e->w4 >> 29) + 2) & 0xFC);
            x += w - b;
            adv = (kern + c) * q;
            if (i != len - 1) {
                s32 nx;
                func_0040D4E8(str, i + 1, &idx[1]);
                nx = idx[1];
                if (nx >= 0x10) {
                    f32 t;
                    if (e->w0 & 0xFFF0) {
                        K_389D18 *k = (K_389D18 *)((u8 *)D_001D55C8 + ((e->w0 >> 2) & 0x3FFC));
                        s32 r;
                        t = x + adv;
                        if (k != 0) {
                            s32 j;
                            for (j = 0; k[j].end == 0; j++) {
                                if (k[j].ch == nx) { r = k[j].adj; goto done; }
                            }
                        }
                        r = 0;
                    done:
                        kern = (f32)r;
                        kern = kern * q;
                    } else {
                        t = x + adv;
                        kern = 0.0f;
                    }
                    x = t;
                }
            }
        }
    }
    return (s32)(x - first);
}
