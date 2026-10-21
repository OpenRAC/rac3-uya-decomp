#include "common.h"

/* localdecomp:start func_00449C10 */
typedef struct Moby_449C10 {
    u8 pad[170];
    s16 oClass;
    u8 pad2[12];
    struct Moby_449C10 *f184;
} Moby_449C10;
typedef struct {
    u8 pad[1];
    u8 f1;
    u8 pad2[14];
    s32 f16;
    u8 pad3[220];
} S_449C10;
typedef struct {
    u8 pad[4608];
    Moby_449C10 *f1200;
    u8 pad2[36];
    s32 f1228;
} H_449C10;
extern H_449C10 D_001A4BE0;
extern u8 D_00142637[];
extern u8 D_001425C0[];
extern S_449C10 D_002C5640[];
s32 func_00449C10(Moby_449C10 *m) {
    Moby_449C10 *r;
    s32 i;
    S_449C10 *w;
    s32 oc;

    if (m == 0) {
        return 255;
    }
    if (D_001A4BE0.f1228 == 135 && m->oClass == 6291) {
        return 135;
    }
    if (D_001A4BE0.f1228 == 87 && m->oClass == 6291) {
        return 87;
    }
    if (D_001A4BE0.f1228 == 119 && D_002C5640[D_00142637[0]].f1 >= 4 && m->oClass == 6229) {
        return 119;
    }
    if (D_001A4BE0.f1228 == 17 && (m->oClass == 3161 || m->oClass == 1481)) {
        return 17;
    }
    if (D_001A4BE0.f1228 == 127 && m->oClass == 71) {
        return 127;
    }
    if (D_001A4BE0.f1228 == 71 && m->oClass == 4501) {
        return 71;
    }
    switch (m->oClass) {
    case 6290:
    case 6235:
    case 6258:
        return 135;
    case 6226:
    case 6227:
    case 6228:
    case 6229:
    case 6287:
    case 6291:
    case 6874:
    case 6892:
        return 87;
    case 6232:
    case 6234:
    case 6245:
    case 6277:
    case 6280:
    case 6296:
        return 119;
    case 1481:
    case 2862:
    case 3161:
        return 17;
    case 4501:
        return 22;
    case 6211:
    case 6288:
    case 7352:
        return 127;
    case 6249:
    case 6253:
        return 103;
    case 6256:
    case 6299:
    case 7257:
        return 143;
    case 6257:
    case 6259:
        return 151;
    case 6250:
    case 6251:
        return 95;
    case 6246:
    case 6247:
        return 79;
    case 2661:
    case 2662:
    case 2690:
    case 3162:
    case 4966:
        return 21;
    case 3684:
    case 3790:
        return 19;
    case 6244:
    case 6279:
    case 6292:
        return 63;
    case 2473:
    case 2715:
        return 16;
    }
    if (m == D_001A4BE0.f1200) {
        return D_001A4BE0.f1228;
    }
    r = m->f184;
    if (r != 0 && r == D_001A4BE0.f1200) {
        return D_001A4BE0.f1228;
    }
    oc = m->oClass;
    for (i = 0; i < 156; i++) {
        w = &D_002C5640[D_001425C0[i]];
        if (oc == w->f16) {
            return i;
        }
        if (m->f184 != 0 && m->f184->oClass == w->f16) {
            return i;
        }
    }
    return 255;
}
/* localdecomp:end func_00449C10 */
