#include "common.h"

/* localdecomp:start func_00453FC0 */
typedef struct E_453FC0 {
    void (*fn)(struct E_453FC0 *);
    s32 id;
    u8 pad[0xA428];
} E_453FC0;
typedef struct {
    u8 pad[0xAA];
    s16 id;
} O_453FC0;
extern s32 D_001D6780;
extern E_453FC0 D_002D1710[];

s32 func_00453FC0(O_453FC0 *obj, void (*fn)(E_453FC0 *), s32 *out) {
    s32 i;
    s32 cur;

    for (i = 0; i < 2; i++) {
        cur = D_001D6780;
        if (D_002D1710[cur].id == -1 || D_002D1710[cur].id == obj->id) {
            *out = D_002D1710[cur].id != -1;
            D_002D1710[cur].id = obj->id;
            D_002D1710[cur].fn = fn;
            D_001D6780 = (D_001D6780 + 1) % 2;
            return cur;
        }
        D_001D6780 = (D_001D6780 + 1) % 2;
    }
    if (D_002D1710[D_001D6780].fn != 0) {
        D_002D1710[D_001D6780].fn(&D_002D1710[D_001D6780]);
    }
    {
        s32 j = D_001D6780;
        *out = 0;
        D_002D1710[j].id = obj->id;
        D_002D1710[j].fn = fn;
        D_001D6780 = (D_001D6780 + 1) % 2;
        return j;
    }
}
/* localdecomp:end func_00453FC0 */
