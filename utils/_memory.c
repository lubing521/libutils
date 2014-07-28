/*
 * =====================================================================================
 *
 *       Filename:  _memory.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/19/2012 02:44:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#include "_memory.h"

void *malloc_wrapper(int size){
    printf("call malloc function.\n");
    return malloc(size);
}


