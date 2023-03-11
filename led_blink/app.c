/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "em_cmu.h"
#include "em_gpio.h"

typedef struct
{
    GPIO_Port_TypeDef port;
    uint8_t pin;
} LED;

LED led_0;

// LED 闪烁函数
// 通过循环实现延时
void led_blink(LED *led)
{
    for (int i = 0; i < 10000; i++)
    {
        GPIO_PinOutToggle(led->port, led->pin);
    }
}

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
    led_0.port = gpioPortA;
    led_0.pin = 1;

    CMU_ClockEnable(cmuClock_GPIO, true);
    GPIO_PinModeSet(led_0.port, led_0.pin, gpioModePushPull, 0);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
    led_blink(&led_0);
}
