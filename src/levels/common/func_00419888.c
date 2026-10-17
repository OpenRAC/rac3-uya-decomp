#include "common.h"

typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
extern LookupEntry_38E730 *D_001DFD9C_0038E730[];
s32 func_00419888(s32 key) {
    LookupEntry_38E730 *entry = *D_001DFD9C_0038E730;
    s32 index = 0;
    if (entry->key != 0xFFFF && entry->key != key) {
        LookupEntry_38E730 *cursor = entry;
        s32 current;
        for (;;) {
            cursor++;
            current = cursor->key;
            index++;
            if (current == 0xFFFF || current == key) break;
        }
    }
    return index <= 0x3FF ? index : -1;
}
