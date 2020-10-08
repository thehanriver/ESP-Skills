/* ADC1 Example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.

   Mario Han 9/30/20
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "sdkconfig.h"
#include "esp_vfs_dev.h"
#include <math.h>

#define DEFAULT_VREF    1100        //Use adc2_vref_to_gpio() to obtain a better estimate
#define NO_OF_SAMPLES   10          //Multisampling

const float Beta = 3435;   // replace "Beta" with beta of thermistor
const float initTemp = 298.15;   // room temp in Kelvin
const int adcMAX = 4096;

static esp_adc_cal_characteristics_t *adc_chars;
static const adc_channel_t channel = ADC_CHANNEL_6;     //GPIO34 if ADC1, GPIO14 if ADC2
static const adc_atten_t atten = ADC_ATTEN_DB_11;
static const adc_unit_t unit = ADC_UNIT_1;
////////////////////////////////////////////////////////////////////////////////

static void check_efuse(void)
{
    //Check TP is burned into eFuse
    if (esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_TP) == ESP_OK) {
        printf("eFuse Two Point: Supported\n");
    } else {
        printf("eFuse Two Point: NOT supported\n");
    }

    //Check Vref is burned into eFuse
    if (esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_VREF) == ESP_OK) {
        printf("eFuse Vref: Supported\n");
    } else {
        printf("eFuse Vref: NOT supported\n");
    }
}

static void print_char_val_type(esp_adc_cal_value_t val_type)
{
    if (val_type == ESP_ADC_CAL_VAL_EFUSE_TP) {
        printf("Characterized using Two Point Value\n");
    } else if (val_type == ESP_ADC_CAL_VAL_EFUSE_VREF) {
        printf("Characterized using eFuse Vref\n");
    } else {
        printf("Characterized using Default Vref\n");
    }
}

static void voltage_reading() {
  //Check if Two Point or Vref are burned into eFuse
  check_efuse();
  //Configure ADC
  if (unit == ADC_UNIT_1) {
      adc1_config_width(ADC_WIDTH_BIT_12);
      adc1_config_channel_atten(channel, atten);
  } else {
      adc2_config_channel_atten((adc2_channel_t)channel, atten);
  }
  //Characterize ADC
  adc_chars = calloc(1, sizeof(esp_adc_cal_characteristics_t));
  esp_adc_cal_value_t val_type = esp_adc_cal_characterize(unit, atten, ADC_WIDTH_BIT_12, DEFAULT_VREF, adc_chars);
  print_char_val_type(val_type);
  //Continuously sample ADC1
  while (1) {
      uint32_t adc_reading = 0;
      //Multisampling
      for (int i = 0; i < NO_OF_SAMPLES; i++) {
          if (unit == ADC_UNIT_1) {
              adc_reading += adc1_get_raw((adc1_channel_t)channel);
              vTaskDelay(100 / portTICK_PERIOD_MS);
          }
      }
      adc_reading /= NO_OF_SAMPLES;
      //Convert adc_reading to voltage in mV
      uint32_t voltage = esp_adc_cal_raw_to_voltage(adc_reading, adc_chars);

      float temp, Therm_res;
      Therm_res = adc_reading;
      Therm_res = (1000 * ((adcMAX / Therm_res) - 1));
      temp = Therm_res / 10000;
      temp = log(temp);
      temp /= Beta;
      temp += 1.0 / (initTemp);
      temp = 1.0 / temp;
      temp -= 273.15;

/*
      float Kel, Cel;
      float R0 = 1000;
      float Rt = R0 * ((adcMAX/adc_reading)-1);

      float mult =log ( Rt );
      float calc = invT0 + (invBeta* mult);
      Kel = 1.00 / calc;
      Cel = Kel - 273.15;                      // convert to Celsius
*/
      printf("Raw: %d\t volt: %d\t Temp: %f\n", adc_reading, voltage, temp);
      vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void app_main(void)
{
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_0, 256,0,0,NULL,0));
    esp_vfs_dev_uart_use_driver(UART_NUM_0);
    xTaskCreate(voltage_reading, "voltage_reading",4096, NULL, 4, NULL);

}
