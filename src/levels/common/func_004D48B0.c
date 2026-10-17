#include "common.h"

extern f32 D_001DB920;

extern f32 D_001DB920;
void func_004D48B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
  arg1 = arg1 - 1;
  if (arg0 <= 0 || arg0 >= arg1) {
    D_001DB920 = 0.0f;
  } else if (arg2 >= arg0) {
    D_001DB920 = (f32)arg0 / (f32)arg2;
  } else if (arg1 - arg3 < arg0) {
    D_001DB920 = (f32)(arg1 - arg0) / (f32)arg3;
  } else {
    D_001DB920 = 1.0f;
  }
  D_001DB920 = 1.0f - D_001DB920;
}
