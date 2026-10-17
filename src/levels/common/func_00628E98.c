#include "common.h"
typedef struct { u8 pad[16]; u8 b16; } Info_00628E98;
typedef struct { u8 pad[72]; Info_00628E98 *info[1]; } Tbl_00628E98;
typedef struct { u8 pad0[36]; Tbl_00628E98 *tbl; u8 pad1[24]; u8 b64; u8 b65; u8 b66; u8 b67; s32 w68; } Sub_00628E98;
typedef struct { u8 pad[9508]; Sub_00628E98 *sub; } Obj_00628E98;
extern void func_005A8760(Sub_00628E98 *);
void func_00628E98(Obj_00628E98 *o, s32 a1, s32 a2) {
    Sub_00628E98 *s = o->sub;
    s32 n;
    s->b65 = a2 + 1;
    s->b64 = a2;
    n = s->tbl->info[a1]->b16 - 1;
    if (n < s->b65) s->b65 = n;
    s->b66 = a1;
    s->b67 = a1;
    s->w68 = 0;
    func_005A8760(s);
}
