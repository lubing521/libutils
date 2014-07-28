/*
 * =====================================================================================
 *
 *       Filename:  _mem_pool.h
 *
 *    Description:  仿照nginx的内存池原理，实现一个专门为小内存分配的内存池。
 *                  设计思路：
 *                  在一次请求 <-> 应答过程中，会有多次大小不一的小内存分配需求，
 *                  服务器长时间运行后，会有内存碎片的问题。
 *                  那么如何解决这个问题呢，借鉴了部分nginx内存池设计思想后，可以采用如下方法：
 *                  1. 一次请求应答创建一个内存池实例，应答结束后销毁内存池实例。
 *                  2. 只处理小于一个page大小的内存申请，内存维护若干个page大小的单元，
 *                     初始化为1单元，自动扩容。
 *                  由于每一次malloc都是page大小的内存，不会引起内存碎片问题。
 *                  而且性能有了比较好的提升。
 *
 *        Version:  1.0
 *        Created:  07/13/2012 05:19:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _MEM_POOL_H_
#define _MEM_POOL_H_
#include "_common.h"

#define MAX_FAILED_COUNT   4
#define PLATFORM_ALIGNMENT sizeof(unsigned long)

/* 内存池初始化时，只有一个page单元, 以后自动扩展
 * 但扩容的单位仍然是一个page */
typedef struct _mem_page_t{
    void               *start;     /* 内存page的起始地址 */
    void               *last;      /* 内存page可用内存的地址 */
    void               *end;       /* 内存page的末地址 */
    struct _mem_page_t *next;      /* 下一个内存page */
    int                 failed;    /* 当前page申请内存失败的次数 */
}mem_page_t;

typedef struct _mem_pool_t {
    int         page_size;         /* 内存page的大小，为固定值 */
    int         page_count;        /* 当前内存池有多少个page */
    mem_page_t *current;           /* 当前正在使用的page */
    mem_page_t *head;              /* 头page */
    mem_page_t *tail;              /* 尾page */

#ifdef MEM_POOL_LOCK
    pthread_mutex_t lock;
#endif
}mem_pool_t;

/** 
 *        Name: mem_pool_create
 * Description: 创建内存池.
 *   Parameter:  
 *      Return: 返回内存池实例.
 */
mem_pool_t *mem_pool_create();

/** 
 *        Name: mem_pool_alloc
 * Description: 从内存池分配内存，不初始化(清0).
 *   Parameter:  
 *      Return: NULL  -> 分配失败.
 *              !NULL -> 分配成功.
 */
void *mem_pool_alloc(mem_pool_t *mem_pool, int size);

/** 
 *        Name: mem_pool_calloc
 * Description: 从内存池分配内存，初始化(清0).
 *   Parameter:  
 *      Return: NULL  -> 分配失败.
 *              !NULL -> 分配成功.
 */
void *mem_pool_calloc(mem_pool_t *mem_pool, int size);

/** 
 *        Name: mem_pool_destroy
 * Description: 销毁内存池.
 *   Parameter: mem_pool -> 内存池实例的地址. 
 *      Return: 
 *              
 */
void mem_pool_destroy(mem_pool_t **mem_pool);

/** 
 *        Name: mem_pool_dump
 * Description: dump的状态信息.
 *   Parameter: mem_pool -> 内存池实例的地址. 
 *      Return: 
 *              
 */
void mem_pool_dump(mem_pool_t *mem_pool);
#endif
