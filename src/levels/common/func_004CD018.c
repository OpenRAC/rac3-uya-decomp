#include "common.h"

typedef struct {
    u8 padding[0x18];
    f32 value;
    u8 reserved[0xC];
    char flag;
} InitContext_004CD018;
extern void func_004C8B28_004CD018(void *, s32);
extern void func_004CB788_004CD018(u8 *, s32);
extern void func_004CB6F8_004CD018(InitContext_004CD018 *);

void func_004CD018(void *object, s32 value) {
    void *part0;
    void *part1;
    void *part2;
    void *part3;
    void *part4;
    void *part5;
    *(s32 *)((u8 *)object + 0xB38) = value;
    if (*(s32 *)((u8 *)object + 0xB3C) != 0) {
        *(s32 *)((u8 *)object + 0xB3C) = 0;
        part4 = object + 0x7E8;
        func_004C8B28_004CD018(object + 0x628, 0);
        part5 = object + 0x870;
        func_004CB788_004CD018(part4, 1);
        part3 = object + 0x8F8;
        func_004CB788_004CD018(part5, 1);
        part2 = object + 0x980;
        func_004CB788_004CD018(part3, 1);
        part1 = object + 0xA08;
        func_004CB788_004CD018(part2, 1);
        part0 = object + 0xA90;
        func_004CB788_004CD018(part1, 1);
        func_004CB788_004CD018(part0, 1);
        func_004CB6F8_004CD018(part4);
        func_004CB6F8_004CD018(part5);
        func_004CB6F8_004CD018(part3);
        func_004CB6F8_004CD018(part2);
        func_004CB6F8_004CD018(part1);
        func_004CB6F8_004CD018(part0);
    }
}
