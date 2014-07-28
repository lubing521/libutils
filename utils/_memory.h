/*
 * =====================================================================================
 *
 *       Filename:  _memory.h
 *
 *    Description:  对内存操作的封装
 *
 *        Version:  1.0
 *        Created:  07/19/2012 02:44:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _MEMORY_H_
#define _MEMORY_H_
#include "_common.h"

#ifndef MALLOC_DEBUG
#define MALLOC_WRAPPER(size) malloc(size)
#else
#define MALLOC_WRAPPER(size) malloc_wrapper(size)
#endif

/** 
 *        Name: malloc_wrapper
 * Description: 用来debug malloc用的.
 *   Parameter: size -> 分配内存的大小.
 *      Return: 分配的内存的首地址.
 */
void *malloc_wrapper(int size);
#endif
