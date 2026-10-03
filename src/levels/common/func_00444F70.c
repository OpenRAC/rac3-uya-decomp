#include "common.h"
typedef struct {
    f32 first;
    f32 second;
    f32 third;
    f32 fourth;
} __attribute__((aligned(16))) Vector_00444F70;
extern f32 func_00444F60_00444F70(f32, f32, f32);
void func_00444F70(Vector_00444F70 *output, Vector_00444F70 first, Vector_00444F70 second, f32 fraction) {
    output->first = func_00444F60_00444F70(first.first, second.first, fraction);
    output->second = func_00444F60_00444F70(first.second, second.second, fraction);
    output->third = func_00444F60_00444F70(first.third, second.third, fraction);
    output->fourth = func_00444F60_00444F70(first.fourth, second.fourth, fraction);
}
