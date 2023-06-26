/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd_driver.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint8_t temp_id=53;
  uint8_t RotationCnt = 0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(1000);
  lcd_init();
  //HAL_Delay(1000);
  //HAL_UART_Transmit(&huart2, &temp_id, 1, 1000);
  //lcd_clear_screen(WHITE);
  //HAL_Delay(1000);
  /* USER CODE END 2 */
  int X_MAX = 240;
  int X_MIN = 0;
  int Y_MAX = 320;
  int Y_MIN = 0;
  int x = 25;
  int y = 160;

  int HOR_DIRECTION = 1;
  int VER_DIRECTION = 1;

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if (HOR_DIRECTION == 1) {
		  x += 6;
	  } else {
		  x -= 6;
	  }

	  if (VER_DIRECTION == 1) {
	  	y += 8;
	  } else {
	  	y -= 8;
	  }

	  lcd_draw_circle(x, y, 25, RED);
	  HAL_Delay(100);
	  lcd_draw_circle(x, y, 25, WHITE);

	  if (x > X_MAX - 25) {
		  HOR_DIRECTION = 0;
	  } else if (x < X_MIN + 25) {
		  HOR_DIRECTION = 1;
	  }

	  if (y > Y_MAX - 25) {
		  VER_DIRECTION = 0;
	  } else if (y < Y_MIN + 25) {
		  VER_DIRECTION = 1;
	 }



		//
		// TEXT
		//
	    //setRotation((RotationCnt++)%4);
		//lcd_display_string(43, 100, (const uint8_t *) "Embedded Systems", FONT_1608, RED);
		//lcd_display_string(40, 120, (const uint8_t *) "WI ZUT 22.04.2021", FONT_1608, BLUE);

		//
		// SHAPES
		//
		//lcd_draw_rect(95, 135, 50, 50, BLUE);
		//lcd_fill_rect(95, 210, 50, 50, GRAY);
		//
		// COLORS
		//
//		lcd_clear_screen(BLUE);
//		HAL_Delay(100);
//		lcd_clear_screen(RED);
//		HAL_Delay(100);
//		lcd_clear_screen(GREEN);
//		HAL_Delay(100);
//		lcd_clear_screen(WHITE);
//		HAL_Delay(100);
//		lcd_clear_screen(BRED);
//		HAL_Delay(100);
//		lcd_clear_screen(GRED);
//		HAL_Delay(100);
//		lcd_clear_screen(GBLUE);
//		HAL_Delay(100);
//		lcd_clear_screen(RED);
//		HAL_Delay(100);
//		lcd_clear_screen(MAGENTA);
//		HAL_Delay(100);
//		lcd_clear_screen(GREEN);
//		HAL_Delay(100);
//		lcd_clear_screen(CYAN);
//		HAL_Delay(100);
//		lcd_clear_screen(YELLOW);
//		HAL_Delay(100);
//		lcd_clear_screen(BROWN);
//		HAL_Delay(100);
//		lcd_clear_screen(BRRED);
//		HAL_Delay(100);
//		lcd_clear_screen(GRAY);
//		HAL_Delay(100);
//		lcd_clear_screen(WHITE);
	  //HAL_Delay(10);
	  //temp_id = lcd_read_id();
	  //HAL_UART_Transmit(&huart2, &temp_id, 1, 1000);

	  //HAL_Delay(500);
	  //HAL_UART_Transmit(&huart2, (&(uint8_t){0x55}), 1, 1000);

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
