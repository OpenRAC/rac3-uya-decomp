#include "common.h"
typedef struct { char pad[48]; char data[80]; } S_003B1D10;
extern char *D_001DE670;
extern S_003B1D10 *D_001E0180;
char *func_003B1D10(void)
{
    int i;
    if (D_001DE670 == 0) {
        return 0;
    }
    i = *(int *)(*(char **)(D_001DE670 + 104) + 32);
    if (i == -1) {
        return 0;
    }
    return D_001E0180[i].data;
}
