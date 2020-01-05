/*
 * OTB-IOT - Out of The Box Internet Of Things
 *
 * Copyright (C) 2019 Piers Finlayson
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
 */

#define OTB_BREAK_C
#include "otb.h"

void ICACHE_FLASH_ATTR otb_break_start(void)
{
  DEBUG("BREAK: otb_break_start entry");

  otb_break_rx_buf_len = 0;
  otb_break_state = OTB_BREAK_STATE_MAIN;
  INFO("Entered otb-iot break processing");
  INFO("Enable watchdog");
  otb_util_break_enable_timer(OTB_BREAK_WATCHDOG_TIMER);
  INFO(" Watchdog enabled: %dms", OTB_BREAK_WATCHDOG_TIMER)
  otb_util_uart0_rx_en();
  INFO("Press h or ? for help");

  DEBUG("BREAK: otb_break_start exit");

  return;
}

void ICACHE_FLASH_ATTR otb_break_options_output(void)
{

  DEBUG("BREAK: otb_break_options_output entry");

  INFO("otb-iot break options:")
  INFO("  c - change config (changes do not persist)");
  INFO("  x - resumes booting (with changed config as applicable");
  INFO("  q - reboot");
  INFO("  f - factory reset");
  INFO("  g - run gpio test");
  INFO("  r - waits for soft reset button to be pressed");
  INFO("  i - outputs device info");
  INFO("  w - wipe stored config (auto-reboots)");
  INFO("  d - disable watchdog (device will not reboot automatically after 5 minutes)");
  INFO("  e - enable watchdog (device will rebot after 5 minutes)");
  INFO("  h - output this list of options");

  DEBUG("BREAK: otb_break_options_output exit");

}  

void ICACHE_FLASH_ATTR otb_break_process_char_timerfunc(void *arg)
{
  char rx_char;

  DEBUG("BREAK: otb_break_process_char_timerfunc entry");

  otb_util_timer_cancel((os_timer_t*)&otb_break_process_char_timer);
  OTB_ASSERT(otb_break_rx_buf > 0);
  otb_break_options_fan_out(otb_break_rx_buf[0]);

  DEBUG("BREAK: otb_break_process_char_timerfunc exit");

  return;
}

void ICACHE_FLASH_ATTR otb_break_options_fan_out(char input)
{
  bool rc = TRUE;

  DEBUG("BREAK: otb_break_options_fan_out entry");

  switch (otb_break_state)
  {
    case OTB_BREAK_STATE_MAIN:
      rc = otb_break_options_select(input);
      break;

    case OTB_BREAK_STATE_CONFIG:
      otb_break_config_input(input);
      break;

    case OTB_BREAK_STATE_GPIO:
      otb_break_gpio_input(input);
      break;

    case OTB_BREAK_STATE_SOFT_RESET:
      otb_break_soft_reset_input(input);
      break;

    default:
      OTB_ASSERT(FALSE);
      break;
  }

  if (rc)
  {
    otb_break_rx_buf_len = 0;
  }

  DEBUG("BREAK: otb_break_options_fan_out exit");

  return;
}

char ALIGN4 otb_break_user_reboot_string[] = "BREAK: User triggered reboot";
char ALIGN4 otb_break_config_reboot_string[] = "BREAK: User triggered config wipe";
bool ICACHE_FLASH_ATTR otb_break_options_select(char option)
{
  bool output_options = FALSE;
  bool clear_buf = TRUE;
  unsigned char mac1[3], mac2[3];
  bool rc;
  uint32_t chipid;

  DEBUG("BREAK: otb_break_options_select entry");

  switch (option)
  {
    case 'c':
    case 'C':
      INFO("Change config");
      otb_break_state = OTB_BREAK_STATE_CONFIG;
;
      otb_break_config_state = OTB_BREAK_CONFIG_STATE_MAIN;
      INFO(" Select config to change");
      break;

    case 'x':
    case 'X':
      INFO("Resume booting");
      otb_util_uart0_rx_dis();
      otb_util_break_disable_timer();
      otb_wifi_kick_off();
      break;

    case 'q':
    case 'Q':
      INFO("Reboot");
      otb_reset(otb_break_user_reboot_string);
      break;

    case 'f':
    case 'F':
      INFO("Factory reset");
      INFO(" For factory reset reboot and hold down soft reset (GPIO 14) for > 15 seconds");
      break;

    case 'g':
    case 'G':
      INFO("Run GPIO test");
      otb_break_state = OTB_BREAK_STATE_GPIO;
      INFO(" GPIO test running (test not yet implemented)");
      break;

    case 'r':
    case 'R':
      INFO("Soft reset button test");
      otb_break_state = OTB_BREAK_STATE_SOFT_RESET;
      INFO(" Waiting for soft reset button to be pressed (Not yet implemented)");
      break;

    case 'i':
    case 'I':
      INFO("Output device info");
      INFO(" SDK Version:    %s", otb_sdk_version_id);
      chipid = system_get_chip_id();
      INFO(" Actual Chip ID: %06x", chipid);
      os_memset(mac1, 0, 3);
      os_memset(mac2, 0, 3);
      if (wifi_get_macaddr(STATION_IF, mac1))
      {
        INFO(" Station MAC:    %02x%02x%02x", mac1[0], mac1[1], mac1[2]);
      }
      if (wifi_get_macaddr(SOFTAP_IF, mac2))
      {
        INFO(" AP MAC:         %02x%02x%02x", mac2[0], mac2[1], mac2[2]);
      }
      INFO(" Eeprom args:    -i %06x -1 %02x%02x%02x -2 %02x%02x%02x", chipid, mac1[0], mac1[1], mac1[2], mac2[0], mac2[1], mac2[2]);
      INFO(" Hardware info:  %s", otb_hw_info);
      INFO(" Boot slot:      %d", otb_rboot_get_slot(FALSE));
      INFO(" Free heap size: %d bytes", system_get_free_heap_size());
      INFO(" SW Chip ID:     %s", OTB_MAIN_CHIPID);
      INFO(" Device ID:      %s", OTB_MAIN_DEVICE_ID);
      INFO(" Wifi SSID:      %s", otb_conf->ssid);
      INFO(" Wifi Password:  %s", otb_conf->password);
      INFO(" MQTT Server:    %s", otb_conf->mqtt.svr);
      INFO(" MQTT Port:      %d", otb_conf->mqtt.port);
      INFO(" MQTT Username:  %s", otb_conf->mqtt.user);
      INFO(" MQTT Password:  %s", otb_conf->mqtt.pass);
      break;

    case 'w':
    case 'W':
      INFO("Wipe stored config");
      uint8 spi_rc = spi_flash_erase_sector(OTB_BOOT_CONF_LOCATION / 0x1000);
      INFO(" Wiped");
      otb_reset(otb_break_config_reboot_string);
      break;

    case 'd':
    case 'D':
      INFO("Disable watchdog");
      otb_util_break_disable_timer();
      INFO(" Watchdog disabled");
      break;

    case 'e':
    case 'E':
      INFO("Enable watchdog");
      otb_util_break_disable_timer();
      otb_util_break_enable_timer(OTB_BREAK_WATCHDOG_TIMER);
      INFO(" Watchdog enabled: %dms", OTB_BREAK_WATCHDOG_TIMER)
      break;

    case 'h':
    case 'H':
    case '?':
      output_options = TRUE;
      break;

    default:
      INFO("Invalid option selected");
      break;
  }

  if (output_options)
  {
      otb_break_options_output();
  }

  DEBUG("BREAK: otb_break_options_select exit");

  return(clear_buf);
}

bool ICACHE_FLASH_ATTR otb_break_gpio_input(char input)
{

  DEBUG("BREAK: otb_break_gpio_input entry");

  switch (input)
  {
    case 'x':
    case 'X':
      otb_break_state = OTB_BREAK_STATE_MAIN;
      INFO(" Exiting GPIO test")
      break;

    case 'h':
    case 'H':
    case '?':
      INFO("  x - Terminate");
      break;

    default:
      INFO(" Invalid option selected");
      break;
  }

  DEBUG("BREAK: otb_break_gpio_input exit");

  return(TRUE);
}

bool ICACHE_FLASH_ATTR otb_break_config_input(char input)
{
  bool rc = TRUE;

  DEBUG("BREAK: otb_break_config_input entry");

  switch (otb_break_config_state)
  {
    case OTB_BREAK_CONFIG_STATE_MAIN:
      rc = otb_break_config_input_main(input);
      break;

    case OTB_BREAK_CONFIG_STATE_SSID:
      if (otb_break_collect_string(input))
      {
        os_strncpy(otb_conf->ssid, otb_break_string, OTB_CONF_WIFI_SSID_MAX_LEN);
        otb_conf->ssid[OTB_CONF_WIFI_SSID_MAX_LEN-1] = 0;
        INFO("  Set SSID to: %s", otb_conf->ssid);
        otb_break_config_state = OTB_BREAK_CONFIG_STATE_MAIN;
      }
      break;
      
    case OTB_BREAK_CONFIG_STATE_PASSWORD:
      if (otb_break_collect_string(input))
      {
        os_strncpy(otb_conf->password, otb_break_string, OTB_CONF_WIFI_PASSWORD_MAX_LEN);
        otb_conf->password[OTB_CONF_WIFI_PASSWORD_MAX_LEN-1] = 0;
        INFO("  Set WiFi password to: %s", otb_conf->password);
        otb_break_config_state = OTB_BREAK_CONFIG_STATE_MAIN;
      }
      break;
      
    case OTB_BREAK_CONFIG_STATE_MQTT_SVR:
      if (otb_break_collect_string(input))
      {
        os_strncpy(otb_conf->mqtt.svr, otb_break_string, OTB_MQTT_MAX_SVR_LEN);
        otb_conf->mqtt.svr[OTB_MQTT_MAX_SVR_LEN-1] = 0;
        INFO("  Set MQTT server to: %s", otb_conf->mqtt.svr);
        otb_break_config_state = OTB_BREAK_CONFIG_STATE_MAIN;
      }
      break;
      
    case OTB_BREAK_CONFIG_STATE_MQTT_PORT:
      if (otb_break_collect_string(input))
      {
        otb_conf->mqtt.port = atoi(otb_break_string);
        INFO("  Set MQTT port to: %d", otb_conf->mqtt.port);
        otb_break_config_state = OTB_BREAK_CONFIG_STATE_MAIN;
      }
      break;
      
    case OTB_BREAK_CONFIG_STATE_CHIP_ID:
      if (otb_break_collect_string(input))
      {
        os_strncpy(OTB_MAIN_CHIPID, otb_break_string, OTB_MAIN_CHIPID_STR_LENGTH);
        OTB_MAIN_CHIPID[OTB_MAIN_CHIPID_STR_LENGTH-1] = 0;
        INFO("  Set Chip ID to: %s", OTB_MAIN_CHIPID);
        otb_break_config_state = OTB_BREAK_CONFIG_STATE_MAIN;
      }
      break;

    case OTB_BREAK_CONFIG_STATE_DEVICE_ID:
      if (otb_break_collect_string(input))
      {
        os_strncpy(OTB_MAIN_DEVICE_ID, otb_break_string, OTB_MAIN_DEVICE_ID_STR_LENGTH);
        OTB_MAIN_DEVICE_ID[OTB_MAIN_DEVICE_ID_STR_LENGTH-1] = 0;
        INFO("  Set Device ID to: %s", OTB_MAIN_DEVICE_ID);
        otb_break_config_state = OTB_BREAK_CONFIG_STATE_MAIN;
      }
      break;

    default:
      OTB_ASSERT(FALSE);
      break;
  }

  DEBUG("BREAK: otb_break_config_input exit");

  return(rc);
}

void ICACHE_FLASH_ATTR otb_break_clear_string(void)
{
  DEBUG("BREAK: otb_break_clear_string entry");
  os_memset(otb_break_string, 0, OTB_BREAK_CONFIG_STRING_LEN);
  DEBUG("BREAK: otb_break_clear_string exit");
  return;
}

// returns TRUE if string is finished (got \r or \n)
bool ICACHE_FLASH_ATTR otb_break_collect_string(char input)
{
  bool rc = FALSE;
  size_t len;

  DEBUG("BREAK: otb_break_collect_string entry");

  if ((input == '\r') || (input == '\n'))
  {
    rc = TRUE;
  }
  else
  {
    len = os_strnlen(otb_break_string, OTB_BREAK_CONFIG_STRING_LEN);
    if (len < (OTB_BREAK_CONFIG_STRING_LEN - 1))
    {
      otb_break_string[len] = input;
      ets_printf("%c", input);
    }
    else
    {
      INFO("  Hit max config string length %d", OTB_BREAK_CONFIG_STRING_LEN-1);
      rc = TRUE;
      otb_break_string[OTB_BREAK_CONFIG_STRING_LEN-1] = 0;
    }
  }

  if (rc)
  {
    ets_printf("\r\n");
  }

  DEBUG("BREAK: otb_break_collect_string exit");

  return(rc);
}

bool ICACHE_FLASH_ATTR otb_break_config_input_main(char input)
{

  DEBUG("BREAK: otb_break_config_input_main entry");

  switch (input)
  {
    case 'x':
    case 'X':
      otb_break_state = OTB_BREAK_STATE_MAIN;
      INFO(" Exiting config change")
      break;

    case 's':
    case 'S':
      INFO(" SSID");
      otb_break_config_state = OTB_BREAK_CONFIG_STATE_SSID;
      otb_break_clear_string();
      break;

    case 'p':
    case 'P':
      INFO(" WiFi Password");
      otb_break_config_state = OTB_BREAK_CONFIG_STATE_PASSWORD;
      otb_break_clear_string();
      break;

    case 'm':
    case 'M':
      INFO(" MQTT Server");
      otb_break_config_state = OTB_BREAK_CONFIG_STATE_MQTT_SVR;
      otb_break_clear_string();
      break;

    case 'r':
    case 'R':
      INFO(" MQTT Port");
      otb_break_config_state = OTB_BREAK_CONFIG_STATE_MQTT_PORT;
      otb_break_clear_string();
      break;

    case 'c':
    case 'C':
      INFO(" Chip ID");
      otb_break_config_state = OTB_BREAK_CONFIG_STATE_CHIP_ID;
      otb_break_clear_string();
      break;

    case 'd':
    case 'D':
      INFO(" Device ID");
      otb_break_config_state = OTB_BREAK_CONFIG_STATE_DEVICE_ID;
      otb_break_clear_string();
      break;

    case 'h':
    case 'H':
    case '?':
      INFO(" Config change options:")
      INFO("  s - SSID");
      INFO("  p - WiFi Password");
      INFO("  m - MQTT Server");
      INFO("  r - MQTT Port");
      INFO("  c - Chip ID");
      INFO("  d - Device ID");
      INFO("  x - Exit");
      break;

    default:
      INFO("Invalid option selected");
      break;
  }

  DEBUG("BREAK: otb_break_config_input_main exit");

  return(TRUE);
}

bool ICACHE_FLASH_ATTR otb_break_soft_reset_input(char input)
{

  DEBUG("BREAK: otb_break_soft_reset_input entry");

  switch (input)
  {
    case 'x':
    case 'X':
      otb_break_state = OTB_BREAK_STATE_MAIN;
      INFO(" Exiting soft reset test")
      break;

    case 'h':
    case 'H':
    case '?':
      INFO("  x - Terminate");
      break;

    default:
      INFO("Invalid option selected");
      break;
  }

  DEBUG("BREAK: otb_break_soft_reset_input exit");

  return(TRUE);
}

// Called from within interrupts
void otb_break_process_char(void)
{
  otb_util_timer_set((os_timer_t*)&otb_break_process_char_timer, 
                    (os_timer_func_t *)otb_break_process_char_timerfunc,
                    NULL,
                    0,
                    0);

  return;
}
