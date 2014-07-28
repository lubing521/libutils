/*
 * =====================================================================================
 *
 *       Filename:  _time.h
 *
 *    Description:  时间处理工具函数。
 *
 *        Version:  1.0
 *        Created:  07/13/2012 11:13:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _TIME_H_
#define _TIME_H_
#include "_common.h"

/** 
 *        Name: time_delta
 * Description: time delta between two times.
 *   Parameter: t1 -> time 1
 *              t2 -> time 2
 *      Return: return t1, t2's time delta, unit by ms.
 */
int time_delta(struct timeval *t1, struct timeval *t2);

/** 
 *        Name: time_signed_delta
 * Description: time signed delta between two times.
 *   Parameter: t1 -> time 1
 *              t2 -> time 2
 *      Return: return t1, t2's time delta, unit by ms.
 */
int time_signed_delta(struct timeval *t1, struct timeval *t2);

/** 
 *        Name: time_great
 * Description: compare two times.
 *   Parameter: t1 -> time 1
 *              t2 -> time 2
 *      Return: 1  -> t1 > t2;
 *              0  -> t1 == t2;
 *              -1 -> t1 < t2 
 */
int time_great(struct timeval *t1, struct timeval *t2);

/** 
 *        Name: time_less
 * Description: compare two times.
 *   Parameter: t1 -> time 1
 *              t2 -> time 2
 *      Return: 1  -> t1 < t2;
 *              0  -> t1 == t2;
 *              -1 -> t1 > t2 
 */
int time_less(struct timeval *t1, struct timeval *t2);

/** 
 *        Name: time_add
 * Description: add increment to t1.
 *   Parameter: t1 -> time
 *              increment -> time increment by ms.
 *      Return:
 */
void time_add(struct timeval *t1, int increment);

/** 
 *        Name: time_subtract
 * Description: subtract decrement to t1.
 *   Parameter: t1 -> time
 *              decrement -> time decrement by ms.
 *      Return:
 */
void time_subtract(struct timeval *t1, int decrement);

/** 
 *        Name: time_str
 * Description: get time string by format: %Y-%m-%d %H:%M:%S.
 *   Parameter: time_buffer -> output time string.
 *              buffer_size -> time string buffer size.
 *      Return: 
 */
void time_str(char *time_buffer, int buffer_size);

/** 
 *        Name: time_str_by_time
 * Description: get time string by format: %Y-%m-%d %H:%M:%S and specified time.
 *   Parameter: time_buffer -> output time string.
 *              buffer_size -> time string buffer size.
 *              t           -> specified time.
 *      Return: 
 */
void time_str_by_time(char *time_buffer, int buffer_size, time_t t);
#endif
