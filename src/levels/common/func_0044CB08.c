#include "common.h"

typedef int s128_44CB08 __attribute__((mode(TI)));

extern void func_00437600(u8 *, int, s128_44CB08 *);
extern void func_0040BE90(void *, void *, f32);
extern void func_004389D8(u8 *);
extern void func_00439610(u8 *);
extern void func_0040C8C0(void *, void *);
extern void func_00445CD8(void *);
extern void func_004397B0(u8 *);

void func_0044CB08(u8 *src, u8 *m, int arg, int flags) {
    s128_44CB08 mat[4];

    func_00437600(src, arg, mat);
    *(s128_44CB08 *)(m + 0x10) = mat[3];
    if (flags & 1) {
        func_0040BE90(&mat[0], &mat[0], -1.0f);
    }
    if (flags & 2) {
        func_0040BE90(&mat[1], &mat[1], -1.0f);
    }
    if (flags & 4) {
        func_0040BE90(&mat[2], &mat[2], -1.0f);
    }
    func_004389D8(m);
    if (!(*(u16 *)(m + 0x34) & 4)) {
        func_00439610(m);
    }
    func_0040C8C0(m + 0xC0, mat);
    func_00445CD8(m + 0xC0);
    func_004397B0(m);
    if (*(u16 *)(src + 0x34) & 1) {
        *(u16 *)(m + 0x34) |= 0x41;
    } else {
        *(u16 *)(m + 0x34) &= ~0x41;
    }
    *(u16 *)(m + 0x34) |= 6;
}
