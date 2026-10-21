#include "common.h"

/* localdecomp:start func_003D1188 */
typedef struct { u8 pad[208]; f32 arr[6]; } S_003D1188;

extern s16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern s32 D_001E00D8;
extern void *func_00438488(s32, s32, s32);
extern s32 func_0040BA90(s32 *);
extern void func_00443A90(u8 *, void *, s32, u8 *, f32);
extern void func_003D0C28(void *, u8 *, u8 *);

#define SECT(s) (*(s32 *)((s) + 44))
#define FOR_MOBYS(s, p, m)                                                                          \
    for (p = D_0021DEA0[SECT(s)];                                                                   \
         (SECT(s) & 0xff) != 0xff && SECT(s) <= D_001E00D8 && p != 0 &&                            \
         (p[-1] >= 0 || p == D_0021DEA0[SECT(s)]);                                                  \
         p++)

void func_003D1188(void *a0, u8 *s)
{
    s16 *p;
    u8 *m;
    s32 n = 0;
    s32 idx, j;
    void *r;
    u8 *o;

    FOR_MOBYS(s, p, m) {
        m = D_001E009C + ((*p & 0x7fff) << 8);
        if (m == 0) break;
        if (m[32] == 254) continue;
        if (m[32] == 253) continue;
        if (*(s32 *)(s + 64) != -1) {
            r = func_00438488(*(s16 *)(m + 170), 1, 28);
            if (r == 0) continue;
            if ((*(s32 (**)(u8 *))((u8 *)r + 8))(m) != 0) continue;
        }
        n++;
    }
    *(s32 *)(s + 232) = n;
    if (n == 0) return;
    if (*(s32 *)(s + 228) >= n) return;
    if (*(s32 *)(s + 236) != 0 && func_0040BA90((s32 *)(s + 236)) == 0) {
        if (*(s32 *)(s + 236) >= 26) return;
        if (*(f32 *)(s + 48) < *(f32 *)(s + 224)) return;
    }
    idx = 5 - *(s32 *)(s + 232);
    if (*(f32 *)(s + 48) < ((S_003D1188 *)s)->arr[idx]) {
        *(s32 *)(s + 236) = 6;
        return;
    }
    goto check;
found:
    o = D_001E009C + (*(s32 *)(*(u8 **)(m + 104) + 80) << 8);
    func_00443A90(o, a0, 0x10001, o + 16, 9999.0f);
    return;
check:
    if ((idx < 4 && (j = idx + 1, ((S_003D1188 *)s)->arr[j]) <= *(f32 *)(s + 48)) || 0.95f < *(f32 *)(s + 48)) {
        FOR_MOBYS(s, p, m) {
            m = D_001E009C + ((*p & 0x7fff) << 8);
            if (m == 0) return;
            if (m[32] == 254) continue;
        if (m[32] == 253) continue;
            if (*(s32 *)(s + 64) != -1) {
                r = func_00438488(*(s16 *)(m + 170), 1, 28);
                if (r == 0) continue;
                if ((*(s32 (**)(u8 *))((u8 *)r + 8))(m) != 0) continue;
            }
            if (*(s32 *)(*(u8 **)(m + 104) + 80) != -1) goto found;
        }
    } else {
        FOR_MOBYS(s, p, m) {
            m = D_001E009C + ((*p & 0x7fff) << 8);
            if (m == 0) break;
            if (m[32] == 254) continue;
        if (m[32] == 253) continue;
            if (*(s32 *)(s + 64) != -1) {
                r = func_00438488(*(s16 *)(m + 170), 1, 28);
                if (r == 0) continue;
                if ((*(s32 (**)(u8 *))((u8 *)r + 8))(m) != 0) continue;
            }
            func_003D0C28(a0, s, m);
            *(s32 *)(s + 236) = 80;
            return;
        }
        *(s32 *)(s + 236) = 80;
    }
}
/* localdecomp:end func_003D1188 */
