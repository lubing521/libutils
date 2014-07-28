/*
 * =====================================================================================
 *
 *       Filename:  _network.h
 *
 *    Description:  网络编程的API封装
 *
 *        Version:  1.0
 *        Created:  08/29/2012 05:30:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _NETWORK_H_
#define _NETWORK_H_
#include "_common.h"
#include "_log.h"

/** 
 *        Name: udp_server_create
 * Description: 创建udp socket的服务器端，并设置为异步。 
 *   Parameter: port -> 端口。
 *      Return: -1 -> 创建失败。
 *              >=0 返回创建的upd socket的句柄。
 */
int udp_server_create(int port);

/** 
 *        Name: udp_client_create
 * Description: 创建udp socket ，并设置为异步。 
 *   Parameter: 
 *      Return: -1 -> 创建失败。
 *              >=0 返回创建的upd socket的句柄。
 */
int udp_client_create();

/** 
 *        Name: unix_udp_server_create
 * Description: 创建unix domain udp socket的服务器端，并设置为异步。 
 *   Parameter: sock_path -> unix socket路径。
 *      Return: -1 -> 创建失败。
 *              >=0 返回创建的unix udp socket的句柄。
 */
int unix_udp_server_create(char *sock_path);

/** 
 *        Name: unix_udp_client_create
 * Description: 创建unix domain udp socket的客户端，并设置为异步。 
 *   Parameter: 
 *      Return: -1 -> 创建失败。
 *              >=0 返回创建的unix udp socket的句柄。
 */
int unix_udp_client_create();

/** 
 *        Name: sock_set_nonblocking
 * Description: 。 
 *   Parameter: sock_fd -> socket描述符 
 *      Return: 0 -> 设置失败。
 *              1 -> 设置成功。
 */
int sock_set_nonblocking(int sock_fd);

/** 
 *        Name: sock_set_rcv_buffer_size
 * Description: 设置接收缓冲区大小 
 *   Parameter: sockd_fd -> socket描述符
 *              size -> 接收缓冲区大小
 *      Return: 0 -> 设置失败。
 *              1 -> 设置成功 。
 */
int sock_set_rcv_buffer_size(int sock_fd, int size);

/** 
 *        Name: sock_set_snd_buffer_size
 * Description: 设置发送缓冲区大小 
 *   Parameter: sockd_fd -> socket描述符
 *              size -> 发送缓冲区大小
 *      Return: 0 -> 设置失败。
 *              1 -> 设置成功 。
 */
int sock_set_snd_buffer_size(int sock_fd, int size);

/** 
 *        Name: is_valid_ip
 * Description: 是否是合法IP 
 *   Parameter: ip_str -> 是否是合法IP 
 *      Return: 0 -> 不是合法IP。
 *              1 -> 合法IP。
 */
int is_valid_ip(const char *ip_str);
#endif
