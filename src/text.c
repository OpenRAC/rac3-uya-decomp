#include "common.h"

/* localdecomp:start func_0037D100 */
void func_0037D100(void) {
    func_003934E8(0, 0);
}
/* localdecomp:end func_0037D100 */

/* localdecomp:start func_0037D120 */
extern void func_003B62D0(s32);
extern void func_003ADC80(void *);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern u8 D_001E2340[];

void func_0037D120(void) {
    func_003B62D0(1);
    func_003ADC80(D_001E2340);
    func_0039BEC0(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_0037D120 */

/* localdecomp:start func_0037D160 */
extern void func_003B62D0(s32);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);

void func_0037D160(void) {
    func_003B62D0(1);
    func_0039BEC0(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_0037D160 */

/* localdecomp:start func_0037D198 */
s32 func_0037D198(void) {
}
/* localdecomp:end func_0037D198 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037D1A0);

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003ECDC0(s32, s32);
extern void *func_003A9B10(void *, s32);
extern s32 D_001D5C78;

typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227600;
INCLUDE_ASM("asm/nonmatchings/text", func_0037D1A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037D200);

/* localdecomp:start func_0037DC30 */
s32 func_0037DC30(void) {
    return 0;
}
/* localdecomp:end func_0037DC30 */

/* localdecomp:start func_0037DC38 */
s32 func_0037DC38(void) {
}
/* localdecomp:end func_0037DC38 */

/* localdecomp:start func_0037DC40 */
s32 func_0037DC40(void) {
}
/* localdecomp:end func_0037DC40 */

/* localdecomp:start func_0037DC48 */
s32 func_0037DC48(void) {
}
/* localdecomp:end func_0037DC48 */

/* localdecomp:start func_0037DC50 */
s32 func_0037DC50(void) {
}
/* localdecomp:end func_0037DC50 */

/* localdecomp:start func_0037DC58 */
extern u8 D_001427AB;
u8 func_0037DC58(void) {
    return D_001427AB;
}
/* localdecomp:end func_0037DC58 */

extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
INCLUDE_ASM("asm/nonmatchings/text", func_0037DC68);

/* localdecomp:start func_0037DCB0 */
extern s32* func_0037DC68(void);
void func_0037DCB0(void) {
    func_0037DC68();
}
/* localdecomp:end func_0037DCB0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037DCD0);

/* localdecomp:start func_0037DCD8 */
s32 func_0037DCD8(void) {
}
/* localdecomp:end func_0037DCD8 */

/* localdecomp:start func_0037DCE0 */
s32 func_0037DCE0(void) {
}
/* localdecomp:end func_0037DCE0 */

/* localdecomp:start func_0037DCE8 */
s32 func_0037DCE8(void) {
}
/* localdecomp:end func_0037DCE8 */

/* localdecomp:start func_0037DCF0 */
s32 func_0037DCFB(void) {
    return 0;
}
/* localdecomp:end func_0037DCF0 */

/* localdecomp:start func_0037DCF8 */
s32 func_0037DCF8(void) {
    return 0;
}
/* localdecomp:end func_0037DCF8 */

/* localdecomp:start func_0037DD00 */
s32 func_0037DD00(void) {
}
/* localdecomp:end func_0037DD00 */

/* localdecomp:start func_0037DD08 */
s32 func_0037DD08(void) {
}
/* localdecomp:end func_0037DD08 */

/* localdecomp:start func_0037DD10 */
s32 func_0037DD10(void) {
}
/* localdecomp:end func_0037DD10 */

/* localdecomp:start func_0037DD18 */
s32 func_0037DD18(void) {
}
/* localdecomp:end func_0037DD18 */

/* localdecomp:start func_0037DD20 */
s32 func_0037DD20(void) {
    return 0;
}
/* localdecomp:end func_0037DD20 */

/* localdecomp:start func_0037DD28 */
s32 func_0037DD28(void) {
    return 1;
}
/* localdecomp:end func_0037DD28 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037DD30);

INCLUDE_ASM("asm/nonmatchings/text", func_0037DF20);

INCLUDE_ASM("asm/nonmatchings/text", func_0037DF28);

/* localdecomp:start func_0037DF98 */
extern s32 func_0037DF28(void);

s32 func_0037DF98(void) {
    register u8 *gp __asm__("gp");
    s32 index;
    s32 fallback;
    s32** basePtr;

    index = func_0037DF28();
    fallback = (s32)(gp - 0x7128);
    
    // Pattern Library Scheduling Fence: Passing both operands forces the 
    // compiler to completely materialize row 14 BEFORE executing the branch check.
    __asm__ volatile("" : : "r"(index), "r"(fallback));

    if (index < 0) {
        return fallback;
    }
    
    basePtr = (s32**)0x1D9A20; // 0x001E0000 - 0x65E0
    return (*basePtr)[index * 4];
}
/* localdecomp:end func_0037DF98 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037DFD8);

/* localdecomp:start func_0037E030 */
extern s32 func_0037DFD8(void);
extern void func_0037DF98(s32);
void func_0037E030(void) {
    func_0037DF98(func_0037DFD8());
}
/* localdecomp:end func_0037E030 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037E058);

extern s32 D_001D5680;
INCLUDE_ASM("asm/nonmatchings/text", func_0037E060);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E070);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E098);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E0B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E0F0);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E1D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E208);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E250);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E2A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E2F0);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E368);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E4B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E548);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E568);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E630);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E7C8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E7D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E878);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E920);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E9B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EA98);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EAA0);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EB20);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EB68);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EE80);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F090);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F228);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F420);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F4F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F550);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F588);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F7A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F978);

INCLUDE_ASM("asm/nonmatchings/text", func_0037FEE8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037FF90);

INCLUDE_ASM("asm/nonmatchings/text", func_003801C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003804A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00380600);

INCLUDE_ASM("asm/nonmatchings/text", func_003807F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003808E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003809F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00380AB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00380D28);

INCLUDE_ASM("asm/nonmatchings/text", func_00380D48);

INCLUDE_ASM("asm/nonmatchings/text", func_003810C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003813E0);

INCLUDE_ASM("asm/nonmatchings/text", func_00381A48);

INCLUDE_ASM("asm/nonmatchings/text", func_00381A50);

INCLUDE_ASM("asm/nonmatchings/text", func_00381C18);

INCLUDE_ASM("asm/nonmatchings/text", func_00381D90);

INCLUDE_ASM("asm/nonmatchings/text", func_00381DD0);

INCLUDE_ASM("asm/nonmatchings/text", func_00381F10);

INCLUDE_ASM("asm/nonmatchings/text", func_00381F18);

INCLUDE_ASM("asm/nonmatchings/text", func_003821E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003822C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003823A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00382458);

INCLUDE_ASM("asm/nonmatchings/text", func_00382F40);

INCLUDE_ASM("asm/nonmatchings/text", func_00382F90);

INCLUDE_ASM("asm/nonmatchings/text", func_003830E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00383840);

INCLUDE_ASM("asm/nonmatchings/text", func_00383848);

INCLUDE_ASM("asm/nonmatchings/text", func_003838C0);

INCLUDE_ASM("asm/nonmatchings/text", func_00383A90);

INCLUDE_ASM("asm/nonmatchings/text", func_00383B08);

/* localdecomp:start func_00383B90 */
extern void func_0038DA80(void);
void func_00383B90(void) {
    func_0038DA80();
}
/* localdecomp:end func_00383B90 */

INCLUDE_ASM("asm/nonmatchings/text", func_00383BB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00383FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00384418);

INCLUDE_ASM("asm/nonmatchings/text", func_00384420);

INCLUDE_ASM("asm/nonmatchings/text", func_00384B48);

INCLUDE_ASM("asm/nonmatchings/text", func_00384B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00384C98);

INCLUDE_ASM("asm/nonmatchings/text", func_00384DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_00384EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00384EC0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385438);

INCLUDE_ASM("asm/nonmatchings/text", func_00385570);

INCLUDE_ASM("asm/nonmatchings/text", func_00385628);

INCLUDE_ASM("asm/nonmatchings/text", func_00385688);

INCLUDE_ASM("asm/nonmatchings/text", func_003856D8);

INCLUDE_ASM("asm/nonmatchings/text", func_00385750);

INCLUDE_ASM("asm/nonmatchings/text", func_003857C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00385840);

INCLUDE_ASM("asm/nonmatchings/text", func_00385890);

INCLUDE_ASM("asm/nonmatchings/text", func_00385908);

INCLUDE_ASM("asm/nonmatchings/text", func_00385980);

INCLUDE_ASM("asm/nonmatchings/text", func_00385B60);

INCLUDE_ASM("asm/nonmatchings/text", func_00385CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385E40);

INCLUDE_ASM("asm/nonmatchings/text", func_00386210);

INCLUDE_ASM("asm/nonmatchings/text", func_00386488);

INCLUDE_ASM("asm/nonmatchings/text", func_00386608);

INCLUDE_ASM("asm/nonmatchings/text", func_003866E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003867F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003869E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003869E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00386D98);

INCLUDE_ASM("asm/nonmatchings/text", func_00386F28);

INCLUDE_ASM("asm/nonmatchings/text", func_00386F38);

INCLUDE_ASM("asm/nonmatchings/text", func_00387118);

INCLUDE_ASM("asm/nonmatchings/text", func_003872F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003875A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00387A00);

INCLUDE_ASM("asm/nonmatchings/text", func_00387B10);

INCLUDE_ASM("asm/nonmatchings/text", func_00387BD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00387C78);

INCLUDE_ASM("asm/nonmatchings/text", func_00387DB8);

INCLUDE_ASM("asm/nonmatchings/text", func_00387DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388018);

INCLUDE_ASM("asm/nonmatchings/text", func_00388258);

INCLUDE_ASM("asm/nonmatchings/text", func_00388278);

/* localdecomp:start func_003882D0 */
register char *_gpreg __asm__("$28");
#define D_001D5308 (*(f32 *)(_gpreg + -30120))
f32 func_003882D0(f32 x) {
    f32 val = D_001D5308;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_003882D0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003882E0);

/* localdecomp:start func_00388308 */
register char *_gpreg __asm__("$28");
#define D_001D530C (*(f32 *)(_gpreg + -30116))

f32 func_00388308(f32 x) {
    f32 val = D_001D530C;
    
    // Inject a raw nop right after the load.
    __asm__ volatile("nop"); 

    // The compiler's -O2 will naturally schedule this multiplication 
    // into the branch delay slot of the jr $ra instruction.
    return val * x;
}
/* localdecomp:end func_00388308 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388318);

/* localdecomp:start func_00388340 */
register char *_gpreg __asm__("$28");
#define D_001D5310 (*(f32 *)(_gpreg + -30112))
f32 func_00388340(f32 x) {
    f32 val = D_001D5310;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_00388340 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388350);

/* localdecomp:start func_00388378 */
register char *_gpreg __asm__("$28");
#define D_001D5314 (*(f32 *)(_gpreg + -30108))
f32 func_00388378(f32 x) {
    f32 val = D_001D5314;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_00388378 */

/* localdecomp:start func_00388388 */
register char *_gpreg __asm__("$28");
#define D_001D5318 (*(f32 *)(_gpreg + -30104))
f32 func_00388388(f32 x) {
    f32 val = D_001D5318;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_00388388 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388398);

INCLUDE_ASM("asm/nonmatchings/text", func_003883C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003883F8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388418);

INCLUDE_ASM("asm/nonmatchings/text", func_00388440);

INCLUDE_ASM("asm/nonmatchings/text", func_00388468);

INCLUDE_ASM("asm/nonmatchings/text", func_00388490);

INCLUDE_ASM("asm/nonmatchings/text", func_00388550);

INCLUDE_ASM("asm/nonmatchings/text", func_003885F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388618);

INCLUDE_ASM("asm/nonmatchings/text", func_00388648);

INCLUDE_ASM("asm/nonmatchings/text", func_00388680);

INCLUDE_ASM("asm/nonmatchings/text", func_00388698);

INCLUDE_ASM("asm/nonmatchings/text", func_003886B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003886C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003886E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388700);

INCLUDE_ASM("asm/nonmatchings/text", func_00388718);

INCLUDE_ASM("asm/nonmatchings/text", func_00388730);

INCLUDE_ASM("asm/nonmatchings/text", func_00388758);

INCLUDE_ASM("asm/nonmatchings/text", func_00388770);

INCLUDE_ASM("asm/nonmatchings/text", func_003887A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003887C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388800);

INCLUDE_ASM("asm/nonmatchings/text", func_00388830);

INCLUDE_ASM("asm/nonmatchings/text", func_00388880);

INCLUDE_ASM("asm/nonmatchings/text", func_003888C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003888F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388920);

INCLUDE_ASM("asm/nonmatchings/text", func_00388948);

INCLUDE_ASM("asm/nonmatchings/text", func_00388960);

INCLUDE_ASM("asm/nonmatchings/text", func_00388978);

INCLUDE_ASM("asm/nonmatchings/text", func_00388990);

INCLUDE_ASM("asm/nonmatchings/text", func_00388A28);

INCLUDE_ASM("asm/nonmatchings/text", func_00388B40);

INCLUDE_ASM("asm/nonmatchings/text", func_00388B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00388B98);

INCLUDE_ASM("asm/nonmatchings/text", func_00388BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388BF0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388C10);

INCLUDE_ASM("asm/nonmatchings/text", func_00388E38);

INCLUDE_ASM("asm/nonmatchings/text", func_00388E58);

INCLUDE_ASM("asm/nonmatchings/text", func_00388E78);

INCLUDE_ASM("asm/nonmatchings/text", func_00388EB8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388F08);

INCLUDE_ASM("asm/nonmatchings/text", func_00388F50);

INCLUDE_ASM("asm/nonmatchings/text", func_00388F90);

INCLUDE_ASM("asm/nonmatchings/text", func_00389018);

INCLUDE_ASM("asm/nonmatchings/text", func_003890D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003890F8);

INCLUDE_ASM("asm/nonmatchings/text", func_00389118);

INCLUDE_ASM("asm/nonmatchings/text", func_00389150);

INCLUDE_ASM("asm/nonmatchings/text", func_00389158);

INCLUDE_ASM("asm/nonmatchings/text", func_00389240);

INCLUDE_ASM("asm/nonmatchings/text", func_003892D8);

INCLUDE_ASM("asm/nonmatchings/text", func_00389330);

INCLUDE_ASM("asm/nonmatchings/text", func_00389380);

INCLUDE_ASM("asm/nonmatchings/text", func_003893C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00389410);

INCLUDE_ASM("asm/nonmatchings/text", func_00389468);

INCLUDE_ASM("asm/nonmatchings/text", func_003894A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003894E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003895E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003895E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003896E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003898C0);

INCLUDE_ASM("asm/nonmatchings/text", func_00389900);

extern s32 D_001D9C48;
register char *_gpreg __asm__("$28");
#define D_001D5B34 (*(s32 *)(_gpreg + -0x6d7c))
INCLUDE_ASM("asm/nonmatchings/text", func_00389908);

INCLUDE_ASM("asm/nonmatchings/text", func_00389920);

INCLUDE_ASM("asm/nonmatchings/text", func_00389998);

INCLUDE_ASM("asm/nonmatchings/text", func_003899B8);

INCLUDE_ASM("asm/nonmatchings/text", func_00389B90);

INCLUDE_ASM("asm/nonmatchings/text", func_00389B98);

INCLUDE_ASM("asm/nonmatchings/text", func_00389D18);

INCLUDE_ASM("asm/nonmatchings/text", func_00389FB8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038A848);

INCLUDE_ASM("asm/nonmatchings/text", func_0038B1B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038B1E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038BB50);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C3C0);

/* localdecomp:start func_0038C450 */
extern void func_003899B8(void);

void func_0038C450(void) {
    func_003899B8();
}
/* localdecomp:end func_0038C450 */

/* localdecomp:start func_0038C470 */
extern void func_00389B90(s32 a0);

void func_0038C470(void) {
    func_00389B90(1);
}
/* localdecomp:end func_0038C470 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C490);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C4B0);

/* localdecomp:start func_0038C4E8 */
extern void func_00389D18(void);

void func_0038C4E8(void) {
    func_00389D18();
}
/* localdecomp:end func_0038C4E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C508);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C510);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C530);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C538);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C558);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C580);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C628);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C708);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C718);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C778);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C830);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C840);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C878);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C888);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C8A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C8D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C8F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C980);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C9B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C9B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C9D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CA08);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CAB0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CAD0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CAF0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CB60);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CBC8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CBD0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CC58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CC68);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CE40);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA28);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA50);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA80);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DB18);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DB98);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DC08);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DEB0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DF10);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E030);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E1E0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E200);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E248);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E2E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E360);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E380);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E410);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E440);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E508);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E5B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E688);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E6B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E6C0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E6D0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E728);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E730);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E788);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E798);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E8F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E900);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E930);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EA58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EA88);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EB10);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EC18);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EC80);

INCLUDE_ASM("asm/nonmatchings/text", func_0038ED00);

INCLUDE_ASM("asm/nonmatchings/text", func_0038ED78);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EDE8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EE58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EFD0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F0C0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F0F0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F2A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F310);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F3A0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F3F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038FDC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003906E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00390730);

INCLUDE_ASM("asm/nonmatchings/text", func_00390C18);

INCLUDE_ASM("asm/nonmatchings/text", func_003919E0);

INCLUDE_ASM("asm/nonmatchings/text", func_00391B30);

INCLUDE_ASM("asm/nonmatchings/text", func_00391B60);

INCLUDE_ASM("asm/nonmatchings/text", func_00391B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00391B70);

INCLUDE_ASM("asm/nonmatchings/text", func_00391D08);

INCLUDE_ASM("asm/nonmatchings/text", func_00391E30);

INCLUDE_ASM("asm/nonmatchings/text", func_00391E78);

INCLUDE_ASM("asm/nonmatchings/text", func_00391FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00392108);

INCLUDE_ASM("asm/nonmatchings/text", func_003921D8);

INCLUDE_ASM("asm/nonmatchings/text", func_00392400);

INCLUDE_ASM("asm/nonmatchings/text", func_003925F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00392878);

INCLUDE_ASM("asm/nonmatchings/text", func_00392A20);

INCLUDE_ASM("asm/nonmatchings/text", func_00392A40);

INCLUDE_ASM("asm/nonmatchings/text", func_00392DD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393120);

INCLUDE_ASM("asm/nonmatchings/text", func_00393290);

INCLUDE_ASM("asm/nonmatchings/text", func_00393360);

INCLUDE_ASM("asm/nonmatchings/text", func_00393370);

INCLUDE_ASM("asm/nonmatchings/text", func_00393380);

INCLUDE_ASM("asm/nonmatchings/text", func_00393418);

INCLUDE_ASM("asm/nonmatchings/text", func_00393420);

INCLUDE_ASM("asm/nonmatchings/text", func_00393428);

INCLUDE_ASM("asm/nonmatchings/text", func_00393430);

/* localdecomp:start func_00393448 */
register char *_gpreg __asm__("$28");
#define D_001D5EE0 (*(s32 *)(_gpreg + -0x69d0))
s32 func_00393448(void) {
    return D_001D5EE0 == 3;
}
/* localdecomp:end func_00393448 */

INCLUDE_ASM("asm/nonmatchings/text", func_00393458);

INCLUDE_ASM("asm/nonmatchings/text", func_00393460);

INCLUDE_ASM("asm/nonmatchings/text", func_003934E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393550);

INCLUDE_ASM("asm/nonmatchings/text", func_00393580);

INCLUDE_ASM("asm/nonmatchings/text", func_003936A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003936A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003937C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393878);

INCLUDE_ASM("asm/nonmatchings/text", func_00393A18);

INCLUDE_ASM("asm/nonmatchings/text", func_00393C98);

INCLUDE_ASM("asm/nonmatchings/text", func_00393DB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00393DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393E90);

INCLUDE_ASM("asm/nonmatchings/text", func_00394060);

INCLUDE_ASM("asm/nonmatchings/text", func_00394300);

INCLUDE_ASM("asm/nonmatchings/text", func_00394368);

INCLUDE_ASM("asm/nonmatchings/text", func_00394660);

INCLUDE_ASM("asm/nonmatchings/text", func_003947B0);

INCLUDE_ASM("asm/nonmatchings/text", func_00394A20);

INCLUDE_ASM("asm/nonmatchings/text", func_00394B38);

INCLUDE_ASM("asm/nonmatchings/text", func_00394C18);

INCLUDE_ASM("asm/nonmatchings/text", func_00394C58);

INCLUDE_ASM("asm/nonmatchings/text", func_00394F78);

INCLUDE_ASM("asm/nonmatchings/text", func_00395088);

INCLUDE_ASM("asm/nonmatchings/text", func_00395090);

INCLUDE_ASM("asm/nonmatchings/text", func_00395358);

INCLUDE_ASM("asm/nonmatchings/text", func_00395360);

INCLUDE_ASM("asm/nonmatchings/text", func_003953E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003953F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395628);

INCLUDE_ASM("asm/nonmatchings/text", func_00395648);

INCLUDE_ASM("asm/nonmatchings/text", func_003958A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003958F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395958);

INCLUDE_ASM("asm/nonmatchings/text", func_003959A8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395AC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395C48);

INCLUDE_ASM("asm/nonmatchings/text", func_00395E10);

INCLUDE_ASM("asm/nonmatchings/text", func_00395E18);

INCLUDE_ASM("asm/nonmatchings/text", func_00395EA8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395EB8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395FE0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395FF0);

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad1[0x150];
    s32 f164;
    s32 f168;
    u8 pad2[0x10];
    s32 f17c;
} S_142430;
extern S_142430 D_00142430;

extern s32 D_001D4CE8;
INCLUDE_ASM("asm/nonmatchings/text", func_00396100);

INCLUDE_ASM("asm/nonmatchings/text", func_00396120);

INCLUDE_ASM("asm/nonmatchings/text", func_00396248);

INCLUDE_ASM("asm/nonmatchings/text", func_00396298);

extern s32 D_001D4CE8;
INCLUDE_ASM("asm/nonmatchings/text", func_003962C0);

extern s32 D_001D4CE8;
INCLUDE_ASM("asm/nonmatchings/text", func_003962E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396310);

INCLUDE_ASM("asm/nonmatchings/text", func_00396378);

INCLUDE_ASM("asm/nonmatchings/text", func_003963C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396458);

INCLUDE_ASM("asm/nonmatchings/text", func_00396488);

INCLUDE_ASM("asm/nonmatchings/text", func_003964E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396538);

INCLUDE_ASM("asm/nonmatchings/text", func_00396590);

INCLUDE_ASM("asm/nonmatchings/text", func_00396628);

INCLUDE_ASM("asm/nonmatchings/text", func_00396680);

INCLUDE_ASM("asm/nonmatchings/text", func_00396780);

INCLUDE_ASM("asm/nonmatchings/text", func_003967C0);

INCLUDE_ASM("asm/nonmatchings/text", func_00396830);

INCLUDE_ASM("asm/nonmatchings/text", func_00396890);

INCLUDE_ASM("asm/nonmatchings/text", func_003968F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003969B8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396A28);

extern s32 D_001D4CEC;
extern s32 D_001D4CE8;
INCLUDE_ASM("asm/nonmatchings/text", func_00396AE0);

INCLUDE_ASM("asm/nonmatchings/text", func_00396B08);

extern s32 D_00142438;
extern s32 D_001D4CE8;
INCLUDE_ASM("asm/nonmatchings/text", func_00396B50);

INCLUDE_ASM("asm/nonmatchings/text", func_00396B78);

INCLUDE_ASM("asm/nonmatchings/text", func_00396BC0);

extern s32 D_001D4CEC;
extern s32 D_001D4CE8;
INCLUDE_ASM("asm/nonmatchings/text", func_00396C20);

INCLUDE_ASM("asm/nonmatchings/text", func_00396C48);

INCLUDE_ASM("asm/nonmatchings/text", func_00396CE8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396D70);

INCLUDE_ASM("asm/nonmatchings/text", func_00396DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396E20);

INCLUDE_ASM("asm/nonmatchings/text", func_00396E80);

INCLUDE_ASM("asm/nonmatchings/text", func_00396F18);

INCLUDE_ASM("asm/nonmatchings/text", func_00396FA0);

INCLUDE_ASM("asm/nonmatchings/text", func_00396FD0);

INCLUDE_ASM("asm/nonmatchings/text", func_00397058);

extern s32 D_001D4CEC;
extern s32 D_00142578;
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
INCLUDE_ASM("asm/nonmatchings/text", func_00397080);

extern s32 D_001D4CEC;
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
INCLUDE_ASM("asm/nonmatchings/text", func_003970A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003970B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003970C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003970D0);

INCLUDE_ASM("asm/nonmatchings/text", func_00397100);

extern s32 D_001D4CEC;
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
INCLUDE_ASM("asm/nonmatchings/text", func_003971E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00397200);

extern s32 D_001D4CEC;
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
INCLUDE_ASM("asm/nonmatchings/text", func_00397238);

extern s32 D_001D4CEC;
INCLUDE_ASM("asm/nonmatchings/text", func_00397258);

extern s32 D_001D4CEC;
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
INCLUDE_ASM("asm/nonmatchings/text", func_00397270);

INCLUDE_ASM("asm/nonmatchings/text", func_00397288);

INCLUDE_ASM("asm/nonmatchings/text", func_003972A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00397380);

INCLUDE_ASM("asm/nonmatchings/text", func_00397490);

INCLUDE_ASM("asm/nonmatchings/text", func_00399660);

INCLUDE_ASM("asm/nonmatchings/text", func_00399708);

INCLUDE_ASM("asm/nonmatchings/text", func_00399710);

INCLUDE_ASM("asm/nonmatchings/text", func_00399748);

INCLUDE_ASM("asm/nonmatchings/text", func_003997F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00399830);

INCLUDE_ASM("asm/nonmatchings/text", func_00399948);

INCLUDE_ASM("asm/nonmatchings/text", func_00399A00);

INCLUDE_ASM("asm/nonmatchings/text", func_00399C90);

INCLUDE_ASM("asm/nonmatchings/text", func_00399F40);

INCLUDE_ASM("asm/nonmatchings/text", func_00399F70);

INCLUDE_ASM("asm/nonmatchings/text", func_00399F78);

INCLUDE_ASM("asm/nonmatchings/text", func_00399F80);

INCLUDE_ASM("asm/nonmatchings/text", func_00399F90);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A040);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A130);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A170);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A3B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A518);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A528);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A550);

/* localdecomp:start func_0039A590 */
extern u8 D_00142734;
s32 func_0039A590(void) {
    s32 v = D_00142734 & 0x1e;
    return v == 0x1e;
}
/* localdecomp:end func_0039A590 */

/* localdecomp:start func_0039A5A8 */
extern void func_0039A550(s32);
void func_0039A5A8(void) {
    func_0039A550(0x21);
}
/* localdecomp:end func_0039A5A8 */

/* localdecomp:start func_0039A5C8 */
extern void func_0039A550(s32);
void func_0039A5C8(void) {
    func_0039A550(0x22);
}
/* localdecomp:end func_0039A5C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039A5E8);

/* localdecomp:start func_0039A620 */
extern void func_0039A550(s32);
void func_0039A620(void) {
    func_0039A550(0x20);
}
/* localdecomp:end func_0039A620 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039A640);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A6E0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A720);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A730);

/* localdecomp:start func_0039A740 */
typedef struct { u8 pad[0x25]; u8 f25; u8 pad2[0x0d]; u8 f33; } S_1426E0;
extern S_1426E0 D_001426E0;
s32 func_0039A740(void) {
    return D_001426E0.f25 != 0 && D_001426E0.f33 != 0;
}
/* localdecomp:end func_0039A740 */

/* localdecomp:start func_0039A768 */
extern s32 D_00142C4C;
s32 func_0039A768(void) {
    s32 v = D_00142C4C & 0x4000;
    return v != 0;
}
/* localdecomp:end func_0039A768 */

/* localdecomp:start func_0039A780 */
extern u16 D_001A8E74;
extern u8 D_00142CBF;
s32 func_0039A780(void) {
    if (D_001A8E74 != 0) {
        return D_00142CBF == 0;
    }
    return 0;
}
/* localdecomp:end func_0039A780 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039A7A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A7B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A7F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A980);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A9E0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039AA80);

INCLUDE_ASM("asm/nonmatchings/text", func_0039AAF0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039ABA0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039ABB0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039AE08);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B0E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B0F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B198);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B200);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B240);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B2DC);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B2E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B4E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B628);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B760);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BA30);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BA50);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BBC8);

/* localdecomp:start func_0039BC00 */
void func_0039BC00(void) {
    __asm__ volatile (
        "lui $3, 0x8\n"
        "addi $3, $3, 0x200\n"
        "mtc0 $3, $25\n"
    );
}
/* localdecomp:end func_0039BC00 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC18);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC40);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC70);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC80);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC90);

/* localdecomp:start func_0039BCA0 */
void func_0039BCA0(void) {
    __asm__ volatile (
        "sync.p\n"
        "mfc0 $8, $24\n"
        "lui $9, 0x7fff\n"
        "ori $9, $9, 0xffff\n"
        "and $8, $8, $9\n"
        "mtc0 $8, $24\n"
        "sync.p\n"
    );
}
/* localdecomp:end func_0039BCA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039BCC8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BD08);

/* localdecomp:start func_0039BD40 */
s32 func_0039BD40(void) {
}
/* localdecomp:end func_0039BD40 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039BD48);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BE90);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BEA0);

extern s32 D_001D5B90;
INCLUDE_ASM("asm/nonmatchings/text", func_0039BEA8);

extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D4CEC;
extern u8  D_001D5B78[];
extern s32 D_001DA050[];
extern s32 D_001A7430;
extern s32 D_001D6DA4;
extern s32 D_001D6D9C;
extern s32 D_001D6DA0;
extern s32 D_001D6DA8;

extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D4CEC;
extern u8  D_001D5B78[];
extern s32 D_001DA050[];
extern s32 D_001A7430;
extern s32 D_001D6DA4;
extern s32 D_001D6D9C;
extern s32 D_001D6DA0;
extern s32 D_001D6DA8;
INCLUDE_ASM("asm/nonmatchings/text", func_0039BEC0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BF98);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C020);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C028);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C158);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C170);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C1C8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C210);

extern void func_0013CF40(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0039C2A8);

/* localdecomp:start func_0039C2C8 */
void func_0039C2C8(s32 a0, s32 *a1) {
    if (a0 >= 0x1770) {
        *a1 = 6;
    } else {
        *a1 = 2;
    }
}
/* localdecomp:end func_0039C2C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039C2E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C548);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C710);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C7B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C8A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CAB8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CBA0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CC70);

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
    u8 pad1[0x24];
    u16 f50;
    u8 pad2[0x78 - 0x52];
    u16 f78;
    u8 pad3[0xc8 - 0x7a];
    u16 fc8;
} S_1CCFD0;
extern S_1CCFD0 D_001CCFD0;

/* localdecomp:start func_0039CC78 */
void func_0039CC78(void) {
    D_001CCFD0.f50 = 4;
    D_001CCFD0.fc8 = 4;
    D_001CCFD0.f78 = 4;
}
/* localdecomp:end func_0039CC78 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039CC98);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CEA8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D4D0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D510);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D5A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D5F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D668);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D6C8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D770);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D800);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D830);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D8B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D920);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D970);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D9C8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DA08);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DA48);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DA60);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DAD0);

extern s32 D_001D6DE8;
INCLUDE_ASM("asm/nonmatchings/text", func_0039DAE0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DB00);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DB38);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E4A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E4B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E8E0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E928);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EA58);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EA60);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EB38);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EB98);

INCLUDE_ASM("asm/nonmatchings/text", func_0039ED50);

/* localdecomp:start func_0039EE40 */
extern s32 D_001685EC;
extern void func_0013CFC0(s32, s32);
void func_0039EE40(void) {
    func_0013CFC0(2, D_001685EC);
}
/* localdecomp:end func_0039EE40 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039EE68);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FAF8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FB08);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FB60);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FBD8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FE80);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FF28);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FFB8);

/* localdecomp:start func_0039FFC8 */
extern u8 D_001A30B0;
s32 func_0039FFC8(u32 a0, s32 a1) {
    if (a0 < 0x34) {
        u8 *p = (u8 *)&D_001A30B0 + a0 * 0x80;
        *(u16 *)(p + 0xcc) = a1;
    }
    return 1;
}
/* localdecomp:end func_0039FFC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039FFF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0010);

INCLUDE_ASM("asm/nonmatchings/text", func_003A00D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A00E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0130);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0170);

INCLUDE_ASM("asm/nonmatchings/text", func_003A01F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0200);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0268);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0280);

INCLUDE_ASM("asm/nonmatchings/text", func_003A02D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A04A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0D20);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0D58);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1340);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1380);

INCLUDE_ASM("asm/nonmatchings/text", func_003A13B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1438);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1870);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1AA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1AD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1E48);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2028);

INCLUDE_ASM("asm/nonmatchings/text", func_003A21C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2460);

INCLUDE_ASM("asm/nonmatchings/text", func_003A26D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2C18);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2DF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2E40);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2EE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3028);

INCLUDE_ASM("asm/nonmatchings/text", func_003A30D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A30E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3128);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3220);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3288);

INCLUDE_ASM("asm/nonmatchings/text", func_003A32E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3368);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3430);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3508);

INCLUDE_ASM("asm/nonmatchings/text", func_003A35C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3A00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3A40);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3B00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3B50);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3BB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3C00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3DE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3E38);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3E40);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3EE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3EF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3FA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3FB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A40C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4128);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4188);

INCLUDE_ASM("asm/nonmatchings/text", func_003A41E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A41F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A42D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A42E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A44F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4580);

INCLUDE_ASM("asm/nonmatchings/text", func_003A45F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A46F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4720);

/* localdecomp:start func_003A4758 */
register char *_gpreg __asm__("$28");
void func_003A4758(char a0) {
    *(_gpreg + -18512) = a0; 
}
/* localdecomp:end func_003A4758 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A4760);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4768);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4860);

extern int D_001DA0D0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003A4A20);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4A78);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4E70);

INCLUDE_ASM("asm/nonmatchings/text", func_003A53B0);

extern void func_00116F98(s32 *a0, s32 a1, s32 *a2);
INCLUDE_ASM("asm/nonmatchings/text", func_003A53E0);

extern char D_001D8160[];
extern void func_003A53B0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A5458);

INCLUDE_ASM("asm/nonmatchings/text", func_003A54A0);

/* localdecomp:start func_003A5608 */
extern s32 D_001D8178;

void func_003A5608(void *a0) {
    register void *dest __asm__("$2");    // $v0 ($2)
    register s32 val __asm__("$3");       // $v1 ($3)

    // Force the exact 64-bit move instruction (daddu) at offset 0.
    // This generates the exact machine code bytes for 0x0080102d.
    __asm__ volatile("daddu %0, %1, $0" : "=r"(dest) : "r"(a0));

    val = (s32)&D_001D8178;

    __asm__ volatile("" : : "r"(dest), "r"(val));

    *(s32 *)dest = val;
}
/* localdecomp:end func_003A5608 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5620);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5650);

INCLUDE_ASM("asm/nonmatchings/text", func_003A56C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5750);

INCLUDE_ASM("asm/nonmatchings/text", func_003A57A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5800);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5870);

/* localdecomp:start func_003A58A0 */
extern void func_003A53B0(void);
void func_003A58A0(void) {
    func_003A53B0();
}
/* localdecomp:end func_003A58A0 */

extern s32 D_001D8118;
extern void func_003A5620(void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003A58C0);

extern s32 D_001D8100;
extern void func_003A5620(void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003A58E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5900);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5908);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5910);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5918);

/* localdecomp:start func_003A5928 */
void func_003A5928(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)a0) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)a0) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)a0) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)a0) + 0xc) = a4;
}
/* localdecomp:end func_003A5928 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5950);

/* localdecomp:start func_003A5958 */
void func_003A5958(void *a0, s32 a1) {
    s32 *v0 = *(s32 **)((u8 *)a0 + 0x10);
    if (a1 != 0) {
        *(f32 *)v0 = 1.0f;
    } else {
        *v0 = 0;
    }
}
/* localdecomp:end func_003A5958 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5978);

INCLUDE_ASM("asm/nonmatchings/text", func_003A59E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A59E8);

/* localdecomp:start func_003A5A50 */
void func_003A5A50(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0xc) = a4;
}
/* localdecomp:end func_003A5A50 */

extern s32 D_001D8218;
INCLUDE_ASM("asm/nonmatchings/text", func_003A5A78);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5BB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5C70);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5CA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5D58);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5DD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5DE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5DF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5E80);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5EC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5EF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5F58);

/* localdecomp:start func_003A5F88 */
void func_003A5F88(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 4) = a2;
}
/* localdecomp:end func_003A5F88 */

/* localdecomp:start func_003A5FA0 */
void func_003A5FA0(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 8) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0xc) = a2;
}
/* localdecomp:end func_003A5FA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5FB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6190);

INCLUDE_ASM("asm/nonmatchings/text", func_003A61C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A61D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6278);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6280);

INCLUDE_ASM("asm/nonmatchings/text", func_003A62E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A63E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6410);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6448);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6450);

extern s32 D_001D81D0;
extern void func_003A5BC0(void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003A64B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A64D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A64E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A64E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6518);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6638);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6640);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6768);

/* localdecomp:start func_003A6770 */
void func_003A6770(void *a0, s32 a1) {
    f32 result;
    void *p;
    __asm__ volatile (
        "mtc1 %2, %0\n"
        "nop\n"
        "cvt.s.w %0, %0\n"
        "lw %1, 4(%3)\n"
        : "=f"(result), "=r"(p)
        : "r"(a1), "r"(a0)
    );
    *(f32 *)((u8 *)p + 4) = result;
}
/* localdecomp:end func_003A6770 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6788);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6790);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6830);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6880);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6888);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6908);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6910);

/* localdecomp:start func_003A69A0 */
void func_003A69A0(void *a0, void *a1) {
    *(s32 *)a1 = *(s32 *)((u8 *)a0 + 0x14);
    *(s32 *)((u8 *)a0 + 0x14) = (s32)a1;
    *(s32 *)((u8 *)a0 + 0x10) = *(s32 *)((u8 *)a0 + 0x10) - 1;
}
/* localdecomp:end func_003A69A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A69C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A69C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6A00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6C08);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6C30);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7090);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7380);

/* localdecomp:start func_003A7398 */
s32 func_003A7398(void) {
}
/* localdecomp:end func_003A7398 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A73A0);

/* localdecomp:start func_003A7610 */
s32 func_003A7610(void) {
}
/* localdecomp:end func_003A7610 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7618);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7690);

/* localdecomp:start func_003A7CC8 */
s32 func_003A7CC8(void) {
}
/* localdecomp:end func_003A7CC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7CD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7D80);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7E48);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7E80);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F38);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F40);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F48);

/* localdecomp:start func_003A7F58 */
typedef struct {
    char pad_0[0x18];   /* Offset 0x00 down to 0x18 */
    f32 float_field;    /* Offset 0x18 - Targeted by lwc1/swc1 */
    char pad_1C[0xC];   /* Padding from 0x1C to 0x28 */
    char byte_flag;     /* Offset 0x28 - Targeted by sb $v0, 0x28($a0) */
} InitContext;

void func_003A7F58(InitContext* ctx) {
    // 0: lui $at, 0x3f80
    // 4: mtc1 $at, $f1
    register f32 constant_one __asm__("$f1") = 1.0f;

    // FENCE 1: Blocks 'li $v0, 1' from climbing to offset 0:
    __asm__ __volatile__ ("");

    // 8: li $v0, 1
    ctx->byte_flag = 1;

    // c: lwc1 $f0, 0x18($a0)
    (void)((volatile InitContext*)ctx)->float_field;

    // MEMORY CLOBBER FENCE:
    // This tells ee-gcc that all previous memory actions (the lwc1 load) must be 
    // completely processed and finalized before any subsequent memory instructions 
    // are evaluated. This forces 'sb' perfectly down to offset 10:!
    __asm__ __volatile__ ("" : : : "memory");

    // 18: swc1 $f1, 0x18($a0)
    ctx->float_field = constant_one;
}
/* localdecomp:end func_003A7F58 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F78);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F80);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F90);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7FC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7FE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7FE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8028);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8030);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8038);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8060);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8228);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8230);

INCLUDE_ASM("asm/nonmatchings/text", func_003A95A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9698);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9758);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9768);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9890);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9AB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9AC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9AE8);

extern void func_003A6880(void *);
extern void func_003A9768(void *);
extern void func_00121760(void *, void *);
extern void func_0039D668(void *, s32, s32);
extern void func_003A6888(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern void func_0039D6C8(s32);
extern void func_003A6790(void *);
extern void func_003A9890(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
INCLUDE_ASM("asm/nonmatchings/text", func_003A9B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9CE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9CF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9DE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9E00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9E60);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9EF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA080);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA0B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA278);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA290);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA2D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA2E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA4B0);

/* localdecomp:start func_003AA7E0 */
// Declare the external game function target matching address 0x0011ECD0
extern void func_0011ECD0(s32 parameter);

// Signature must be void to eliminate the implicit return zero instruction (0x102d)
void func_003AA7E0(void) {
    // Calling this function with 1 triggers the 'li $a0, 1' optimization pass, 
    // which naturally slides directly into the jal branch delay slot at offset c:
    func_0011ECD0(1);
}
/* localdecomp:end func_003AA7E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AA800);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA828);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAA00);

/* localdecomp:start func_003AAA98 */
s32 func_003AAA98(void) {
}
/* localdecomp:end func_003AAA98 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AAAA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAAC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAB60);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAB80);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAB88);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAC28);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAC70);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAD40);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAE00);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAE60);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAEC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAF88);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB100);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB180);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB220);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB3A8);

/* localdecomp:start func_003AB608 */
s32 func_003AB608(void) {
}
/* localdecomp:end func_003AB608 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AB610);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB7B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB9A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB9E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABA38);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABA48);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABB60);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABC30);

/* localdecomp:start func_003ABD60 */
void func_003ABD60(void *a0) {
    u8 *p = (u8 *)a0 + 0x50000;
    *(s32 *)(p + 8) = 0x50000;
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003ABD60 */

/* localdecomp:start func_003ABD78 */
s32 func_003ABD78(void) {
}
/* localdecomp:end func_003ABD78 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ABD80);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABDB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABDF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABE30);

/* localdecomp:start func_003ABE58 */
register char *_gpreg __asm__("$28");
#define D_001D87E0 (*(s32 *)(_gpreg + -0x40d0))
s32 func_003ABE58(void *a0, s32 a1, s32 a2) {
    D_001D87E0 = 0;
    *(s32 *)((u8 *)a0 + 8) = a1;
    *(s32 *)a0 = a2;
    return 1;
}
/* localdecomp:end func_003ABE58 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ABE70);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABE98);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABF88);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABFD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC040);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC0B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC150);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC2B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC3A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC3F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC5E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC6F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACA00);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACA58);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACAA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACB00);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACC30);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACD38);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACED0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACFD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACFD8);

/* localdecomp:start func_003ACFF8 */
s32 func_003ACFF8(s32 arg0) {
    func_003AC2B0(arg0 + 0x48);
}
/* localdecomp:end func_003ACFF8 */

/* localdecomp:start func_003AD018 */
s32 func_003AD018(s32 arg0) {
    func_003AC3A0(arg0 + 0x48);
}
/* localdecomp:end func_003AD018 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD038);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD040);

/* localdecomp:start func_003AD078 */
void func_003AD078(void *a0) {
    *(s32 *)((u8 *)a0 + 168) = 1;
}
/* localdecomp:end func_003AD078 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD088);

/* localdecomp:start func_003AD090 */
s32 func_003AD090(void *a0, s32 a1) {
    s32 old = *(s32 *)((u8 *)a0 + 168);
    *(s32 *)((u8 *)a0 + 168) = a1;
    return old;
}
/* localdecomp:end func_003AD090 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD0A0);

/* localdecomp:start func_003AD0E0 */
s32 func_003AD0E0(s32 arg0) {
    func_003ACA58(arg0 + 0x48);
}
/* localdecomp:end func_003AD0E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD100);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD108);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD1D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD220);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD288);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD430);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD458);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD488);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD4B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD4D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD520);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD650);

/* localdecomp:start func_003AD6A8 */
s32 func_003AD6A8(void) {
}
/* localdecomp:end func_003AD6A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD6B0);

/* localdecomp:start func_003AD6C0 */
s32 func_003AD6C0(void *a0) {
    return *(s32 *)((u8 *)a0 + 0xc) == *(s32 *)((u8 *)a0 + 0x10);
}
/* localdecomp:end func_003AD6C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD6D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD748);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD788);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD798);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD7F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD818);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD820);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD8A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD8A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADAA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADAE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADB40);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADB78);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADBB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADC68);

extern s32 D_001D8888;
extern s32 D_001D888C;
INCLUDE_ASM("asm/nonmatchings/text", func_003ADC70);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADC80);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADC88);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADCB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADD30);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADDD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADE68);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADEF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADF88);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE068);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE098);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE120);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE1A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE240);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE300);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE368);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE430);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE438);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE8A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AECA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AECC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AED00);

INCLUDE_ASM("asm/nonmatchings/text", func_003AED08);

INCLUDE_ASM("asm/nonmatchings/text", func_003AED40);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEDC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEDF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEE80);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEEB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEEC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEF70);

/* localdecomp:start func_003AEFB0 */
s32 func_003AEFB0(s32 *arg0) {
    s32 val = arg0[4]; // offset 0x10 (4 * 4 bytes)
    
    if (val != 0) {
        return val;
    }
    
    return arg0[3]; // offset 0x0C (3 * 4 bytes)
}
/* localdecomp:end func_003AEFB0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AEFD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF0A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF0C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF0D0);

/* localdecomp:start func_003AF120 */
s32 func_003AF120(s32 *arg0) {
    if (arg0[4] != 0) {
        return arg0[4];
    }
    return arg0[3];
}
/* localdecomp:end func_003AF120 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AF140);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF148);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF150);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF158);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF160);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF170);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF178);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF180);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF188);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF190);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF198);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF1B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF208);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF250);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF288);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF2C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF718);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF9E0);

/* localdecomp:start func_003AFA08 */
s32 func_003AFA08(void) {
}
/* localdecomp:end func_003AFA08 */

/* localdecomp:start func_003AFA10 */
s32 func_003AFA10(void) {
}
/* localdecomp:end func_003AFA10 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AFA18);

/* localdecomp:start func_003AFA70 */
void func_003AFA70(s32 arg0) {
    func_003AFA18(arg0);
}
/* localdecomp:end func_003AFA70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AFA90);

INCLUDE_ASM("asm/nonmatchings/text", func_003AFAA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AFC10);

INCLUDE_ASM("asm/nonmatchings/text", func_003AFC68);

INCLUDE_ASM("asm/nonmatchings/text", func_003AFF20);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0210);

/* localdecomp:start func_003B0258 */
void func_003B0258(void) {
    func_0037DCE0();
}
/* localdecomp:end func_003B0258 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B0278);

INCLUDE_ASM("asm/nonmatchings/text", func_003B02A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0580);

INCLUDE_ASM("asm/nonmatchings/text", func_003B05D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0608);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0720);

INCLUDE_ASM("asm/nonmatchings/text", func_003B07B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0A60);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0C40);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0C70);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0D18);

/* localdecomp:start func_003B0D70 */
extern u8 D_00143950;
s32 func_003B0D70(void) {
    u8 *p = &D_00143950;
    s32 v = p[6] == 0;
    p[6] = v;
    return v;
}
/* localdecomp:end func_003B0D70 */

/* localdecomp:start func_003B0D88 */
extern s32 D_00143950_b[];

s32 func_003B0D88(void) {
    s32 inverted_val = !D_00143950_b[2];
    D_00143950_b[2] = inverted_val;
    return inverted_val;
}
/* localdecomp:end func_003B0D88 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B0DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0F58);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0FC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1028);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1030);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1068);

extern s32 D_001D8A70;
INCLUDE_ASM("asm/nonmatchings/text", func_003B1098);

INCLUDE_ASM("asm/nonmatchings/text", func_003B10A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1158);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1190);

INCLUDE_ASM("asm/nonmatchings/text", func_003B11C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1210);

INCLUDE_ASM("asm/nonmatchings/text", func_003B12C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1368);

INCLUDE_ASM("asm/nonmatchings/text", func_003B13A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B13D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1400);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1430);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1490);

INCLUDE_ASM("asm/nonmatchings/text", func_003B14D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1518);

INCLUDE_ASM("asm/nonmatchings/text", func_003B15B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B15E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B16B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1DA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B22C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B23F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2640);

INCLUDE_ASM("asm/nonmatchings/text", func_003B26E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2720);

INCLUDE_ASM("asm/nonmatchings/text", func_003B27A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2958);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2A28);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2A50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2AA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2AF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2F50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B3558);

INCLUDE_ASM("asm/nonmatchings/text", func_003B3DB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B41E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B41F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B41F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4220);

extern s32 D_001D8C0C;
extern s32 D_001D8C10;
INCLUDE_ASM("asm/nonmatchings/text", func_003B42C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B42D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B43B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B43C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B45B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B46F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4778);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4788);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4950);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4970);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4990);

INCLUDE_ASM("asm/nonmatchings/text", func_003B49A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B49B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B49E8);

/* localdecomp:start func_003B4E60 */
void func_003B4E60(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x8c) = a1;
    *(s32 *)((u8 *)a0 + 0x90) = a2;
    *(s32 *)((u8 *)a0 + 0x94) = a3;
    *(s32 *)((u8 *)a0 + 0x98) = a4;
}
/* localdecomp:end func_003B4E60 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B4E78);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4F08);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4F10);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4F50);

/* localdecomp:start func_003B5000 */
void func_003B5000(void *a0, s32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "sb $5, 0x74($4)\n"
        "swc1 $12, 0x70($4)\n"
        "swc1 $13, 0xa4($4)\n"
        :: "r"(a0), "r"(a1)
    );
    *(f32 *)((u8 *)a0 + 0xa0) = a4;
}
/* localdecomp:end func_003B5000 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5018);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5128);

INCLUDE_ASM("asm/nonmatchings/text", func_003B51F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5290);

INCLUDE_ASM("asm/nonmatchings/text", func_003B52B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5440);

INCLUDE_ASM("asm/nonmatchings/text", func_003B56C8);

/* localdecomp:start func_003B56D0 */
void func_003B56D0(s32 *arg0, float float1, float float2, float float3, float float4, float float5) {
    float *floatPtr = (float *)arg0;
    
    floatPtr[24] = float2; // $f13 -> 0x60
    floatPtr[25] = float3; // $f14 -> 0x64
    floatPtr[26] = float4; // $f15 -> 0x68
    floatPtr[27] = float5; // $f16 -> 0x6c
    floatPtr[23] = float1; // $f12 -> 0x5c
    
    arg0[30] = 0;          // $zero -> 0x78
}
/* localdecomp:end func_003B56D0 */

/* localdecomp:start func_003B56F0 */
void func_003B56F0(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "swc1 $15, 0x88($4)\n"
        "swc1 $12, 0x7c($4)\n"
        "swc1 $13, 0x80($4)\n"
        :: "r"(a0)
    );
    *(f32 *)((u8 *)a0 + 0x84) = a3;
}
/* localdecomp:end func_003B56F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5708);

INCLUDE_ASM("asm/nonmatchings/text", func_003B57F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5A70);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5AB0);

extern s32 D_001D8C18;
INCLUDE_ASM("asm/nonmatchings/text", func_003B5BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5BE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5BE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5BF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5BF8);

/* localdecomp:start func_003B5C08 */
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_0037BA20;

void func_003B5C08(s32 arg_a0) {
    D_0037BA20.field_74 = 1;
    D_0037BA20.field_78 = arg_a0;
}
/* localdecomp:end func_003B5C08 */

/* localdecomp:start func_003B5C20 */
extern s32 D_0037BA94;
s32 func_003B5C20(s32 a0) {
    return D_0037BA94 == a0;
}
/* localdecomp:end func_003B5C20 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5C38);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5C60);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5C68);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5C90);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5CA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5D10);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5EC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5F88);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6050);

INCLUDE_ASM("asm/nonmatchings/text", func_003B60B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B60F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6190);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6198);

INCLUDE_ASM("asm/nonmatchings/text", func_003B61A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B62D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B62D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B62E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B62E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6358);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6368);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6410);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6488);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6528);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6F28);

INCLUDE_ASM("asm/nonmatchings/text", func_003B70A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7190);

INCLUDE_ASM("asm/nonmatchings/text", func_003B71B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7288);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7320);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7378);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7568);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7618);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7870);

INCLUDE_ASM("asm/nonmatchings/text", func_003B78C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7AA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7B50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8168);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8280);

INCLUDE_ASM("asm/nonmatchings/text", func_003B82C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8440);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8560);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8700);

INCLUDE_ASM("asm/nonmatchings/text", func_003B87B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8810);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8840);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8928);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8968);

INCLUDE_ASM("asm/nonmatchings/text", func_003B89F8);

/* localdecomp:start func_003B8A08 */
extern s32 D_002257B4;
s32 func_003B8A08(void) {
    return D_002257B4;
}
/* localdecomp:end func_003B8A08 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8A18);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8A20);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8A48);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8A68);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8B18);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8BC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8C70);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8D00);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8D08);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8E08);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8E10);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8EC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8EF8);

/* localdecomp:start func_003B8F48 */
s32 func_003B8F48(void) {
}
/* localdecomp:end func_003B8F48 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8F50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9030);

/* localdecomp:start func_003B9090 */
s32 func_003B9090(void) {
}
/* localdecomp:end func_003B9090 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9098);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9160);

INCLUDE_ASM("asm/nonmatchings/text", func_003B92B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9730);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9880);

INCLUDE_ASM("asm/nonmatchings/text", func_003B98B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B99A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9A08);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9B38);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9B60);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9BE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9C50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9DA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9E98);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA0B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA108);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA280);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA2A8);

/* localdecomp:start func_003BA350 */
extern s32 D_0016C5E4;
s32 func_003BA350(void) {
    return D_0016C5E4 == 1;
}
/* localdecomp:end func_003BA350 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA368);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA3C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA3E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA490);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA5B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA748);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA850);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA948);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BAE98);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB210);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB398);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB4D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB520);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB558);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB5C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB730);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB790);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB7B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB7B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB7E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB9F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBA50);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBC48);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBD70);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBD98);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBF80);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBFC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BC0B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BC0F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BC218);

INCLUDE_ASM("asm/nonmatchings/text", func_003BC568);

INCLUDE_ASM("asm/nonmatchings/text", func_003BCFB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD360);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD428);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD490);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD550);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD630);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD668);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD768);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD778);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD810);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD868);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD8A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDA38);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDAC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDAC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDBA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDC90);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDD68);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDEA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE0D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE118);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE140);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE170);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE1A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE260);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE2E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE340);

/* localdecomp:start func_003BE3A0 */
// Bypass the C compiler entirely so it stops adding jr $ra
__asm__(    
    ".section .text\n"
    ".global func_003BE3A0\n"
    "func_003BE3A0:\n"
    "addiu $29, $29, 0x30\n"
    "nop\n"
    "addiu $2, $0, 0xff\n"
    "nop\n"
    "sw    $0, 0($3)\n"
    "nop\n"
    "addiu $2, $0, 0x1\n"
    "nop\n"
);
/* localdecomp:end func_003BE3A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BE3C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE400);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE418);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE4F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE688);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE6A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE740);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE7F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE860);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE948);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE988);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEA80);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEB18);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEB48);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEB58);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEBF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEBF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEC48);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEC60);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEE08);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEE20);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEFF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF058);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF2A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF2F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF2F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF360);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF4F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF5C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF5D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF5E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF630);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF640);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF690);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF6A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF728);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF778);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF7C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF7E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF820);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF838);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF8F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF910);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFA18);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFAF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFB60);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFB80);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFBA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFC18);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFCE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFD08);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFD10);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFD90);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFDB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFDB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFE08);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFEE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFEF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C00B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0D70);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0E08);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0E10);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1070);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1130);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1440);

INCLUDE_ASM("asm/nonmatchings/text", func_003C18F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1950);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A28);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A40);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A60);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1F10);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1FE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C21A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C2310);

INCLUDE_ASM("asm/nonmatchings/text", func_003C2370);

INCLUDE_ASM("asm/nonmatchings/text", func_003C23E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C26C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C2868);

INCLUDE_ASM("asm/nonmatchings/text", func_003C28B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C35A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4280);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4F30);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5098);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5AE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5D90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5E70);

INCLUDE_ASM("asm/nonmatchings/text", func_003C78B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C79F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7AD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7AE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7B90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7B98);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7BA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7DE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7E68);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8B28);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8C40);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8CD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8D50);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8E68);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8E70);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8ED0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9078);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9208);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9210);

INCLUDE_ASM("asm/nonmatchings/text", func_003C92B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C93B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C94B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9798);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9888);

INCLUDE_ASM("asm/nonmatchings/text", func_003C99D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9AE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9B80);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9C58);

INCLUDE_ASM("asm/nonmatchings/text", func_003CA860);

INCLUDE_ASM("asm/nonmatchings/text", func_003CA9C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CAC10);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB310);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB498);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB5A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB5B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB748);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB860);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB890);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB958);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBA68);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBAC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBC70);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBE40);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC198);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC4B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC5F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC838);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC880);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC884);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC8B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC950);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCB40);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCCF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCD08);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCDC4);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCE10);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCF38);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCFB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD194);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD250);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD470);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD4A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD510);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD548);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD598);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD710);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD7D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD830);

INCLUDE_ASM("asm/nonmatchings/text", func_003CDDF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CDE70);

INCLUDE_ASM("asm/nonmatchings/text", func_003CDEB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CE4B4);

INCLUDE_ASM("asm/nonmatchings/text", func_003CE6A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CE740);

INCLUDE_ASM("asm/nonmatchings/text", func_003CF790);

INCLUDE_ASM("asm/nonmatchings/text", func_003D00C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D00F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D00F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D14B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D14D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1570);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1650);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1978);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1B08);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1D40);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1E68);

INCLUDE_ASM("asm/nonmatchings/text", func_003D22D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D22E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2308);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2330);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2358);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2370);

INCLUDE_ASM("asm/nonmatchings/text", func_003D27C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2878);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2F90);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3050);

INCLUDE_ASM("asm/nonmatchings/text", func_003D30D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3148);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3428);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3780);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3A50);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3B90);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3CF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3E08);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3E40);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3EE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3F78);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3FA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4198);

INCLUDE_ASM("asm/nonmatchings/text", func_003D41E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4680);

INCLUDE_ASM("asm/nonmatchings/text", func_003D46B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D46E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D47A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4850);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4858);

INCLUDE_ASM("asm/nonmatchings/text", func_003D48D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D5814);

INCLUDE_ASM("asm/nonmatchings/text", func_003D5840);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6130);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6BE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6C10);

INCLUDE_ASM("asm/nonmatchings/text", func_003D764C);

INCLUDE_ASM("asm/nonmatchings/text", func_003D7674);

INCLUDE_ASM("asm/nonmatchings/text", func_003D76A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D7950);

INCLUDE_ASM("asm/nonmatchings/text", func_003D8098);

INCLUDE_ASM("asm/nonmatchings/text", func_003D80C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D81E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D8218);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9308);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9330);

INCLUDE_ASM("asm/nonmatchings/text", func_003D94A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D95B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D96C4);

INCLUDE_ASM("asm/nonmatchings/text", func_003D97C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D98D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D99D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9A40);

INCLUDE_ASM("asm/nonmatchings/text", func_003DB318);

INCLUDE_ASM("asm/nonmatchings/text", func_003DB5C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBB70);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBCE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBDF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBE20);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBE98);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBEA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBEB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DCD08);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE260);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE3A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE430);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE4A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE558);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE560);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE870);

/* localdecomp:start func_003DE8A0 */
extern s32 D_00302DC0;
s32 func_003DE8A0(void) {
    return D_00302DC0 == 7;
}
/* localdecomp:end func_003DE8A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DE8B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE8C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE8D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE8E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE8F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DEEF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DEFB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF038);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF7C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF810);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF820);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF958);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF9C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF9E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFB20);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFB40);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFCA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFE10);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFF78);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFF90);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFFC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFFD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0068);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0178);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0190);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0358);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0370);

INCLUDE_ASM("asm/nonmatchings/text", func_003E03A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E03C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E03D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0478);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0550);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0680);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0690);

INCLUDE_ASM("asm/nonmatchings/text", func_003E06A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E06D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0770);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0780);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0798);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0870);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0900);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0930);

INCLUDE_ASM("asm/nonmatchings/text", func_003E09D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0B78);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0CC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0D78);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0DF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0DF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0E28);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0E48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0E90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0FC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E10E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1120);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1150);

INCLUDE_ASM("asm/nonmatchings/text", func_003E11D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E12A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1338);

INCLUDE_ASM("asm/nonmatchings/text", func_003E13D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1460);

INCLUDE_ASM("asm/nonmatchings/text", func_003E14A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1510);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1548);

INCLUDE_ASM("asm/nonmatchings/text", func_003E15D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1668);

INCLUDE_ASM("asm/nonmatchings/text", func_003E16B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1760);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1770);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1788);

INCLUDE_ASM("asm/nonmatchings/text", func_003E17C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1890);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1898);

INCLUDE_ASM("asm/nonmatchings/text", func_003E18C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1928);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1930);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1950);

INCLUDE_ASM("asm/nonmatchings/text", func_003E19C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1A50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1A98);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1AA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1AA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1AC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1AF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1B18);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1B40);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1B68);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1B90);

typedef struct {
    s32 field_0;        /* Offset 0x00 - Targeted by sw $zero, 0($a0) */
    s32 field_4;        /* Offset 0x04 - Padding */
    void* field_8;      /* Offset 0x08 - Targeted by sw $v0, 8($a0) */
} TargetStruct;

extern char D_001D96B0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003E1B98);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1BB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1BB8);

/* localdecomp:start func_003E1BC8 */
// Define the context structure passing through $a0
typedef struct {
    s32 counter; /* Offset 0x00 - Targeted by lw/sw operations */
} CounterContext;

// Signature must take the context pointer ($a0) and return an s32 ($v0)
s32 func_003E1BC8(CounterContext* ctx) {
    // 0: lw $v0, 0($a0)
    s32 current_val = ctx->counter;

    // 4: beqz $v0
    if (current_val != 0) {
        // 8: addiu $v0, $v0, -1
        // c: sw $v0, 0($a0)
        ctx->counter = current_val - 1;
    }

    // 14: lw $v0, 0($a0) (Scheduled cleanly into the jr $ra delay slot)
    return ctx->counter;
}
/* localdecomp:end func_003E1BC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1BE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1C10);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1C38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1C90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1CC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1CE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1D08);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1D18);

/* localdecomp:start func_003E1D50 */
register char *_gpreg __asm__("$28");
#define D_001D96E8 (*(f32 *)(_gpreg + -0x31c8))
#define D_001D96EC (*(f32 *)(_gpreg + -0x31c4))
void func_003E1D50(f32 *a0, f32 *a1) {
    *a0 = D_001D96E8;
    *a1 = D_001D96EC;
}
/* localdecomp:end func_003E1D50 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1D68);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1E38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1E40);

/* localdecomp:start func_003E1E48 */
s32 func_003E1E48(void) {
}
/* localdecomp:end func_003E1E48 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1E50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1F38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1F40);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2028);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2110);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2118);

INCLUDE_ASM("asm/nonmatchings/text", func_003E21F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E21F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E22D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E23B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E23C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E24A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E24B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2560);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2610);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2618);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2720);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2728);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2800);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2808);

INCLUDE_ASM("asm/nonmatchings/text", func_003E28E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E29B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2B98);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2C88);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2D70);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2D90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2DD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2DE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2E60);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2ED0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2ED8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2F48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2FB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2FC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3040);

INCLUDE_ASM("asm/nonmatchings/text", func_003E30B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E30C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E31A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3250);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3320);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3330);

INCLUDE_ASM("asm/nonmatchings/text", func_003E33E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E33F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E34A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E34F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3580);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3630);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3700);

INCLUDE_ASM("asm/nonmatchings/text", func_003E37F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E38A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E38B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E38D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3988);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3A80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3B50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3D08);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3DF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3EE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3F08);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4788);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4790);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4810);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4890);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4918);

INCLUDE_ASM("asm/nonmatchings/text", func_003E49A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4A20);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4AA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4B20);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4BA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4C20);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4CA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4D20);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4E28);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4EA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4F28);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4FA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5028);

INCLUDE_ASM("asm/nonmatchings/text", func_003E50A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5210);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5378);

INCLUDE_ASM("asm/nonmatchings/text", func_003E53E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E54B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5518);

INCLUDE_ASM("asm/nonmatchings/text", func_003E55E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5638);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5708);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5770);

INCLUDE_ASM("asm/nonmatchings/text", func_003E57C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5890);

INCLUDE_ASM("asm/nonmatchings/text", func_003E58F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E59C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5A30);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5B00);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5B68);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5CA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5D08);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5DE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5F00);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6048);

INCLUDE_ASM("asm/nonmatchings/text", func_003E60B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6108);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6198);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6268);

INCLUDE_ASM("asm/nonmatchings/text", func_003E62D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6330);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6398);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6400);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6468);

INCLUDE_ASM("asm/nonmatchings/text", func_003E64D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6538);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6610);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6680);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6758);

INCLUDE_ASM("asm/nonmatchings/text", func_003E67B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6890);

INCLUDE_ASM("asm/nonmatchings/text", func_003E68F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6960);

INCLUDE_ASM("asm/nonmatchings/text", func_003E69B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6A88);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6AF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6B48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6BB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6C18);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6CE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6D48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6DB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6E18);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6E80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6EE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6F50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7028);

INCLUDE_ASM("asm/nonmatchings/text", func_003E70B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7180);

INCLUDE_ASM("asm/nonmatchings/text", func_003E71D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E72A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7310);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7378);

INCLUDE_ASM("asm/nonmatchings/text", func_003E73E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7430);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7498);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7500);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7568);

INCLUDE_ASM("asm/nonmatchings/text", func_003E75D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7638);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7710);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7778);

INCLUDE_ASM("asm/nonmatchings/text", func_003E77E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7848);

INCLUDE_ASM("asm/nonmatchings/text", func_003E78B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7900);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7960);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7A30);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7A98);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7B00);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7B68);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7C38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7C90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7D68);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7DF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7EC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7F20);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7F70);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8040);

INCLUDE_ASM("asm/nonmatchings/text", func_003E80A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8110);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8178);

INCLUDE_ASM("asm/nonmatchings/text", func_003E81E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8248);

INCLUDE_ASM("asm/nonmatchings/text", func_003E82B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8320);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8390);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8420);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8560);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8568);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8590);

INCLUDE_ASM("asm/nonmatchings/text", func_003E85A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E85D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8600);

/* localdecomp:start func_003E8610 */
void func_003E8610(void *a0, f32 *a1, f32 *a2) {
    *a1 = *(f32 *)((u8 *)a0 + 0x10);
    *a2 = *(f32 *)((u8 *)a0 + 0x14);
}
/* localdecomp:end func_003E8610 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E8628);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8638);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8640);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8670);

INCLUDE_ASM("asm/nonmatchings/text", func_003E86C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8718);

/* localdecomp:start func_003E8788 */
s32 func_003E8788(void) {
}
/* localdecomp:end func_003E8788 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E8790);

INCLUDE_ASM("asm/nonmatchings/text", func_003E87C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E87D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8838);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8970);

INCLUDE_ASM("asm/nonmatchings/text", func_003E89F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8AD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8BF8);

/* localdecomp:start func_003E8C28 */
s32 func_003E8C28(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_003E8C28 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E8C40);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8EA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8EC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8FB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E90C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E91B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E91C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E91F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E91F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9260);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9290);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9298);

INCLUDE_ASM("asm/nonmatchings/text", func_003E92D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E98B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9B18);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9B48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9B80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9BA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9C50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9CE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9D18);

/* localdecomp:start func_003E9D20 */
void func_003E9D20(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003E9D20 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E9D38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9D78);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA078);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA290);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA648);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA8A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA930);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA950);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA980);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA9B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EAA38);

/* localdecomp:start func_003EAA68 */
s32 func_003EAA68(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003EAA68 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EAA80);

INCLUDE_ASM("asm/nonmatchings/text", func_003EAA90);

INCLUDE_ASM("asm/nonmatchings/text", func_003EAAD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EAC88);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB0D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB100);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB130);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB160);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB180);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB358);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB3F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB408);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB440);

/* localdecomp:start func_003EB4A8 */
void func_003EB4A8(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x28) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003EB4A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EB4C0);

/* localdecomp:start func_003EB4E8 */
void func_003EB4E8(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x44) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003EB4E8 */

/* localdecomp:start func_003EB500 */
s32 func_003EB500(void *a0, f32 *a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *a1 = *(f32 *)((u8 *)p + 0x44);
    return 1;
}
/* localdecomp:end func_003EB500 */

/* localdecomp:start func_003EB518 */
s32 func_003EB518(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
/* localdecomp:end func_003EB518 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EB538);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB578);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB588);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB598);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB5A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB5E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB5F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB620);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB6B0);

/* localdecomp:start func_003EB710 */
void func_003EB710(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(u8 *)((u8 *)p + 0x58) = (u8)a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003EB710 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EB728);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC3D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC630);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC660);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC690);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC6E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC760);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC790);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC798);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC7D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC960);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECB80);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECBB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECBE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECC20);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECC40);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECC70);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECCA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECD08);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECD40);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECD60);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECD90);

/* localdecomp:start func_003ECDB8 */
s32 func_003ECDB8(void) {
}
/* localdecomp:end func_003ECDB8 */

/* localdecomp:start func_003ECDC0 */
s32 func_003ECDC0(s32 a0, s32 a1) {
    return a1;
}
/* localdecomp:end func_003ECDC0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ECDC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECDD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECDE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECDF0);
