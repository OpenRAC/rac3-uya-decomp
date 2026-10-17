#include "common.h"
typedef struct { u8 a; u8 b; u8 pad[238]; } Ent_004C4F88;
extern Ent_004C4F88 D_002C5640[];
extern u8 D_0014261F[];
extern void func_0032C5E8(void);
extern void func_0032F658(void);
extern void func_004C5480(void);
extern void func_004C4FF0(void);
extern void func_004C5220(void);
void func_004C4F88(void) {
    func_0032C5E8();
    func_0032F658();
    if ((D_0014261F[0] + D_002C5640)->b) func_004C5480();
    func_004C4FF0();
    func_004C5220();
}
