#include "common.h"
typedef struct {
    u8 pad0[16];
    s32 f10;
} Sub_4A8EB8;
typedef struct {
    u8 pad0[36];
    Sub_4A8EB8 *p24;
    u8 pad28[12];
    u16 h34;
    u8 pad36[98];
    s32 f98;
} Obj_4A8EB8;
extern Obj_4A8EB8 *D_0016C580[];
extern void func_004A7D30(void);
extern void func_004A7F50(Obj_4A8EB8 *, s32);
void func_004A8EB8(void) {
    Obj_4A8EB8 *o = D_0016C580[0];
    if (o != 0) {
        o->h34 &= 0xFFFC;
        func_004A7D30();
        func_004A7F50(D_0016C580[0], 0);
        D_0016C580[0]->f98 = D_0016C580[0]->p24->f10;
    }
}
