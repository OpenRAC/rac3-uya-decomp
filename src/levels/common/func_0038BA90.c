#include "common.h"

/* localdecomp:start func_0038BA90 */
typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G38BA90;

extern G38BA90 D_001CFEC0;
extern s32 D_001D5520[] __attribute__((section(".sdata")));
extern s32 D_001DDF90;
extern s32 D_001DDF94;
extern s32 D_001DDF98;
extern s32 D_001DDF9C;
extern s32 D_001DDFA0;
extern s32 D_001DDFA4;
extern s32 D_001DDFA8;
extern s32 D_001DDFAC;
extern s32 D_001DDFB0;
extern s32 D_001DDFB4;
extern s32 D_001DDFB8;
extern s32 D_001DDFBC;
extern s32 D_001DDFC0;
extern s32 D_001DDFC4;
extern s32 D_001DDFC8;
extern void func_004C2280(void);
extern void func_004C1FE8(s32, unsigned long);
extern unsigned long func_00401CD0(s32);
extern void func_00403CA8(s32, s32, s32, s32, s32, s32, s32, s32, long, unsigned long);

void func_0038BA90(s32 a0, s32 a1, s32 a2) {
    long c;
    unsigned long t;

    func_004C2280();
    if (D_001D5520[0] != 0) {
        D_001DDFC8 = -1;
        D_001DDFC0 = 236;
        D_001DDFC4 = 240;
    }
    func_004C1FE8(71, 0x513F1);
    func_004C1FE8(66, (long)D_001DDF98 | ((long)D_001DDF9C << 2) | ((long)D_001DDFA0 << 4) | ((long)D_001DDFA4 << 6) | 0x8000000000UL);
    t = func_00401CD0(D_001DDF90);
    c = (a2 << 24) | 0x7F7F7F;
    func_00403CA8(0, 0, (s32)(D_001CFEC0.unk150 * 0.5f), (s32)(D_001CFEC0.unk152 * 0.5f), 0, 0, 255, 255, c, t);
    func_00403CA8(D_001CFEC0.unk150, 0, -(s32)(D_001CFEC0.unk150 * 0.5f), (s32)(D_001CFEC0.unk152 * 0.5f), 0, 0, 255, 255, c, t);
    func_00403CA8(0, D_001CFEC0.unk152, (s32)(D_001CFEC0.unk150 * 0.5f), -(s32)(D_001CFEC0.unk152 * 0.5f), 0, 0, 255, 255, c, t);
    func_00403CA8(D_001CFEC0.unk150, D_001CFEC0.unk152, -(s32)(D_001CFEC0.unk150 * 0.5f), -(s32)(D_001CFEC0.unk152 * 0.5f), 0, 0, 255, 255, c, t);
    func_004C1FE8(66, (long)D_001DDF98 | ((long)D_001DDF9C << 2) | ((long)D_001DDFA0 << 4) | ((long)D_001DDFA4 << 6) | 0x8000000000UL);
    func_004C1FE8(66, (long)D_001DDFA8 | ((long)D_001DDFAC << 2) | ((long)D_001DDFB0 << 4) | ((long)D_001DDFB4 << 6) | 0x8000000000UL);
    func_00403CA8(0, 0, D_001CFEC0.unk150, D_001CFEC0.unk152, D_001DDFB8, D_001DDFBC, D_001DDFC0, D_001DDFC4, D_001DDF94, func_00401CD0(D_001DDFC8));
}
/* localdecomp:end func_0038BA90 */
