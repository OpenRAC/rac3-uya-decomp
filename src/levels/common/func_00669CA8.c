#include "common.h"

typedef struct {
    int w0;
    char pad4[0x2C];
    u8 b30;
    u8 b31;
    char pad32[0xA];
    int w3C;
    char pad40[0x4];
} Unk669CA8;

typedef struct {
    int w0;
    int w4;
    int w8;
} Unk669CA8Clock;

extern Unk669CA8 D_0033ACA0[];
extern Unk669CA8Clock D_001A5E50[];

extern int func_00669BD0(int);
extern void func_00669C50(int);

void func_00669CA8(void) {
    int i;
    for (i = 0; i < 50; i++) {
        u8 st = D_0033ACA0[i].b31;
        if (st == 1 && func_00669BD0(D_0033ACA0[i].w3C)) {
            D_0033ACA0[i].b30 = st;
            D_0033ACA0[i].w3C = D_001A5E50->w8;
            func_00669C50(D_0033ACA0[i].w0);
        }
    }
}
