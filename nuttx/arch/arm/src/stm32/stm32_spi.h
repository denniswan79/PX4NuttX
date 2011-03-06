/************************************************************************************
 * arch/arm/src/stm32/stm32_spi.h
 *
 *   Copyright (C) 2009 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <spudmonkey@racsa.co.cr>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_STC_STM32_STM32_SPI_H
#define __ARCH_ARM_STC_STM32_STM32_SPI_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include "chip.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

#define STM32_SPI_CLK_MAX     18000000UL  /* Maximum allowed speed as per specifications for all SPIs */

/* Register Offsets *****************************************************************/

#define STM32_SPI_CR1_OFFSET      0x0000  /* SPI Control Register 1 (16-bit) */
#define STM32_SPI_CR2_OFFSET      0x0004  /* SPI control register 2 (16-bit) */
#define STM32_SPI_SR_OFFSET       0x0008  /* SPI status register (16-bit) */
#define STM32_SPI_DR_OFFSET       0x000c  /* SPI data register (16-bit) */
#define STM32_SPI_CRCPR_OFFSET    0x0010  /* SPI CRC polynomial register (16-bit) */
#define STM32_SPI_RXCRCR_OFFSET   0x0014  /* SPI Rx CRC register (16-bit) */
#define STM32_SPI_TXCRCR_OFFSET   0x0018  /* SPI Tx CRC register (16-bit) */

/* Register Addresses ***************************************************************/

#if STM32_NSPI > 0
#  define STM32_SPI1_CR1          (STM32_SPI1_BASE+STM32_SPI_CR1_OFFSET)
#  define STM32_SPI1_CR2          (STM32_SPI1_BASE+STM32_SPI_CR2_OFFSET)
#  define STM32_SPI1_SR           (STM32_SPI1_BASE+STM32_SPI_SR_OFFSET)
#  define STM32_SPI1_DR           (STM32_SPI1_BASE+STM32_SPI_DR_OFFSET)
#  define STM32_SPI1_CRCPR        (STM32_SPI1_BASE+STM32_SPI_CRCPR_OFFSET)
#  define STM32_SPI1_RXCRCR       (STM32_SPI1_BASE+STM32_SPI_RXCRCR_OFFSET)
#  define STM32_SPI1_TXCRCR       (STM32_SPI1_BASE+STM32_SPI_TXCRCR_OFFSET)
#endif

#if STM32_NSPI > 1
#  define STM32_SPI2_CR1          (STM32_SPI2_BASE+STM32_SPI_CR1_OFFSET)
#  define STM32_SPI2_CR2          (STM32_SPI2_BASE+STM32_SPI_CR2_OFFSET)
#  define STM32_SPI2_SR           (STM32_SPI2_BASE+STM32_SPI_SR_OFFSET)
#  define STM32_SPI2_DR           (STM32_SPI2_BASE+STM32_SPI_DR_OFFSET)
#  define STM32_SPI2_CRCPR        (STM32_SPI2_BASE+STM32_SPI_CRCPR_OFFSET)
#  define STM32_SPI2_RXCRCR       (STM32_SPI2_BASE+STM32_SPI_RXCRCR_OFFSET)
#  define STM32_SPI2_TXCRCR       (STM32_SPI2_BASE+STM32_SPI_TXCRCR_OFFSET)
#endif

#if STM32_NSPI > 2
#  define STM32_SPI3_CR1          (STM32_SPI3_BASE+STM32_SPI_CR1_OFFSET)
#  define STM32_SPI3_CR2          (STM32_SPI3_BASE+STM32_SPI_CR2_OFFSET)
#  define STM32_SPI3_SR           (STM32_SPI3_BASE+STM32_SPI_SR_OFFSET)
#  define STM32_SPI3_DR           (STM32_SPI3_BASE+STM32_SPI_DR_OFFSET)
#  define STM32_SPI3_CRCPR        (STM32_SPI3_BASE+STM32_SPI_CRCPR_OFFSET)
#  define STM32_SPI3_RXCRCR       (STM32_SPI3_BASE+STM32_SPI_RXCRCR_OFFSET)
#  define STM32_SPI3_TXCRCR       (STM32_SPI3_BASE+STM32_SPI_TXCRCR_OFFSET)
#endif

/* Register Bitfield Definitions ****************************************************/

/* SPI Control Register 1 */

#define SPI_CR1_CPHA              (1 << 0)  /* Bit 0: Clock Phase */
#define SPI_CR1_CPOL              (1 << 1)  /* Bit 1: Clock Polarity */
#define SPI_CR1_MSTR              (1 << 2)  /* Bit 2: Master Selection */
#define SPI_CR1_BR_SHIFT          (3)       /* Bits 5:3 Baud Rate Control */
#define SPI_CR1_BR_MASK           (7 << SPI_CR1_BR_SHIFT)
#  define SPI_CR1_FPCLCKd2        (0 << SPI_CR1_BR_SHIFT) /* 000: fPCLK/2 */
#  define SPI_CR1_FPCLCKd4        (1 << SPI_CR1_BR_SHIFT) /* 001: fPCLK/4 */
#  define SPI_CR1_FPCLCKd8        (2 << SPI_CR1_BR_SHIFT) /* 010: fPCLK/8 */
#  define SPI_CR1_FPCLCKd16       (3 << SPI_CR1_BR_SHIFT) /* 011: fPCLK/16 */
#  define SPI_CR1_FPCLCKd32       (4 << SPI_CR1_BR_SHIFT) /* 100: fPCLK/32 */
#  define SPI_CR1_FPCLCKd64       (5 << SPI_CR1_BR_SHIFT) /* 101: fPCLK/64 */
#  define SPI_CR1_FPCLCKd128      (6 << SPI_CR1_BR_SHIFT) /* 110: fPCLK/128 */
#  define SPI_CR1_FPCLCKd256      (7 << SPI_CR1_BR_SHIFT) /* 111: fPCLK/256 */
#define SPI_CR1_SPE               (1 << 6)  /* Bit 6: SPI Enable */
#define SPI_CR1_LSBFIRST          (1 << 7)  /* Bit 7: Frame Format */
#define SPI_CR1_SSI               (1 << 8)  /* Bit 8: Internal slave select */
#define SPI_CR1_SSM               (1 << 9)  /* Bit 9: Software slave management */
#define SPI_CR1_RXONLY            (1 << 10) /* Bit 10: Receive only */
#define SPI_CR1_DFF               (1 << 11) /* Bit 11: Data Frame Format */
#define SPI_CR1_CRCNEXT           (1 << 12) /* Bit 12: Transmit CRC next */
#define SPI_CR1_CRCEN             (1 << 13) /* Bit 13: Hardware CRC calculation enable */
#define SPI_CR1_BIDIOE            (1 << 14) /* Bit 14: Output enable in bidirectional mode */
#define SPI_CR1_BIDIMODE          (1 << 15) /* Bit 15: Bidirectional data mode enable */

/* SPI Control Register 2 */

#define SPI_CR2_RXDMAEN           (1 << 0)  /* Bit 0: Rx Buffer DMA Enable */
#define SPI_CR2_TXDMAEN           (1 << 1)  /* Bit 1: Tx Buffer DMA Enable */
#define SPI_CR2_SSOE              (1 << 2)  /* Bit 2: SS Output Enable */
#define SPI_CR2_ERRIE             (1 << 5)  /* Bit 5: Error interrupt enable */
#define SPI_CR2_RXNEIE            (1 << 6)  /* Bit 6: RX buffer not empty interrupt enable */
#define SPI_CR2_TXEIE             (1 << 7)  /* Bit 7: Tx buffer empty interrupt enable */

/* SPI status register */

#define SPI_SR_RXNE               (1 << 0)  /* Bit 0: Receive buffer not empty */
#define SPI_SR_TXE                (1 << 1)  /* Bit 1: Transmit buffer empty */
#define SPI_SR_CRCERR             (1 << 4)  /* Bit 4: CRC error flag */
#define SPI_SR_MODF               (1 << 5)  /* Bit 5: Mode fault */
#define SPI_SR_OVR                (1 << 6)  /* Bit 6: Overrun flag */
#define SPI_SR_BSY                (1 << 7)  /* Bit 7: Busy flag */

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C" {
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Public Functions
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */

#endif /* __ARCH_ARM_STC_STM32_STM32_SPI_H */
