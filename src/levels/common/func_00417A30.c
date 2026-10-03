#include "common.h"

typedef struct { s32 first; s32 second; } Entry_00417A30;
typedef struct {
    u8 pad[8];
    Entry_00417A30 entries[10];
    s32 f58, f5C, f60, f64, f68;
    u8 f6C;
} Queue_00417A30;

s32 func_00417A30(Queue_00417A30 *queue, s32 *first_output, s32 *second_output) {
    s32 next_index;
    if (queue->f60 == 0) return 0;
    if (--queue->f60 == 0) queue->f6C = 0;
    *first_output = queue->entries[queue->f5C].first;
    *second_output = queue->entries[queue->f5C].second;
    queue->entries[queue->f5C].first = -1;
    queue->entries[queue->f5C].second = -1;
    next_index = queue->f5C + 1;
    if (next_index == 10) next_index = 0;
    queue->f5C = next_index;
    return 1;
}
