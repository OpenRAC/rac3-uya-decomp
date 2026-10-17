#include "common.h"

typedef struct VObj486688 VObj486688;
typedef struct {
    s32 pad0;
    s32 pad4;
    s32 pad8;
    void (*fn)(VObj486688 *);
} VTbl486688;
struct VObj486688 {
    s32 pad0;
    VTbl486688 *vt;
};

extern s32 D_001D8908;
extern s32 D_001D890C;
extern s32 D_001D87D0[2];
extern s32 D_001D87F0[2];
extern u8 D_001D4C60[];
extern u8 D_001D4C80[];
extern void func_0047B7B8(s32);
extern VObj486688 *func_00490968(s32);
extern void func_0045CA60(s32);
extern void func_00513928(s32);
extern void func_004846F0(void *, void *);

void func_00486688(void) {
    VObj486688 *o;
    func_0047B7B8(D_001D8908);
    func_0047B7B8(D_001D890C);
    o = func_00490968(0);
    o->vt->fn(o);
    func_0045CA60(1);
    func_00513928(16);
    func_00513928(17);
    func_00513928(19);
    func_004846F0(D_001D87D0, D_001D4C60);
    func_004846F0(D_001D87F0, D_001D4C80);
}
