#include "common.h"

typedef struct Motion_004957A0 Motion_004957A0;
extern void func_00495760_00495868(u8 *);
extern void func_00495980_00495868(void *);
extern void func_00495A48_00495868(void *);
extern void func_00495B08_00495868(void *);
extern void func_00496068_00495868(void *);
extern void func_004957A0_00495868(Motion_004957A0 *);
extern void func_0047B920_00495868(void);
extern void func_00495C98_00495868(void *, s32);
extern s32 func_00512480_00495868(s32, f32, f32);
extern s32 func_00513548_00495868(s32, f32, f32);
extern s32 func_00512D70_00495868(s32, s32);
extern s32 func_005129D8_00495868(s32, f32);

void func_00495868(void *arg0, s32 arg1) {
    func_00495760_00495868(arg0);
    func_00495980_00495868(arg0);
    func_00495A48_00495868(arg0);
    func_00495B08_00495868(arg0);
    func_00496068_00495868(arg0);
    func_004957A0_00495868(arg0);
    func_0047B920_00495868();
    if ((*(s32 *)((u8 *)(arg0) + 0x1C)) == 0) {
        func_00495C98_00495868(arg0, arg1);
    }
    func_00512480_00495868(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_00513548_00495868(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_00512480_00495868(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_00513548_00495868(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_00512D70_00495868(0x4F00B3, (*(u8 *)((u8 *)(arg0) + 0xA9)));
    func_005129D8_00495868(0x4F00B0, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_005129D8_00495868(0x4F00B1, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_00513548_00495868(0x4F00AF, (*(f32 *)((u8 *)(arg0) + 0x60)), (*(f32 *)((u8 *)(arg0) + 0x64)));
}
