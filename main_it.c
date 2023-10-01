#include <main.h>


extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim3;


void SysTick_Handler(void)
{
   HAL_IncTick();
   HAL_SYSTICK_IRQHandler();
}

void TIM3_IRQHandler(void)
{
	//la funcion que ejecuta el timer debe de ser ejecutada por la funcion callback del timer3, no el IRQHandler
	//HAL_TIM_PeriodElapsedCallback
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	HAL_TIM_IRQHandler(&htim3);
}

void USART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart1); //busca en los registros del periferico el motivo de la interrupcion
	//llamar las funciones callback
}


