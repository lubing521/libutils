/*
 * =====================================================================================
 *
 *       Filename:  _buffer.c
 *
 *    Description:  对buffer相关结构体的定义。
 *
 *        Version:  1.0
 *        Created:  07/19/2012 04:24:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _BUFFER_H_
#define _BUFFER_H_
#include "_common.h"
#include "utils.h"

#define BUFFER_FROM_MEM_POOL 0
#define BUFFER_FROM_MALLOC   1

#define BUFFER_TYPE_MEMORY   0
#define BUFFER_TYPE_FILE     1

/* 定义buffer结构体 */
typedef struct _buffer_t {
    mem_pool_t *pool;              /* 如果不为空，表示buffer内部内存分配从pool分配 */
    int   type;                    /* buffer存储的形式,是在文件还是内存 */
    char *start;                   /* buffer的首地址,一般不会改变 */
    char *pos;                     /* buffer中可用数据的地址 */
    char *last;                    /* buffer中可用数据的尾地址 */
    char *end;                     /* buffer的尾地址 */
    //int   from;                  /* buffer从哪儿分配，目前支持内存池和malloc */
    off_t file_start;              /* 文件buffer的起始位置 */
    off_t file_end;                /* 文件buffer的结束位置 */
} buffer_t;

/* 定义buffer链结构体 */
typedef struct _buffer_chain_t {
    buffer_t *buffer; 
    struct _buffer_chain_t *next;
} buffer_chain_t;

/** 
 *        Name: buffer_eof
 * Description: buffer是否到达末尾.
 *   Parameter: buffer -> buffer实例. 
 *      Return: 1 -> buffer末尾;
 *              0 -> buffer未达到末尾。
 *              
 */
int buffer_eof(buffer_t *buffer);

/** 
 *        Name: buffer_read
 * Description: 从buffer读数据.
 *   Parameter: buffer   -> buffer实例.
 *              buf      -> 数据输出buf.
 *              buf_size -> 数据输出buf的大小.
 *      Return: >0 -> 返回read数据的大小。
 *              0  -> 无数据
 *              -1 -> 出错
 */
int buffer_read(buffer_t *buffer, char *buf, int buf_size);

/** 
 *        Name: buffer_read_line
 * Description: 从buffer中读取一行数据.
 *   Parameter: buffer   -> buffer实例. 
 *              buf      -> 数据输出buf。
 *              buf_size -> 数据输出buf大小。
 *      Return: >0 -> 返回read的数据的大小。
 *              0  -> 无数据返回。
 *              -1 -> 出错。
 */
int buffer_read_line(buffer_t *buffer, char *buf, int buf_size);

/** 
 *        Name: buffer_write
 * Description: 向buffer写入数据
 *   Parameter: buffer   -> buffer实例。
 *              buf      -> 写入数据的buf。
 *              buf_size -> 写入数据的大小。
 *      Return: >0 -> 返回write的数据的大小。
 *              0  -> 无数据返回。
 *              -1 -> 出错。
 */
int buffer_write(buffer_t *buffer, char *buf, int size);
#endif
