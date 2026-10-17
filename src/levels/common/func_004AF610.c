#include "common.h"

extern void func_004AF610(void);

typedef struct { s16 a; s16 b; } T_D46E0;
typedef struct { u8 p0[0x33]; u8 f33; } E_D46E0;
typedef struct { u8 p0[0xF]; u8 cnt; u8 q[0xC]; E_D46E0 *ent; } O_D46E0;
extern s32 D_00243A80[];
extern O_D46E0 *D_0023C580[];
extern T_D46E0 D_00243480[];
void func_004AF610(void) {
    s32 *p;
    s32 i;
    O_D46E0 *o;
    u8 *e;
    for (p = D_00243A80; *p >= 0; p++) {
        o = D_0023C580[*p];
        e = (u8 *)o->ent;
        for (i = 0; i < o->cnt; i++) {
            T_D46E0 *t = &D_00243480[e[0x33]];
            if (t->a != 0) { *(u32 *)e = (*(u32 *)e & 0xFFFFC000) | t->a; }
            if (t->b != 0) { *(u32 *)(e + 0x20) = (*(u32 *)(e + 0x20) & 0xFFFFC000) | t->b; }
            e += 0x50;
        }
    }
}
