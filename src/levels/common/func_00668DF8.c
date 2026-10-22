#include "common.h"

/* localdecomp:start func_00668DF8 */
typedef struct N_00668DF8 {
    u8 pad0[0x80];
    struct N_00668DF8 *prev;
    struct N_00668DF8 *next;
    u8 pad88[0x90 - 0x88];
} N_00668DF8;
extern N_00668DF8 D_0033C210[];
extern N_00668DF8 D_0033C180[];
extern N_00668DF8 D_0033FA50[];
extern N_00668DF8 D_0033F9C0[];
extern N_00668DF8 *D_0024D060[1];
extern s32 D_0024D064[1];
extern N_00668DF8 *D_0024D068[1];
extern s32 D_001E17DC;
extern void func_00669B18(void);

void func_00668DF8(void) {
    s32 i;
    for (i = 0; i < 100; i++) {
        if (i == 0) {
            D_0033C210[0].prev = 0;
            D_0033FA50[0].prev = 0;
        } else {
            D_0033C210[i].prev = &D_0033C180[i];
            D_0033FA50[i].prev = &D_0033F9C0[i];
        }
        if (i == 99) {
            D_0033C210[99].next = 0;
            D_0033FA50[99].next = 0;
        } else {
            D_0033C210[i].next = &D_0033C210[i + 1];
            D_0033FA50[i].next = &D_0033FA50[i + 1];
        }
    }
    D_0024D060[0] = D_0033C210;
    D_0024D068[0] = D_0033FA50;
    D_0024D064[0] = 0;
    D_001E17DC = 0;
    func_00669B18();
}
/* localdecomp:end func_00668DF8 */
