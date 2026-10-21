#include "common.h"

/* localdecomp:start func_00437500 */
extern void func_00437500(void);
extern void func_00437500();

typedef struct { u8 p0[0x13]; u8 f13; } S_BDb;
typedef struct { u8 p0[0x48]; S_BDb *arr[1]; } S_BDt;
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[3]; S_BDt *f24; u8 p28[9]; u8 f31; u8 p32[0x10]; u8 f42; u8 f43; f32 f44; u8 p48[4]; f32 f4C; } S_BDa;
extern S_BDa *D_001E0000_003BD8A0[16];
extern s32 D_001E0040_003BD8A0[16];
extern void func_004389D8();
void func_00437500(void) {
    s32 i = 0;
    S_BDa *p;
    do {
        p = D_001E0000_003BD8A0[i];
        if (p != 0) {
            if (p->f20 & 0x80) { D_001E0000_003BD8A0[i] = 0; goto z; }
            if (p->f42 != 0xFF) { D_001E0000_003BD8A0[i] = 0; goto z; }
            if (p->f31 == 0 && D_001E0040_003BD8A0[i] >= 20) {
                if (p->f24->arr[p->f43]->f13 == p->f42) {
                    p->f44 = 1.0f - p->f4C;
                    func_004389D8(D_001E0000_003BD8A0[i]);
                }
            } else {
                D_001E0040_003BD8A0[i]++;
            }
        } else {
z:
            D_001E0040_003BD8A0[i] = 0;
        }
        i++;
    } while (i < 16);
}
/* localdecomp:end func_00437500 */
