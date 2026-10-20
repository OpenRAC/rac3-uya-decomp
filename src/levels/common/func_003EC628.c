#include "common.h"

typedef struct {
    u8 pad0[28];
    u8 *obj;
} Entry_003EC628;

extern Entry_003EC628 *D_001DF884;
extern s32 D_001D545C;
extern s32 D_001D6694;
extern s32 func_004B6C68(void);
extern s32 func_003EBE48(u8 *);
extern void func_003EC0B0(u8 *);

s32 func_003EC628(u8 *m) {
    u8 *e = D_001DF884[*(s16 *)(m + 132)].obj;

    if (*(s16 *)(e + 38) != 0) {
        if (D_001D545C == 28 && func_004B6C68() != 0) {
            *(s16 *)(e + 38) = 0;
        }
        return 0;
    }
    if (D_001D6694 != 0 && func_003EBE48(m) != 0) {
        *(s16 *)(e + 38) = 0;
        *(s32 *)(e + 32) = 0;
        return 0;
    }
    if (D_001D545C != 28 || func_004B6C68() == 0) {
        func_003EC0B0(m);
    }
    return 0;
}
