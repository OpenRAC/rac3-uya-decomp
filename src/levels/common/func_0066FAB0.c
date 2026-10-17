#include "common.h"
typedef struct { u8 p0[136]; f32 f136[13]; u8 b188; u8 b189; } S_1A5E50;
extern S_1A5E50 D_001A5E50;
extern u8 *D_001D5F30;
extern f32 D_001A6BC8[];
extern s32 func_00197640(s32);
extern void func_001962F8(void);
void func_0066FAB0(void) {
    S_1A5E50 *p = &D_001A5E50;
    if (p->b189) {
        if (p->b188) {
            s32 i = func_00197640(*(s32 *)(D_001D5F30 + 384));
            p->b188 = 0;
            p->f136[i] += D_001A6BC8[0];
            func_001962F8();
        }
    }
}
