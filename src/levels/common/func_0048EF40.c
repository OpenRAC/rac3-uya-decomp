#include "common.h"
extern void func_004A7368(s32 a0, s32 a1, s32 a2);
extern s32 func_0049B908(s32 a0);
extern void func_00513758(s32 a0);
extern s32 func_00513698(void);
extern s32 func_0048DCD8(s32 a0);
extern void func_005120B8(s32 a0);
void func_0048EF40(void) {
    func_004A7368(4, 0, 0);
    func_00513758(func_0049B908(0));
    func_005120B8(func_0048DCD8(func_00513698()));
}
