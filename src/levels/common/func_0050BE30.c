#include "common.h"

typedef struct {
    char pad0[0x10];
    u8 count;
} Anim;

typedef struct {
    char pad0[0x48];
    Anim *anims[1];
} Class;

typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x40 - 0x28];
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    s32 unk44;
    char pad48[0x58 - 0x48];
    s32 unk58;
    s32 unk5C;
} Moby;

typedef struct {
    char data[0x600];
} Buf;

extern Moby *D_001A71A0[];
extern Buf D_00252900[];
extern void func_00436350(Moby *);
extern s32 func_004DBFE8(Moby *, s32, s32, Buf *);

void func_0050BE30(s32 a, s32 b) {
    Moby *m = D_001A71A0[0];
    s32 max;

    m->unk41 = b + 1;
    m->unk40 = b;
    max = m->cls->anims[a]->count - 1;
    if (max < m->unk41) {
        m->unk41 = max;
    }
    m->unk44 = 0;
    m->unk42 = a;
    m->unk43 = a;
    func_00436350(m);
    m->unk58 = func_004DBFE8(m, m->unk42, m->unk40, &D_00252900[0]);
    m->unk5C = func_004DBFE8(m, m->unk43, m->unk41, &D_00252900[1]);
}
