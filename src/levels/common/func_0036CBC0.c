#include "common.h"

/* localdecomp:start func_0036CBC0 */
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
/* Small to gcc (one lw macro) but sizeless, so no .extern hint: the
   assembler expands it to lui/lw in the same register, as retail does. */
extern s32 D_001D5520[0] __attribute__((section(".sdata")));
extern s32 D_001DD8B0;
extern s32 D_001DD8B8;
extern s32 D_001DD8BC;
extern s32 D_001DD8C0;
extern s32 D_001DD8C4;
extern s32 D_001DD8C8;
extern s32 D_001DD8CC;
extern s32 D_001DD8D0;
extern s32 D_001DD8D4;
extern s32 D_001DD8D8;
extern s32 D_001DD8DC;
extern s32 D_001DD8E0;
extern s32 D_001DD8E4;
extern s32 D_001DD8E8;
extern s32 D_001DD90C;

extern void func_004C2280(void);
extern void func_004C1FE8(s32 reg, long value);
extern void func_004A04B0(void);
extern long func_00401CD0(s32);
extern void func_00403CA8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, long c, long d);

void func_0036CBC0(s32 a0, s32 a1, s32 alpha) {
    S_1A1ED0 *z;
    S_1CFEC0 *s;
    s32 color;
    long tex;

    func_004C2280();
    if (D_001D5520[0] != 0) {
        D_001DD90C = -1;
        D_001DD8E4 = 236;
        D_001DD8E8 = 240;
    }
    z = D_001A1ED0;
    func_004C1FE8(0x4E, (long)(z->w8 >> 13) | 0x1000000 | 0x100000000L);
    func_004C1FE8(0x42, (long)D_001DD8BC | ((long)D_001DD8C0 << 2) | ((long)D_001DD8C4 << 4)
                  | ((long)D_001DD8C8 << 6) | (0x80L << 32));
    func_004A04B0();
    tex = func_00401CD0(D_001DD8B0);
    s = D_001CFEC0;
    color = (alpha << 24) | 0x7F7F7F;
    func_00403CA8(0, 0, (s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_00403CA8(s->h150, 0, -(s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_00403CA8(0, s->h152, (s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_00403CA8(s->h150, s->h152, -(s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_004C1FE8(0x42, (long)D_001DD8BC | ((long)D_001DD8C0 << 2) | ((long)D_001DD8C4 << 4)
                  | ((long)D_001DD8C8 << 6) | (0x80L << 32));
    func_004C1FE8(0x42, (long)D_001DD8CC | ((long)D_001DD8D0 << 2) | ((long)D_001DD8D4 << 4)
                  | ((long)D_001DD8D8 << 6) | (0x80L << 32));
    func_00403CA8(0, 0, s->h150, s->h152, D_001DD8DC, D_001DD8E0, D_001DD8E4, D_001DD8E8, D_001DD8B8, func_00401CD0(D_001DD90C));
    func_004C1FE8(0x4E, 0x1000000 | (long)(z->w8 >> 13));
}
/* localdecomp:end func_0036CBC0 */
