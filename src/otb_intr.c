/*
 * OTB-IOT - Out of The Box Internet Of Things
 *
 * Copyright (C) 2018-2020 Piers Finlayson
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

#define OTB_INTR_C
#include "otb.h"

MLOG("INTR");

void ICACHE_FLASH_ATTR otb_intr_init(void)
{
  int ii;

  ENTRY;

  for (ii=0; ii < OTB_GPIO_ESP_GPIO_PINS; ii++)
  {
    otb_intr_reg_info[ii].fn = NULL;
    otb_intr_reg_info[ii].arg = NULL;
  }

  EXIT;

  return;
}

void ICACHE_FLASH_ATTR otb_intr_clear(uint32_t gpio_status)
{
  ENTRY;

  GPIO_REG_WRITE(GPIO_STATUS_W1TC_ADDRESS, gpio_status);

  EXIT;

  return;  
}

void ICACHE_FLASH_ATTR otb_intr_set()
{
  int ii;
  bool have_intr = FALSE;

  ENTRY;

  for (ii=0; ii < OTB_GPIO_ESP_GPIO_PINS; ii++)
  {
    if (otb_intr_reg_info[ii].fn != NULL)
    {
      gpio_pin_intr_state_set(GPIO_ID_PIN(ii), 3);  // ANYEDGE
      otb_intr_clear(1<<ii);
      have_intr = TRUE;
    }
  }

  if (have_intr)
  {
		ETS_GPIO_INTR_DISABLE();
		ETS_GPIO_INTR_ATTACH(otb_intr_main_handler, NULL);
		ETS_GPIO_INTR_ENABLE();
    
  }

  EXIT;

  return;  
}

bool ICACHE_FLASH_ATTR otb_intr_register(otb_intr_handler_fn *fn, void *arg, uint8_t pin)
{
  bool rc = FALSE;

  ENTRY;

  OTB_ASSERT(pin < OTB_GPIO_ESP_GPIO_PINS);
  if (otb_intr_reg_info[pin].fn == NULL)
  {
    otb_intr_reg_info[pin].fn = fn;
    otb_intr_reg_info[pin].arg = arg;
    ETS_INTR_LOCK();
    otb_intr_set();
    ETS_INTR_UNLOCK();
    rc = TRUE;
    MDETAIL("Registered interrupt handler for pin %d", pin)
  }
  else
  {
    MERROR("Already have interrupt handler for pin %d", pin);
  }

  EXIT;

  return rc;
}

void ICACHE_FLASH_ATTR otb_intr_unreg(uint8_t pin)
{

  ENTRY;

  OTB_ASSERT(pin < OTB_GPIO_ESP_GPIO_PINS);
  otb_intr_reg_info[pin].fn = NULL;
  otb_intr_reg_info[pin].arg = NULL;
  ETS_INTR_LOCK();
  otb_intr_set();
  gpio_pin_intr_state_set(GPIO_ID_PIN(pin), 0);  //   ETS_INTR_UNLOCK();
  MDETAIL("Unregistered interrupt handler for pin %d", pin)

  EXIT;

  return;
}

void ICACHE_FLASH_ATTR otb_intr_main_handler(void *arg)
{
  uint32_t gpio_status;
  uint8_t gpio;

  ENTRY;

  ETS_INTR_LOCK();

  gpio_status = GPIO_REG_READ(GPIO_STATUS_ADDRESS);
  //ets_printf("gpio status 0x%08x\r\n", gpio_status);
  for (gpio = 0; gpio < 17; gpio++)
  {
    if ((gpio_status >> gpio) & 1)
    {
      OTB_ASSERT(otb_intr_reg_info[gpio].fn != NULL);
      otb_intr_reg_info[gpio].fn(otb_intr_reg_info[gpio].arg);
    }
  }

  otb_intr_clear(gpio_status);
  otb_intr_set();

  ETS_INTR_UNLOCK();

  EXIT;

  return;
}
