#include "common.h"

extern s32 func_004D4868();
extern void func_004D22D0();
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_00251370[];
extern void func_004D4958(f32);

extern s32 func_0040BA90();
extern s32 func_004D4868();
extern void func_004D22D0();
s32 func_004D7408(s32 a) {
    S_3BB558 *g = D_00251370;
    s32 r = 0;
    s32 k;
    switch (g->w44) {
    case 0:
        if (func_0040BA90(&g->w40) == 1) {
            g->w40 = 0xF;
            g->w44 = g->w44 + 1;
        }
        break;
    case 1:
        if (func_0040BA90(&g->w40) == 1) {
            g->w40 = 0x5A;
            g->w44 = g->w44 + 1;
        }
        func_004D4958((f32)g->w40 / 15.0f);
        break;
    case 2:
        if (func_004D4868()) func_004D22D0();
        if (func_0040BA90(&g->w40) == 1 && a != 0) {
            g->w40 = 0xF;
            g->w44 = g->w44 + 1;
        }
        break;
    case 3:
        if (func_0040BA90(&g->w40) == 1) r = 1;
        func_004D4958(1.0f - (f32)g->w40 / 15.0f);
        break;
    }
    return r;
}
