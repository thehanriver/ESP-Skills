/* servo motor control example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
   Mario Han 11/30/20
*/
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_attr.h"

#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"

//You can get these value from the datasheet of servo you use, in general pulse width varies between 1000 to 2000 mocrosecond
#define SERVO_MIN_PULSEWIDTH 700  //Minimum pulse width in microsecond
#define SERVO_MAX_PULSEWIDTH 2100 //Maximum pulse width in microsecond
void calibrateESC();

#define MAX_RIGHT 700
#define MAX_LEFT 2000
#define NEUTRAL 1300

static void mcpwm_example_gpio_initialize(void)
{
    printf("initializing mcpwm servo control gpio......\n");
    // mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, 12); //Set GPIO 12 as PWM0A, to which servo is connected
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, 12); //Steering
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, 32); //speed
}

//Calibrate from brief
void calibrateESC()
{
    printf("Calibrate ESC\n");
    vTaskDelay(3000 / portTICK_PERIOD_MS);                                // Give yourself time to turn on crawler
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 2100); // HIGH signal in microseconds
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 700); // LOW signal in microseconds
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 1400); // NEUTRAL signal in microseconds
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 1400); // reset the ESC to neutral (non-moving) value
}
/**
 * @brief Configure MCPWM module
 */
void movement(void *arg)
{
    //2. initial mcpwm configuration
    printf("Configuring Initial Parameters of mcpwm......\n");
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 50; //frequency = 50Hz, i.e. for every servo motor time period should be 20ms
    pwm_config.cmpr_a = 0;     //duty cycle of PWMxA = 0
    pwm_config.cmpr_b = 0;     //duty cycle of PWMxb = 0
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config); //Configure PWM0A & PWM0B with above settings

    vTaskDelay(1000 / portTICK_PERIOD_MS); // Give yourself time to turn on crawler
    printf("Calibrate\n");
    calibrateESC();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Give yourself time to turn on crawler

    while (1)
    {
        int i;
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 1400); // Neutral signal in microseconds
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 700); // LOW signal in microseconds
        vTaskDelay(50 / portTICK_PERIOD_MS);
        for (i = SERVO_MIN_PULSEWIDTH; i <= 2100; i = i + 10)
        {
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, i);
            printf("Count %d\n", i);
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }
        for (i = SERVO_MAX_PULSEWIDTH; i >= 1400; i = i - 10)
        {
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, i);
            printf("Count %d\n", i);
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }
        printf("Neutral\n");

        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 1400); // LOW signal in microseconds
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 700); // LOW signal in microseconds
        vTaskDelay(1000 / portTICK_PERIOD_MS);
   
        printf("Reset\n");
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 1400); // LOW signal in microseconds
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void steering(void *arg)
{
    //2. initial mcpwm configuration
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 50; //frequency = 50Hz, i.e. for every servo motor time period should be 20ms
    pwm_config.cmpr_a = 0;     //duty cycle of PWMxA = 0
    pwm_config.cmpr_b = 0;     //duty cycle of PWMxb = 0
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config); //Configure PWM0A & PWM0B with above settings
    vTaskDelay(1000 / portTICK_PERIOD_MS);                // Give yourself time to turn on crawler
    while (1)
    {
        int i;
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, NEUTRAL); // Neutral signal in microseconds
        vTaskDelay(4000 / portTICK_PERIOD_MS);
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MAX_LEFT); // LOW signal in microseconds
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MAX_RIGHT); // LOW signal in microseconds
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        
        for (i = MAX_RIGHT; i <= MAX_LEFT; i = i + 10)
        {
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, i);
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }
        for (i = MAX_LEFT; i >= MAX_RIGHT; i = i - 10)
        {
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, i);
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }
    }
}

void app_main(void)
{
    printf("Testing servo motor.......\n");
    mcpwm_example_gpio_initialize();

    xTaskCreate(movement, "movement", 4096, NULL, 5, NULL);
    xTaskCreate(steering, "steering", 4096, NULL, 5, NULL);
}
