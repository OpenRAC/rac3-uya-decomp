#include "common.h"

/* localdecomp:start func_00418028 */
typedef struct {
    s32 active;
    s32 unk4;
    u8 pad8[24];
    s32 index;
    s32 unk24;
} S_002E5F70;

typedef struct {
    u8 pad0[8];
    s32 id;
    s32 padC;
} Entry_00418028;

typedef struct {
    u8 pad0[9800];
    s32 present[1];
} S_00160C40;

typedef struct {
    u8 pad0[112];
    s16 h70;
    u8 pad72[4];
    u16 u76;
    u8 pad78[32];
    s16 h98;
    u8 pad9A[4];
    u16 u9E;
} S_001CCFD0;

extern S_002E5F70 D_002E5F70[];
extern Entry_00418028 *D_001DFD40;
extern S_00160C40 D_00160C40[];
extern S_001CCFD0 D_001CCFD0[];

void func_00418028(void) {
    s32 idx;
    s32 id;

    if (D_002E5F70[0].active == 0) {
        return;
    }
    idx = D_002E5F70[0].index;
    if (idx != -1) {
        id = D_001DFD40[idx].id;
        if (id != -1 && D_00160C40[0].present[id] != 0) {
            if (id == D_001CCFD0[0].h98 - 7000 || id == D_001CCFD0[0].h70 - 7000) {
                if ((u32)(D_001CCFD0[0].u76 - 6) >= 2) {
                    D_001CCFD0[0].u76 = 5;
                }
                if ((u32)(D_001CCFD0[0].u9E - 6) >= 2) {
                    D_001CCFD0[0].u9E = 5;
                }
            }
        }
    }
    D_002E5F70[0].active = 0;
    D_002E5F70[0].unk24 = -1;
    D_002E5F70[0].index = -1;
    D_002E5F70[0].unk4 = 0;
}
/* localdecomp:end func_00418028 */
