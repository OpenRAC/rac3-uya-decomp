#include "common.h"

/* localdecomp:start func_004A0458 */
void func_004A0EA0(s16 *);
void func_004A0FE8(s16 *);
char *func_004A0458(s16 *p) {
    char *q = (char *)p;
    if (*p == 0) { func_004A0EA0(p); q += 0x20; }
    else if (*p == 1) { func_004A0FE8(p); q += 0x30; }
    return q;
}
/* localdecomp:end func_004A0458 */
