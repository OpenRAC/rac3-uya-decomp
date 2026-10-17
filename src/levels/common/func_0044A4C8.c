#include "common.h"
typedef char *va_list_44A4C8;
extern void func_0044A510(s32, s32, va_list_44A4C8);
void func_0044A4C8(s32 a0, s32 a1, ...) {
    va_list_44A4C8 ap;
    ap = (char *)__builtin_next_arg(a1)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    func_0044A510(a0, a1, ap);
}
