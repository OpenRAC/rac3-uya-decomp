/* newlib isnan() (fdlibm s_isnan.c), boot_elf 0x0011B060, 0x3C bytes.
   Byte-identical with Sony's ee-gcc 2.96-ee-001003-1 at -O2 -G0 (the Linux
   build, run under WSL; checked 2026-10-20). Neither SN 2.95.3 nor 2.9-ee
   gives it (14 instructions differ in scheduling and registers), and 2.96
   has no Windows build, so it can't be built by `make` yet. The rest of
   newlib (0x116F80-0x11EA10) is the same compiler (docs/boot_elf.md).

   From fdlibm via newlib's s_isnan.c:
   Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
   Developed at SunPro, a Sun Microsystems, Inc. business.
   Permission to use, copy, modify, and distribute this
   software is freely granted, provided that this notice
   is preserved. */
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

s32 func_0011B060(double x)
{
    s32 hx, lx;
    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (s32)((u32)hx >> 31);
}
