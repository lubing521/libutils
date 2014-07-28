/*
 * =====================================================================================
 *
 *       Filename:  _common.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/2012 05:46:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <linux/types.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>
#include <malloc.h>
#include <pthread.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/un.h>
#include <sys/epoll.h>
#include <assert.h>
#include <inttypes.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <ctype.h>

#define _XOPEN_SOURCE 600

#define ALIGN_PTR(ptr, align)                                \
     (void *)(((long)ptr + (align - 1)) & ~((long)align - 1))

#define ALIGN_INT(ptr, align)                                \
     (((int)ptr + (align - 1)) & ~((int)align - 1))

#endif
