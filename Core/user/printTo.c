#include "usart.h"
#include "main.h"
#include "stdio.h"
#include "stdarg.h"
#include "printTo.h"

void printTo(enum UARTX uartx, const char *format, ...)
{
    char str_buf[512] = {'\0'};

    va_list args;
    va_start(args, format);
    int len = vsnprintf(str_buf, 511, format, args);
    va_end(args);

    if (uartx == uart1)
        HAL_UART_Transmit(&huart1, str_buf, len, 10);
    else if (uartx == uart2)
        HAL_UART_Transmit(&huart2, str_buf, len, 10);
    else if (uartx == uart3)
        HAL_UART_Transmit(&huart3, str_buf, len, 10);
    else if (uartx == uart4)
        HAL_UART_Transmit(&huart4, str_buf, len, 10);

    // else if (uartx == usb)
    //     CDC_Transmit_FS(str_buf, len);
}
