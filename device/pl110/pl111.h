// MIT License

// Copyright (c) 2018 Alexander Perechnev <alexander@perechnev.com>

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DRIVER_PL111_h__
#define __DRIVER_PL111_h__

#include <stdint.h>
#include <kernel/ddm.h>

/*
 * LCD DMA FIFO watermark level:
 * 	0 = asserts HBUSREQM when either of the DMA FIFOs have four or more empty locations
 * 	1 = asserts HBUSREQM when either of the DMA FIFOs have eight or more empty locations
 */
#define PL111_CONTROL_WATERMARK	(1 << 16)
/*
 * Generate interrupt at:
 * 	VS = start of vertical synchronization
 * 	BP = start of back porch
 * 	AV = start of active video
 * 	FP = start of front porch
 */
#define PL111_CONTROL_VCOMP_VS	(0b00 << 12)
#define PL111_CONTROL_VCOMP_BP	(0b01 << 12)
#define PL111_CONTROL_VCOMP_AV	(0b10 << 12)
#define PL111_CONTROL_VCOMP_FP	(0b11 << 12)
/*
 * LCD power enable:
 * 0 = power not gated through to LCD panel and CLD[23:0] signals disabled, (held LOW)
 * 1 = power gated through to LCD panel and CLD[23:0] signals enabled, (active).
 */
#define PL111_CONTROL_PWR	(1 << 11)
/*
 * Big-endian pixel ordering within a byte:
 * 	0 = little-endian ordering within a byte
 * 	1 = big-endian pixel ordering within a byte
 * The BEPO bit selects between little and big-endian pixel packing for 1, 2, and 4bpp display modes and it has no
 * effect on 8 or 16bpp pixel formats. See Pixel serializer on page 2-8 for more information about the data format.
 */
#define PL111_CONTROL_BEPO	(1 << 10)
/*
 * Big-endian byte order:
 * 	0 = little-endian byte order
 * 	1 = big-endian byte order.
 */
#define PL111_CONTROL_BEBO	(1 << 9)
/*
 * RGB or BGR format selection:
 * 	0 = RGB normal output
 * 	1 = BGR red and blue swapped
 */
#define PL111_CONTROL_BGR	(1 << 8)
/*
 * LCD interface is dual-panel STN:
 * 	0 = single-panel LCD is in use
 * 	1 = dual-panel LCD is in use.
 */
#define PL111_CONTROL_DUAL	(1 << 7)
/*
 * Monochrome LCD. This has an 8-bit interface. This bit controls whether monochrome STN LCD uses a 4 or 8-bit parallel
 * interface. It has no meaning in other modes, and you must program it to zero.
 * 	0 = mono LCD uses 4-bit interface
 * 	1 = mono LCD uses 8-bit interface
 */
#define PL111_CONTROL_MONO8	(1 << 6)
/*
 * LCD is TFT:
 * 	0 = LCD is an STN display. Use gray scaler
 * 	1 = LCD is a TFT display. Do not use gray scaler
 */
#define PL111_CONTROL_TFT	(1 << 5)
/*
 * STN LCD is monochrome (black and white):
 * 	0 = STN LCD is color
 * 	1 = STN LCD is monochrome
 * 	This bit has no meaning in TFT mode.
 */
#define PL111_CONTROL_BW	(1 << 4)
/*
 * LCD bits per pixel:
 * 	1BPP = 1bpp
 * 	2BPP = 2bpp
 * 	4BPP = 4bpp
 * 	8BPP = 8bpp
 * 	16BPP = 16bpp
 * 	24BPP = 24bpp (TFT panel only)
 * 	16BPP_565 = 16bpp 5:6:5 mode
 * 	12BPP_444 = 12bpp 4:4:4 mode.
 */
#define PL111_CONTROL_BPP_1BPP		(0b000 << 1)
#define PL111_CONTROL_BPP_2BPP		(0b001 << 1)
#define PL111_CONTROL_BPP_4BPP		(0b010 << 1)
#define PL111_CONTROL_BPP_8BPP		(0b011 << 1)
#define PL111_CONTROL_BPP_16BPP		(0b100 << 1)
#define PL111_CONTROL_BPP_24BPP		(0b101 << 1)
#define PL111_CONTROL_BPP_16BPP_565	(0b110 << 1)
#define PL111_CONTROL_BPP_12BPP_444	(0b111 << 1)
/*
 * CLCDC enable:
 * 	0 = LCD signals CLLP, CLCP, CLFP, CLAC, and CLLE disabled (LOW)
 * 	1 = LCD signals CLLP, CLCP, CLFP, CLAC, and CLLE enabled (HIGH).
 */
#define PL111_CONTROL_EN	(1 << 0)

k_ddm_device_t * dev_pl111_init(void * base, const char * device_id, uint32_t control);

uint32_t * dev_pl111_fb_get();

#endif /* __DRIVER_PL111_h__ */
