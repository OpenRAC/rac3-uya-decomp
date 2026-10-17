#include "common.h"
extern float func_004065E8(float, float);
extern float func_004065A0(float, float);
float func_0043DD10(float a, float b, float c) {
    return func_004065A0(a, func_004065E8(b, a) * c);
}
