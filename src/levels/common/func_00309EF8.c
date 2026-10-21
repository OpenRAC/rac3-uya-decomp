#include "common.h"

/* localdecomp:start func_00309EF8 */
extern void func_004C1FE8(int, long);
extern int func_00440878(int, int);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern void func_004082B0(void *, int, int, int, f32, f32, f32);
extern void func_0030A798(void *);
extern void func_0030B578(void *);

void func_00309EF8(u8 *m) {
    u8 *p = *(u8 **)(m + 104);

    func_004C1FE8(71, 0x53001);
    func_004082B0(m + 16, 44, (func_00440878(128, 200) << 24) | 0x72FF, 1,
                  func_004408C0(0.38500002f, 0.415f) * *(f32 *)(p + 76), -0.01f, func_00440978());
    func_004082B0(m + 16, 45, (func_00440878(4, 40) << 24) | 0xDDB973, 1,
                  *(f32 *)(p + 76) * 1.225f, 0.0f, func_00440978());
    func_004082B0(m + 16, 41, (func_00440878(4, 40) << 24) | 0xDDB973, 1,
                  *(f32 *)(p + 76) * 0.6f, 0.0f, func_00440978());
    func_004082B0(m + 16, 42, (func_00440878(4, 45) << 24) | 0xDDB973, 1,
                  func_004408C0(0.975f, 1.025f) * *(f32 *)(p + 76), 0.0f, func_00440978());
    func_004082B0(m + 16, 42, (func_00440878(4, 45) << 24) | 0xDDB973, 1,
                  func_004408C0(0.975f, 1.025f) * *(f32 *)(p + 76), 0.0f, func_00440978());
    func_0030A798(m);
    func_0030B578(m);
    func_004C1FE8(71, 0x5360B);
}
/* localdecomp:end func_00309EF8 */
