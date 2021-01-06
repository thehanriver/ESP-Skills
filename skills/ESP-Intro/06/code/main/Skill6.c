/* Quest 1 Skill 6 individual
by Mario than 9/19/20

These are mainly defines and includes from
blink and echo example in github*/
#include <stdio.h>
#include "driver/uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_vfs_dev.h"

#define EX_UART_NUM UART_NUM_0
#define ECHO_TEST_TXD  (UART_PIN_NO_CHANGE)
#define ECHO_TEST_RXD  (UART_PIN_NO_CHANGE)
#define ECHO_TEST_RTS  (UART_PIN_NO_CHANGE)
#define ECHO_TEST_CTS  (UART_PIN_NO_CHANGE)

#define BLINK_GPIO 13

#define BUF_SIZE (1024)

void app_main(void)
{
    /*
     Note: This is code from blink example as well as
     Console I/O brief on the site */
     ESP_ERROR_CHECK( uart_driver_install(UART_NUM_0,
         256, 0, 0, NULL, 0) );
    esp_vfs_dev_uart_use_driver(UART_NUM_0);
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    //setting up flags and print initial "toggle mode"
    printf("toggle mode\n");
    int led_flag = 0;
    int toggle_flag = 1;
    int echo_flag = 0;
    int hex_flag = 0;
    while (1) {
        /*depending on the flag it will switch modes
        "Inp" is used to store switch modes such as
        s and t and is cleared evertime mode is switched */
        char inp[32];
        if (toggle_flag == 1) {
          printf("Read:" );
          scanf("%s",inp);
          printf("%s\n",inp);
            //blink stuff from blink example in getting-started file
            if(*inp == 't' && led_flag == 0 && toggle_flag == 1){
              led_flag = 1;
              gpio_set_level(BLINK_GPIO, 1);
              vTaskDelay(1000 / portTICK_PERIOD_MS);
            }
            else if(*inp == 't' && led_flag == 1 && toggle_flag == 1){
              led_flag = 0;
              gpio_set_level(BLINK_GPIO, 0);
              vTaskDelay(1000 / portTICK_PERIOD_MS);
            }
            else if(*inp == 's' ){
              inp[0] =0;
              printf("echo mode\n");
              echo_flag = 1;
              toggle_flag = 0;
            }
        }
        /*some reasone i had to copy it into a different array
        or it wouldn't show white spaces*/
        if(echo_flag == 1 && hex_flag == 0){
            inp[0] =0;
            char an[32];
            printf("echo:");
            gets(inp);
            strncpy(an, inp, 32);
            printf("%s\n", an);
        }
        if(*inp == 's' && hex_flag == 0){
            printf("echo dec to hex mode\n");
            hex_flag = 1;
        }
        if(echo_flag == 1 && hex_flag ==1 ){
            char buffer[20];
            inp[0] =0;
            printf("Enter a integer: \n");
            scanf("%s\n",inp);
            strncpy(buffer, inp, 20);
            if(*inp != 't'){
            int hexx = atoi(buffer);
            printf("hex: %X\n",hexx);}
        }
        if(*inp == 't' && echo_flag == 1){
            hex_flag = 0;
            echo_flag = 0;
            toggle_flag = 1;
            printf("toggle mode\n");
        }


    }
}
