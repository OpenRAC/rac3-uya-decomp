#include "common.h"

void func_0040C2D0(void *, void *, void *);
/* localdecomp:start func_0044DDA0 */
void func_0044DDA0(char *a0, float *a1, float f) { char *p = a0 + 192; __asm__("sq $0, %0" : "=m"(*(char(*)[16])a1)); *a1 = f; func_0040C2D0(a1, a1, p); }
/* localdecomp:end func_0044DDA0 */
