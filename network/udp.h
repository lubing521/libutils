/*
 * =====================================================================================
 *
 *       Filename:  udp.h
 *
 *    Description:  udp 封装 
 *
 *        Version:  1.0
 *        Created:  01/06/2013 10:53:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _UDP_H_
#define _UDP_H_
#include "utils.h"
#include "network_util.h"

/** 
 *        Name: udp_unix_socket_create
 * Description: 创建unix domain udp socket
 *   Parameter: unix_path -> 本地unix path
 *      Return: 返回unix domain socket文件描述符
 *              -1 -> 失败 
 */
int udp_unix_socket_create(char *unix_path);

/** 
 *        Name: udp_unix_socket_send
 * Description: unix domain udp socket send data
 *   Parameter: fd -> sock描述符
 *              peer_path -> 对等节点地址
 *              buffer -> 发送数据buffer
 *              size -> 发送数据字节数
 *      Return: >= 0 -> 发送成功
 *              -1   -> 发送失败
 */
int udp_unix_socket_send(int fd, char *peer_path, char *buffer, int size);

/** 
 *        Name: udp_unix_socket_recv
 * Description: unix domain udp socket recv data
 *   Parameter: fd -> sock描述符
 *              buffer -> 接收数据的buffer
 *              size -> 接收数据buffer的大小
 *      Return: 接收的字节数
 *              -1 -> 接收错误
 *              
 */
int udp_unix_socket_recv(int fd, char *buffer, int size);

/** 
 *        Name: udp_unix_socket_close 
 * Description: 关闭unix domain udp socket
 *   Parameter: fd -> sock描述符
 *      Return:  
 *              
 */
void udp_unix_socket_close(int fd);

#endif
