#include "common.h"

/* localdecomp:start func_0047D868 */
typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8398;
/* One 4-entry, 32-byte array of { u8 on; fn } at D_001D83C8; the target names the
   fn column D_001D83CC, so it is declared with the 3 whole entries before D_001D83E8. */
extern F D_001D83C8[4];
extern T D_001D83CC[3];
typedef struct { s32 a[7]; } R;
extern R D_00142430[];
extern void func_0047D5F0();
extern void func_0047D6B8();
extern void func_0047D718();
extern void func_0047D758();
extern void func_0047D840();
void func_0047D868(s32 unused) {
    s32 i;
    s32 m = D_001D8398;
    for (i = 0; i < 4; i++) {
        D_001D83C8[i].on = 1;
        switch (m) {
        case 0: D_001D83CC[i].fn = func_0047D718; break;
        case 1:
            D_001D83CC[i].fn = func_0047D6B8;
            if (D_00142430[i].a[12] == -1) D_001D83CC[i].fn = func_0047D840;
            break;
        case 2: D_001D83CC[i].fn = func_0047D5F0; break;
        case 3: D_001D83CC[i].fn = func_0047D758; break;
        }
    }
}
/* localdecomp:end func_0047D868 */
