#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A40C8();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003C9888);

/* localdecomp:start func_003C99D0 */
extern u32 *D_001DA0D0_003C99D0;
extern u32 *D_001DA70C_003C99D0;
extern s32 D_001DA714_003C99D0;
extern s32 D_001D4BB0_003C99D0;
extern void func_003CA860(void);
extern s32 func_003CA9C8(s32);
extern void func_003A40C8(void);
void func_003C99D0(void) {
    u32 *save = D_001DA0D0_003C99D0;
    s32 r;
    D_001DA0D0_003C99D0 += 4;
    D_001DA70C_003C99D0[0] = 0x20000000;
    D_001DA70C_003C99D0[1] = (u32)D_001DA0D0_003C99D0;
    D_001DA70C_003C99D0[2] = 0;
    D_001DA70C_003C99D0[3] = 0;
    func_003CA860();
    r = func_003CA9C8(D_001D4BB0_003C99D0);
    func_003A40C8();
    if (D_001DA714_003C99D0 < r) { D_001DA714_003C99D0 = r; }
    D_001DA0D0_003C99D0[0] = 0x20000000;
    D_001DA0D0_003C99D0[1] = (u32)(D_001DA70C_003C99D0 + 4);
    D_001DA0D0_003C99D0[2] = 0;
    D_001DA0D0_003C99D0[3] = 0;
    D_001DA0D0_003C99D0 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA0D0_003C99D0;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003C99D0 */

/* localdecomp:start func_003C9AE0 */
typedef struct {
    u32 word0;
    u8 pad4[0x1F];
    u8 index23;
    u8 pad24[0xC];
    u32 word30;
    u8 pad34[0x1C];
} Item_003C9AE0;

typedef struct {
    Item_003C9AE0 *items;
    s32 count;
} Group_003C9AE0;

typedef struct {
    s16 first;
    s16 second;
} Pair_003C9AE0;

extern Group_003C9AE0 D_002F9880[];
extern Pair_003C9AE0 D_002F9580[];

void func_003C9AE0(void) {
    Group_003C9AE0 *group = D_002F9880;

    if (group->items != 0) {
        do {
            Item_003C9AE0 *item = group->items;
            register s32 loaded_count __asm__("$2") = group->count;

            if (loaded_count > 0) {
                register s32 count __asm__("$7") = loaded_count;
                do {
                    Pair_003C9AE0 *pair = &D_002F9580[item->index23];
                    s16 value = pair->first;

                    if (value != 0) {
                        item->word0 = (item->word0 & 0xFFFFC000) | value;
                    }

                    value = pair->second;
                    count--;
                    if (value != 0) {
                        item->word30 = (item->word30 & 0xFFFFC000) | value;
                    }
                    item++;
                } while (count != 0);
            }
            group++;
        } while (group->items != 0);
    }
}
/* localdecomp:end func_003C9AE0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003C9B80);
TEXT_PADDING(2);
