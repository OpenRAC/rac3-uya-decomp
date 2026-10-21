#include "common.h"

/* localdecomp:start func_004C6CC0 */
typedef struct M_4C6CC0 {
    u8 pad0[0x20];
    s8 b20;
    u8 pad21[0x28 - 0x21];
    struct M_4C6CC0 *next;
    u8 pad2C[0x34 - 0x2C];
    u16 h34;
    u8 pad36[0x64 - 0x36];
    void (*f64)(struct M_4C6CC0 *);
    u8 pad68[0xAA - 0x68];
    s16 hAA;
} M_4C6CC0;

typedef struct {
    unsigned long d0;
    u8 pad8[0x38];
} E_4C6CC0;

extern int D_001D6694;
extern int D_001D4CEC;
extern M_4C6CC0 *D_001E00A8;
extern int D_001E00AC;
extern u8 D_001E118C[];
extern u8 D_001E118D[];
extern int D_001E0300;
extern E_4C6CC0 *D_001E02F8;
extern void func_00412C70(int, int, int);
extern int func_00457288(int, int, int, int, int);
extern int func_004B5360(void);
extern void func_004B51C0(void);
extern void func_004A57D8(void);
extern M_4C6CC0 *func_00438F28(int *);
extern void func_00439610(M_4C6CC0 *);
extern void func_004389D8(M_4C6CC0 *);
extern void func_004DE348(void);
extern void func_003F3660(void);
extern void func_004C5E38(void);
extern void func_0046C640(E_4C6CC0 *);
extern void func_004B5258(void);

void func_004C6CC0(void) {
    M_4C6CC0 *m;
    int i;

    func_00412C70(0, 0, 0);
    if (D_001D6694 == 0 && (D_001D4CEC & 1)) {
        if (func_00457288(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_004B5360() != 0) {
        return;
    }
    func_004B51C0();
    func_004A57D8();
    for (m = D_001E00A8 = func_00438F28(&D_001E00AC); m != 0; m = m->next) {
        if (m->b20 < 0) {
            continue;
        }
        if (m->hAA == 3521) {
            m->f64(m);
            if (m->h34 & 4) {
                continue;
            }
            func_00439610(m);
        } else if (m->hAA == 3250 || m->hAA == 2818 || m->hAA == 601 || m->hAA == 2652 || m->hAA == 4498) {
            func_004389D8(m);
            func_00439610(m);
        }
    }
    if (D_001E118C[0]) {
        func_004DE348();
    }
    if (D_001E118D[0]) {
        func_003F3660();
    }
    func_004C5E38();
    for (i = 0; i <= D_001E0300; i++) {
        E_4C6CC0 *e = &D_001E02F8[i];
        if ((e->d0 & 0x80FF) == 0xFF) {
            func_0046C640(e);
        }
    }
    func_004B5258();
}
/* localdecomp:end func_004C6CC0 */
