#include "common.h"

extern void func_004A7368(s32, s32, s32);
extern s32 func_0048D818(s32);
extern void func_00513758(s32);
extern s32 func_00513698(void);
extern s32 func_0048DCD8(s32);
extern void func_005120B8(s32);

void func_0048EF90(void) {
    func_004A7368(4, 0, 0);
    func_00513758(func_0048D818(func_00513698()));
    func_005120B8(func_0048DCD8(func_00513698()));
}
