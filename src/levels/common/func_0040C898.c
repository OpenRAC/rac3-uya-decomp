#include "common.h"
typedef struct { u8 pad[150]; u16 c; } S40C;
void func_0040C898(S40C *p) {
    if (p->c < 0xFFFF) p->c++;
}
