#include "common.h"

extern void func_0041A278();

// near miss: 17 diff, N mode default flags; only regalloc: retail s3=end,s4=-6,s5=10 and lui/addiu of D_002E6110 after the jal; mine s3=10,s4=-6,s5=end and base before jal
typedef struct S_391D08 {
    s32 f0;
    s32 f4;
    u8 p8[0xC];
    void (*f14)(struct S_391D08 *);
    u8 p18[0x50];
    s32 f68;
    s32 f6C;
    u8 p70[0xC];
    s32 f7C;
    u8 p80[0x10];
} S_391D08;
extern S_391D08 D_002E6110_00391D08[];
extern s32 D_001DFD84_00391D08;
extern void func_0041D5A0();
extern void func_0041A278();
s32 func_0041D430(s32 a0) {
    S_391D08 *s;
    s32 i;
    s32 cnt = 0;
    s32 t;
    s32 ten = 10;
    s32 m6 = -6;
    func_0041D5A0();
    for (i = 0; i < 13; i++) {
        s = &D_002E6110_00391D08[i];
        if ((s->f4 & 0x10) || D_001DFD84_00391D08) {
            if (s->f7C < 10) {
                s->f7C = ten;
            }
        }
        t = s->f7C;
        if (t > 0) {
            t--;
            s->f7C = t;
            if (t > 0) {
                cnt++;
                if (s->f6C < 30) {
                    s->f6C = s->f6C + 1;
                }
                goto skip;
            }
        }
        if (s->f6C >= -5) {
            s->f6C = s->f6C - 1;
        }
skip:
        if (s->f68 != 0 && s->f6C == m6) {
            func_0041A278(s);
        }
        if (a0 != 0 && s->f14 != 0) {
            s->f14(s);
        }
    }
    return cnt;
}
