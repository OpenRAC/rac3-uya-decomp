#include "common.h"

/* localdecomp:start func_004C6A70 */
typedef struct { u8 pad[336]; s16 a; s16 b; } Ent_004C6A70;
extern s16 D_001E11B6;
extern Ent_004C6A70 D_001CFEC0[];
extern void func_004C1FE8(s32, long);
extern void func_00403708(s32, s32, s32, s32, s32);
void func_004C6A70(void) {
    func_004C1FE8(66, ((long)D_001E11B6 << 32) | 68);
    {
        s32 c = D_001E11B6 << 24;
        func_00403708(0, D_001CFEC0[0].b, 0, D_001CFEC0[0].a, c | 0xFFFFFF);
    }
}
/* localdecomp:end func_004C6A70 */
