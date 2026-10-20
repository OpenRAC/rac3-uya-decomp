#include "common.h"

typedef struct {
    u8 pad0[112];
    u8 x70;
    u8 pad71[3];
    s32 x74;
} S_0047B230;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8[2];
} T_0047B230;

extern S_0047B230 D_002E9FD8;
extern u8 D_002EA004[];
extern u8 D_002EA028[];
extern T_0047B230 D_001E1660;

extern T_0047B230 *func_00511BF8(void);
extern void *func_00511E28(T_0047B230 *);
extern void func_00510DF8(void *, s32, s32);
extern void func_00475A28(void);
extern void func_00477BD0(void);
extern void func_00478140(void);
extern void func_00510778(void *);
extern void func_0047B0A8(void);

void func_0047B230(void) {
    void *q;
    s32 i;

    if (D_002E9FD8.x70 == 0 && D_002E9FD8.x74 != 5) {
        q = func_00511E28(D_001E1660.x4 != 0 ? &D_001E1660 : func_00511BF8());
        for (i = 0; i < 35; i++) {
            if (q != 0) {
                func_00510DF8(q, i, D_002EA004[i]);
            }
        }
        if (D_002E9FD8.x74 != 10) {
            func_00475A28();
            func_00477BD0();
            func_00478140();
        }
    }
    func_00510778(D_002EA028);
    func_0047B0A8();
}
