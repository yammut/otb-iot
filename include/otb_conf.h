/*
 * OTB-IOT - Out of The Box Internet Of Things
 *
 * Copyright (C) 2016 Piers Finlayson
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

#ifndef OTB_CONF_H
#define OTB_CONF_H

// Choosing 0x200000 as second boot image is at 0x202000
#define OTB_CONF_LOCATION 0x200000
#define OTB_CONF_MAX_CONF_SIZE 0x1000

// Randomly generated 32-bit int
#define OTB_CONF_MAGIC 0x3B1EC363  

// Lengths are #defined within structs so padding can be easily verified.
// otb_conf_struct will be held in RAM so need to keep as small as possible.

typedef struct otb_conf_location
{
  // 32 bytes * 3 = 96 bytes

#define OTB_CONF_LOCATION_MAX_LEN  32
  // Location 1 - e.g. property
  char loc1[OTB_CONF_LOCATION_MAX_LEN];
  
  // Location 2 - e.g. room
  char loc2[OTB_CONF_LOCATION_MAX_LEN];
  
  // Location 3 e.g. bit of room
  char loc3[OTB_CONF_LOCATION_MAX_LEN];
} otb_conf_location;

typedef struct otb_conf_ds18b20
{
  // 48 bytes

  // The chip ID of a DS18B20 sensor, as a null terminated string in the following format:
  // 28-02157166b0ff.  This is 15 chars, but 16 with 1 byte for terminating.
#define OTB_CONF_DS18B20_MAX_ID_LEN  16
  char id[16];
  
  // Location of this sensor.  Maximum 31 chars, so 32 with padding.
#define OTB_CONF_DS18B20_LOCATION_MAX_LEN  32  
  char loc[OTB_CONF_DS18B20_LOCATION_MAX_LEN];
} otb_conf_ds18b20;

typedef struct otb_conf_struct
{
  // Following fields are in version 1
  
  // Magic number to check this is a valid configuration
  uint32_t magic;
  
  // Version - starts at 1
#define OTB_CONF_VERSION_CURRENT  1
  uint16_t version;
  
  // 16-bit checksum.  #defines are bytes in struct of checksum
#define OTB_CONF_CHECKSUM_BYTE1 7
#define OTB_CONF_CHECKSUM_BYTE2 8
  uint16_t checksum;
  
  // Wifi SSID. Max is 32, but we want to null terminate.
#define OTB_CONF_WIFI_SSID_MAX_LEN  33
  char ssid[OTB_CONF_WIFI_SSID_MAX_LEN]; 
  
  // Must be set to zero 
  char pad1[3]; 
  
  // Wifi password.  Max is 63, but we're going to store as a string
#define OTB_CONF_WIFI_PASSWORD_MAX_LEN  64
  char password[OTB_CONF_WIFI_PASSWORD_MAX_LEN];
  
  // Don't need to worry about padding this array - as otb_conf_ds18b20 must be padded
  // Size is 48 bytes * 8 = 384 bytes
  otb_conf_ds18b20 ds18b20[OTB_DS18B20_MAX_DS18B20S];
  
  // Location information about this OTB-IOT device
  // Size is 96 bytes
  otb_conf_location loc;
  
  // Adding any configuration past this point needs to be supported by a different
  // version

} otb_conf_struct;

extern otb_conf_struct *otb_conf;

void otb_conf_init(void);
bool otb_conf_verify(otb_conf_struct *conf);
void otb_conf_init_config(otb_conf_struct *conf);
bool otb_conf_load(void);
bool otb_conf_save(otb_conf_struct *conf);
uint16_t otb_conf_calc_checksum(otb_conf_struct *conf);
bool otb_conf_verify_checksum(otb_conf_struct *conf);

#ifdef OTB_CONF_C

otb_conf_struct *otb_conf;
otb_conf_struct otb_conf_private;

#endif // OTB_CONF_C

#endif // OTB_CONF_H