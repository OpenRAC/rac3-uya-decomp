#include "common.h"

/* localdecomp:start func_004DD310 */
typedef int Q_4DD310 __attribute__((mode(TI)));
typedef struct {
    f32 f[4];
} __attribute__((aligned(16))) V_4DD310;
typedef struct {
    V_4DD310 r[4];
} __attribute__((aligned(16))) M_4DD310;
extern u8 D_001A4BE0[];
extern u8 *func_00435E70(s32, s32);
extern void func_00439610(u8 *);
extern void func_00437600(u8 *, s32, M_4DD310 *);
extern void func_0040C658(M_4DD310 *, V_4DD310 *);
extern void func_0040C9B0(M_4DD310 *, M_4DD310 *, M_4DD310 *);
extern void func_0040C8C0(u8 *, M_4DD310 *);
extern void func_00441C78(u8 *, s32, s32, s32);
#define OBJ (*(u8 **)(g + 0x1A20))
void func_004DD310(void) {
    u8 *g = D_001A4BE0;
    M_4DD310 m;
    V_4DD310 v;
    f32 t;
    Q_4DD310 q;
    M_4DD310 rot;
    M_4DD310 *pr;
    V_4DD310 *pv;
    if (OBJ == 0) {
        OBJ = func_00435E70(0x47A, 0x80);
        if (OBJ == 0) {
            return;
        }
        *(Q_4DD310 *)(OBJ + 0x10) = *(Q_4DD310 *)(g + 0x80);
        *(Q_4DD310 *)(OBJ + 0xF0) = *(Q_4DD310 *)(g + 0x90);
        *(u16 *)(OBJ + 0x32) = 0x40;
        *(u8 *)(OBJ + 0x31) = 1;
        *(u8 *)(OBJ + 0x30) = 0;
        *(u16 *)(OBJ + 0x34) = 0;
        func_00439610(OBJ);
        if (OBJ == 0) {
            return;
        }
    }
    func_00437600(*(u8 **)(g + 0x25C0), 5, &m);
    q = *(Q_4DD310 *)&m.r[3];
    *(Q_4DD310 *)(OBJ + 0x10) = q;
    func_00439610(OBJ);
    t = *(f32 *)(g + 0x98);
    pr = &rot;
    __asm__("sq $0,%0" : "=m"(v));
    v.f[2] = -t;
    pv = &v;
    func_0040C658(pr, pv);
    func_0040C9B0(&m, &m, pr);
    func_0040C8C0(OBJ + 0xC0, &m);
    *(long *)(OBJ + 0x38) = *(long *)(*(u8 **)(g + 0x25C0) + 0x38);
    if (*(s32 *)(g + 0x25C4) == 0x4B) {
        if (*(u8 *)(OBJ + 0x43) != 1) {
            func_00441C78(OBJ, 1, 0, 10);
        }
    } else {
        if (*(u8 *)(OBJ + 0x43) != 0) {
            func_00441C78(OBJ, 0, 0, 0x11);
        }
    }
}
/* localdecomp:end func_004DD310 */
