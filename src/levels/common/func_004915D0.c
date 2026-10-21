#include "common.h"

/* localdecomp:start func_004915D0 */
typedef struct {
    u8 pad0[84];
    s32 (*unk54)(void);
    u8 pad58[12];
    void (*unk64)(void);
} S_004915D0;

extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_001426E0[];
extern u8 D_00143A07[];

extern S_004915D0 *func_00438468(s32, s32);
extern void func_0047B428(void);
extern void func_00486808(s32);
extern s32 func_004867B0(void);
extern void func_00513758(s32);
extern void func_005120B8(s32);
extern void func_0047A270(s32);
extern s32 func_0047B380(void);
extern s32 func_00494DD0(s32);
extern s32 func_00494E58(s32);
extern void func_00495868(s32, s32);
extern void func_00513548(s32, f32, f32);

void func_004915D0(s32 arg0) {
    S_004915D0 *obj;
    s32 prev;

    obj = func_00438468(6625, 108);
    func_0047B428();
    if (D_001426E0[113] == 255 && D_001426E0[114] == 255) {
        D_001426E0[113] = 0;
        D_001426E0[114] = 0;
        func_00486808(arg0);
        func_00513758(func_004867B0());
        func_005120B8(arg0);
    }
    if ((*(s32 *)(D_001D52FC + 452) & 0x10) && (D_001D545C == 12 || D_001D545C == 18)) {
        func_00486808(arg0);
        func_00513758(func_004867B0());
        func_005120B8(arg0);
        return;
    }
    if (*(s32 *)(D_001D52FC + 452) & 0x80) {
        func_0047A270(2);
        func_00513758(func_0047B380());
        func_005120B8(arg0);
        return;
    }
    prev = func_00494E58(func_00494DD0(0));
    func_00495868(func_00494DD0(0), *(s32 *)(D_001D52FC + 452));
    if (func_00494E58(func_00494DD0(0)) != prev) {
        obj->unk64();
    }
    if (D_00143A07[0] >= 2) {
        func_00513548(0x1A0010, 0.65f, 0.9f);
    }
    if (obj->unk54()) {
        func_00513758(func_0047B380());
        func_005120B8(arg0);
    }
}
/* localdecomp:end func_004915D0 */
