#include "common.h"

/* localdecomp:start func_003FEBC8 */
extern void func_003FFAC8();

typedef struct { u8 pad[0x450]; s32 f450; } E_3821E8;
extern u8 D_001E2AC0_003821E8[];
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_3821E8;
extern S_3821E8 D_001E7600;
extern u8 D_001DAEA4, D_001DAEA5, D_001DAEA6, D_001DFA64, D_001DFA65, D_001DFA66;
extern f32 D_001DAEA8, D_001DAEAC, D_001DAEB0, D_001DAEB4, D_001DFA68, D_001DFA6C, D_001DFA70, D_001DFA74;
extern s32 D_001E0308, D_001DFA78;
extern void func_003FFAC8();
void func_003FEBC8(s32 a) {
    s32 c;
    if (((E_3821E8 *)(a * 0x460 + (s32)D_001E2AC0_003821E8))->f450 != 0) {
        D_001E7600.f250 = D_001DAEA4;
        D_001E7600.f254 = D_001DAEA5;
        D_001E7600.f258 = D_001DAEA6;
        D_001E7600.f228 = D_001DAEA8;
        D_001E7600.f22C = D_001DAEAC;
        D_001E7600.f238 = D_001DAEB0;
        D_001E7600.f23C = D_001DAEB4;
        c = 0x40000;
    } else {
        D_001E7600.f250 = D_001DFA64;
        D_001E7600.f254 = D_001DFA65;
        D_001E7600.f258 = D_001DFA66;
        D_001E7600.f228 = D_001DFA68;
        D_001E7600.f22C = D_001DFA6C;
        D_001E7600.f238 = D_001DFA70;
        D_001E7600.f23C = D_001DFA74;
        c = 0x7D0000;
    }
    D_001E0308 = c;
    func_003FFAC8();
    D_001DFA78 = 0;
}
/* localdecomp:end func_003FEBC8 */
