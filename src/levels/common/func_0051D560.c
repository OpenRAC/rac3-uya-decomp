#include "common.h"

extern void *func_0051D560();
extern void func_005193E8(void *, s32, s32);
extern void func_005192A0(void);

extern void func_005193E8(void *, s32, s32);
extern void func_005192A0(void);
extern u8 D_001DC288[];
void *func_0051D560(void *arg0)
{
  func_005192A0();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x34)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001DC288;
  *((f32 *) (((u8 *) arg0) + 0x14)) = (*((f32 *) (((u8 *) arg0) + 0x10)) = 0.5f);
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x60F00000;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 1.0f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 1.0f;
  func_005193E8(arg0, 0x100, 1);
  return arg0;
}
