/* Quest 1 Skill 7 individual
by Mario than 9/19/20

These are mainly defines and includes from
blink example*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

//Used these pins for output
#define bin_GPIO1 12
#define bin_GPIO2 27
#define bin_GPIO3 33
#define bin_GPIO4 15

void app_main(void)
{
    gpio_pad_select_gpio(bin_GPIO1);
    gpio_set_direction(bin_GPIO1, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(bin_GPIO2);
    gpio_set_direction(bin_GPIO2, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(bin_GPIO3);
    gpio_set_direction(bin_GPIO3, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(bin_GPIO4);
    gpio_set_direction(bin_GPIO4, GPIO_MODE_OUTPUT);
    while (1) {
      gpio_set_level(bin_GPIO1, 0);
      gpio_set_level(bin_GPIO2, 0);
      gpio_set_level(bin_GPIO3, 0);
      gpio_set_level(bin_GPIO4, 0);
      //used modulus to count in bin
              for(int i = 0; i <16; i ++){
                //Error Checking
                //printf("iteration: %u\n",i);
                //printf("4th: %u\n",i/8%2);
                //printf("3th: %u\n",i/4%2);
                //printf("2nd: %u\n",i/2%2);
                //printf("1st: %u\n",i%2);
                //printf("Bin: %u%u%u%u\n", i/8%2, i/4%2, i/2%2, i%2);

                if(i%2){
                gpio_set_level(bin_GPIO1, 1);
                }
                if(i/2%2){
                gpio_set_level(bin_GPIO2,1);
                }
                if(i/4%2){
                gpio_set_level(bin_GPIO3,1);

                }
                if(i/8%2){
                gpio_set_level(bin_GPIO4,1);

                }
                //vTaskDelay
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                gpio_set_level(bin_GPIO1, 0);
                gpio_set_level(bin_GPIO2, 0);
                gpio_set_level(bin_GPIO3, 0);
                gpio_set_level(bin_GPIO4, 0);
              }
    }
}
