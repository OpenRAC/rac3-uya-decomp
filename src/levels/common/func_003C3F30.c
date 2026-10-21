#include "common.h"

/* localdecomp:start func_003C3F30 */
extern char *D_001E0180;
extern void func_003C3EA8(void *, void *, char *, char *);
void func_003C3F30(void *a, void *b, int i) {
    char *p = D_001E0180 + i * 128;
    func_003C3EA8(a, b, p + 48, p + 112);
}
/* localdecomp:end func_003C3F30 */
