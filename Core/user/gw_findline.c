/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-04-28 10:42:34
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-04-28 11:39:20
 * @FilePath: \WuYi_xiaosai\Core\user\GW_findline.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "gw_findline.h"
#include "i2c.h"
#include "printTo.h"

#define GW_GRAY_ADDR 0x4C

#define Ping_CMD 0xAA
#define Ping_SUCCESS 0x66
#define Digital_Output_CMD 0xDD
#define Analogue_Output_CMD 0xB0
#define Get_error_CMD 0xDE

uint8_t gw_gray_get_line_digital_is_black()
{
    uint8_t cmd = Digital_Output_CMD;
    uint8_t buf = 0;
    HAL_I2C_Master_Transmit(&hi2c1, GW_GRAY_ADDR << 1, &cmd, 1, 100);
    HAL_Delay(100);
    HAL_I2C_Master_Receive(&hi2c1, GW_GRAY_ADDR << 1, &buf, 1, 100);
    // printTo(uart3, "%d\r\n", buf);
    return ~buf;
}

void gw_gray_get_line_analog(uint8_t gray[8])
{
    uint8_t cmd = Analogue_Output_CMD;

    // IIC_Write(GW_GRAY_ADDR, 1, &cmd);
    // IIC_Read(GW_GRAY_ADDR, 8, gray);
    //  printf("1:%X 2:%X 3:%X 4:%X 5:%X 6:%X 7:%X 8:%X", buf[0], buf[1], buf[2],
    //  buf[3], buf[4], buf[5], buf[6], buf[7]);
}

void gw_gray_ping()
{
    uint8_t cmd = Ping_CMD;
    // uint8_t buf = IIC_Write(GW_GRAY_ADDR, 1, &cmd);
    // IIC_Read(GW_GRAY_ADDR, 1, &buf);
    // if (buf == Ping_SUCCESS)
}

void gw_gray_get_error()
{
    uint8_t cmd = Get_error_CMD;
    uint8_t buf = 0;
    // IIC_Write(GW_GRAY_ADDR, 1, &cmd);
    // IIC_Read(GW_GRAY_ADDR, 1, &buf);
    // debug_log("gw_gray: gw_gray get error code %hhu", buf);
}
