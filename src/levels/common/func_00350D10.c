#include "common.h"
typedef struct { u8 pad[0x10]; u8 x10; } M_350D10;
typedef struct { u8 pad[0x48]; M_350D10 *x48[1]; } L_350D10;
typedef struct { u8 pad[0x24]; L_350D10 *x24; u8 pad28[0x41 - 0x28]; u8 x41; u8 x42; u8 x43; } A_350D10;
typedef struct { u8 pad[0x260]; A_350D10 *x260; } B_350D10;
extern void func_00424F38(A_350D10 *, s32, s32, s32);
void func_00350D10(A_350D10 *a, B_350D10 *b, s32 c) {
    A_350D10 *t = b->x260;
    s32 idx = t->x43;
    if (a->x43 != idx) {
        func_00424F38(a, idx, (t->x41 + c / 10) % a->x24->x48[idx]->x10, c);
    }
}
