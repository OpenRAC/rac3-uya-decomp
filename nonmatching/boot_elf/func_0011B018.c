/* newlib isinf() (fdlibm s_isinf.c), boot_elf 0x0011B018, 0x48 bytes.
   Byte-identical with Sony's ee-gcc 2.96-ee-001003-1 at -O2 -G0 (the Linux
   build, run under WSL; checked 2026-10-20). Neither SN 2.95.3 nor 2.9-ee
   gives it (12 instructions differ in scheduling and registers), and 2.96
   has no Windows build, so it can't be built by `make` yet. The rest of
   newlib (0x116F80-0x11EA10) is the same compiler (docs/boot_elf.md).
   newlib's s_isinf.c: written by J.T. Conklin, 1994, public domain. */
typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} ieee_double_shape_type;

#define EXTRACT_WORDS(ix0, ix1, d)      \
    do {                                \
        ieee_double_shape_type ew_u;    \
        ew_u.value = (d);               \
        (ix0) = ew_u.parts.msw;         \
        (ix1) = ew_u.parts.lsw;         \
    } while (0)

s32 func_0011B018(double x)
{
    s32 hx, lx;
    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (s32)((u32)(hx | (-hx)) >> 31);
}
