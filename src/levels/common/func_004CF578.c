#include "common.h"

typedef struct { s32 f0; s32 f4; u8 pad8[0x28]; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } Buffer_004CF578;

void func_004CF578(Buffer_004CF578 *buffer, s32 *o1, s32 *o2, s32 *o3, s32 *o4) {
    s32 lo, hi, value, remaining;
    if (buffer->f0 == 0) {
        if (buffer->f4 != 4) {
            *o1 = (s32)((u8 *)buffer + 8 + buffer->f30);
            *o2 = 0x28 - buffer->f30;
            *o3 = buffer->f34;
            *o4 = buffer->f40;
        } else {
            *o1 = buffer->f34;
            *o2 = buffer->f40;
            *o3 = 0;
            *o4 = 0;
        }
    } else {
        value = buffer->f40;
        lo = buffer->f3C;
        hi = buffer->f38;
        remaining = value - lo;
        if (value - hi >= remaining) {
            *o1 = buffer->f34 + hi;
            *o2 = remaining;
            *o3 = 0;
            *o4 = 0;
        } else {
            *o1 = buffer->f34 + hi;
            *o2 = buffer->f40 - buffer->f38;
            *o3 = buffer->f34;
            *o4 = remaining - (buffer->f40 - buffer->f38);
        }
    }
}
