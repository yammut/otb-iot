/*
 *
 * OTB-IOT - Out of The Box Internet Of Things
 *
 * Copyright (C) 2017 Piers Finlayson
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version. 
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */
 
#ifndef OTB_MAIN_BOARD_OTBIOT_V0_5_H_INCLUDED
#define OTB_MAIN_BOARD_OTBIOT_V0_5_H_INCLUDED

// Only used by hwinfo - not used directly by otb-iot (otb-iot uses via eeprom)
#ifdef OTB_HWINFO_C

#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_GPIO_PIN_NUM       17
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM         3
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_HDRS_NUM_1  2
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_HDRS_NUM_2  2
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_HDRS_NUM_3  2
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_1  (16+8)
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_2  (10+10)
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_3  (10+10)
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_ADDR_1      0x50  // XXX Double check
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_ADDR_2      0x51  // XXX Double check
#define OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_ADDR_3      0x52  // XXX Double check

const otb_eeprom_pin_info otb_hwinfo_main_board_otbiot_v0_5_main_board_pin_info[OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_GPIO_PIN_NUM] =
{
  // GPIO 0
  {0,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_INT_SDA,
   OTB_EEPROM_PIN_MODULE_1,
   OTB_EEPROM_PIN_FINFO_I2C_V33,
   OTB_EEPROM_PIN_PULLED_V33},

  // GPIO 1
  {1,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_TX,
   OTB_EEPROM_PIN_MODULE_1,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_FLOAT},

  // GPIO 2
  {2,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_INT_SCL,
   OTB_EEPROM_PIN_MODULE_1,
   OTB_EEPROM_PIN_FINFO_I2C_V33,
   OTB_EEPROM_PIN_PULLED_V33},

  // GPIO 3
  {3,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RX,
   OTB_EEPROM_PIN_MODULE_1,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_FLOAT},

  // GPIO 4
  {4,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_GPIO,
   OTB_EEPROM_PIN_MODULE_3,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_V33},

  // GPIO 5
  {5,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_GPIO,
   OTB_EEPROM_PIN_MODULE_3,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_V33},

  // GPIO 6
  {6,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESERVED,
   OTB_EEPROM_PIN_MODULE_NONE,
   OTB_EEPROM_PIN_FINFO_RSVD_FLASH,
   OTB_EEPROM_PIN_PULLED_NA},

  // GPIO 7
  {7,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESERVED,
   OTB_EEPROM_PIN_MODULE_NONE,
   OTB_EEPROM_PIN_FINFO_RSVD_FLASH,
   OTB_EEPROM_PIN_PULLED_NA},

  // GPIO 8
  {8,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESERVED,
   OTB_EEPROM_PIN_MODULE_NONE,
   OTB_EEPROM_PIN_FINFO_RSVD_FLASH,
   OTB_EEPROM_PIN_PULLED_NA},

  // GPIO 9
  {9,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESERVED,
   OTB_EEPROM_PIN_MODULE_NONE,
   OTB_EEPROM_PIN_FINFO_RSVD_FLASH,
   OTB_EEPROM_PIN_PULLED_NA},

  // GPIO 10
  {10,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESERVED,
   OTB_EEPROM_PIN_MODULE_NONE,
   OTB_EEPROM_PIN_FINFO_RSVD_FLASH,
   OTB_EEPROM_PIN_PULLED_NA},

  // GPIO 11
  {11,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESERVED,
   OTB_EEPROM_PIN_MODULE_NONE,
   OTB_EEPROM_PIN_FINFO_RSVD_FLASH,
   OTB_EEPROM_PIN_PULLED_NA},

  // GPIO 12
  {12,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_GPIO,
   OTB_EEPROM_PIN_MODULE_2,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_V33},

  // GPIO 13
  {13,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_GPIO,
   OTB_EEPROM_PIN_MODULE_2,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_V33},

  // GPIO 14
  {14,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESET_SOFT,
   OTB_EEPROM_PIN_MODULE_1,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_V33},

  // GPIO 15
  {15,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_STATUS_LED,
   OTB_EEPROM_PIN_MODULE_1,
   OTB_EEPROM_PIN_FINFO_LED_TYPE_WS2812B,
   OTB_EEPROM_PIN_PULLED_V0},

  // GPIO 16
  {16,
   OTB_EEPROM_PIN_HEADER_NONE,
   OTB_EEPROM_PIN_USE_RESET_HARD,
   OTB_EEPROM_PIN_MODULE_1,
   OTB_EEPROM_PIN_FINFO_NONE,
   OTB_EEPROM_PIN_PULLED_V33},
};

const otb_eeprom_pin_info otb_hwinfo_main_board_otbiot_v0_5_module_pin_info_1[OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_1] =
{
  // Module 1, Header 1, Pin 1
  {
    1,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 2
  {
    2,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_1,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_3_5MM,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 1, Header 1, Pin 3
  {
    3,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_V33,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_FUSE_100MA,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 4
  {
    4,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_2,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_3_5MM,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 1, Header 1, Pin 5
  {
    5,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GPIO,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_GPIO_14,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 1, Header 1, Pin 6
  {
    6,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_3,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_3_5MM,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 1, Header 1, Pin 7
  {
    7,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 8
  {
    8,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GPIO,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_GPIO_15,
    OTB_EEPROM_PIN_PULLED_V0
  },

  // Module 1, Header 1, Pin 9
  {
    9,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_INT_SDA,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 1, Header 1, Pin 10
  {
    10,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_INT_SCL,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 1, Header 1, Pin 11
  {
    11,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 12
  {
    12,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_V5,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_FUSE_100MA,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 13
  {
    13,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_ADDR_2,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 14
  {
    14,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_ADDR_1,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 15
  {
    15,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_ADDR_0,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 1, Pin 16
  {
    16,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_WP,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_WP_MODULE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 1, Header 2, Pin 1
  {
    1,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_WP,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_WP_MAIN_BOARD,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 1, Header 2, Pin 2
  {
    1,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 2, Pin 3
  {
    3,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_TOUT,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 1, Header 2, Pin 4
  {
    4,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_RESET_HARD,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 1, Header 2, Pin 5
  {
    5,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_TX,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 2, Pin 6
  {
    6,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_RX,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 2, Pin 7
  {
    7,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_D_PLUS,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 1, Header 2, Pin 8
  {
    8,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_D_MINUS,
    OTB_EEPROM_PIN_MODULE_1,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },
};

const otb_eeprom_pin_info otb_hwinfo_main_board_otbiot_v0_5_module_pin_info_2[OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_2] =
{
  // Module 2, Header 1, Pin 1
  {
    1,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 1, Pin 2
  {
    2,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_1,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_PINS,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 2, Header 1, Pin 3
  {
    3,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_V33,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_FUSE_100MA,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 1, Pin 4
  {
    4,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_2,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_PINS,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 2, Header 1, Pin 5
  {
    5,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GPIO,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_GPIO_12,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 2, Header 1, Pin 6
  {
    6,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_3,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_PINS,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 2, Header 1, Pin 7
  {
    7,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_4,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_PINS,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 2, Header 1, Pin 8
  {
    8,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 1, Pin 9
  {
    9,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 1, Pin 10
  {
    10,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GPIO,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_GPIO_13,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 2, Header 2, Pin 1
  {
    1,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_INT_SDA,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 2, Header 2, Pin 2
  {
    1,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_INT_SCL,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 2, Header 2, Pin 3
  {
    3,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_NC,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 2, Pin 4
  {
    4,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_V5,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_FUSE_100MA,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 2, Pin 5
  {
    5,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_ADDR_2,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 2, Pin 6
  {
    6,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 2, Pin 7
  {
    7,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_ADDR_1,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 2, Pin 8
  {
    8,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 2, Pin 9
  {
    9,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_ADDR_0,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 2, Header 2, Pin 10
  {
    10,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_WP,
    OTB_EEPROM_PIN_MODULE_2,
    OTB_EEPROM_PIN_FINFO_WP_MODULE,
    OTB_EEPROM_PIN_PULLED_V33
  },
};

const otb_eeprom_pin_info otb_hwinfo_main_board_otbiot_v0_5_module_pin_info_3[OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_3] =
{
  // Module 3, Header 1, Pin 1
  {
    1,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 1, Pin 2
  {
    2,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_1,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_PINS,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 3, Header 1, Pin 3
  {
    3,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_V33,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_FUSE_100MA,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 1, Pin 4
  {
    4,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_2,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_PINS,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 3, Header 1, Pin 5
  {
    5,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GPIO,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_GPIO_4,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 3, Header 1, Pin 6
  {
    6,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_3,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_3_5MM,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 3, Header 1, Pin 7
  {
    7,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_JACK_4,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_JACK_TYPE_PINS,
    OTB_EEPROM_PIN_PULLED_FLOAT
  },

  // Module 3, Header 1, Pin 8
  {
    8,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 1, Pin 9
  {
    9,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 1, Pin 10
  {
    10,
    OTB_EEPROM_PIN_HEADER_1,
    OTB_EEPROM_PIN_USE_GPIO,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_GPIO_5,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 3, Header 2, Pin 1
  {
    1,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_INT_SDA,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 3, Header 2, Pin 2
  {
    1,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_INT_SCL,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_V33
  },

  // Module 3, Header 2, Pin 3
  {
    3,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_NC,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 2, Pin 4
  {
    4,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_V5,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_FUSE_100MA,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 2, Pin 5
  {
    5,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_ADDR_2,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 2, Pin 6
  {
    6,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 2, Pin 7
  {
    7,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_ADDR_1,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 2, Pin 8
  {
    8,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_GND,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 2, Pin 9
  {
    9,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_ADDR_0,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_NONE,
    OTB_EEPROM_PIN_PULLED_NA
  },

  // Module 3, Header 2, Pin 10
  {
    10,
    OTB_EEPROM_PIN_HEADER_2,
    OTB_EEPROM_PIN_USE_WP,
    OTB_EEPROM_PIN_MODULE_3,
    OTB_EEPROM_PIN_FINFO_WP_MODULE,
    OTB_EEPROM_PIN_PULLED_V33
  },
};

const otb_hwinfo_main_board_module_info otb_hwinfo_main_board_otbiot_v0_5_module_info[OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM] =
{
  // Module 1
  {
    1,
    OTB_EEPROM_MODULE_TYPE_DOUBLE_MEZZ_PROG,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_HDRS_NUM_1,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_1,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_ADDR_1,
    &otb_hwinfo_main_board_otbiot_v0_5_module_pin_info_1
  },

  // Module 2
  {
    2,
    OTB_EEPROM_MODULE_TYPE_DOUBLE_MEZZ,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_HDRS_NUM_2,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_2,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_ADDR_2,
    &otb_hwinfo_main_board_otbiot_v0_5_module_pin_info_2
  },

  // Module 3
  {
    3,
    OTB_EEPROM_MODULE_TYPE_DOUBLE_MEZZ,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_HDRS_NUM_3,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM_PINS_3,
    OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_ADDR_3,
    &otb_hwinfo_main_board_otbiot_v0_5_module_pin_info_3
  },
};

const otb_hwinfo_board_info otb_hwinfo_main_board_otbiot_v0_5_board_info =
{
  "otbiot_v0_5",
  OTB_EEPROM_HW_CODE_MAIN_BOARD,
  OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_GPIO_PIN_NUM,
  OTB_HWINFO_MAIN_BOARD_OTBIOT_V0_5_MODULE_NUM,
  &otb_hwinfo_main_board_otbiot_v0_5_main_board_pin_info,
  &otb_hwinfo_main_board_otbiot_v0_5_module_info,
  NULL
};
#endif // OTB_HWINFO_C

#endif // OTB_MAIN_BOARD_OTBIOT_V0_5_H_INCLUDED