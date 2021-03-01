#include <stm32f0xx_hal.h> // HAL = Hardware Abstraction Layer. This library brings in all the peripheral-related stuff

// runs once at startup
int main(void)
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_Init();

    //init oscillator input and PLL clock
    RCC_OscInitTypeDef RCC_OscInit_Struct;
    RCC_OscInit_Struct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInit_Struct.HSIState = RCC_HSI_ON;
    RCC_OscInit_Struct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInit_Struct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInit_Struct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInit_Struct.PLL.PLLMUL = RCC_PLL_MUL12;
    RCC_OscInit_Struct.PLL.PREDIV = RCC_PREDIV_DIV1;
    HAL_RCC_OscConfig(&RCC_OscInit_Struct);

    //init CPU and bus clocks
    //SYSCLK is for CPU, HCLK is for main internal bus AHB (b/w CPU, RAM, etc), and PCLK1 is for peripheral bus APB
    RCC_ClkInitTypeDef RCC_ClkInit_Struct;
    RCC_ClkInit_Struct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInit_Struct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInit_Struct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInit_Struct.APB1CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&RCC_ClkInit_Struct, FLASH_LATENCY_1);

    //init USART clock
    RCC_PeriphCLKInitTypeDef PeriphClockInit_Struct;
    PeriphClockInit_Struct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClockInit_Struct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClockInit_Struct);

    //init GPIO clock
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    //init GPIO
    GPIO_InitTypeDef GPIO_Init_Struct;
    GPIO_Init_Struct.Pin = GPIO_PIN_9;
    GPIO_Init_Struct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init_Struct.Pull = GPIO_NOPULL;
    GPIO_Init_Struct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_Init_Struct);

    //init UART
    UART_HandleTypeDef uart;
    uart.Instance = USART1;
    uart.Init.BaudRate = 9600;
    uart.Init.WordLength = UART_WORDLENGTH_8B;
    uart.Init.StopBits = UART_STOPBITS_1;
    uart.Init.Parity = UART_PARITY_NONE;
    uart.Init.Mode = UART_MODE_TX_RX;
    uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart.Init.OverSampling = UART_OVERSAMPLING_16;
    uart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    uart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_Init_Struct.Pin = GPIO_PIN_9 | GPIO_PIN_10;
    GPIO_Init_Struct.Mode = GPIO_MODE_AF_PP;
    GPIO_Init_Struct.Pull = GPIO_NOPULL;
    GPIO_Init_Struct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_Init_Struct.Alternate = GPIO_AF1_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);
    HAL_UART_Init(&uart);

    //blink LED and send a message each time it turns on
    while (1)
    {
        uint8_t message[] = "Hello world!";
        uint8_t *ptr = message;
        HAL_UART_Transmit(&uart, ptr, sizeof(message), 100);

        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
        HAL_Delay(1000);
    }
}

//required for tick to increment and HAL_Delay() to work.
void SysTick_Handler(void)
{
    HAL_IncTick();
}