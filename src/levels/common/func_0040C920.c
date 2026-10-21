#include "common.h"

/* localdecomp:start func_0040C920 */
typedef int u128_t __attribute__((mode(TI)));
void func_0040C920(void *dst, void *src) {
    u128_t t;
    __asm__ __volatile__(
        "lq $8,0x0(%2)\n\t"
        "lq $9,0x10(%2)\n\t"
        "lq %0,0x20(%2)\n\t"
        "nop\n\t"
        "pextlw $12,$9,$8\n\t"
        "pextuw $13,$9,$8\n\t"
        "pextlw $14,$0,%0\n\t"
        "pextuw $15,$0,%0\n\t"
        "pcpyld $8,$14,$12\n\t"
        "pcpyud $9,$12,$14\n\t"
        "sq $8,0x0(%1)\n\t"
        "pcpyld %0,$15,$13\n\t"
        "sq $9,0x10(%1)\n\t"
        "nop"
        : "=&r"(t) : "r"(dst), "r"(src)
        : "$2", "$3", "$6", "$7", "$8", "$9", "$12", "$13", "$14", "$15", "memory");
    *(u128_t *)((u8 *)dst + 0x20) = t;
}
/* localdecomp:end func_0040C920 */
