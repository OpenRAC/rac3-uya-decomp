#include "common.h"

/* localdecomp:start func_003EBD50 */
typedef struct {
    u8 pad0[56];
    u8 f38;
    u8 f39;
    u8 pad3A[8];
    s8 f42;
    s8 f43;
} Info_003EBD50;
typedef struct {
    u8 pad0[28];
    Info_003EBD50 *info;
} Ent_003EBD50;
typedef struct {
    u8 pad0[124];
    u8 f7C;
    u8 pad7D;
    s16 f7E;
    u8 pad80[4];
    s16 f84;
    s16 f86;
} Obj_003EBD50;
extern Ent_003EBD50 *D_001DF884;
extern s32 D_001A71AC[];
extern s32 D_001A71A4[];
extern s32 func_003EAB98(Obj_003EBD50 *);
s32 func_003EBD50(Obj_003EBD50 *a, Obj_003EBD50 *b) {
    Info_003EBD50 *info;
    info = D_001DF884[a->f84].info;
    if (info->f39 != 0) {
        return -1;
    }
    if (info->f38 != 0 && b->f86 != 19) {
        return 1;
    }
    if (b != 0 && b->f7E == 0) {
        if (b->f7C >= a->f7C || b->f86 == 32) {
            if (b->f86 != 32) {
                return 0;
            }
        }
    }
    if (func_003EAB98(a) == 0) {
        return 0;
    }
    if (info->f43 >= 0 && D_001A71AC[0] != info->f43) {
        return 0;
    }
    if (info->f42 >= 0 && D_001A71A4[0] != info->f42) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_003EBD50 */
