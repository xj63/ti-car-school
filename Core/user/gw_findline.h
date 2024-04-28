/*
 * Eight-way grayscale sensor
 * use IIC
 */

#ifndef __GW_GRAY_H__
#define __GW_GRAY_H__

#include <stdint.h>

// Get whether there is a black line under the sensor, from left to right
uint8_t gw_gray_get_line_digital_is_black();

void gw_gray_get_line_analog(uint8_t gray[8]); // Get the gray value

void gw_gray_ping();      // ping sensor test the sensor is working or not
void gw_gray_get_error(); // get error code from sensor

#endif // !__GW_GRAY_H__
