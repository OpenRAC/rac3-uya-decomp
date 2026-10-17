#include "common.h"

typedef struct {
    u8 pad0[0xC31];
    u8 flags;
    u8 pad1[2];
    u8 type;
} Sub625720;

typedef struct {
    u8 pad0[0x2544];
    u8 id;
    u8 pad1[0x13];
    Sub625720 *sub;
} Obj625720;

typedef struct {
    f32 pos[3];
    u8 type;
    u8 id;
    u8 flags;
} Msg625720;

typedef struct {
    s32 pad0;
    s32 target;
    u8 pad8[0x168];
    s32 busy;
    u8 pad174[0x7D4 - 0x174];
    u8 channel;
} Net625720;

extern Net625720 D_001A5E50;
extern s32 D_00240764;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_00625720(Obj625720 *o, f32 *pos, s32 flag) {
    Msg625720 msg;
    msg.id = o->id;
    msg.type = o->sub->type;
    msg.flags = o->sub->flags;
    if (flag) {
        msg.flags |= 0x40;
    }
    msg.pos[0] = pos[0];
    msg.pos[1] = pos[1];
    msg.pos[2] = pos[2];
    if (D_001A5E50.busy == 0) {
        func_0014AD08(D_001A5E50.channel | 0x80, D_001A5E50.target, -1, D_00240764, 16, &msg);
    }
}
