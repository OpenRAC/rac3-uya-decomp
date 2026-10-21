#include "common.h"

/* localdecomp:start func_00503668 */
typedef struct {
    u8 pad0[0x25C4];
    s32 x25C4;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 x25ED;
    u8 pad25EE[0x2880 - 0x25EE];
    s16 x2880;
    s16 x2882;
    u8 pad2884[0x28C0 - 0x2884];
    u8 x28C0;
} S_00503668;

extern u8 D_001A7460[];
typedef struct {
    u8 pad0[420];
    s32 x1A4;
    u8 pad1A8[440 - 424];
    s32 x1B8;
} P_00503668;

extern P_00503668 *D_001D52FC;
extern s32 D_002D1630[];
extern s32 D_002E5F70[];

extern void func_0040BAC0(s16 *);
extern void func_0041FD00(void);

void func_00503668(void) {
    S_00503668 *s;
    s32 v;

    func_0040BAC0((s16 *)D_001A7460);
    func_0040BAC0((s16 *)(D_001A7460 + 2));
    s = (S_00503668 *)(D_001A7460 - 0x2880);
    v = s->x25C4;
    if (v == 55 || v == 19 || v == 21 || v == 136 || v == 20) {
        return;
    }
    if (s->x25ED != 0) {
        return;
    }
    if (D_002D1630[0] != 0) {
        return;
    }
    if (D_002E5F70[0] != 0 || D_002E5F70[9] != -1) {
        return;
    }
    if (D_001D52FC->x1A4 & 0x10) {
        s->x2880 = 20;
    }
    if (s->x2880 != 0 && (D_001D52FC->x1B8 & 0x10)) {
        s->x28C0 = 1;
        func_0041FD00();
        if (s->x2882 == 0) {
            s->x2882 = 20;
        }
    }
}
/* localdecomp:end func_00503668 */
