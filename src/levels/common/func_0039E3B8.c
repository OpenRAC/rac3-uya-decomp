#include "common.h"

typedef struct {
    u8 pad0[16];
    s32 unk10;
} C39E3B8;

typedef struct {
    u8 pad0[220];
    s32 unkDC;
} V39E3B8;

typedef struct {
    u8 pad0[36];
    C39E3B8 *unk24;
    u8 pad28[52 - 40];
    u16 unk34;
    u8 pad36[104 - 54];
    V39E3B8 *pVars;
    u8 pad6C[152 - 108];
    s32 unk98;
    u8 pad9C[256 - 156];
} M39E3B8;

extern M39E3B8 *D_001DEA1C[];
extern void func_00335238(M39E3B8 *);

void func_0039E3B8(s32 idx, s32 mode) {
    M39E3B8 *m = &D_001DEA1C[0][idx];

    switch (mode) {
    case 0:
        m->unk34 &= ~0x100;
        m->unk98 = m->unk24->unk10;
        m->pVars->unkDC = 8;
        break;
    case 1:
        func_00335238(m);
    case 2:
        m->unk34 |= 0x100;
        m->unk98 = 0;
        m->pVars->unkDC = 2;
        break;
    }
}
