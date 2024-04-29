/*
 * @Author: zl 2293721550@qq.com
 * @Date: 2024-03-26 23:26:05
 * @LastEditors: zl 2293721550@qq.com
 * @LastEditTime: 2024-03-26 23:26:17
 * @FilePath: \DaChuang\Core\user\printTo.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __PRINTTO_H_
#define __PRINTTO_H_

enum UARTX {
  uart1,
  uart2,
  uart3,
  uart4,
};

extern void printTo(enum UARTX uartx, const char *format, ...);

#endif
