#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 w8;
} S_1A1ED0;

typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} S_1CFEC0;

extern S_1A1ED0 D_001A1ED0[];
extern S_1CFEC0 D_001CFEC0[];
extern s32 D_001DDD30;
extern s32 D_001DDD38;
extern s32 D_001DDD3C;
extern s32 D_001DDD40;
extern s32 D_001DDD44;
extern s32 D_001DDD48;
extern s32 D_001DDD4C;
extern s32 D_001DDD50;
extern s32 D_001DDD54;
extern s32 D_001DDD58;
extern s32 D_001DDD5C;
extern s32 D_001DDD60;
extern s32 D_001DDD64;
extern s32 D_001DDD68;

extern void func_004C2280(void);
extern void func_004C1FE8(s32 reg, long value);
extern void func_004A04B0(void);
extern long func_00401CD0(s32);
extern void func_00403CA8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, long c, long d);

void func_00381418(s32 a0, s32 a1, s32 alpha) {
    S_1A1ED0 *z;
    S_1CFEC0 *s;
    s32 color;
    long tex;

    func_004C2280();
    z = D_001A1ED0;
    func_004C1FE8(0x4E, (long)(z->w8 >> 13) | 0x1000000 | 0x100000000L);
    func_004C1FE8(0x42, (long)D_001DDD3C | ((long)D_001DDD40 << 2) | ((long)D_001DDD44 << 4)
                  | ((long)D_001DDD48 << 6) | (0x80L << 32));
    func_004A04B0();
    tex = func_00401CD0(D_001DDD30);
    s = D_001CFEC0;
    color = (alpha << 24) | 0x7F7F7F;
    func_00403CA8(0, 0, (s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_00403CA8(s->h150, 0, -(s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_00403CA8(0, s->h152, (s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_00403CA8(s->h150, s->h152, -(s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_004C1FE8(0x42, (long)D_001DDD3C | ((long)D_001DDD40 << 2) | ((long)D_001DDD44 << 4)
                  | ((long)D_001DDD48 << 6) | (0x80L << 32));
    func_004C1FE8(0x42, (long)D_001DDD4C | ((long)D_001DDD50 << 2) | ((long)D_001DDD54 << 4)
                  | ((long)D_001DDD58 << 6) | (0x80L << 32));
    func_00403CA8(0, 0, s->h150, s->h152, D_001DDD5C, D_001DDD60, D_001DDD64, D_001DDD68, D_001DDD38, func_00401CD0(-7));
    func_004C1FE8(0x4E, 0x1000000 | (long)(z->w8 >> 13));
}
