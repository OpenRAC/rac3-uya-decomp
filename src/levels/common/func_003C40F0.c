#include "common.h"

extern s32 D_001F3FC0[];
extern u16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern s32 D_001E00D8;
extern void func_004282C0(s32, s32);
extern void func_003C3A10(u8 *, u8 *);

typedef struct {
    u8 pad0[1724];
    s32 idx;
    s32 arr[1];
} S_3C40F0;

void func_003C40F0(u8 *m, u8 *v) {
    s32 e = ((S_3C40F0 *)v)->arr[((S_3C40F0 *)v)->idx];
    u16 *list;
    u8 *o;

    if (e != -1 && e != D_001F3FC0[0]) {
        func_004282C0(e, 0);
    }
    func_003C3A10(m, v);
    list = D_0021DEA0[*(s32 *)(v + 36)];
    while ((*(s32 *)(v + 36) & 0xFF) != 255 && *(s32 *)(v + 36) <= D_001E00D8 && list != 0 &&
           ((s16)list[-1] >= 0 || list == D_0021DEA0[*(s32 *)(v + 36)])) {
        o = D_001E009C + ((*list & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        list++;
        *(u16 *)(o + 52) &= 0xFF7F;
    }
}
