#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;

extern s32 D_001D8C10;
extern struct U_488750 D_001E0980 __attribute__((section(".sdata")));
extern struct U_488750 D_001D8C0C __attribute__((section(".sdata")));
extern char D_001D8C18[];
extern char D_001D8C20[];
extern E_488750 D_002BCA30[];
extern char *func_004181A0(s32 id);
extern void func_00512FE8(s32 id, char *s);
extern void func_005131A0(s32 id, s32 v);
extern void func_00512D70(s32 id, s32 v);
extern void func_0011B2E8(char *dst, char *fmt, char *s);

void func_00488750(void) {
    s32 v = ((s32 *)&D_001E0980)[D_001D8C10];
    E_488750 *e;

    if (v == -1) {
        **(char **)&D_001D8C0C = 0;
        func_00512FE8(29, D_001D8C18);
        func_005131A0(28, 17);
        return;
    }
    e = &D_002BCA30[v];
    func_00512D70(28, 1);
    if (e->w0 != -1) {
        func_0011B2E8(*(char **)&D_001D8C0C, D_001D8C20, func_004181A0(e->w0));
    }
    if (e->w4 != -1) {
        func_00512FE8(29, func_004181A0(e->w4));
    } else {
        func_00512FE8(29, D_001D8C18);
    }
    if (e->w12 != -1) {
        func_00512D70(28, 1);
        func_005131A0(28, e->w12);
    } else {
        func_005131A0(28, 17);
    }
}
