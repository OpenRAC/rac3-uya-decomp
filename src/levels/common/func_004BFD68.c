#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6A38 - 0x4958];
    u8 f6A38[1];
} S_4BFD68;
typedef struct {
    u8 pad0[0x10];
    s32 (*f10)(void *, s32);
} VT_4BFD68;
typedef struct {
    u8 pad0[8];
    VT_4BFD68 *vt;
    u8 pad1[0x50 - 0xC];
    void *f50;
} O_4BFD68;
typedef struct {
    u8 pad0[4];
    s32 f4;
} G_4BFD68;
extern S_4BFD68 D_00160C40[];
extern G_4BFD68 D_001E1660[];
extern u8 D_002F27D8[];
extern u8 D_00244ED0[];
extern s32 D_001DC1F0;
extern s16 D_001CCFD4[];
extern void func_00512478(s32);
extern void func_00477B88(void);
extern void func_004759F0(void);
extern void func_004780F8(void);
extern void func_004BD480(void *);
extern void func_005136D8(s32, s32);
extern void func_004BD808(s32, void *);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, void *, s32, s32, void *);
extern void *func_00511BF8(void);
extern void *func_00511E28(void *);
extern O_4BFD68 *func_00511368(void *, s32);
extern void func_005131A0(s32, s32);
extern void func_00512AB0(s32, s32, s32);
extern void func_004BFEA0(void);
extern void func_004C01C8(void);

/* localdecomp:start func_004BFD68 */
void func_004BFD68(void) {
    O_4BFD68 *o;
    void *p;

    func_00512478(1);
    func_00477B88();
    func_004759F0();
    func_004780F8();
    func_004BD480(D_002F27D8);
    func_005136D8(0x1B, 0x480000);
    func_004BD808(0, D_002F27D8);
    func_00512478(0);
    func_00490B98(func_00490968(0), D_00244ED0, 0, D_00160C40->f4954, D_00160C40->f6A38);
    if (D_001E1660->f4 == 0) {
        p = func_00511BF8();
    } else {
        p = D_001E1660;
    }
    o = func_00511368(func_00511E28(p), 0x480019);
    if (o == 0 || o->vt->f10(o, D_001DC1F0) == 0) {
        o = 0;
    }
    o->f50 = func_00490968(0);
    if (D_001CCFD4[0] == 0) {
        func_005131A0(0x480019, 0x2A);
    }
    func_00512AB0(0x480019, 0x8000, 1);
    func_004BFEA0();
    func_004C01C8();
}
/* localdecomp:end func_004BFD68 */
