#include "common.h"

typedef struct {
    s32 id;
    s32 val;
    s32 idx;
    s32 pad;
} Item_004B7420;

typedef struct {
    u8 pad0[320];
    Item_004B7420 items[96];
    s32 count;
} List_004B7420;

typedef struct {
    s32 v[5];
} Tbl_004B7420;

extern s32 D_001DAC14;
extern u8 D_001DAC08;
extern List_004B7420 D_00244740;
extern Tbl_004B7420 D_001DACB8;
extern s32 func_004B7370(s32);
extern s32 func_00417EA0(void);

void func_004B7420(void) {
    Tbl_004B7420 tbl;
    s32 i;

    D_00244740.count = 0;
    i = 1;
    if (D_001DAC14 != 0) {
        i = D_001DAC14 + 1;
    }
    D_001DAC08 = 0;
    tbl = D_001DACB8;
    for (; i < 5; i++) {
        if (func_004B7370(i) != 0 || func_00417EA0() != 0) {
            D_00244740.items[D_00244740.count].idx = i;
            D_00244740.items[D_00244740.count].val = tbl.v[i];
            D_00244740.items[D_00244740.count].id = i + 0xEA92;
            D_00244740.count++;
        }
    }
}
