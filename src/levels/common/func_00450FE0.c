#include "common.h"
typedef struct { u8 padding[0x48]; void *entries[1]; } List_00450FE0;
void func_00450FE0(void *object, s32 index, f32 *first, f32 *second, f32 *third, f32 *fourth, f32 *fifth, f32 *sixth, f32 *seventh, u8 *flag) {
    u8 value;
    void *entry;
    List_00450FE0 *list;
    list = *(List_00450FE0 **)((u8 *)object + 0x24);
    entry = *(void **)((u8 *)list->entries[index] + 0x14);
    if (entry != 0) {
        *first = *(f32 *)((u8 *)entry + 8) * 0.016666668f;
        *second = *(f32 *)((u8 *)entry + 0xC) * 0.016666668f;
        *third = *(f32 *)((u8 *)entry + 0x10) * 0.00027777778f;
        *fourth = *(f32 *)((u8 *)entry + 0x14) * 0.00027777778f;
        *seventh = *(f32 *)((u8 *)entry + 4) * 0.00027777778f;
        *fifth = *(f32 *)((u8 *)entry + 0x18);
        *sixth = *(f32 *)((u8 *)entry + 0x1C);
        value = *(u8 *)((u8 *)entry + 1);
        if (value != 0) {
            *flag = value;
        }
    }
}
