#include "common.h"

typedef struct { u8 p0[0x3E]; s16 h3E; u8 p40[0xC]; f32 f4C; u8 p50[4]; f32 f54; } Q_3E6DA8;
typedef struct { u8 p0[0x70]; u8 *w70; u8 p74[0x12]; s16 h86; } O_3E6DA8;
typedef struct { u8 p0[0x50]; O_3E6DA8 *w50; u8 pad[0x460 - 0x54]; } E_3E6DA8;
extern E_3E6DA8 D_001E2AC0[];

void func_003E6DA8(s32 i, f32 a, f32 b) {
    O_3E6DA8 *o = ((E_3E6DA8 *)((u8 *)D_001E2AC0 + i * 1120))->w50;
    if (o->h86 == 0) {
        Q_3E6DA8 *q = (Q_3E6DA8 *)(o->w70 + 384);
        q->h3E = 1;
        q->f4C = a;
        q->f54 = b;
    }
}
