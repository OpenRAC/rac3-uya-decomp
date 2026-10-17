#include "common.h"

extern void func_004D1F58();

typedef struct {
    s32 stream;
    u8 *entries;
    s32 write_index;
    s32 count;
    s32 capacity;
} Queue_003AD650;
void func_004D1F58(volatile Queue_003AD650 *queue, s32 stream, u8 *entries, s32 capacity) {
    s32 index = 0;
    s32 offset;
    queue->count = 0;
    queue->stream = stream;
    queue->entries = entries;
    queue->capacity = capacity;
    queue->write_index = 0;
    if (capacity > 0) {
        offset = 0;
        do {
            *(s32 *)(offset + (s32)queue->entries) = 0;
            *(s32 *)(offset + (s32)queue->entries + 4) = index;
            index++;
            offset += 0x27E40;
        } while (index < capacity);
    }
}
