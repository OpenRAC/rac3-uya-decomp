#include "common.h"

extern s32 func_0060F1F8(s32, s32);
extern void func_0060E1F0(s32, f32, f32);
extern void func_0060E900(s32, s32, s32);
void func_005D8708(s32 id, s32 a, s32 b) {
    func_0060F1F8(0x20016, id);
    if (id == 0xED36) {
        func_0060E1F0(0x20017, 0.1f, 0.866f);
        func_0060E1F0(0x20018, 0.1f, 0.91f);
    } else if (id == 0xED37) {
        func_0060E1F0(0x20017, 0.1f, 0.854f);
        func_0060E1F0(0x20018, 0.1f, 0.89f);
    } else if (id == 0xED4B) {
        func_0060E1F0(0x20017, 0.1f, 0.854f);
    }
    if (a != 0) {
        func_0060E900(0x20017, 1, 1);
    }
    if (b != 0) {
        func_0060E900(0x20018, 1, 1);
    }
}
