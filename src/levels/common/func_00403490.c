#include "common.h"

typedef struct {
    u8 pad0[170];
    s16 id;
} Item403490;

typedef struct {
    u8 pad0[68];
    s16 count;
    u8 pad46[416 - 70];
    Item403490 *items[1];
} List403490;

extern List403490 D_001E5F80;

Item403490 *func_00403490(s32 id) {
    s32 i;
    for (i = 0; i < D_001E5F80.count; i++) {
        Item403490 *item = D_001E5F80.items[i];
        if (item != 0 && item->id == id) {
            return item;
        }
    }
    return 0;
}
