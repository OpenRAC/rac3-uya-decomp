#include "common.h"

extern s32 func_00511CE8();

typedef struct { u8 pad[0x18]; s32 arr[1]; } S_3E1770;
 
s32 func_00511CE8(void *p, s32 i) {
    return (*(S_3E1770 **)((u8 *)p + 0x4))->arr[i];
}
