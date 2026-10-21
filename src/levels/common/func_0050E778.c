#include "common.h"

/* localdecomp:start func_0050E778 */
extern s32 D_001D6694;
extern u8 D_001A4BE0[];
extern u8 D_001E6E00[];
extern void func_004E7148(void);
extern void func_004E1518(s32);
extern void func_004E7FD8(s32);
extern void func_0050E500(void);

#define MOBY_FLAGS(p) (*(u16 *)((u8 *)(p) + 52))

void func_0050E778(s32 arg) {
    u8 *p;
    u8 *g;
    u8 *m;
    s32 i;
    u8 *h;

    if (D_001D6694 != 2 && D_001D6694 != 6) {
        return;
    }
    g = D_001A4BE0;
    if (*(u8 **)(g + 4768) == 0) {
        func_004E7148();
    }
    m = D_001E6E00;
    for (i = 0; i < *(s16 *)(m + 68); i++) {
        p = ((u8 **)(m + 416))[i];
        if (p != 0 && (*(s16 *)(p + 170) == 1290 || *(s16 *)(p + 170) == 3412)) {
            MOBY_FLAGS(p) |= 0x800;
        }
    }
    func_004E1518(arg);
    func_004E7FD8(arg);
    func_0050E500();
    h = D_001A4BE0;
    if (*(u8 **)(h + 4768) != 0) MOBY_FLAGS(*(u8 **)(h + 4768)) &= ~1;
    if (*(u8 **)(h + 4688) != 0) MOBY_FLAGS(*(u8 **)(h + 4688)) &= ~1;
    if (*(u8 **)(h + 4692) != 0) MOBY_FLAGS(*(u8 **)(h + 4692)) &= ~1;
    if (*(u8 **)(h + 4928) != 0) MOBY_FLAGS(*(u8 **)(h + 4928)) &= ~1;
    if (*(u8 **)(h + 4932) != 0) MOBY_FLAGS(*(u8 **)(h + 4932)) &= ~1;
    if (*(u8 **)(h + 4936) != 0) MOBY_FLAGS(*(u8 **)(h + 4936)) &= ~1;
    if (*(u8 **)(h + 5008) != 0) MOBY_FLAGS(*(u8 **)(h + 5008)) &= ~1;
}
/* localdecomp:end func_0050E778 */
