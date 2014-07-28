/*
 * =====================================================================================
 *
 *       Filename:  network_util.h
 *
 *    Description:  网络编程工具代码
 *
 *        Version:  1.0
 *        Created:  01/07/2013 03:48:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _NETWORK_UTIL_H_
#define _NETWORK_UTIL_H_
#include "utils.h"
#include "_common.h"

/** 
 *        Name: set_non_blocking
 * Description: 设置非阻塞 
 *   Parameter: sock_fd -> sock描述符
 *      Return: 0 -> 设置失败
 *              1 -> 设置成功 
 */
int set_non_blocking(int sock_fd);

/** 
 *        Name: set_reuse_addr
 * Description: 设置地址重用
 *   Parameter: sock_fd -> sock描述符
 *      Return: 0 -> 设置失败
 *              1 -> 设置成功 
 */
int set_reuse_addr(int sock_fd);

/** 
 *        Name: nic_get_ip
 * Description: 根据网卡名称获取网卡IP
 *   Parameter: name -> 网卡名称，例如eth0
 *              ip   -> 输出IP
 *              ip_size -> 输出ip的buffer大小
 *      Return: 0 -> 获取失败
 *              1 -> 获取成功 
 */
int nic_get_ip(char *name, char *ip, int ip_size);
    
#endif
