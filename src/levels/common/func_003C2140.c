#include "common.h"

/* localdecomp:start func_003C2140 */
typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[106];
    f32 unk6C;
    u8 pad70[128];
} S_002C5640;

extern u8 D_001425C0[];
extern S_002C5640 D_002C5640[];

extern void func_004C41E8(u8 *, u8 *);
extern u8 *func_003914C0(u8 *, u8 *);
extern void func_004A7200(s32, s32, u8 *);
extern s32 func_003BD258(void);
extern s32 func_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00443648(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_004C7670(void);
extern void func_003C2068(u8 *);

void func_003C2140(u8 *arg0) {
    u8 buf[16];
    u8 *v;
    u8 x;
    s32 t;

    x = D_002C5640[D_001425C0[87]].unk1;
    t = x < 4;
    if (!t) {
        func_004C41E8(arg0 + 16, buf);
        v = func_003914C0(arg0 + 16, buf);
        if (v != 0) {
            *(s32 *)(v + 184) = *(s32 *)(arg0 + 184);
        }
    } else if (x == 0 || !t) {
        func_004A7200(0, 0, arg0);
        func_0032FE90(arg0 + 16, 0, 20, 20, 20, 20, 0, 2, 0.5f, 0.0f, 0.0f, 2.0f,
                      func_003BD258() == 0, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_00443648(arg0, arg0 + 16, 0x1010000, 0, 1, 0, 2.0f, D_002C5640[D_001425C0[87]].unk6C, 0.0f);
    }
    if (func_004C7670() != 0) {
        func_0032FE90(arg0 + 16, 0, 3, 3, 3, 6, 3, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                      0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    func_003C2068(arg0);
}
/* localdecomp:end func_003C2140 */
