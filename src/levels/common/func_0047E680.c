#include "common.h"

extern void func_004A7368(s32, s32, s32);
typedef struct { void (*fn)(); s32 pad; } T;
extern f32 D_001D83E8;
extern f32 D_001D83EC;
extern f32 D_001D8414;
extern f32 D_001D8418;
typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
extern P_3B23F8 *D_001D52FC[4] __attribute__((section(".sdata")));
extern F_3B23F8 D_001D83C8[1];
extern T_3B23F8 D_001D83CC[4] __attribute__((section(".sdata")));
extern s32 D_001D8434;
extern u8 D_001D672C;
extern u8 D_001D672D[16] __attribute__((section(".sdata")));
extern s32 func_0047C620_003B23F8(void);
extern s32 func_0048DCD8(s32);
extern s32 func_0047C878(void);
extern s32 func_0047B380_003B23F8(void);
extern void func_00513758_003B23F8(s32);
extern void func_005120B8_003B23F8(s32);
extern s32 func_00512480(s32, f32, f32);
extern void func_0047B920();
extern void func_0047B8E0(s32);
void func_0047E680(s32 a0) {
    u32 b = D_001D52FC[0]->f1C4;
    s32 i;
    s32 n = 0;
    if (b & 0x4000) {
        s32 found = 0;
        i = D_001D8434;
        do {
            i++;
            if (i >= 4) i = 0;
            if (D_001D83C8[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8434 = i;
        ((s32 (*)(s32, s32, s32))func_004A7368)(3, 0, 0);
    } else if (b & 0x1000) {
        s32 found = 0;
        i = D_001D8434;
        do {
            i--;
            { s32 lim = -1; if (i <= lim) i = 3; lim = 0; }
            if (D_001D83C8[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8434 = i;
        ((s32 (*)(s32, s32, s32))func_004A7368)(3, 0, 0);
    } else if (b & 0x40) {
        if (D_001D83C8[D_001D8434].on) {
            if (D_001D83CC[D_001D8434].fn) {
                D_001D83CC[D_001D8434].fn();
                ((s32 (*)(s32, s32, s32))func_004A7368)(4, 0, 0);
            }
        }
    } else if (b & 0x10) {
        ((s32 (*)(s32, s32, s32))func_004A7368)(4, 0, 0);
        if (D_001D672D[0]) {
            func_00513758_003B23F8(func_0047C878());
            func_005120B8_003B23F8(a0);
        } else if (D_001D672C) {
            func_00513758_003B23F8(func_0047C620_003B23F8());
            func_005120B8_003B23F8(a0);
        } else {
            func_00513758_003B23F8(func_0048DCD8(0));
            func_005120B8_003B23F8(a0);
        }
    } else if (b & 0x900) {
        ((s32 (*)(s32, s32, s32))func_004A7368)(4, 0, 0);
        if (D_001D672D[0]) {
            func_00513758_003B23F8(func_0047C878());
            func_005120B8_003B23F8(a0);
        } else if (!D_001D672C) {
            func_00513758_003B23F8(func_0047B380_003B23F8());
            func_005120B8_003B23F8(a0);
        }
    }
    func_00512480(0x4C0038, D_001D8414, D_001D83EC + D_001D8418 + (f32)D_001D8434 * D_001D83E8);
    func_0047B920();
    func_0047B8E0(0x4C0038);
}
