#include "common.h"

extern s32 func_0045CA60(s32);
extern void func_0040D548(s32);
extern s32 func_0045CA60();
extern void *func_00490968();
extern s32 func_00513928();
extern void *func_00490968(s32);
extern void func_004179B8(s32);
extern s32 D_001D8420;
extern s32 D_001D842C;
extern s32 D_001D8424;
extern u8 D_001D672C[];
extern s32 D_001D84B8[2];

typedef struct { s32 p0; void *vt; } O_B2958;
extern s32 D_001D8420;
extern s32 D_001D8424;
extern s32 D_001D842C;
extern s32 D_001D84B8[2];
extern u8 D_001D672C[];
void func_0047EBE0(void) {
    s32 i;
    s32 j;
    s32 *p;
    O_B2958 *o;
    func_00513928(0x10);
    func_00513928(0x11);
    for (i = 0; i < 4; i++) {
        o = (O_B2958 *)func_00490968(i);
        (*(void (**)(O_B2958 *))((u8 *)o->vt + 0xC))(o);
    }
    func_0045CA60(1);
    func_0047B7B8(D_001D8420);
    for (j = 0; j < 4; j++) {
        func_0047B7B8(D_001D84B8[j]);
    }
    if (D_001D672C[0] == 0) {
        func_0047B7B8(D_001D842C);
        func_0047B7B8(D_001D8424);
    }
    func_0040D548(0);
    func_004179B8(0);
}
