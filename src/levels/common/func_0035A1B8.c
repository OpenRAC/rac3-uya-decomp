#include "common.h"

/* localdecomp:start func_0035A1B8 */
typedef struct {
    u8 pad0[32];
    f32 m[2][4];
    u8 pad40[1264 - 64];
    f32 f1264[2];
    u8 pad4F8[8];
    f32 f1280[2];
    u8 pad508[8];
    f32 f1296;
    s32 f1300;
    s32 f1304;
    s32 f1308;
    s32 f1312;
    u8 pad524[1328 - 1316];
} E0035A1B8;

extern E0035A1B8 D_00284580[];
extern void func_004C6EC8(f32 *, f32 *);
extern f32 func_00445168(f32 *, f32, f32, f32, f32, s32 *);
extern s32 func_0040BA90(s32 *);

void func_0035A1B8(void) {
    E0035A1B8 *base = D_00284580;
    E0035A1B8 *e;
    s32 i;
    s32 j;

    for (i = 0; i < 25; i++) {
        e = &base[i];
        if (e->f1300 == 1) {
            for (j = 0; j < 2; j++) {
                func_004C6EC8(e->m[j], e->m[j]);
                e->f1280[j] += e->f1264[j];
                if (e->f1280[j] <= -8.0f) {
                    e->f1280[j] += 8.0f;
                }
            }
            if (e->f1304 == 0) {
                func_00445168(&e->f1296, 0.5f, 0.002f, 0.0002f, 0.02f, &e->f1308);
                if (e->f1296 == 0.5f) {
                    e->f1304 = 2;
                    e->f1312 = 60;
                }
            } else if (e->f1304 == 1) {
                func_00445168(&e->f1296, 0.0f, 0.002f, 0.0002f, 0.02f, &e->f1308);
                if (e->f1296 == 0.0f) {
                    e->f1300 = 0;
                }
            } else if (func_0040BA90(&e->f1312)) {
                e->f1304 = 1;
            }
        }
    }
}
/* localdecomp:end func_0035A1B8 */
