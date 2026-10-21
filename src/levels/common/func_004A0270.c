#include "common.h"

/* localdecomp:start func_004A0270 */
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;

typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

extern u8 *func_004A0230(s32 a, s32 b);
extern void func_0040BCB8(void *dst, void *src, s32 size);

void func_004A0270(Table_4A0270 *table) {
    s32 i;
    for (i = 0; i < table->count; i++) {
        Entry_4A0270 *e = &table->entries[i];
        u8 *obj = func_004A0230(e->arg0, e->arg1);
        if (obj != 0) {
            u8 *dst;
            if (e->kind == 1) {
                dst = (u8 *)e->offset + (s32)obj;
            } else {
                dst = (u8 *)e->offset + *(s32 *)(obj + 104);
            }
            func_0040BCB8(dst, &e->data, e->size);
        }
    }
}
/* localdecomp:end func_004A0270 */
