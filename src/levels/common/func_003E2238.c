#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[1120];
} Ent1120;
extern Ent1120 D_001E2C50[];

void func_003E2238(u8 *obj, u128_t *out) {
    *out = *(u128_t *)&D_001E2C50[*(s32 *)(obj + 148)];
}
