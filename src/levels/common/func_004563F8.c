#include "common.h"

extern u8 *D_001E00A0;
extern u8 *D_001E00A4;
extern void func_0035B9A8(u8 *);
extern void func_00384CB0(u8 *);
extern void func_003C2068(u8 *);
extern void func_0032DDE0(u8 *);
extern void func_0032FE68(u8 *);
extern void func_00378268(u8 *);
extern void func_003D2870(u8 *);
extern void func_0039E8A0(u8 *);
extern void func_003D9008(u8 *);
extern void func_003098E8(u8 *);
extern void func_00370CC8(u8 *);
extern void func_003DF848(u8 *);
extern void func_0038E920(u8 *);
extern void func_00361870(u8 *);
extern void func_0035F128(u8 *);
extern void func_0038B618(u8 *);
extern void func_00382610(u8 *);
extern void func_00395470(u8 *);
extern void func_003985B0(u8 *);
extern void func_00344188(u8 *);
extern void func_0030C5C0(u8 *);
extern void func_0031D6B0(u8 *);
extern void func_0031ED58(u8 *);
extern void func_00436220(u8 *);
extern void func_00303440(u8 *);

void func_004563F8(s32 (*filter)(u8 *), void (*deflt)(u8 *))
{
    u8 *m;
    s32 (*f)(u8 *) = filter;
    void (*d)(u8 *) = deflt;

    for (m = D_001E00A0; m < D_001E00A4; m += 256) {
        if (m == 0) continue;
        if (m[32] == 254) continue;
        if (m[32] == 253) continue;
        if (filter != 0 && f(m) == 0) continue;
        switch (*(s16 *)(m + 170)) {
        case 6225:
            func_0035B9A8(m);
            break;
        case 6273:
            func_00384CB0(m);
            break;
        case 6874:
            func_003C2068(m);
            break;
        case 4966:
            func_0032DDE0(m);
            break;
        case 4967:
            func_0032FE68(m);
            break;
        case 6253:
            func_00378268(m);
            break;
        case 7107:
            func_003D2870(m);
            break;
        case 6299:
            func_0039E8A0(m);
            break;
        case 7486:
            func_003D9008(m);
            break;
        case 2473:
            func_003098E8(m);
            break;
        case 6247:
            func_00370CC8(m);
            break;
        case 7685:
            func_003DF848(m);
            break;
        case 6282:
            func_0038E920(m);
            break;
        case 6234:
            func_00361870(m);
            break;
        case 6232:
            func_0035F128(m);
            break;
        case 6280:
            func_0038B618(m);
            break;
        case 6258:
            func_00382610(m);
            break;
        case 6291:
            func_00395470(m);
            break;
        case 6292:
            func_003985B0(m);
            break;
        case 2690:
            func_00344188(m);
            break;
        case 2715:
            func_0030C5C0(m);
            break;
        case 3684:
            func_0031D6B0(m);
            break;
        case 3790:
        case 6295:
            func_0031ED58(m);
            break;
        case 3291:
            func_00436220(m);
            break;
        case 806:
            if (*(u8 **)(m + 184) == m) func_00303440(m);
            break;
        default:
            if (deflt != 0) d(m);
            break;
        }
    }
}
