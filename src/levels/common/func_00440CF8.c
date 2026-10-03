#include "common.h"
extern f32 func_0040C3C8_00440CF8(f32);
extern f32 func_0040C3E0_00440CF8(f32);
void func_00440CF8(void *output, f32 radius, f32 first_angle, f32 second_angle) {
    f32 cosine;
    cosine = func_0040C3C8_00440CF8(second_angle);
    *(f32 *)((u8 *)output + 0) = func_0040C3C8_00440CF8(first_angle) * radius * cosine;
    *(f32 *)((u8 *)output + 4) = func_0040C3E0_00440CF8(first_angle) * radius * cosine;
    *(f32 *)((u8 *)output + 8) = func_0040C3E0_00440CF8(second_angle) * radius;
}
