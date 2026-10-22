#include "common.h"

typedef struct {
    u8 p0[0x464];
    u8 x464[1];
} T_3A1A58;

extern T_3A1A58 D_00235280;
extern s32 D_001D545C;
extern u8 D_001BBE90[];
extern u8 *D_001DF21C;
extern s32 D_001D66B0;

extern u8 *func_004186B0(s32, s32);
extern void func_00435B90(u8 *, u8 *);
extern void func_00431AB0(u8 *, s32, void *, f32, f32, f32, f32, s32, f32, f32,
                          s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_00423710(u8 *, s32, s32);
extern void func_00418A60(u8 *);

void func_003A1A58(u8 *moby) {
    u8 *pv = *(u8 **)(moby + 0x68);
    u16 h = *(u16 *)(moby + 0xB2);
    s32 v;

    if (!D_00235280.x464[(s16)h] &&
        !(v = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)], (h & 1) ? (v >> 4) & 7 : v & 7)) {
        u8 *e = func_004186B0(0x8C4, 0x80);
        func_00435B90(e, moby);
        *(f32 *)(e + 0x18) += 1.5f;
        *(f32 *)(e + 0x2C) = *(f32 *)(*(u8 **)(e + 0x24) + 0x24) * 0.5f;
        if (*(u16 *)(moby + 0xB2) & 1) {
            u8 *q = &D_001BBE90[(*(s16 *)(moby + 0xB2) >> 1) + (D_001D545C << 10)];
            if (((*q >> 4) & 7) != 7) *q += 16;
        } else {
            u8 *q = &D_001BBE90[(*(s16 *)(moby + 0xB2) >> 1) + (D_001D545C << 10)];
            if ((*q & 7) != 7) *q += 1;
        }
    }
    if (*(s32 *)(pv + 0x2E0) != -1) {
        u8 *p = D_001DF21C + (*(s32 *)(pv + 0x2E0) << 8);
        func_00431AB0(p, 0x4FFF, &D_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF,
                      -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_00431AB0(p, 0x4FFF, &D_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF,
                      -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_00423710(p, 0, 3);
        func_00418A60(p);
        *(s32 *)(pv + 0x2E0) = -1;
    }
    if (*(s32 *)(pv + 0x2F8) != -1) {
        u8 *p = D_001DF21C + (*(s32 *)(pv + 0x2F8) << 8);
        func_00431AB0(p, 0x4FFF, &D_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF,
                      -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_00431AB0(p, 0x4FFF, &D_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF,
                      -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_00423710(p, 0, 3);
        func_00418A60(p);
        *(s32 *)(pv + 0x2F8) = -1;
    }
    func_00423710(moby, 0, 3);
}
