#include "common.h"

/* localdecomp:start func_004295C8 */
typedef struct {
    u8 pad[92];
    s16 count;
} State_004295C8;

extern State_004295C8 D_001E6E00[];
extern void func_0042A988(void);

void func_004295C8(void) {
    while (D_001E6E00[0].count > 0) {
        func_0042A988();
        D_001E6E00[0].count--;
    }
}
/* localdecomp:end func_004295C8 */
