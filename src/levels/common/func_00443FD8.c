#include "common.h"
typedef struct { f32 elements[4]; } __attribute__((aligned(16))) Quaternion_00443FD8;
extern void func_0040C9F8_00443FD8(Quaternion_00443FD8 *, const Quaternion_00443FD8 *, const Quaternion_00443FD8 *);
extern void func_0040CAC0_00443FD8(void *, s32, f32);
void func_00443FD8(Quaternion_00443FD8 *output, void *angles) {
    Quaternion_00443FD8 rotations[3];
    func_0040CAC0_00443FD8(&rotations[2], 0, *(f32 *)((u8 *)angles + 0));
    func_0040CAC0_00443FD8(&rotations[1], 1, *(f32 *)((u8 *)angles + 4));
    func_0040CAC0_00443FD8(rotations, 2, *(f32 *)((u8 *)angles + 8));
    func_0040C9F8_00443FD8(output, &rotations[2], &rotations[1]);
    func_0040C9F8_00443FD8(output, output, rotations);
}
