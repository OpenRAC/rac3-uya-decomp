#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_00388B68();
extern void func_003C9B80(void);
extern void func_003C9AE0(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003C9B80();
extern void func_003C9AE0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C9888 */
extern f32 D_001DA6F0[];
extern s32 D_001DA700[];
extern f32 D_00225BB0[];
extern f32 D_00330FF0[];
extern void func_00388468();
void func_003C9888(void) {
    f32 *v = D_001DA6F0;
    f32 s = D_00225BB0[0];
    f32 a, ar1, b, c, r1, r2;
    b = v[1] * s;
    a = v[0] * s;
    r1 = 1.0f / (a - b);
    ar1 = a * r1;
    D_001DA700[0] = (s32)(v[0] * 1024.0f);
    D_001DA700[1] = (s32)(v[1] * 1024.0f);
    c = v[2] * s;
    D_001DA700[2] = (s32)(v[2] * 1024.0f);
    r2 = 1.0f / (b - c);
    func_00388468(D_00330FF0, 0x40);
    D_00330FF0[13] = b * r2;
    D_00330FF0[3] = a;
    D_00330FF0[9] = ar1;
    D_00330FF0[0] = r1 * 0.5f;
    D_00330FF0[1] = -r1;
    D_00330FF0[8] = b * r1 * -0.5f;
    D_00330FF0[4] = r2 * 0.5f;
    D_00330FF0[7] = b;
    D_00330FF0[5] = -r2;
    D_00330FF0[12] = c * r2 * -0.5f;
}
/* localdecomp:end func_003C9888 */

/* localdecomp:start func_003C99D0 */
extern u32 *D_001DA0D0;
extern u32 *D_001DA70C;
extern s32 D_001DA714;
extern s32 D_001D4BB0;
extern void func_003CA860(void);
extern s32 func_003CA9C8(s32);
extern void func_003A40C8(void);
void func_003C99D0(void) {
    u32 *save = D_001DA0D0;
    s32 r;
    D_001DA0D0 += 4;
    D_001DA70C[0] = 0x20000000;
    D_001DA70C[1] = (u32)D_001DA0D0;
    D_001DA70C[2] = 0;
    D_001DA70C[3] = 0;
    func_003CA860();
    r = func_003CA9C8(D_001D4BB0);
    func_003A40C8();
    if (D_001DA714 < r) { D_001DA714 = r; }
    D_001DA0D0[0] = 0x20000000;
    D_001DA0D0[1] = (u32)(D_001DA70C + 4);
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0;
    D_001DA0D0 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA0D0;
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

/* localdecomp:start func_003C9B80 */
extern s32 D_001D4BB4;
extern u8 D_00222480[];
extern u8 D_002F9C80[];
extern void func_003886E8(f32 *, void *, f32);
extern void func_00388F08();
extern void func_00388648();
extern void func_11F0A0(s32);
extern void func_003C9C58();
void func_003C9B80(void) {
    u8 v[0x40];
    u32 *o = D_001DA0D0;
    s32 t = D_001D4BB4;
    D_001DA70C = o;
    o += 4;
    D_001D4BB0 = t;
    D_001DA0D0 = o;
    func_00388B68(v);
    func_003886E8((f32 *)(v + 0x30), D_00222480, -1024.0f);
    *(f32 *)(v + 0x3C) = 1.0f;
    func_00388F08(v, D_00222480 - 0x100, v);
    func_003A3E40(5, (s32)v, 4);
    func_003A3E40(0x14D, (s32)v, 4);
    func_11F0A0(0);
    func_003C9C58();
    func_003C99D0();
    func_00388648(D_002F9C80, 0x3000, 0x40);
}
/* localdecomp:end func_003C9B80 */
TEXT_PADDING(2);
