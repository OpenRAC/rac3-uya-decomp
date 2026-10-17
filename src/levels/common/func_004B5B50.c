#include "common.h"

typedef struct Iface Iface;
struct Iface {
    char pad0[0x64];
    void (*fn100)(Iface *);
};

extern s32 D_001D6694[];
extern s32 D_001D4CEC;
extern Iface *D_001D9760[];
extern void func_00412C70(s32, s32, s32);
extern void func_00457288(s32, s32, s32, s32, s32);
extern s32 func_004B5360(void);
extern void func_004B51C0(void);
extern void func_004A57D8(void);
extern void func_0045E788(void);
extern void func_00435DE0(void);
extern void func_004B5258(void);
extern void func_00418478(void);

void func_004B5B50(void) {
    func_00412C70(0, 0, 0);
    if (D_001D6694[0] == 0 && (D_001D4CEC & 1)) {
        func_00457288(4, 1, 1, 0, 0);
        return;
    }
    if (func_004B5360() != 0) {
        return;
    }
    func_004B51C0();
    func_004A57D8();
    func_0045E788();
    func_00435DE0();
    {
        Iface *p = D_001D9760[0];
        p->fn100(p);
    }
    func_004B5258();
    func_00418478();
}
