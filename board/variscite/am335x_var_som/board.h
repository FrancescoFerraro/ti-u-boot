/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * board.h
 *
 * Variscite AM335x VAR-SOM information header
 *
 * Copyright (C) 2023, Variscite Ltd - http://www.variscite.com/
 */

#ifndef _BOARD_H_
#define _BOARD_H_

/**
 * AM335X (EMIF_4D) EMIF REG_COS_COUNT_1, REG_COS_COUNT_2, and
 * REG_PR_OLD_COUNT values to avoid LCDC DMA FIFO underflows and Frame
 * Synchronization Lost errors. The values are the biggest that work
 * reliably with offered video modes and the memory subsystem on the
 * boards. These register have are briefly documented in "7.3.3.5.2
 * Command Starvation" section of AM335x TRM. The REG_COS_COUNT_1 and
 * REG_COS_COUNT_2 do not have any effect on current versions of
 * AM335x.
 */
#define EMIF_OCP_CONFIG_AM335X_VAR_SOM       0x00141414

/*
 * We have three pin mux functions that must exist.  We must be able to enable
 * uart0, for initial output and i2c0 to read the main EEPROM.  We then have a
 * main pinmux function that can be overridden to enable all other pinmux that
 * is required on the board.
 */
void enable_uart0_pin_mux(void);
void enable_i2c1_pin_mux(void);
void enable_rmii1_pin_mux(void);
void enable_rgmii2_pin_mux(void);
void enable_board_pin_mux(void);
#endif
