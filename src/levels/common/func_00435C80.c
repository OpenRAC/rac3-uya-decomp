#include "common.h"

/* localdecomp:start func_00435C80 */
typedef struct {
    unsigned char id;
    unsigned char pad;
} Slot00435C80;

extern Slot00435C80 D_00143B30[];
extern int func_00434A28(Slot00435C80 *p);

Slot00435C80 *func_00435C80(int id)
{
    Slot00435C80 *r = 0;
    int i;

    if (id != -1) {
        for (i = 0; i < 96; i++) {
            if (func_00434A28(&D_00143B30[i]) == 0 && D_00143B30[i].id - 1 == id) {
                r = &D_00143B30[i];
                break;
            }
        }
    } else {
        r = &D_00143B30[0];
    }
    return r;
}
/* localdecomp:end func_00435C80 */
