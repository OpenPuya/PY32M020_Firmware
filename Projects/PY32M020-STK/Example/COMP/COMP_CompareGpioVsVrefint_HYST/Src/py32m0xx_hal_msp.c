/**
  ******************************************************************************
  * @file    py32m0xx_hal_msp.c
  * @author  MCU Application Team
  * @brief   This file provides code for the MSP Initialization
  *          and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* External functions --------------------------------------------------------*/

/**
  * @brief Initialize global MSP
  */
void HAL_MspInit(void)
{
}

/**
  * @brief Initialize COMP-related MSP
  */
void HAL_COMP_MspInit(COMP_HandleTypeDef *hcomp)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();                 /* Enable GPIOA clock */
  __HAL_RCC_COMP1_CLK_ENABLE();                 /* Enable COMP1 clock */
  __HAL_RCC_COMP2_CLK_ENABLE();                 /* Enable COMP2 clock */
  /* Configure GPIO PA3 as analog input */
  GPIO_InitTypeDef COMPINPUT;
  COMPINPUT.Pin = GPIO_PIN_3;
  COMPINPUT.Mode = GPIO_MODE_ANALOG;            /* Analog mode */
  COMPINPUT.Speed = GPIO_SPEED_FREQ_HIGH;
  COMPINPUT.Pull = GPIO_PULLDOWN;               /* Pull-down */
  HAL_GPIO_Init(GPIOA,  &COMPINPUT);            /* Initialize GPIO */

  /* Configure GPIO PA7 as output */
  COMPINPUT.Pin = GPIO_PIN_7;
  COMPINPUT.Mode = GPIO_MODE_AF_PP;             /* Output mode */
  COMPINPUT.Speed = GPIO_SPEED_FREQ_HIGH;
  COMPINPUT.Pull = GPIO_PULLDOWN;               /* Pull-down */
  COMPINPUT.Alternate = GPIO_AF7_COMP2;         /* Alternate as COMP2_OUT */
  HAL_GPIO_Init(GPIOA,  &COMPINPUT);            /* Initialize GPIO */
}

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
