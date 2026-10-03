#include "common.h"

extern void *func_0011A0B0(void *destination, const void *source, u32 count);

s32 func_004D0538(u8 *first_output, s32 first_size, u8 *second_output, s32 offset, u8 *first_input, s32 first_length, u8 *second_input, s32 second_length) {
    s32 difference;
    if (first_size + offset < first_length + second_length) return 0;
    if (first_length >= first_size) {
        difference = first_size - first_length;
        func_0011A0B0(first_output, first_input, first_size);
        func_0011A0B0(second_output, first_input + first_size, first_length - first_size);
        func_0011A0B0(second_output + first_length - first_size, second_input, second_length);
    } else {
        difference = first_size - first_length;
        if (second_length >= difference) {
            func_0011A0B0(first_output, first_input, first_length);
            func_0011A0B0(first_output + first_length, second_input, difference);
            func_0011A0B0(second_output, second_input + first_size - first_length, second_length - difference);
        } else {
            func_0011A0B0(first_output, first_input, first_length);
            func_0011A0B0(first_output + first_length, second_input, second_length);
        }
    }
    return first_length + second_length;
}
