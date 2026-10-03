#include "common.h"
typedef struct {
    u8 padding[0xDC];
    s32 first[16];
    s32 second[16];
} Object_00511200;
extern s32 func_00512028_00511200(void *);
s32 func_00511200(Object_00511200 **owner, s32 address) {
    s32 result = -1;
    s32 index;
    if (func_00512028_00511200((void *)address) == 0) {
        for (index = 0; index < 16; index++) {
            if ((*owner)->first[index] == 0 && (*owner)->second[index] == 0) {
                (*owner)->second[index] = address;
                result = index;
                break;
            }
        }
    }
    return result;
}
