#include "common.h"

extern s32 D_001DBF38;
extern s32 D_001DBF40;

void *func_0041A808(s32 a0, s32 id, s32 *size) {
    void *r = 0;
    switch (id) {
    case 0x4027571:
        r = &D_001DBF38;
        *size = 4;
        break;
    case 0x4027572:
        r = &D_001DBF40;
        *size = 4;
        break;
    }
    return r;
}
