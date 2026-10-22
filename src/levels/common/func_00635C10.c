#include "common.h"

/* localdecomp:start func_00635C10 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_00635C68(void);

void func_00635C10(u8 *p) {
    __asm__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x140)));
    func_00635C68();
    *(s32 *)(p + 0x1A0) = 0;
    __asm__ __volatile__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x130)));
    *(s32 *)(p + 0xFD4) = 0;
    __asm__ __volatile__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x120)));
    *(s32 *)(p + 0x1A8) = 0;
    __asm__ __volatile__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x140)));
    __asm__ __volatile__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x150)));
    __asm__ __volatile__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x160)));
    __asm__ __volatile__("sq $0, %0" : "=m"(*(u128_t *)(p + 0x190)));
    __asm__ __volatile__("sq $0, %0" : "=m"(*(u128_t *)(p + 0xC0)));
}
/* localdecomp:end func_00635C10 */
